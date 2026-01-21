//// CalibrationManager 구현파일:

#include "pch.h"
#include "CalibrationManager.h"

bool CalibrationManager::loadCalibration(const std::string& filepath)
{
	destroyCalibration();
	m_cal = std::make_unique<Calibration>();

	std::ifstream fin(filepath);
	if (!fin.is_open()) {
		std::cerr << "[CalibrationManager] Failed to open file : " << filepath << std::endl;
		m_cal.reset();

		return false;
	}

	std::string line;
	int axisIndex = 0;

	while (std::getline(fin, line)) {
		// NumGages
		if (line.find("<FTSensor") != std::string::npos) {
			std::size_t pos = line.find("NumGages=");
			if (pos != std::string::npos) {
				std::size_t start = line.find('"', pos);
				std::size_t end = line.find('"', start + 1);

				if (start != std::string::npos && end != std::string::npos) {
					int numGages = std::stoi(line.substr(start + 1, end - start - 1));
					m_cal->m_numChannels = std::min(numGages, MAX_GAGES);
				}
			}
		}

		// Calibration (ForceUnits, TorqueUnits, GainMultiplier)
		else if (line.find("<Calibration") != std::string::npos) {
			std::size_t pos;

			pos = line.find("ForceUnits=");
			if (pos != std::string::npos) {
				std::size_t start = line.find('"', pos);
				std::size_t end = line.find('"', start + 1);
				m_cal->m_forceUnits = line.substr(start + 1, end - start - 1);
			}

			pos = line.find("TorqueUnits=");
			if (pos != std::string::npos) {
				std::size_t start = line.find('"', pos);
				std::size_t end = line.find('"', start + 1);
				m_cal->m_torqueUnits = line.substr(start + 1, end - start - 1);
			}

			pos = line.find("GainMultiplier=");
			if (pos != std::string::npos) {
				std::size_t start = line.find('"', pos);
				std::size_t end = line.find('"', start + 1);
				m_cal->m_gainMultiplier = std::stof(line.substr(start + 1, end - start - 1));
			}
		}

		// UserAxis
		else if (line.find("UserAxis") != std::string::npos && axisIndex < MAX_AXES) {
			if (line.find("<!--") != std::string::npos) continue;	// skip comment line

			std::cout << "[DEBUG] Found UserAxis line : " << line << "\r\n";

			std::size_t pos = line.find("Name=");
			if (pos != std::string::npos) {
				std::size_t start = line.find('"', pos);
				std::size_t end = line.find('"', start + 1);
				m_cal->m_axisNames[axisIndex] = line.substr(start + 1, end - start - 1);
			}

			pos = line.find("max=");
			if (pos != std::string::npos) {
				std::size_t start = line.find('"', pos);
				std::size_t end = line.find('"', start + 1);
				m_cal->m_maxLoads[axisIndex] = std::stof(line.substr(start + 1, end - start - 1));
			}

			pos = line.find("scale=");
			if (pos != std::string::npos) {
				std::size_t start = line.find('"', pos);
				std::size_t end = line.find('"', start + 1);
				m_cal->m_scales[axisIndex] = std::stof(line.substr(start + 1, end - start - 1));
			}

			pos = line.find("values=");
			if (pos != std::string::npos) {
				std::size_t start = line.find('"', pos);
				std::size_t end = line.find('"', start + 1);
				std::string values = line.substr(start + 1, end - start - 1);

				std::istringstream iss(values);
				float val;
				int g = 0;
				while (iss >> val && g < MAX_GAGES) {
					m_cal->m_workingMatrix[axisIndex][g] = val;
					++g;
				}
				m_cal->m_numChannels = std::max(m_cal->m_numChannels, g);
			}
			axisIndex++;
		}
	}
	m_cal->m_numAxes = axisIndex;

	std::cout << "[CalibrationManager] Loaded : axes = " << m_cal->m_numAxes << ", channels = " << m_cal->m_numChannels << ", GainMultiplier = " << m_cal->m_gainMultiplier
		<< "\r\n";

	return true;
}

void CalibrationManager::destroyCalibration()
{
	m_cal.reset();
}

void CalibrationManager::applyBias(const std::array<float, MAX_GAGES>& voltages)
{
	if (!m_cal) return;

	std::copy_n(voltages.begin(), m_cal->m_numChannels, m_cal->m_biasVector.begin());
	m_cal->m_biasApplied = true;
}

void CalibrationManager::clearBias()
{
	if (!m_cal) return;

	m_cal->m_biasVector.fill(0.0f);
	m_cal->m_biasApplied = false;
}

void CalibrationManager::convertToFT(const std::array<float, MAX_GAGES>& voltages, std::array<float, MAX_AXES>& result) const
{
	if (!m_cal) return;
	result.fill(0.0f);

	std::array<float, MAX_GAGES> corrected{};
	for (int g = 0; g < m_cal->m_numChannels; g++) {
		corrected[g] = voltages[g];
		if (m_cal->m_biasApplied) {
			corrected[g] -= m_cal->m_biasVector[g];
		}
	}

	for (int axis = 0; axis < m_cal->m_numAxes; axis++) {
		float sum = 0.0f;
		for (int g = 0; g < m_cal->m_numChannels; g++) {
			sum += m_cal->m_workingMatrix[axis][g] * corrected[g];
		}

		result[axis] = sum * m_cal->m_scales[axis] * m_cal->m_gainMultiplier;
	}
}

int CalibrationManager::getNumAxes() const
{
	return m_cal ? m_cal->m_numAxes : 0;
}

int CalibrationManager::getNumChannels() const
{
	return m_cal ? m_cal->m_numChannels : 0;
}

bool CalibrationManager::isBiasApplied() const
{
	return m_cal ? m_cal->m_biasApplied : false;
}

float CalibrationManager::getMatrix(int axis, int channel) const
{
	if (!m_cal) return 0.0f;
	if (axis < 0 || axis >= m_cal->m_numAxes) return 0.0f;
	if (channel < 0 || channel >= m_cal->m_numChannels) return 0.0f;

	return m_cal->m_workingMatrix[axis][channel];
}


