#pragma once

#include <string>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>


constexpr int MAX_GAGES = 8;
constexpr int MAX_AXES = 6;

struct Calibration {
	std::string m_serial;
	std::string m_bodyStyle;
	std::string m_partNumber;
	std::string m_calDate;
	std::string m_family;

	int m_numChannels = 0;
	int m_numAxes = 0;

	std::array<std::array<float, MAX_GAGES>, MAX_AXES> m_basicMatrix{};
	std::array<std::array<float, MAX_GAGES>, MAX_AXES> m_workingMatrix{};

	std::array<float, MAX_AXES> m_maxLoads{};
	std::array<std::string, MAX_AXES> m_axisNames{};

	std::array<float, MAX_GAGES> m_biasVector{};
	std::array<float, MAX_AXES> m_scales{};

	float m_gainMultiplier = 1.0f;
	bool m_biasApplied = false;

	std::string m_forceUnits = "N";
	std::string m_torqueUnits = "N-mm";

	Calibration() {
		m_scales.fill(1.0f);
	}

};


class CalibrationManager {
public:
	CalibrationManager() = default;
	~CalibrationManager() = default;

	bool loadCalibration(const std::string& filepath);
	void destroyCalibration();

	void applyBias(const std::array<float, MAX_GAGES>& voltages);
	void clearBias();
	void convertToFT(const std::array<float, MAX_GAGES>& voltages, std::array<float, MAX_AXES>& result) const;

	int getNumAxes() const;
	int getNumChannels() const;
	bool isBiasApplied() const;
	float getMatrix(int axis, int channel) const;


private:
	std::unique_ptr<Calibration> m_cal;
};