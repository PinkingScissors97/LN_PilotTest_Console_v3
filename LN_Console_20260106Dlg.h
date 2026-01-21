
// LN_Console_20260106Dlg.h: 헤더 파일
// 2026 01 21 latest update
//

#pragma once

#include "CalibrationManager.h"


// CLNConsole20260106Dlg 대화 상자
class CLNConsole20260106Dlg : public CDialogEx
{
// 생성입니다.
public:
	CLNConsole20260106Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LN_CONSOLE_20260106_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()
public:
	// ====================== Linear Stage ================================
	CSerialComm m_SerialPort;

	CComboBox m_comboLinearPort;
	CString m_cstrLinearPort;

	CButton m_checkLinearConnect;
	CStatic m_staticLinearState;
	BOOL m_bIsLinearConnected;

	CStatic m_staticLinearSpeed;
	CEdit m_editLinearSpeed;
	int m_nLinearSpeed;

	CStatic m_staticLinearMaxPos;
	int m_nLinearMaxPos;

	CStatic m_staticLinearCurPos;
	int m_nLinearCurPos;

	CEdit m_editLinearStep;
	int m_nLinearStep;

	afx_msg void OnCbnDropdownComport();
	afx_msg void OnCbnSelchangeComport();
	afx_msg void OnBnClickedLinearConnect();
	afx_msg void OnBnClickedLinearSetzero();
	afx_msg void OnBnClickedLinearSetmax();
	afx_msg void OnBnClickedLinearSetspeed();
	afx_msg void OnBnClickedLinearForward();
	afx_msg void OnBnClickedLinearReverse();
	afx_msg void OnBnClickedLinearHome();

	// ======================== Camera =======================
	CStatic m_staticCameraState;
	CButton m_checkCameraConnect;
	CStatic m_pictureCam0;
	CStatic m_pictureCam1;

	BOOL m_bIsCameraConnected;
	std::vector<int> m_vecCameraIndices;
	std::vector<cv::VideoCapture> m_vecVideoCaptures;
	// std::vector<cv::Mat> m_vecLastFrames;

	static constexpr int REQUIRED_CAMERA_COUNT = 2;

	BOOL ValidateC920Cameras();
	BOOL InitializeCameras();
	void ReleaseCameras();
	void DisplayFrames(CStatic& pictureCtrl, const cv::Mat& frame);

	//afx_msg void OnBnClickedCamConnect()
	//{
	//	BOOL bChecked = m_checkCameraConnect.GetCheck();

	//	if (bChecked == BST_CHECKED) {
	//		AfxMessageBox(_T("step 1 : 시작"));

	//		AfxMessageBox(_T("step 2 : IntializeCameras 호출 전"));
	//		if (InitializeCameras()) {
	//			AfxMessageBox(_T("step 3 : InitializeCameras 성공"));
	//			m_checkCameraConnect.SetWindowText(_T("Disconnect"));

	//			AfxMessageBox(_T("step 4 : StartCameraThread 호출 전"));

	//			StartCameraThread();  // ⭐ 개별 제어
	//			UpdateAllControls();
	//			AfxMessageBox(_T("Cameras connected!"));
	//		}
	//		else {
	//			AfxMessageBox(_T("InitializeCameras 실패"));
	//			UpdateAllControls();
	//			m_checkCameraConnect.SetCheck(BST_UNCHECKED);
	//		}
	//	}
	//	else {
	//		StopCameraThread();  // ⭐ 개별 제어
	//		ReleaseCameras();
	//		m_checkCameraConnect.SetWindowText(_T("Connect"));
	//		UpdateAllControls();
	//		AfxMessageBox(_T("Cameras disconnected!"));
	//	}
	//}

	// ======================== DAQ ========================
	TaskHandle m_TaskHandle = nullptr;
	CComboBox m_comboDAQList;
	CButton m_checkDAQConnect;

	BOOL m_bIsDAQConnected;
	BOOL m_bIsDAQCalibrated;
	BOOL m_bIsDAQBiased;

	CButton m_radioDAQVoltage;
	CButton m_radioDAQUnit;
	CEdit m_editDAQCalibPath;
	CStatic m_staticDAQFx, m_staticDAQFy, m_staticDAQFz;
	CStatic m_staticDAQTx, m_staticDAQTy, m_staticDAQTz;

	double m_dDAQFx, m_dDAQFy, m_dDAQFz;
	double m_dDAQTx, m_dDAQTy, m_dDAQTz;

	double m_arrDAQBiasValues[6];

	// double m_arrLastVoltages[6];

	// static constexpr UINT IDT_SENSOR_TIMER = 3;

	enum class SensorDisplayMode {
		Voltage,
		ForceTorque
	};

	SensorDisplayMode m_displayMode;

	CalibrationManager m_CalibrationManager;
	afx_msg void OnCbnDropdownDaqList();
	afx_msg void OnBnClickedDaqConnect();
	afx_msg void OnBnClickedDaqCalibpath();
	afx_msg void OnBnClickedDaqBias();
	afx_msg void OnBnClickedDaqUnbias();
	afx_msg void OnBnClickedDaqVoltage();
	afx_msg void OnBnClickedDaqUnit();

	void UpdateDAQDisplay(const double values[6]);


	// =================== Thread & Sync ====================
private:
	static constexpr UINT IDT_UI_UPDATE_TIMER = 1;

	// camera thread
	std::thread m_threadCamera;
	std::atomic<bool> m_bIsCameraThreadRunning;

	// DAQ thread
	std::thread m_threadDAQ;
	std::atomic<bool> m_bIsDAQThreadRunning;

	struct LatestData {
		cv::Mat frames[REQUIRED_CAMERA_COUNT];
		double sensorValues[6];
		std::chrono::steady_clock::time_point cameraTimestamp;
		std::chrono::steady_clock::time_point daqTimestamp;

		uint64_t cameraSeq;
		uint64_t daqSeq;

		LatestData() : cameraSeq(0), daqSeq(0) {
			for (int i = 0; i < 6; ++i) sensorValues[i] = 0.0;
			cameraTimestamp = std::chrono::steady_clock::time_point();
			daqTimestamp = std::chrono::steady_clock::time_point();
		}
	};

	struct SynchronizedSnapshot {
		cv::Mat frames[REQUIRED_CAMERA_COUNT];
		double sensorValues[6];

		std::chrono::steady_clock::time_point saveTimestamp;
		std::chrono::steady_clock::time_point cameraTimestamp;
		std::chrono::steady_clock::time_point daqTimestamp;
	};

	LatestData m_latestData;
	std::mutex m_mutexLatestData;
	std::condition_variable m_cvLatestData;

	bool AcquireSynchronizedSnapshot(SynchronizedSnapshot& outSnapshot, int maxWaitMs);
	bool SaveSynchronizedSample(int position);

	//cv::Mat m_latestFrames[REQUIRED_CAMERA_COUNT];
	//std::mutex m_mutexLatestFrames;

	void CameraThreadFunc();
	void DAQThreadFunc();
	void UpdateUIFromThreads();

	void StartThreads();
	void StopThreads();

	void StartCameraThread();
	void StopCameraThread();
	void StartDAQThread();
	void StopDAQThread();


	// ====================Auto Experiment Protocol ===================
public:
	CEdit m_editAutoSavePath;
	CEdit m_editAutoStartPos;
	CEdit m_editAutoEndPos;
	CEdit m_editAutoStepInterval;

	CString m_cstrAutoSavePath;
	CStatic m_staticAutoState;
	int m_nAutoStartPos;
	int m_nAutoEndPos;
	int m_nAutoStepInterval;

	afx_msg void OnBnClickedSavePath();

private:
	// auto 실행 상태
	enum class AutoState{
		Idle,
		Initializing,
		MovingToStart,
		Running,
		Capturing,
		Saving,
		Aborting,
		Completed,
		Error
	};

	enum class LinearDirection {
		Forward,
		Reverse
	};

	AutoState m_autoState;
	std::atomic<bool> m_bIsAutoRunning;
	std::atomic<bool> m_bIsAutoAbortRequested;
	std::thread m_threadAuto;

	std::wofstream m_autoCSVFile;
	std::chrono::steady_clock::time_point m_autoStartTime;

	int m_nAutoCurrentPos;
	int m_nAutoCurrentStep;
	int m_nAutoTotalSteps;

	// auto thread 함수
	void AutoExperimentThread();
	void UpdateAutoStatus(const CString& status);
	//void UpdateAutoProgress(int current, int total);

	// 데이터 저장 함수
	bool SaveFrames(int position);
	bool SaveSensorData(int position);
	bool CreateExperimentFolder();
	bool OpenCSVFile();
	void CloseCSVFile();

	// 리니어스테이지 통신 (프로토콜 구현시 사용)
	bool SendLinearCmd_Move(int position, LinearDirection direction);
	bool SendLinearCmd_MoveTo(int absolutePosition);	// 절대 위치로 이동
	bool WaitForLinearResponse(int& currentPosition, int timeouts = 5000);

	void OnAutoCompleted();
	void OnAutoCleanup();

	afx_msg void OnBnClickedAutoRun();
	afx_msg void OnBnClickedAutoAbort();

	// ======================== Linear Stage Protocol ====================
public:
	afx_msg LRESULT OnSerialReceived(WPARAM wParam, LPARAM lParam);

private:
	// 명령어 타입
	enum class CMD_TYPE: uint8_t {
		GET_POS = 0x10,
		GET_SPEED = 0x11,
		GET_MAX = 0x12,
		SET_ZERO = 0x20,
		SET_MAX = 0x21,
		SET_SPEED = 0x22,
		MOVE_REL = 0x30,
		MOVE_ABS = 0x31,
		HOME = 0x32,
		STOP = 0x40,
		ERR = 0xFF
	};

	// 상태 타입
	enum class STATUS_TYPE : uint8_t {
		OK = 0x00,
		ERR = 0x01
	};

	// 방향 타입
	enum class DIR_TYPE : uint8_t {
		FORWARD = 0x00,
		REVERSE = 0x01
	};


	// 패킷 인덱스
	static constexpr uint8_t IDX_HEADER = 0;
	static constexpr uint8_t IDX_CMD = 1;
	static constexpr uint8_t IDX_STATUS = 2;
	static constexpr uint8_t IDX_RESERVED = 3;
	static constexpr uint8_t IDX_DATA_3 = 4;
	static constexpr uint8_t IDX_DATA_2 = 5;
	static constexpr uint8_t IDX_DATA_1 = 6;
	static constexpr uint8_t IDX_DATA_0 = 7;
	static constexpr uint8_t IDX_CHECKSUM = 8;
	static constexpr uint8_t IDX_TAIL = 9;
	static constexpr uint8_t PACKET_SIZE = 10;

	static constexpr uint8_t HEADER = 0xAA;
	static constexpr uint8_t TAIL = 0x55;

	// Pending ACK 구조체
	struct PendingAck {
		CMD_TYPE cmd;
		BOOL waiting;
		BOOL got;
		STATUS_TYPE status;
		int32_t data;

		PendingAck() : cmd(CMD_TYPE::ERR), waiting(FALSE), got(FALSE), status(STATUS_TYPE::ERR), data(0) {}
	};

	PendingAck m_linearPending;
	std::vector<uint8_t> m_linearRxBuffer;

	void BuildLinearPacket(uint8_t* packet, CMD_TYPE cmd, STATUS_TYPE status, uint8_t reserved, int32_t data);
	uint8_t ComputeChecksum(CMD_TYPE cmd, STATUS_TYPE status, uint8_t reserved, int32_t data);
	bool CheckPacketIntegrity(const uint8_t* packet);
	bool VerifyChecksum(const uint8_t* packet);

	// 데이터 추출
	CMD_TYPE ExtractCmd(const uint8_t* packet);
	STATUS_TYPE ExtractStatus(const uint8_t* packet);
	uint8_t ExtractReserved(const uint8_t* packet);
	int32_t ExtractData(const uint8_t* packet);

	// 통신 함수
	bool SendLinearCmd(CMD_TYPE cmd, int32_t data, int32_t* outData = nullptr);
	bool SendLinearCmd(CMD_TYPE cmd, int32_t data, DIR_TYPE dir, int32_t* outData = nullptr);
	void ProcessLinearPacket(const uint8_t* packet);

private:
	void UpdateLinearControls();
	void UpdateDAQControls();
	void UpdateAutoControls();
	void UpdateAllControls();

public:
	afx_msg LRESULT OnCameraInitComplete(WPARAM wParam, LPARAM lParam);	// 추가
	std::mutex m_mutexCameraInit;
	CString m_strCameraInitError;


	afx_msg void OnBnClickedCamConnect();

	afx_msg LRESULT OnAutoStatusUpdate(WPARAM wParam, LPARAM lParam);

	std::atomic<bool> m_bIsUIShuttingDown{ false };
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
