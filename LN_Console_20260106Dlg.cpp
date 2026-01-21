
// LN_Console_20260106Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "LN_Console_20260106.h"
#include "LN_Console_20260106Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLNConsole20260106Dlg 대화 상자



CLNConsole20260106Dlg::CLNConsole20260106Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LN_CONSOLE_20260106_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLNConsole20260106Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, COMBO_COMPORT, m_comboLinearPort);
	DDX_Control(pDX, CHECK_LINEAR_CONNECT, m_checkLinearConnect);
	DDX_Control(pDX, TEXT_LINEAR_STATE, m_staticLinearState);
	DDX_Control(pDX, TEXT_LINEAR_SPEED, m_staticLinearSpeed);
	DDX_Control(pDX, TEXT_LINEAR_MAXPOS, m_staticLinearMaxPos);
	DDX_Control(pDX, TEXT_LINEAR_CURPOS, m_staticLinearCurPos);
	DDX_Control(pDX, EDIT_LINEAR_SPEED, m_editLinearSpeed);
	DDX_Control(pDX, EDIT_LINEAR_STEPS, m_editLinearStep);
	DDX_Control(pDX, TEXT_CAM_STATE, m_staticCameraState);
	DDX_Control(pDX, CHECK_CAM_CONNECT, m_checkCameraConnect);
	DDX_Control(pDX, PICTURE_VIEW_LEFT, m_pictureCam0);
	DDX_Control(pDX, PICTURE_VIEW_RIGHT, m_pictureCam1);
	DDX_Control(pDX, COMBO_DAQ_LIST, m_comboDAQList);
	DDX_Control(pDX, CHECK_DAQ_CONNECT, m_checkDAQConnect);
	DDX_Control(pDX, RADIO_DAQ_VOLTAGE, m_radioDAQVoltage);
	DDX_Control(pDX, RADIO_DAQ_UNIT, m_radioDAQUnit);
	DDX_Control(pDX, EDIT_DAQ_CALIBPATH, m_editDAQCalibPath);
	DDX_Control(pDX, TEXT_DAQ_FX, m_staticDAQFx);
	DDX_Control(pDX, TEXT_DAQ_FY, m_staticDAQFy);
	DDX_Control(pDX, TEXT_DAQ_FZ, m_staticDAQFz);
	DDX_Control(pDX, TEXT_DAQ_TX, m_staticDAQTx);
	DDX_Control(pDX, TEXT_DAQ_TY, m_staticDAQTy);
	DDX_Control(pDX, TEXT_DAQ_TZ, m_staticDAQTz);
	DDX_Control(pDX, EDIT_SAVE_PATH, m_editAutoSavePath);
	DDX_Control(pDX, EDIT_AUTO_ENDPOS2, m_editAutoStepInterval);
	DDX_Control(pDX, EDIT_AUTO_STARTPOS, m_editAutoStartPos);
	DDX_Control(pDX, EDIT_AUTO_ENDPOS, m_editAutoEndPos);
	DDX_Control(pDX, TEXT_AUTO_STATE, m_staticAutoState);
}

BEGIN_MESSAGE_MAP(CLNConsole20260106Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_DROPDOWN(COMBO_COMPORT, &CLNConsole20260106Dlg::OnCbnDropdownComport)
	ON_CBN_SELCHANGE(COMBO_COMPORT, &CLNConsole20260106Dlg::OnCbnSelchangeComport)
	ON_BN_CLICKED(CHECK_LINEAR_CONNECT, &CLNConsole20260106Dlg::OnBnClickedLinearConnect)
	ON_BN_CLICKED(BUTTON_LINEAR_SETZERO, &CLNConsole20260106Dlg::OnBnClickedLinearSetzero)
	ON_BN_CLICKED(BUTTON_LINEAR_SETMAX, &CLNConsole20260106Dlg::OnBnClickedLinearSetmax)
	ON_BN_CLICKED(BUTTON_LINEAR_SETSPEED, &CLNConsole20260106Dlg::OnBnClickedLinearSetspeed)
	ON_BN_CLICKED(BUTTON_LINEAR_FORWARD, &CLNConsole20260106Dlg::OnBnClickedLinearForward)
	ON_BN_CLICKED(BUTTON_LINEAR_REVERSE, &CLNConsole20260106Dlg::OnBnClickedLinearReverse)
	ON_BN_CLICKED(BUTTON_LINEAR_HOME, &CLNConsole20260106Dlg::OnBnClickedLinearHome)
	//ON_BN_CLICKED(CHECK_CAM_CONNECT, &CLNConsole20260106Dlg::OnBnClickedCamConnect)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_CBN_DROPDOWN(COMBO_DAQ_LIST, &CLNConsole20260106Dlg::OnCbnDropdownDaqList)
	ON_BN_CLICKED(CHECK_DAQ_CONNECT, &CLNConsole20260106Dlg::OnBnClickedDaqConnect)
	ON_BN_CLICKED(BUTTON_DAQ_CALIBPATH, &CLNConsole20260106Dlg::OnBnClickedDaqCalibpath)
	ON_BN_CLICKED(BUTTON_DAQ_BIAS, &CLNConsole20260106Dlg::OnBnClickedDaqBias)
	ON_BN_CLICKED(BUTTON_DAQ_UNBIAS, &CLNConsole20260106Dlg::OnBnClickedDaqUnbias)
	ON_BN_CLICKED(RADIO_DAQ_VOLTAGE, &CLNConsole20260106Dlg::OnBnClickedDaqVoltage)
	ON_BN_CLICKED(RADIO_DAQ_UNIT, &CLNConsole20260106Dlg::OnBnClickedDaqUnit)
	ON_BN_CLICKED(BUTTON_SAVE_PATH, &CLNConsole20260106Dlg::OnBnClickedSavePath)
	ON_BN_CLICKED(BUTTON_AUTO_RUN, &CLNConsole20260106Dlg::OnBnClickedAutoRun)
	ON_BN_CLICKED(BUTTON_AUTO_ABORT, &CLNConsole20260106Dlg::OnBnClickedAutoAbort)

	ON_COMMAND(IDC_AUTO_COMPLETED, &CLNConsole20260106Dlg::OnAutoCompleted)
	ON_COMMAND(IDC_AUTO_CLEANUP, &CLNConsole20260106Dlg::OnAutoCleanup)

	ON_MESSAGE(WM_SERIAL_RECEIVED, &CLNConsole20260106Dlg::OnSerialReceived)

	ON_MESSAGE(WM_CAMERA_INIT_COMPLETE, &CLNConsole20260106Dlg::OnCameraInitComplete)
	ON_BN_CLICKED(CHECK_CAM_CONNECT, &CLNConsole20260106Dlg::OnBnClickedCamConnect)
	ON_MESSAGE(WM_AUTO_STATUS_UPDATE, &CLNConsole20260106Dlg::OnAutoStatusUpdate)
END_MESSAGE_MAP()


// CLNConsole20260106Dlg 메시지 처리기

BOOL CLNConsole20260106Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	// Linear Stage 초기화
	m_bIsLinearConnected = FALSE;
	m_nLinearSpeed = 0;
	m_nLinearMaxPos = 0;
	m_nLinearCurPos = 0;
	m_nLinearStep = 0;

	m_staticLinearState.SetWindowTextW(_T("Disconnected"));
	m_staticLinearSpeed.SetWindowTextW(_T("0"));
	m_staticLinearMaxPos.SetWindowTextW(_T("N/A"));
	m_staticLinearCurPos.SetWindowTextW(_T("0"));


	// Camera 초기화
	m_bIsCameraConnected = FALSE;
	m_bIsCameraThreadRunning = false;
	m_staticCameraState.SetWindowTextW(_T("Disconnected"));



	// DAQ 초기화
	m_bIsDAQConnected = FALSE;
	m_bIsDAQBiased = FALSE;
	m_TaskHandle = nullptr;
	m_bIsDAQThreadRunning = false;

	// 센서 표시 모드 초기화
	m_displayMode = SensorDisplayMode::Voltage;
	m_radioDAQVoltage.SetCheck(BST_CHECKED);
	m_radioDAQUnit.SetCheck(BST_UNCHECKED);

	m_dDAQFx = m_dDAQFy = m_dDAQFz = 0.0;
	m_dDAQTx = m_dDAQTy = m_dDAQTz = 0.0;

	// LatestData 초기화
	for (int i = 0; i < 6; i++) {
		m_latestData.sensorValues[i] = 0.0;
	}

	double zeros[6] = { 0.0 };
	UpdateDAQDisplay(zeros);

	// auto 초기화
	m_autoState = AutoState::Idle;
	m_bIsAutoRunning = false;
	m_bIsAutoAbortRequested = false;
	m_nAutoStartPos = 0;
	m_nAutoEndPos = 0;
	m_nAutoStepInterval = 0;
	m_nAutoCurrentPos = 0;
	m_nAutoCurrentStep = 0;
	m_nAutoTotalSteps = 0;

	m_staticAutoState.SetWindowTextW(_T("Ready"));

	//CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

	UpdateAllControls();


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CLNConsole20260106Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CLNConsole20260106Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CLNConsole20260106Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLNConsole20260106Dlg::OnCbnDropdownComport()
{
	HKEY hKey;
	if (RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"), &hKey) != ERROR_SUCCESS) {
		return;
	}

	TCHAR szData[20] = { 0 };
	TCHAR szName[100] = { 0 };
	DWORD index = 0;

	m_comboLinearPort.ResetContent();

	while (true) {
		DWORD nameSize = _countof(szName);
		DWORD dataSize = sizeof(szData);
		DWORD dwType = REG_SZ;

		if (RegEnumValue(hKey, index, szName, &nameSize, nullptr, nullptr, nullptr, nullptr) != ERROR_SUCCESS) {
			break;
		}

		if (RegQueryValueEx(hKey, szName, nullptr, &dwType, reinterpret_cast<LPBYTE>(szData), &dataSize) == ERROR_SUCCESS) {
			m_comboLinearPort.AddString(CString(szData));
		}

		++index;
		ZeroMemory(szData, sizeof(szData));
		ZeroMemory(szName, sizeof(szName));
	}

	RegCloseKey(hKey);
}

void CLNConsole20260106Dlg::OnCbnSelchangeComport()
{
	int index = m_comboLinearPort.GetCurSel();
	if (index != CB_ERR) {
		CString temp;
		m_comboLinearPort.GetLBText(index, temp);
		m_cstrLinearPort = _T("\\\\.\\") + temp;
	}
}

void CLNConsole20260106Dlg::OnBnClickedLinearConnect()
{
	m_SerialPort.SetMessageDest(this->GetSafeHwnd());
	UpdateData(TRUE);
	BOOL isChecked = m_checkLinearConnect.GetCheck();

	if (isChecked == TRUE) {
		// 연결
		if (!m_SerialPort.Connect(m_cstrLinearPort, CSerialComm::EBaudrate(9600))) {
			m_bIsLinearConnected = FALSE;
			m_checkLinearConnect.SetWindowText(_T("Connect"));
			m_checkLinearConnect.SetCheck(FALSE);
			AfxMessageBox(_T("Failed to connect!"));
			UpdateAllControls();
			return;
		}

		if (m_SerialPort.IsOpen()) {
			m_bIsLinearConnected = TRUE;
			m_checkLinearConnect.SetWindowText(_T("Disconnect"));
			m_staticLinearState.SetWindowText(_T("Initializing..."));

			OutputDebugString(_T("[Linear] Waiting for Arduino initialization...\r\n"));

			Sleep(1000);

			// ⭐ 버퍼 클리어
			m_linearRxBuffer.clear();

			m_staticLinearState.SetWindowText(_T("Connected"));

			OutputDebugString(_T("[Linear] Querying initial state...\r\n"));

			// 초기 상태 조회
			int32_t currentPos = 0;
			int32_t currentSpeed = 0;
			int32_t maxPos = 0;

			// 현재 위치 조회
			if (SendLinearCmd(CMD_TYPE::GET_POS, 0, &currentPos)) {
				m_nLinearCurPos = currentPos;
				CString str;
				str.Format(_T("%d"), m_nLinearCurPos);
				m_staticLinearCurPos.SetWindowText(str);
				OutputDebugString(_T("[Linear] Position: OK\r\n"));
			}
			else {
				OutputDebugString(_T("[Linear] Position: FAILED\r\n"));
			}

			// 현재 속도 조회
			if (SendLinearCmd(CMD_TYPE::GET_SPEED, 0, &currentSpeed)) {
				m_nLinearSpeed = currentSpeed;
				CString str;
				str.Format(_T("%d"), m_nLinearSpeed);
				m_staticLinearSpeed.SetWindowText(str);
				OutputDebugString(_T("[Linear] Speed: OK\r\n"));
			}
			else {
				OutputDebugString(_T("[Linear] Speed: FAILED\r\n"));
			}

			// Max Pos 조회
			if (SendLinearCmd(CMD_TYPE::GET_MAX, 0, &maxPos)) {
				m_nLinearMaxPos = maxPos;
				CString str;
				str.Format(_T("%d"), m_nLinearMaxPos);
				m_staticLinearMaxPos.SetWindowText(str);
				OutputDebugString(_T("[Linear] Max: OK\r\n"));
			}
			else {
				OutputDebugString(_T("[Linear] Max: FAILED\r\n"));
			}
			UpdateAllControls();
			AfxMessageBox(_T("Connected successfully!"));
		}
	}
	else {
		// 연결 해제
		m_SerialPort.Disconnect();
		m_bIsLinearConnected = FALSE;
		m_checkLinearConnect.SetWindowText(_T("Connect"));
		m_staticLinearState.SetWindowText(_T("Disconnected"));

		// 버퍼 초기화
		m_linearRxBuffer.clear();
		UpdateAllControls();
		AfxMessageBox(_T("Disconnected!"));
	}
	//m_SerialPort.SetMessageDest(this->GetSafeHwnd());
	//UpdateData(TRUE);
	//BOOL isChecked = m_checkLinearConnect.GetCheck();

	//if (isChecked == TRUE) {
	//	// 연결
	//	if (!m_SerialPort.Connect(m_cstrLinearPort, CSerialComm::EBaudrate(9600))) {
	//		m_bIsLinearConnected = FALSE;
	//		m_checkLinearConnect.SetWindowText(_T("Connect"));
	//		m_checkLinearConnect.SetCheck(FALSE);
	//		AfxMessageBox(_T("Failed to connect!"));
	//		return;
	//	}

	//	if (m_SerialPort.IsOpen()) {
	//		m_staticLinearState.SetWindowTextW(_T("Waiting for Arduino..."));

	//		ULONGLONG start = GetTickCount64();
	//		bool ready = false;

	//		while (GetTickCount64() - start < 3000) {
	//			uint8_t packet[PACKET_SIZE];
	//			std::copy_n(m_linearRxBuffer.begin(), PACKET_SIZE, packet);

	//			if (CheckPacketIntegrity(packet) && ExtractCmd(packet) == CMD_TYPE::GET_POS) {
	//				ready = true;
	//				m_linearRxBuffer.clear();
	//				break;
	//			}
	//		}
	//		m_bIsLinearConnected = TRUE;
	//		m_checkLinearConnect.SetWindowText(_T("Disconnect"));
	//		m_staticLinearState.SetWindowText(_T("Connected"));

	//		// ⭐ 아두이노 리셋 대기
	//		OutputDebugString(_T("[Linear] Waiting for Arduino reset...\r\n"));
	//		Sleep(2000);  // 2초 대기 (부트로더 + setup 완료)

	//		// ⭐ 버퍼 클리어 (부트로더 쓰레기 데이터 제거)
	//		m_linearRxBuffer.clear();

	//		OutputDebugString(_T("[Linear] Querying initial state...\r\n"));

	//		// 초기 상태 조회
	//		int32_t currentPos = 0;
	//		int32_t currentSpeed = 0;
	//		int32_t maxPos = 0;

	//		// 현재 위치 조회
	//		if (SendLinearCmd(CMD_TYPE::GET_POS, 0, &currentPos)) {
	//			m_nLinearCurPos = currentPos;
	//			CString str;
	//			str.Format(_T("%d"), m_nLinearCurPos);
	//			m_staticLinearCurPos.SetWindowText(str);
	//			OutputDebugString(_T("[Linear] Position: OK\r\n"));
	//		}
	//		else {
	//			OutputDebugString(_T("[Linear] Position: FAILED\r\n"));
	//		}

	//		// 현재 속도 조회
	//		if (SendLinearCmd(CMD_TYPE::GET_SPEED, 0, &currentSpeed)) {
	//			m_nLinearSpeed = currentSpeed;
	//			CString str;
	//			str.Format(_T("%d"), m_nLinearSpeed);
	//			m_staticLinearSpeed.SetWindowText(str);
	//			OutputDebugString(_T("[Linear] Speed: OK\r\n"));
	//		}
	//		else {
	//			OutputDebugString(_T("[Linear] Speed: FAILED\r\n"));
	//		}

	//		// Max Pos 조회
	//		if (SendLinearCmd(CMD_TYPE::GET_MAX, 0, &maxPos)) {
	//			m_nLinearMaxPos = maxPos;
	//			CString str;
	//			str.Format(_T("%d"), m_nLinearMaxPos);
	//			m_staticLinearMaxPos.SetWindowText(str);
	//			OutputDebugString(_T("[Linear] Max: OK\r\n"));
	//		}
	//		else {
	//			OutputDebugString(_T("[Linear] Max: FAILED\r\n"));
	//		}

	//		AfxMessageBox(_T("Connected successfully!"));
	//	}
	//}
	//else {
	//	// 연결 해제
	//	m_SerialPort.Disconnect();
	//	m_bIsLinearConnected = FALSE;
	//	m_checkLinearConnect.SetWindowText(_T("Connect"));
	//	m_staticLinearState.SetWindowText(_T("Disconnected"));

	//	// 버퍼 초기화
	//	m_linearRxBuffer.clear();

	//	AfxMessageBox(_T("Disconnected!"));
	//}
}

void CLNConsole20260106Dlg::OnBnClickedLinearSetzero()
{
	if (!m_bIsLinearConnected) {
		AfxMessageBox(_T("Linear Stage not connected!"));
		return;
	}

	int32_t result = 0;
	if (SendLinearCmd(CMD_TYPE::SET_ZERO, 0, &result)) {
		m_nLinearCurPos = result;

		CString str;
		str.Format(_T("%d"), m_nLinearCurPos);
		m_staticLinearCurPos.SetWindowText(str);

		AfxMessageBox(_T("Current position set to 0!"));
	}
	else {
		AfxMessageBox(_T("Failed to set zero!"));
	}
}

void CLNConsole20260106Dlg::OnBnClickedLinearSetmax()
{
	if (!m_bIsLinearConnected) {
		AfxMessageBox(_T("Linear Stage not connected!"));
		return;
	}

	int32_t maxPos = 0;
	if (SendLinearCmd(CMD_TYPE::SET_MAX, 0, &maxPos)) {
		m_nLinearMaxPos = maxPos;

		CString str;
		str.Format(_T("%d"), m_nLinearMaxPos);
		m_staticLinearMaxPos.SetWindowText(str);

		CString msg;
		msg.Format(_T("Max position set to %d!"), m_nLinearMaxPos);
		AfxMessageBox(msg);
	}
	else {
		AfxMessageBox(_T("Failed to set max!"));
	}
}

void CLNConsole20260106Dlg::OnBnClickedLinearSetspeed()
{
	if (!m_bIsLinearConnected) {
		AfxMessageBox(_T("Linear Stage not connected!"));
		return;
	}

	CString temp;
	m_editLinearSpeed.GetWindowText(temp);
	int speed = _ttoi(temp);

	if (speed <= 0) {
		AfxMessageBox(_T("Invalid speed value!"));
		return;
	}

	int32_t resultSpeed = 0;
	if (SendLinearCmd(CMD_TYPE::SET_SPEED, speed, &resultSpeed)) {
		m_nLinearSpeed = resultSpeed;

		CString str;
		str.Format(_T("%d"), m_nLinearSpeed);
		m_staticLinearSpeed.SetWindowText(str);

		m_editLinearSpeed.SetWindowText(_T(""));

		CString msg;
		msg.Format(_T("Speed set to %d μs!"), m_nLinearSpeed);
		AfxMessageBox(msg);
	}
	else {
		AfxMessageBox(_T("Failed to set speed!"));
	}

}

void CLNConsole20260106Dlg::OnBnClickedLinearForward()
{
	if (!m_bIsLinearConnected) {
		AfxMessageBox(_T("Linear Stage not connected!"));
		return;
	}

	CString temp;
	m_editLinearStep.GetWindowText(temp);
	m_nLinearStep = _ttoi(temp);

	if (m_nLinearStep <= 0) {
		AfxMessageBox(_T("Invalid step value!"));
		return;
	}

	int32_t newPos = 0;
	if (SendLinearCmd(CMD_TYPE::MOVE_REL, m_nLinearStep, DIR_TYPE::FORWARD, &newPos)) {
		m_nLinearCurPos = newPos;

		CString str;
		str.Format(_T("%d"), m_nLinearCurPos);
		m_staticLinearCurPos.SetWindowText(str);

		m_editLinearStep.SetWindowText(_T(""));

		OutputDebugString(_T("[Linear] Forward move completed\r\n"));
	}
	else {
		AfxMessageBox(_T("Failed to move forward!"));
	}
}

void CLNConsole20260106Dlg::OnBnClickedLinearReverse()
{
	if (!m_bIsLinearConnected) {
		AfxMessageBox(_T("Linear Stage not connected!"));
		return;
	}

	CString temp;
	m_editLinearStep.GetWindowText(temp);
	m_nLinearStep = _ttoi(temp);

	if (m_nLinearStep <= 0) {
		AfxMessageBox(_T("Invalid step value!"));
		return;
	}

	int32_t newPos = 0;
	if (SendLinearCmd(CMD_TYPE::MOVE_REL, m_nLinearStep, DIR_TYPE::REVERSE, &newPos)) {
		m_nLinearCurPos = newPos;

		CString str;
		str.Format(_T("%d"), m_nLinearCurPos);
		m_staticLinearCurPos.SetWindowText(str);

		m_editLinearStep.SetWindowText(_T(""));

		OutputDebugString(_T("[Linear] Reverse move completed\r\n"));
	}
	else {
		AfxMessageBox(_T("Failed to move reverse!"));
	}
}

void CLNConsole20260106Dlg::OnBnClickedLinearHome()
{
	if (!m_bIsLinearConnected) {
		AfxMessageBox(_T("Linear Stage not connected!"));
		return;
	}

	int32_t finalPos = 0;
	if (SendLinearCmd(CMD_TYPE::HOME, 0, &finalPos)) {
		m_nLinearCurPos = finalPos;

		CString str;
		str.Format(_T("%d"), m_nLinearCurPos);
		m_staticLinearCurPos.SetWindowText(str);

		AfxMessageBox(_T("Homing completed!"));
	}
	else {
		AfxMessageBox(_T("Failed to home!"));
	}
}

BOOL CLNConsole20260106Dlg::ValidateC920Cameras()
{
	m_vecCameraIndices.clear();

	HRESULT hrInit = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
	bool needUninit = SUCCEEDED(hrInit);

	if (hrInit == RPC_E_CHANGED_MODE) {
		needUninit = false;
	}
	else if (FAILED(hrInit)) {
		return FALSE;
	}

	ICreateDevEnum* pDevEnum = nullptr;
	IEnumMoniker* pEnum = nullptr;

	HRESULT hr = CoCreateInstance(
		CLSID_SystemDeviceEnum,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum,
		(void**)&pDevEnum
	);

	if (FAILED(hr) || !pDevEnum) {
		if (needUninit) CoUninitialize();
		return FALSE;
	}

	hr = pDevEnum->CreateClassEnumerator(
		CLSID_VideoInputDeviceCategory,
		&pEnum,
		0
	);

	if (hr != S_OK || !pEnum) {
		pDevEnum->Release();
		if (needUninit) CoUninitialize();
		return FALSE;
	}

	IMoniker* pMoniker = nullptr;
	int idx = 0;

	while (pEnum->Next(1, &pMoniker, nullptr) == S_OK)
	{
		IPropertyBag* pPropBag = nullptr;

		if (SUCCEEDED(pMoniker->BindToStorage(nullptr, nullptr, IID_IPropertyBag, (void**)&pPropBag)))
		{
			VARIANT varName;
			VariantInit(&varName);

			if (SUCCEEDED(pPropBag->Read(L"FriendlyName", &varName, nullptr)) &&
				varName.vt == VT_BSTR && varName.bstrVal)
			{
				std::wstring name(varName.bstrVal);
				std::transform(
					name.begin(), name.end(),
					name.begin(), ::towlower
				);

				if (name.find(L"hd pro webcam c920") != std::wstring::npos) {
					m_vecCameraIndices.push_back(idx);
				}
			}

			VariantClear(&varName);
			pPropBag->Release();
		}

		pMoniker->Release();
		++idx;
	}

	pEnum->Release();
	pDevEnum->Release();

	if (needUninit) {
		CoUninitialize();
	}

	if (m_vecCameraIndices.size() != REQUIRED_CAMERA_COUNT) {
		CString msg;
		msg.Format(
			_T("Required: %d C920 cameras\nFound: %d cameras\n\nCheck connections!"),
			REQUIRED_CAMERA_COUNT,
			(int)m_vecCameraIndices.size()
		);
		AfxMessageBox(msg, MB_ICONERROR);
		m_vecCameraIndices.clear();
		return FALSE;
	}

	return TRUE;

	/*m_vecCameraIndices.clear();

	HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
	bool needUninit = SUCCEEDED(hr);

	if (hr == RPC_E_CHANGED_MODE) {
		needUninit = false;
	}
	else if (FAILED(hr)) {
		return FALSE;
	}

	ICreateDevEnum* pDevEnum = nullptr;
	IEnumMoniker* pEnum = nullptr;

	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, nullptr, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, (void**)&pDevEnum);
	if (FAILED(hr)) {
		if (needUninit) CoUninitialize();
		return FALSE;
	}

	hr = pDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEnum, 0);
	if (hr != S_OK) {
		pDevEnum->Release();
		if (needUninit) CoUninitialize();
		return FALSE;
	}

	IMoniker* pMoniker = nullptr;
	int idx = 0;

	while (pEnum->Next(1, &pMoniker, nullptr) == S_OK)
	{
		IPropertyBag* pPropBag = nullptr;
		if (SUCCEEDED(pMoniker->BindToStorage(nullptr, nullptr, IID_IPropertyBag, (void**)&pPropBag)))
		{
			VARIANT varName;
			VariantInit(&varName);

			if (SUCCEEDED(pPropBag->Read(L"FriendlyName", &varName, nullptr)) &&
				varName.bstrVal != nullptr)
			{
				std::wstring devName(varName.bstrVal);
				std::wstring lowerName = devName;
				std::transform(lowerName.begin(), lowerName.end(),
					lowerName.begin(), ::towlower);

				// C920 매칭
				if (lowerName.find(L"hd pro webcam c920") != std::wstring::npos)
				{
					m_vecCameraIndices.push_back(idx);
				}
			}

			VariantClear(&varName);
			pPropBag->Release();
		}

		pMoniker->Release();
		idx++;
	}

	pEnum->Release();
	pDevEnum->Release();
	if (needUninit) CoUninitialize();

	// 정확히 2개가 아니면 실패
	if (m_vecCameraIndices.size() != REQUIRED_CAMERA_COUNT) {
		CString errMsg;
		errMsg.Format(
			_T("Required: %d C920 cameras\nFound: %d cameras\n\nCheck connections!"),
			REQUIRED_CAMERA_COUNT,
			static_cast<int>(m_vecCameraIndices.size())
		);
		AfxMessageBox(errMsg, MB_ICONERROR);
		m_vecCameraIndices.clear();
		return FALSE;
	}

	return TRUE;
	*/
}

BOOL CLNConsole20260106Dlg::InitializeCameras()
{
	if (!ValidateC920Cameras()) {
		return FALSE;
	}

	ReleaseCameras();

	// 카메라 연결x, 캡처 컨테이너만 준비
	m_vecVideoCaptures.clear();
	m_vecVideoCaptures.resize(REQUIRED_CAMERA_COUNT);

	m_bIsCameraConnected = FALSE;
	m_staticCameraState.SetWindowTextW(_T("Connecting..."));

	return TRUE;
}

	//// 1. C920 2개 검증
	//if (!ValidateC920Cameras()) {
	//	return FALSE;
	//}

	//ReleaseCameras();

	//// 2. 카메라 오픈
	//m_vecVideoCaptures.resize(REQUIRED_CAMERA_COUNT);

	//std::vector<std::thread> threads;
	//std::mutex mutex;
	//int connectedCount = 0;

	//for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
	//	int deviceIndex = m_vecCameraIndices[i];

	//	threads.emplace_back([&, i, deviceIndex]() {
	//		HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	//		bool comInitialized = SUCCEEDED(hr);

	//		cv::VideoCapture cap(deviceIndex, cv::CAP_DSHOW);

	//		if (cap.isOpened()) {
	//			cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
	//			cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
	//			cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
	//			cap.set(cv::CAP_PROP_FPS, 15);

	//			// 초기 프레임 버리기
	//			for (int k = 0; k < 5; ++k) {
	//				cap.grab();
	//				cv::Mat temp;
	//				cap.retrieve(temp);
	//				std::this_thread::sleep_for(std::chrono::milliseconds(30));
	//			}

	//			std::lock_guard<std::mutex> lock(mutex);
	//			m_vecVideoCaptures[i] = std::move(cap);
	//			connectedCount++;
	//		}
	//		if (comInitialized) {
	//			CoUninitialize();
	//		}
	//	});
	//}

	//for (auto& t : threads) {
	//	if (t.joinable()) t.join();
	//}

	//// 3. 연결 확인
	//if (connectedCount != REQUIRED_CAMERA_COUNT) {
	//	AfxMessageBox(_T("Failed to open cameras!"), MB_ICONERROR);
	//	ReleaseCameras();
	//	return FALSE;
	//}

	//m_bIsCameraConnected = TRUE;
	//m_staticCameraState.SetWindowText(_T("Connected"));
	//return TRUE;
//}

void CLNConsole20260106Dlg::ReleaseCameras()
{
	// thread가 돌고 있을때 release 금지
	if (m_bIsCameraThreadRunning.load()) {
		return;
	}
	for (int i = 0; i < (int)m_vecVideoCaptures.size(); ++i) {
		if (m_vecVideoCaptures[i].isOpened()) {
			m_vecVideoCaptures[i].release();
		}
	}
	//if (m_bIsCameraThreadRunning) {
	//	return;
	//}
	//for (int i = 0; i < (int)m_vecVideoCaptures.size(); ++i) {
	//	if (m_vecVideoCaptures[i].isOpened()) {
	//		m_vecVideoCaptures[i].release();
	//	}
	//}
	//// 카메라 리소스만 정리
	//for (int i = 0; i < static_cast<int>(m_vecVideoCaptures.size()); ++i) {
	//	if (m_vecVideoCaptures[i].isOpened()) {
	//		m_vecVideoCaptures[i].release();
	//	}
	//}
	//m_vecVideoCaptures.clear();
	//m_bIsCameraConnected = FALSE;
	//m_staticCameraState.SetWindowText(_T("Disconnected"));
}

void CLNConsole20260106Dlg::DisplayFrames(CStatic& pictureCtrl, const cv::Mat& frame)
{
	if (frame.empty() || frame.channels() != 1) return;

	CRect rect;
	pictureCtrl.GetClientRect(&rect);

	if (rect.Width() <= 0 || rect.Height() <= 0) {
		OutputDebugString(_T("[DisplayFrames] Invalid rect size\r\n"));
		return;
	}

	cv::Mat resized;  // ⭐ try 블록 밖으로 이동
	try {
		cv::resize(frame, resized, cv::Size(rect.Width(), rect.Height()));
	}
	catch (const cv::Exception& e) {
		CString msg;
		msg.Format(_T("[DisplayFrames] OpenCV Exception: %S\r\n"), e.what());
		OutputDebugString(msg);
		return;  // ⭐ 예외 발생 시 함수 종료
	}

	// ⭐ resize 실패 체크
	if (resized.empty()) {
		OutputDebugString(_T("[DisplayFrames] Resize failed\r\n"));
		return;
	}

	int stride = ((resized.cols * 8 + 31) / 32) * 4;
	std::vector<BYTE> buffer(stride * resized.rows, 0);

	for (int y = 0; y < resized.rows; ++y) {
		memcpy(&buffer[y * stride], resized.ptr(y), resized.cols);
	}

	const int paletteSize = 256;
	const size_t bmiSize = sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * paletteSize;
	BITMAPINFO* pBmi = (BITMAPINFO*)malloc(bmiSize);
	if (!pBmi) return;

	ZeroMemory(pBmi, bmiSize);
	pBmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pBmi->bmiHeader.biWidth = resized.cols;
	pBmi->bmiHeader.biHeight = -resized.rows;
	pBmi->bmiHeader.biPlanes = 1;
	pBmi->bmiHeader.biBitCount = 8;
	pBmi->bmiHeader.biCompression = BI_RGB;

	for (int i = 0; i < paletteSize; ++i) {
		pBmi->bmiColors[i].rgbBlue = (BYTE)i;
		pBmi->bmiColors[i].rgbGreen = (BYTE)i;
		pBmi->bmiColors[i].rgbRed = (BYTE)i;
	}

	CDC* pDC = pictureCtrl.GetDC();
	if (pDC) {
		StretchDIBits(pDC->m_hDC,
			0, 0, rect.Width(), rect.Height(),
			0, 0, resized.cols, resized.rows,
			buffer.data(), pBmi, DIB_RGB_COLORS, SRCCOPY);
		pictureCtrl.ReleaseDC(pDC);
	}

	free(pBmi);
}

bool CLNConsole20260106Dlg::AcquireSynchronizedSnapshot(SynchronizedSnapshot& outSnapshot, int maxWaitMs)
{
	using namespace std::chrono;

	const auto deadline = steady_clock::now() + milliseconds(maxWaitMs);

	uint64_t startCamSeq = 0;
	uint64_t startDaqSeq = 0;

	{
		std::lock_guard<std::mutex> lock(m_mutexLatestData);
		startCamSeq = m_latestData.cameraSeq;
		startDaqSeq = m_latestData.daqSeq;
	}

	cv::Mat tempFrames[REQUIRED_CAMERA_COUNT];
	double tempSensor[6] = { 0.0 };
	steady_clock::time_point tempCamTs;
	steady_clock::time_point tempDaqTs;

	std::unique_lock<std::mutex> lock(m_mutexLatestData);

	while (true) {
		const bool camUpdated = (m_latestData.cameraSeq != startCamSeq);
		const bool daqUpdated = (m_latestData.daqSeq != startDaqSeq);

		const bool framesReady =
			(!m_latestData.frames[0].empty()) && (!m_latestData.frames[1].empty());

		if (camUpdated && daqUpdated && framesReady) {
			for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
				tempFrames[i] = m_latestData.frames[i].clone();
			}
			for (int i = 0; i < 6; i++) {
				tempSensor[i] = m_latestData.sensorValues[i];
			}
			tempCamTs = m_latestData.cameraTimestamp;
			tempDaqTs = m_latestData.daqTimestamp;
			break;
		}

		if (m_cvLatestData.wait_until(lock, deadline) == std::cv_status::timeout) {
			return false;
		}
	}

	lock.unlock();

	for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
		outSnapshot.frames[i] = tempFrames[i];
	}
	for (int i = 0; i < 6; ++i) {
		outSnapshot.sensorValues[i] = tempSensor[i];
	}

	outSnapshot.cameraTimestamp = tempCamTs;
	outSnapshot.daqTimestamp = tempDaqTs;
	outSnapshot.saveTimestamp = steady_clock::now();

	return true;

}

bool CLNConsole20260106Dlg::SaveSynchronizedSample(int position)
{
	const int MAX_WAIT_MS = 150;

	SynchronizedSnapshot snapshot;
	if (!AcquireSynchronizedSnapshot(snapshot, MAX_WAIT_MS)) {
		OutputDebugString(_T("[SaveSync] Failed to acquire synchronized snapshot\r\n"));
		return false;
	}

	for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
		if (snapshot.frames[i].empty()) {
			OutputDebugString(_T("[SaveSync] Empty frmae\r\n"));
			return false;
		}
	}

	// 1. save image
	try {
		CString filename0, filename1;
		filename0.Format(_T("%s\\Camera0\\pos_%05d.png"), m_cstrAutoSavePath, position);
		filename1.Format(_T("%s\\Camera1\\pos_%05d.png"), m_cstrAutoSavePath, position);

		std::string path0 = CW2A(filename0, CP_UTF8);
		std::string path1 = CW2A(filename1, CP_UTF8);

		bool success0 = cv::imwrite(path0, snapshot.frames[0]);
		bool success1 = cv::imwrite(path1, snapshot.frames[1]);

		if (!success0 || !success1) {
			OutputDebugString(_T("[SaveSync] Failed to write images\r\n"));
			return false;
		}
	}

	catch (...) {
		OutputDebugString(_T("[SaveSync] Exception during image write\r\n"));
		return false;
	}

	// 2. write csv
	try {
		if (!m_autoCSVFile.is_open()) {
			AfxOutputDebugString(_T("[SaveSync] CSV file not open\r\n"));
			return false;
		}

		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(snapshot.saveTimestamp - m_autoStartTime).count();

		auto dtCamMs = std::chrono::duration_cast<std::chrono::milliseconds>(snapshot.saveTimestamp - snapshot.cameraTimestamp).count();

		auto dtDaqMs = std::chrono::duration_cast<std::chrono::milliseconds>(snapshot.saveTimestamp - snapshot.daqTimestamp).count();

		m_autoCSVFile << elapsed << L","
			<< position << L","
			<< dtCamMs << L","
			<< dtDaqMs << L","
			<< std::fixed << std::setprecision(6)
			<< snapshot.sensorValues[0] << L","
			<< snapshot.sensorValues[1] << L","
			<< snapshot.sensorValues[2] << L","
			<< snapshot.sensorValues[3] << L","
			<< snapshot.sensorValues[4] << L","
			<< snapshot.sensorValues[5] << L"\n";

		m_autoCSVFile.flush();
	}
	catch (...) {
		OutputDebugString(_T("[SaveSync] Exception during CSV write\r\n"));
		return false;
	}
	return true;
}



void CLNConsole20260106Dlg::CameraThreadFunc()
{
	bool needUninit = false;

	try {
		HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
		needUninit = SUCCEEDED(hr);

		if (hr == RPC_E_CHANGED_MODE) {
			needUninit = false;
		}
		else if (FAILED(hr)) {
			{
				std::lock_guard<std::mutex> lock(m_mutexCameraInit);
				m_strCameraInitError = _T("CoInitializeEx failed.");
			}
			if (::IsWindow(m_hWnd)) {
				::PostMessage(m_hWnd, WM_CAMERA_INIT_COMPLETE, FALSE, 0);

			}
			//m_bIsCameraThreadRunning = false;
			m_bIsCameraThreadRunning.store(false);
			return;
		}


		using namespace std::chrono;
		OutputDebugString(_T("[CameraThread] Started\r\n"));

		// 이 스레드에서 카메라 open 수행
		for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
			int deviceIndex = m_vecCameraIndices[i];

			cv::VideoCapture cap(deviceIndex, cv::CAP_DSHOW);
			if (!cap.isOpened()) {
				{
					std::lock_guard<std::mutex> lock(m_mutexCameraInit);
					CString msg;
					msg.Format(_T("Failed to open camera index %d"), deviceIndex);
					m_strCameraInitError = msg;
				}

				// cleanup alreday-opened captures
				for (int k = 0; k < REQUIRED_CAMERA_COUNT; ++k) {
					if (m_vecVideoCaptures[k].isOpened()) {
						m_vecVideoCaptures[k].release();
					}
				}

				if (::IsWindow(m_hWnd)) {
					::PostMessage(m_hWnd, WM_CAMERA_INIT_COMPLETE, FALSE, 0);
				}
				//m_bIsCameraThreadRunning = false;
				m_bIsCameraThreadRunning.store(false);
				if (needUninit) CoUninitialize();
				return;
			}

			cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
			cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
			cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
			cap.set(cv::CAP_PROP_FPS, 15);

			// warm up
			for (int k = 0; k < 5; ++k) {
				cap.grab();
				cv::Mat temp;
				cap.retrieve(temp);
				std::this_thread::sleep_for(std::chrono::milliseconds(30));
			}

			m_vecVideoCaptures[i] = std::move(cap);
		}

		if (::IsWindow(m_hWnd)) {
			::PostMessage(m_hWnd, WM_CAMERA_INIT_COMPLETE, TRUE, 0);
		}

		const auto targetInterval = milliseconds(66);	// 15 fps
		auto nextWakeup = steady_clock::now();

		while (m_bIsCameraThreadRunning.load()) {
			// 1. grab
			for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
				if (m_vecVideoCaptures[i].isOpened()) {
					m_vecVideoCaptures[i].grab();
				}
			}

			// 2. retrieve + gray
			cv::Mat frames[REQUIRED_CAMERA_COUNT];
			for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
				if (!m_vecVideoCaptures[i].isOpened()) continue;

				cv::Mat frame;
				m_vecVideoCaptures[i].retrieve(frame);
				if (!frame.empty()) {
					cv::Mat gray;
					cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
					frames[i] = gray;
				}
			}

			// 3. publish
			{
				std::lock_guard<std::mutex> lock(m_mutexLatestData);
				for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
					if (!frames[i].empty()) {
						m_latestData.frames[i] = frames[i].clone();
					}
				}
				m_latestData.cameraTimestamp = steady_clock::now();
				++m_latestData.cameraSeq;
			}
			m_cvLatestData.notify_all();

			// 4. pacing
			nextWakeup += targetInterval;
			auto now = steady_clock::now();

			if (nextWakeup > now) {
				std::this_thread::sleep_until(nextWakeup);
			}
			else {
				nextWakeup = now;
			}
		}

		OutputDebugString(_T("[CameraThread] Exited\r\n"));

		// 종료시 캡쳐 해제는 이 스레드에서 수행
		for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
			if (m_vecVideoCaptures[i].isOpened()) {
				m_vecVideoCaptures[i].release();
			}
		}

		if (::IsWindow(m_hWnd)) {
			::PostMessage(m_hWnd, WM_CAMERA_INIT_COMPLETE, FALSE, 0);
		}

		if (needUninit) {
			CoUninitialize();
		}

		m_bIsCameraThreadRunning.store(false);
	}
	catch (...) {
		{
			std::lock_guard<std::mutex> lock(m_mutexCameraInit);
			m_strCameraInitError = _T("CameraThreadFunc exception.");

		}

		for (int k = 0; k < REQUIRED_CAMERA_COUNT; ++k) {
			if (m_vecVideoCaptures[k].isOpened()) {
				m_vecVideoCaptures[k].release();
			}
		}
		if (::IsWindow(m_hWnd)) {
			::PostMessage(m_hWnd, WM_CAMERA_INIT_COMPLETE, FALSE, 0);
		}

		if (needUninit) {
			CoUninitialize();
		}

		//m_bIsCameraThreadRunning = false;
		m_bIsCameraThreadRunning.store(false);
	}

}

void CLNConsole20260106Dlg::DAQThreadFunc()
{
	bool needUninit = false;

	try {
		HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
		needUninit = SUCCEEDED(hr);

		if (hr == RPC_E_CHANGED_MODE) {
			needUninit = false;
		}
		else if (FAILED(hr)) {
			OutputDebugString(_T("[DAQThread] CoInitializeEx failed\r\n"));
			m_bIsDAQThreadRunning.store(false);
			return;
		}

		using namespace std::chrono;
		const auto targetInterval = milliseconds(33); // 30Hz
		auto nextWakeup = steady_clock::now();

		OutputDebugStringW(_T("[DAQThread] Started\r\n"));

		while (m_bIsDAQThreadRunning.load()) {
			if (!m_bIsDAQConnected || !m_TaskHandle) {
				std::this_thread::sleep_for(milliseconds(100));
				continue;
			}

			int32 samplesRead = 0;
			double buffer[6];

			// timeout을 짧게 유지해서 stop 시 join이 빨리 되게 함
			int32 error = DAQmxReadAnalogF64(

				m_TaskHandle,
				1,
				0.01,
				DAQmx_Val_GroupByChannel,
				buffer,
				6,
				&samplesRead,
				NULL
			);

			if (!m_bIsDAQThreadRunning.load()) {
				break;
			}
			if (error == 0 && samplesRead > 0) {
				double processedValues[6];
				for (int i = 0; i < 6; i++) {
					if (m_bIsDAQBiased) {
						processedValues[i] = buffer[i] - m_arrDAQBiasValues[i];
					}
					else {
						processedValues[i] = buffer[i];
					}
				}
				{
					std::lock_guard<std::mutex> lock(m_mutexLatestData);
					for (int i = 0; i < 6; ++i) {
						m_latestData.sensorValues[i] = processedValues[i];
					}
					m_latestData.daqTimestamp = steady_clock::now();
					++m_latestData.daqSeq;
				}
				m_cvLatestData.notify_all();
			}
			else if (error != 0) {
				std::this_thread::sleep_for(milliseconds(10));
			}
			nextWakeup += targetInterval;
			auto now = steady_clock::now();

			if (nextWakeup > now) {
				std::this_thread::sleep_until(nextWakeup);
			}
			else {
				nextWakeup = now;
			}
		}
		OutputDebugString(_T("[DAQThread] Exited\r\n"));

		if (needUninit) {
			CoUninitialize();
		}
		m_bIsDAQThreadRunning.store(false);
	}
	catch (...) {
		OutputDebugString(_T("[DAQThread] Exceptionr\r\n"));
		if (needUninit) {
			CoUninitialize();
		}
		m_bIsDAQThreadRunning.store(false);
	}
}
//	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
//	bool comInitialized = SUCCEEDED(hr);
//
//
//	using namespace std::chrono;
//
//	const auto targetInterval = milliseconds(33);  // 30Hz
//	auto nextWakeup = steady_clock::now();
//
//	OutputDebugString(_T("[DAQThread] Started\r\n"));
//
//	while (m_bIsDAQThreadRunning) {
//		if (!m_bIsDAQConnected || !m_TaskHandle) {
//			std::this_thread::sleep_for(milliseconds(100));
//			continue;
//		}
//
//		// 1. DAQ에서 센서값 읽기
//		int32 samplesRead = 0;
//		double buffer[6] = { 0 };
//
//		/*int32 error = DAQmxReadAnalogF64(
//			m_TaskHandle,
//			DAQmx_Val_Auto,
//			1.0,
//			DAQmx_Val_GroupByChannel,
//			buffer,
//			6,
//			&samplesRead,
//			NULL
//		);*/
//
//		int32 error = DAQmxReadAnalogF64(
//			m_TaskHandle,
//			1,
//			0.01,
//			DAQmx_Val_GroupByChannel,
//			buffer,
//			6,
//			&samplesRead,
//			NULL
//		);
//
//		if (error == 0 && samplesRead > 0) {
//			// 2. Bias 적용
//			double processedValues[6];
//			for (int i = 0; i < 6; ++i) {
//				if (m_bIsDAQBiased) {
//					processedValues[i] = buffer[i] - m_arrDAQBiasValues[i];
//				}
//				else {
//					processedValues[i] = buffer[i];
//				}
//			}
//
//			// 3. 최신 데이터 업데이트
//			{
//				std::lock_guard<std::mutex> lock(m_mutexLatestData);
//				for (int i = 0; i < 6; ++i) {
//					m_latestData.sensorValues[i] = processedValues[i];
//				}
//				m_latestData.timestamp = steady_clock::now();
//			}
//		}
//
//		// 4. 정밀한 주기 제어
//		nextWakeup += targetInterval;
//		auto now = steady_clock::now();
//
//		if (nextWakeup > now) {
//			std::this_thread::sleep_until(nextWakeup);
//		}
//		else {
//			nextWakeup = now;
//		}
//	}
//
//	OutputDebugString(_T("[DAQThread] Exited\r\n"));
//
//	if (comInitialized) {
//		CoUninitialize();
//	}
//}

void CLNConsole20260106Dlg::UpdateUIFromThreads()
{
	if (m_bIsUIShuttingDown.load()) return;
	if (!IsWindow(m_hWnd)) return;
	if (!IsWindow(m_pictureCam0.GetSafeHwnd())) return;
	if (!IsWindow(m_pictureCam1.GetSafeHwnd())) return;

	cv::Mat frame0;
	cv::Mat frame1;
	double sensorValues[6] = { 0.0 };
	bool daqConnected = false;
	SensorDisplayMode displayModeLocal;
	bool calibrated = false;

	{
		std::lock_guard<std::mutex> lock(m_mutexLatestData);

		if (!m_latestData.frames[0].empty()) frame0 = m_latestData.frames[0].clone();
		if (!m_latestData.frames[1].empty()) frame1 = m_latestData.frames[1].clone();

		for (int i = 0; i < 6; i++) sensorValues[i] = m_latestData.sensorValues[i];

		daqConnected = (m_bIsDAQConnected != FALSE);
		displayModeLocal = m_displayMode;
		calibrated = m_bIsDAQCalibrated;
	}

	if (!frame0.empty()) DisplayFrames(m_pictureCam0, frame0);
	if (!frame1.empty()) DisplayFrames(m_pictureCam1, frame1);

	if (daqConnected) {
		double displayValues[6];
		if (displayModeLocal == SensorDisplayMode::Voltage) {
			for (int i = 0; i < 6; ++i) displayValues[i] = sensorValues[i];
			UpdateDAQDisplay(displayValues);
		}
		else if (displayModeLocal == SensorDisplayMode::ForceTorque && calibrated) {
			std::array<float, MAX_GAGES> voltages = { 0.0f };
			int numChannels = m_CalibrationManager.getNumChannels();
			if (numChannels <= 0 || numChannels > MAX_GAGES) numChannels = 6;

			for (int i = 0; i < numChannels; ++i) {
				voltages[i] = static_cast<float>(sensorValues[i]);
			}
			std::array<float, MAX_AXES> ft = { 0.0f };
			m_CalibrationManager.convertToFT(voltages, ft);

			for (int i = 0; i < 6; ++i) displayValues[i] = static_cast<double>(ft[i]);
			UpdateDAQDisplay(displayValues);

		}
	}
}
//
//	LatestData localCopy;
//
//	// 최신 데이터 복사 (한 번에)  // 변경
//	{
//		std::lock_guard<std::mutex> lock(m_mutexLatestData);
//		localCopy = m_latestData;
//	}
//
//	// 프레임 표시
//	if (!localCopy.frames[0].empty()) {
//		DisplayFrames(m_pictureCam0, localCopy.frames[0]);
//	}
//	if (!localCopy.frames[1].empty()) {
//		DisplayFrames(m_pictureCam1, localCopy.frames[1]);
//	}
//
//	// TODO: 센서값 UI 표시 (나중에 추가)
//	// / 센서값 표시
//	if (m_bIsDAQConnected) {
//		double displayValues[6];
//
//		// Voltage 모드
//		if (m_displayMode == SensorDisplayMode::Voltage) {
//			for (int i = 0; i < 6; ++i) {
//				displayValues[i] = localCopy.sensorValues[i];
//			}
//			UpdateDAQDisplay(displayValues);
//		}
//		// F-T 모드
//		else if (m_displayMode == SensorDisplayMode::ForceTorque && m_bIsDAQCalibrated) {
//			// 전압 → F/T 변환
//			std::array<float, MAX_GAGES> voltages = { 0.0f };
//			int numChannels = m_CalibrationManager.getNumChannels();
//			if (numChannels <= 0 || numChannels > MAX_GAGES) numChannels = 6;
//
//			for (int i = 0; i < numChannels; ++i) {
//				voltages[i] = static_cast<float>(localCopy.sensorValues[i]);
//			}
//
//			std::array<float, MAX_AXES> ft = { 0.0f };
//			m_CalibrationManager.convertToFT(voltages, ft);
//
//			for (int i = 0; i < 6; ++i) {
//				displayValues[i] = static_cast<double>(ft[i]);
//			}
//			UpdateDAQDisplay(displayValues);
//		}
//	}
//	// CString str;
//	// str.Format(_T("%.3f"), localCopy.sensorValues[0]);
//	// m_staticFx.SetWindowText(str);
//}

void CLNConsole20260106Dlg::StartThreads()
{
	StartCameraThread();
	StartDAQThread();
}

void CLNConsole20260106Dlg::StopThreads()
{
	StopCameraThread();
	StopDAQThread();
}

void CLNConsole20260106Dlg::StartCameraThread()
{
	bool expected = false;
	if (m_bIsCameraThreadRunning.compare_exchange_strong(expected, true)) {
		m_threadCamera = std::thread(&CLNConsole20260106Dlg::CameraThreadFunc, this);
		OutputDebugString(_T("[Thread] Camera thread started\r\n"));
	}
	/*if (!m_bIsCameraThreadRunning) {
		m_bIsCameraThreadRunning = true;
		m_threadCamera = std::thread(&CLNConsole20260106Dlg::CameraThreadFunc, this);
		OutputDebugString(_T("[Thread] Camera thread started\r\n"));
	}*/
	//if (m_bIsCameraConnected && !m_bIsCameraThreadRunning) {
	//	m_bIsCameraThreadRunning = true;
	//	m_threadCamera = std::thread(&CLNConsole20260106Dlg::CameraThreadFunc, this);
	//	OutputDebugString(_T("[Thread] Camera thread started\r\n"));

	//	// UI 타이머 시작 (아직 안 켜져있으면)
	//	// UI 타이머는 OnCameraInitComplete에서 on
	//	// SetTimer(IDT_UI_UPDATE_TIMER, 33, nullptr);
	//}
}

void CLNConsole20260106Dlg::StopCameraThread()
{
	if (m_bIsCameraThreadRunning.load()) {
		m_bIsCameraThreadRunning.store(false);

		if (m_threadCamera.joinable()) {
			m_threadCamera.join();
		}
		OutputDebugString(_T("[Thread] Camera thread joined\r\n"));
	}
	m_bIsCameraConnected = FALSE;
	m_staticCameraState.SetWindowTextW(_T("Disconnected"));

	if (!m_bIsDAQThreadRunning.load()) {
		KillTimer(IDT_UI_UPDATE_TIMER);
	}
	/*if (m_bIsCameraThreadRunning) {
		m_bIsCameraThreadRunning = false;

		if (m_threadCamera.joinable()) {
			m_threadCamera.join();
		}
		OutputDebugString(_T("[Thread] Camera thread joined\r\n"));
	}
	m_bIsCameraConnected = FALSE;
	m_staticCameraState.SetWindowTextW(_T("Disconnected"));*/
		//[// DAQ도 안 돌고 있으면 타이머 종료
		//if (!m_bIsDAQThreadRunning) {
		//	KillTimer(IDT_UI_UPDATE_TIMER);
		//}
}

void CLNConsole20260106Dlg::StartDAQThread()
{
	if (!m_bIsDAQConnected || !m_TaskHandle) {
		return;
	}

	bool expected = false;
	if (m_bIsDAQThreadRunning.compare_exchange_strong(expected, true)) {
		m_threadDAQ = std::thread(&CLNConsole20260106Dlg::DAQThreadFunc, this);
		OutputDebugString(_T("[Thread] DAQ thread started\r\n"));

		// UI 타이머 시작 (UI 동일이면 reset)
		SetTimer(IDT_UI_UPDATE_TIMER, 33, nullptr);
	}



	//if (m_bIsDAQConnected && !m_bIsDAQThreadRunning) {
	//	m_bIsDAQThreadRunning = true;
	//	m_threadDAQ = std::thread(&CLNConsole20260106Dlg::DAQThreadFunc, this);
	//	OutputDebugString(_T("[Thread] DAQ thread started\r\n"));

	//	// UI 타이머 시작 (아직 안 켜져있으면)
	//	SetTimer(IDT_UI_UPDATE_TIMER, 33, nullptr);
	//}
}

void CLNConsole20260106Dlg::StopDAQThread()
{
	if (m_bIsDAQThreadRunning.load()) {
		m_bIsDAQThreadRunning.store(false);

		if (m_threadDAQ.joinable()) {
			m_threadDAQ.join();
		}

		OutputDebugString(_T("[Thread] DAQ thread stopped\r\n"));

		// 카메라도 안 돌고 있으면 타이머 종료
		if (!m_bIsCameraThreadRunning.load()) {
			KillTimer(IDT_UI_UPDATE_TIMER);
		}
	}
	//if (m_bIsDAQThreadRunning) {
	//	m_bIsDAQThreadRunning = false;

	//	if (m_TaskHandle) {
	//		DAQmxStopTask(m_TaskHandle);
	//	}

	//	if (m_threadDAQ.joinable()) {
	//		m_threadDAQ.join();
	//	}
	//	OutputDebugString(_T("[Thread] DAQ thread stopped\r\n"));

	//	// 카메라도 안 돌고 있으면 타이머 종료
	//	if (!m_bIsCameraThreadRunning) {
	//		KillTimer(IDT_UI_UPDATE_TIMER);
	//	}
	//}
}




void CLNConsole20260106Dlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == IDT_UI_UPDATE_TIMER) {
		UpdateUIFromThreads();
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CLNConsole20260106Dlg::OnClose()
{
	KillTimer(IDT_UI_UPDATE_TIMER);


	// ========== 1. 종료 확인 ==========
	int result = AfxMessageBox(
		_T("Are you sure you want to exit?\n\n")
		_T("All devices will be disconnected."),
		MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2
	);

	if (result != IDYES) {
		return;
	}

	m_bIsUIShuttingDown.store(true);

	OutputDebugString(_T("[Close] ========== Starting Shutdown ==========\r\n"));

	// ========== 2. Auto 실험 중단 ==========
	if (m_bIsAutoRunning) {
		OutputDebugString(_T("[Close] Stopping Auto...\r\n"));
		m_bIsAutoAbortRequested = true;
		CloseCSVFile();

		if (m_threadAuto.joinable()) {
			auto start = std::chrono::steady_clock::now();
			while (m_bIsAutoRunning) {
				auto elapsed = std::chrono::steady_clock::now() - start;
				if (elapsed > std::chrono::seconds(5)) {
					OutputDebugString(_T("[Close] Auto thread timeout\r\n"));
					break;
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}

			if (m_threadAuto.joinable()) {
				m_threadAuto.join();
			}
		}
		OutputDebugString(_T("[Close] Auto stopped\r\n"));
	}

	// ========== 3. 카메라/DAQ 스레드 정리 ==========
	OutputDebugString(_T("[Close] Stopping threads...\r\n"));

	// 카메라 스레드
	if (m_bIsCameraThreadRunning.load()) {
		m_bIsCameraThreadRunning.store(false);
		if (m_threadCamera.joinable()) {
			m_threadCamera.join();
		}
	}

	// DAQ 스레드
	if (m_bIsDAQThreadRunning.load()) {
		m_bIsDAQThreadRunning.store(false);
		if (m_threadDAQ.joinable()) {
			m_threadDAQ.join();
		}
	}

	// UI 타이머
	KillTimer(IDT_UI_UPDATE_TIMER);

	OutputDebugString(_T("[Close] Threads stopped\r\n"));

	// ========== 4. 카메라 정리 ==========
	try {
		if (m_bIsCameraConnected) {
			OutputDebugString(_T("[Close] Releasing cameras...\r\n"));

			for (int i = 0; i < static_cast<int>(m_vecVideoCaptures.size()); ++i) {
				if (m_vecVideoCaptures[i].isOpened()) {
					m_vecVideoCaptures[i].release();
				}
			}
			m_vecVideoCaptures.clear();
			m_bIsCameraConnected = FALSE;

			OutputDebugString(_T("[Close] ✓ Cameras released\r\n"));
		}
	}
	catch (...) {
		OutputDebugString(_T("[Close] ✗ Error releasing cameras\r\n"));
	}

	// ========== 5. DAQ 정리 ==========
	try {
		if (m_bIsDAQConnected && m_TaskHandle) {
			OutputDebugString(_T("[Close] Stopping DAQ...\r\n"));

			DAQmxStopTask(m_TaskHandle);
			DAQmxClearTask(m_TaskHandle);
			m_TaskHandle = nullptr;
			m_bIsDAQConnected = FALSE;

			OutputDebugString(_T("[Close] ✓ DAQ stopped\r\n"));
		}
	}
	catch (...) {
		OutputDebugString(_T("[Close] ✗ Error stopping DAQ\r\n"));

		if (m_TaskHandle) {
			try {
				DAQmxClearTask(m_TaskHandle);
				m_TaskHandle = nullptr;
			}
			catch (...) {
			}
		}
	}

	// ========== 6. Linear Stage 정리 ==========
	try {
		if (m_bIsLinearConnected && m_SerialPort.IsOpen()) {
			OutputDebugString(_T("[Close] Disconnecting Linear Stage...\r\n"));
			m_SerialPort.Disconnect();
			m_bIsLinearConnected = FALSE;
			OutputDebugString(_T("[Close] ✓ Linear Stage disconnected\r\n"));
		}
	}
	catch (...) {
		OutputDebugString(_T("[Close] ✗ Error disconnecting Linear Stage\r\n"));
	}

	OutputDebugString(_T("[Close] ========== Shutdown Complete ==========\r\n"));

	// ========== 7. 대화상자 종료 ==========
	CDialogEx::OnClose();
}

void CLNConsole20260106Dlg::OnCbnDropdownDaqList()
{
	// clear combo box
	m_comboDAQList.ResetContent();

	char deviceNames[2048] = { 0 };

	// enumerate DAQ devices
	if (DAQmxGetSysDevNames(deviceNames, sizeof(deviceNames)) >= 0) {
		CString allNames(deviceNames);

		int start = 0;
		while (true) {
			int pos = allNames.Find(',', start);
			CString token;

			if (pos == -1) {
				// last token
				token = allNames.Mid(start).Trim();
				if (!token.IsEmpty()) {
					m_comboDAQList.AddString(token);
				}
				break;
			}
			else {
				// intermediate tokens
				token = allNames.Mid(start, pos - start).Trim();
				if (!token.IsEmpty()) {
					m_comboDAQList.AddString(token);
				}
				start = pos + 1;
			}
		}
	}

	// select first if available
	if (m_comboDAQList.GetCount() > 0) {
		m_comboDAQList.SetCurSel(0);
	}

	OutputDebugString(_T("[Sensor] Device list updated.\r\n"));
}

void CLNConsole20260106Dlg::OnBnClickedDaqConnect()
{
	int state = m_checkDAQConnect.GetCheck();

	if (state == BST_CHECKED) {
		int sel = m_comboDAQList.GetCurSel();
		if (sel == CB_ERR) {
			AfxMessageBox(_T("Please select a device."));
			m_checkDAQConnect.SetCheck(BST_UNCHECKED);
			return;
		}

		CString deviceName;
		m_comboDAQList.GetLBText(sel, deviceName);

		int32 error = 0;
		bool success = true;

		error = DAQmxCreateTask("", &m_TaskHandle);
		if (error < 0) success = false;

		if (success) {
			CString channel;
			channel.Format(_T("%s/ai0:5"), (LPCTSTR)deviceName);

			error = DAQmxCreateAIVoltageChan(
				m_TaskHandle, CT2A(channel), "",
				DAQmx_Val_Diff, -10.0, 10.0, DAQmx_Val_Volts, nullptr
			);
			if (error < 0) success = false;
		}

		if (success) {
			error = DAQmxStartTask(m_TaskHandle);
			if (error < 0) success = false;
		}

		if (success) {
			m_bIsDAQConnected = TRUE;
			m_bIsDAQBiased = FALSE;

			// 전압 모드로 초기화
			m_displayMode = SensorDisplayMode::Voltage;
			m_radioDAQVoltage.SetCheck(BST_CHECKED);
			m_radioDAQUnit.SetCheck(BST_UNCHECKED);


			StartDAQThread();
			UpdateAllControls();
			AfxMessageBox(_T("DAQ connected!"));
		}
		else {
			if (m_TaskHandle) {
				DAQmxClearTask(m_TaskHandle);
				m_TaskHandle = nullptr;
			}
			m_bIsDAQConnected = FALSE;
			m_checkDAQConnect.SetCheck(BST_UNCHECKED);
			AfxMessageBox(_T("DAQ connect failed."));
		}
	}
	else {
		if (m_bIsDAQConnected) {
			StopDAQThread();

			DAQmxStopTask(m_TaskHandle);
			DAQmxClearTask(m_TaskHandle);
			m_TaskHandle = nullptr;

			m_bIsDAQConnected = FALSE;
			m_bIsDAQBiased = FALSE;

			// 버튼 비활성화

			// 센서값 0으로 초기화
			double zeros[6] = { 0.0 };
			UpdateDAQDisplay(zeros);

			UpdateAllControls();

			AfxMessageBox(_T("DAQ disconnected."));
		}
	}
}

void CLNConsole20260106Dlg::UpdateDAQDisplay(const double values[6])
{
	CString str;

	// 단위 문자열 배열
	const TCHAR* units[6];

	if (m_displayMode == SensorDisplayMode::Voltage) {
		// Voltage 모드: 모두 V
		for (int i = 0; i < 6; ++i) {
			units[i] = _T("V");
		}
	}
	else {
		// F/T 모드: Force는 N, Torque는 N-mm
		units[0] = units[1] = units[2] = _T("N");        // Fx, Fy, Fz
		units[3] = units[4] = units[5] = _T("N-mm");     // Tx, Ty, Tz
	}

	// Fx
	m_dDAQFx = values[0];
	str.Format(_T("%.4f %s"), m_dDAQFx, units[0]);
	m_staticDAQFx.SetWindowText(str);

	// Fy
	m_dDAQFy = values[1];
	str.Format(_T("%.4f %s"), m_dDAQFy, units[1]);
	m_staticDAQFy.SetWindowText(str);

	// Fz
	m_dDAQFz = values[2];
	str.Format(_T("%.4f %s"), m_dDAQFz, units[2]);
	m_staticDAQFz.SetWindowText(str);

	// Tx
	m_dDAQTx = values[3];
	str.Format(_T("%.4f %s"), m_dDAQTx, units[3]);
	m_staticDAQTx.SetWindowText(str);

	// Ty
	m_dDAQTy = values[4];
	str.Format(_T("%.4f %s"), m_dDAQTy, units[4]);
	m_staticDAQTy.SetWindowText(str);

	// Tz
	m_dDAQTz = values[5];
	str.Format(_T("%.4f %s"), m_dDAQTz, units[5]);
	m_staticDAQTz.SetWindowText(str);
}



void CLNConsole20260106Dlg::OnBnClickedDaqCalibpath()
{
	CFileDialog fileDlg(
		TRUE,
		_T("cal"),
		nullptr,
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
		_T("Calibration Files (*.cal)|*.cal|All Files (*.*)|*.*||"),
		this
	);

	if (fileDlg.DoModal() != IDOK) {
		return;
	}

	// update edit box
	CString path = fileDlg.GetPathName();
	m_editDAQCalibPath.SetWindowText(path);

	// load calibration file
	CT2CA converted(path);
	if (m_CalibrationManager.loadCalibration(std::string(converted))) {
		AfxMessageBox(_T("Calibration file loaded successfully."));
		m_bIsDAQCalibrated  = true;
		UpdateAllControls();


		// debug log
		CString debug;
		debug.Format(_T("[CAL] Loaded : axes = %d, channels = %d, bias = %d\r\n"),
			m_CalibrationManager.getNumAxes(),
			m_CalibrationManager.getNumChannels(),
			m_CalibrationManager.isBiasApplied() ? 1 : 0
		);
		OutputDebugString(debug);

		// print working matrix (only first 6 columns for readability)
		for (int i = 0; i < m_CalibrationManager.getNumAxes(); ++i) {
			debug.Format(_T("[CAL] Row %d : %.6f %.6f %.6f %.6f %.6f %.6f \r\n"),
				i,
				m_CalibrationManager.getMatrix(i, 0),
				m_CalibrationManager.getMatrix(i, 1),
				m_CalibrationManager.getMatrix(i, 2),
				m_CalibrationManager.getMatrix(i, 3),
				m_CalibrationManager.getMatrix(i, 4),
				m_CalibrationManager.getMatrix(i, 5)
			);
			OutputDebugString(debug);
		}
	}
	else {
		AfxMessageBox(_T("Failed to parse calibration file."));
		m_bIsDAQCalibrated = false;
		UpdateAllControls();
		//m_radioDAQUnit.EnableWindow(FALSE);
	}
}

void CLNConsole20260106Dlg::OnBnClickedDaqBias()
{
	if (!m_bIsDAQConnected) {
		AfxMessageBox(_T("DAQ not connected!"));
		return;
	}

	// ⭐ 이미 Bias가 적용된 상태면 경고
	if (m_bIsDAQBiased) {
		int result = AfxMessageBox(
			_T("Bias is already applied.\n\n")
			_T("Do you want to re-apply bias with current values?"),
			MB_YESNO | MB_ICONQUESTION
		);

		if (result != IDYES) {
			return;
		}
	}

	// 현재 센서값을 Bias로 저장
	{
		std::lock_guard<std::mutex> lock(m_mutexLatestData);
		for (int i = 0; i < 6; ++i) {
			m_arrDAQBiasValues[i] = m_latestData.sensorValues[i];
		}
	}

	m_bIsDAQBiased = TRUE;

	// ⭐ 버튼 상태 업데이트
	//m_btnDAQApplyBias.EnableWindow(FALSE);   // Apply 비활성화
	//m_btnDAQClearBias.EnableWindow(TRUE);    // Clear 활성화

	// 확인 메시지
	CString msg;
	msg.Format(_T("Bias applied!\n\n")
		_T("Bias values:\n")
		_T("Ch0: %.6f\n")
		_T("Ch1: %.6f\n")
		_T("Ch2: %.6f\n")
		_T("Ch3: %.6f\n")
		_T("Ch4: %.6f\n")
		_T("Ch5: %.6f"),
		m_arrDAQBiasValues[0], m_arrDAQBiasValues[1], m_arrDAQBiasValues[2],
		m_arrDAQBiasValues[3], m_arrDAQBiasValues[4], m_arrDAQBiasValues[5]);
	AfxMessageBox(msg, MB_ICONINFORMATION);

	OutputDebugString(_T("[Bias] Applied\r\n"));
}

void CLNConsole20260106Dlg::OnBnClickedDaqUnbias()
{
	if (!m_bIsDAQConnected) {
		AfxMessageBox(_T("DAQ not connected!"));
		return;
	}

	// ⭐ Bias가 적용되지 않은 상태면 무시
	if (!m_bIsDAQBiased) {
		AfxMessageBox(_T("Bias is not applied."), MB_ICONINFORMATION);
		return;
	}

	// Bias 값 초기화
	for (int i = 0; i < 6; ++i) {
		m_arrDAQBiasValues[i] = 0.0;
	}

	m_bIsDAQBiased = FALSE;

	// ⭐ 버튼 상태 업데이트
	//m_btnDAQApplyBias.EnableWindow(TRUE);    // Apply 활성화
	//m_btnDAQClearBias.EnableWindow(FALSE);   // Clear 비활성화

	AfxMessageBox(_T("Bias cleared!"), MB_ICONINFORMATION);
	OutputDebugString(_T("[Bias] Cleared\r\n"));
}

void CLNConsole20260106Dlg::OnBnClickedDaqVoltage()
{
	if (m_radioDAQVoltage.GetCheck() == BST_CHECKED) {
		m_displayMode = SensorDisplayMode::Voltage;
		OutputDebugString(_T("[Display] Voltage mode\r\n"));
	}
}

void CLNConsole20260106Dlg::OnBnClickedDaqUnit()
{
	if (m_radioDAQUnit.GetCheck() == BST_CHECKED) {
		if (!m_bIsDAQCalibrated) {
			AfxMessageBox(_T("Please load calibration file first!"));
			m_radioDAQVoltage.SetCheck(BST_CHECKED);
			m_radioDAQUnit.SetCheck(BST_UNCHECKED);
			return;
		}

		m_displayMode = SensorDisplayMode::ForceTorque;
		OutputDebugString(_T("[Display] Force-Torque mode\r\n"));
	}
}


BOOL CAboutDlg::PreTranslateMessage(MSG* pMsg)
{
	// ESC 키 차단
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) {
		return TRUE;  // 메시지 처리함 (무시)
	}

	// Enter 키 차단
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) {
		return TRUE;  // 메시지 처리함 (무시)
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CLNConsole20260106Dlg::OnBnClickedSavePath()
{
	CFolderPickerDialog dlg(nullptr, OFN_FILEMUSTEXIST, this, 0);

	if (dlg.DoModal() == IDOK) {
		// update log path
		m_cstrAutoSavePath = dlg.GetPathName();
		m_editAutoSavePath.SetWindowText(m_cstrAutoSavePath);

	}
}

void CLNConsole20260106Dlg::OnBnClickedAutoRun()
{
	// ⭐ 1. 이전 스레드 완전히 정리
	if (m_threadAuto.joinable()) {
		OutputDebugString(_T("[Auto] Waiting for previous thread to finish...\r\n"));
		m_threadAuto.join();
		OutputDebugString(_T("[Auto] Previous thread joined\r\n"));
	}

	// 2. 이미 실행 중이면 무시
	if (m_bIsAutoRunning) {
		AfxMessageBox(_T("Auto experiment is already running!"));
		return;
	}

	// 3. 장치 연결 확인
	if (!m_bIsLinearConnected) {
		AfxMessageBox(_T("Linear Stage is not connected!"));
		return;
	}
	if (!m_bIsCameraConnected || !m_bIsCameraThreadRunning.load()) {
		AfxMessageBox(_T("Cameras are not ready!"));
		return;
	}
	if (!m_bIsDAQConnected || !m_bIsDAQThreadRunning.load()) {
		AfxMessageBox(_T("DAQ is not ready!"));
		return;
	}

	// 4. 파라미터 읽기
	CString temp;
	m_editAutoStartPos.GetWindowText(temp);
	m_nAutoStartPos = _ttoi(temp);

	m_editAutoEndPos.GetWindowText(temp);
	m_nAutoEndPos = _ttoi(temp);

	m_editAutoStepInterval.GetWindowText(temp);
	m_nAutoStepInterval = _ttoi(temp);

	m_editAutoSavePath.GetWindowText(m_cstrAutoSavePath);

	// 5. 유효성 검사
	if (m_nAutoStepInterval <= 0) {
		AfxMessageBox(_T("Step interval must be greater than 0!"));
		return;
	}

	if (m_nAutoStartPos >= m_nAutoEndPos) {
		AfxMessageBox(_T("Start position must be less than end position!"));
		return;
	}

	if (m_cstrAutoSavePath.IsEmpty()) {
		AfxMessageBox(_T("Please select save path!"));
		return;
	}

	// 6. 총 스텝 수 계산
	m_nAutoTotalSteps = (m_nAutoEndPos - m_nAutoStartPos) / m_nAutoStepInterval + 1;

	// 7. 최종 확인
	CString msg;
	msg.Format(_T("Start Auto Experiment?\n\n")
		_T("Start: %d\n")
		_T("End: %d\n")
		_T("Interval: %d\n")
		_T("Total steps: %d\n\n")
		_T("Save path: %s"),
		m_nAutoStartPos, m_nAutoEndPos, m_nAutoStepInterval,
		m_nAutoTotalSteps, m_cstrAutoSavePath);

	if (AfxMessageBox(msg, MB_YESNO | MB_ICONQUESTION) != IDYES) {
		return;
	}

	// 8. Auto 시작
	m_bIsAutoRunning = true;
	m_bIsAutoAbortRequested = false;
	m_autoState = AutoState::Initializing;

	UpdateAllControls();

	// UI 업데이트
	/*m_btnAutoRun.EnableWindow(FALSE);
	m_btnAutoAbort.EnableWindow(TRUE);
	m_editAutoStartPos.EnableWindow(FALSE);
	m_editAutoEndPos.EnableWindow(FALSE);
	m_editAutoStepInterval.EnableWindow(FALSE);
	m_btnAutoBrowsePath.EnableWindow(FALSE);*/

	UpdateAutoStatus(_T("Initializing..."));

	// ⭐ 9. 새 스레드 시작
	m_threadAuto = std::thread(&CLNConsole20260106Dlg::AutoExperimentThread, this);

	OutputDebugString(_T("[Auto] Experiment started\r\n"));
}

void CLNConsole20260106Dlg::OnBnClickedAutoAbort()
{
	if (!m_bIsAutoRunning) {
		return;
	}

	// MOD: confirm dialog removed
	m_bIsAutoAbortRequested = true;                 // MOD
	m_autoState = AutoState::Aborting;              // MOD
	UpdateAutoStatus(_T("Aborted!! Please restart"));            // MOD

	// MOD: disable abort button to prevent repeated clicks
	if (GetDlgItem(BUTTON_AUTO_ABORT)) {            // MOD
		GetDlgItem(BUTTON_AUTO_ABORT)->EnableWindow(FALSE); // MOD
	}

	// MOD: keep UI consistent
	UpdateAllControls();                            // MOD

	OutputDebugString(_T("[Auto] Abort requested\r\n"));
}

LRESULT CLNConsole20260106Dlg::OnSerialReceived(WPARAM wParam, LPARAM lParam)
{
	OutputDebugString(_T("[Serial] OnSerialReceived entered\r\n"));

	if (!m_bIsLinearConnected || !m_SerialPort.IsOpen()) {
		return 0;
	}

	const size_t rxLength = static_cast<size_t>(lParam);
	if (rxLength == 0) {
		return 0;
	}

	const uint8_t* rxBuffer = reinterpret_cast<const uint8_t*>(m_SerialPort.GetRcvData());
	if (!rxBuffer) {
		return 0;
	}

	// 수신 데이터 출력 (raw)
	CString debugRx = _T("[Serial] RX RAW: ");
	for (size_t i = 0; i < rxLength; ++i) {
		CString hex;
		hex.Format(_T("%02X "), rxBuffer[i]);
		debugRx += hex;
	}
	debugRx += _T("\r\n");
	OutputDebugString(debugRx);

	// 수신 버퍼에 추가
	m_linearRxBuffer.insert(m_linearRxBuffer.end(), rxBuffer, rxBuffer + rxLength);

#ifdef _DEBUG
	CString debug;
	debug.Format(_T("[Serial] Received %u bytes\r\n"), static_cast<unsigned>(rxLength));
	OutputDebugString(debug);
#endif

	// 패킷 처리 루프
	while (m_linearRxBuffer.size() >= PACKET_SIZE) {
		// 헤더 찾기
		if (m_linearRxBuffer.front() != HEADER) {
			auto it = std::find(m_linearRxBuffer.begin(), m_linearRxBuffer.end(), HEADER);

			if (it == m_linearRxBuffer.end()) {
				m_linearRxBuffer.clear();
				break;
			}

			m_linearRxBuffer.erase(m_linearRxBuffer.begin(), it);
			if (m_linearRxBuffer.size() < PACKET_SIZE) {
				break;
			}
		}

		// 패킷 크기 확인
		if (m_linearRxBuffer.size() < PACKET_SIZE) {
			break;
		}

		// 패킷 처리
		uint8_t packet[PACKET_SIZE];
		std::copy(m_linearRxBuffer.begin(), m_linearRxBuffer.begin() + PACKET_SIZE, packet);

		// 패킷 출력
		CString debugPacket;
		debugPacket.Format(_T("[Serial] Packet: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n"),
			packet[0], packet[1], packet[2], packet[3], packet[4],
			packet[5], packet[6], packet[7], packet[8], packet[9]);

		bool integrityOK = CheckPacketIntegrity(packet);
		bool checksumOK = VerifyChecksum(packet);

		CString debugVerify;
		debugVerify.Format(_T("[Serial] Integrity: %s, Checksum: %s\r\n"),
			integrityOK ? _T("OK") : _T("FAILED"),
			checksumOK ? _T("OK") : _T("FAILED"));
		OutputDebugString(debugVerify);
		OutputDebugString(debugPacket);

		if (integrityOK && checksumOK) {
			ProcessLinearPacket(packet);
			m_linearRxBuffer.erase(m_linearRxBuffer.begin(), m_linearRxBuffer.begin() + PACKET_SIZE);
		}
		else {
			OutputDebugString(_T("[Serial] Invalid packet, skip 1 byte\r\n"));
			m_linearRxBuffer.erase(m_linearRxBuffer.begin());
		}
	}

	return 0;
}

void CLNConsole20260106Dlg::AutoExperimentThread()
{
	using namespace std::chrono;

	OutputDebugString(_T("[AutoThread] Started\r\n"));

	try {
		// ========== 1. 실험 폴더 생성 ==========
		if (!CreateExperimentFolder()) {
			m_autoState = AutoState::Error;
			UpdateAutoStatus(_T("Error: Failed to create experiment folder"));
			goto cleanup;
		}

		if (!OpenCSVFile()) {
			m_autoState = AutoState::Error;
			UpdateAutoStatus(_T("Error: Failed to open CSV file"));
			goto cleanup;
		}

		// ========== 2. 시작 위치로 이동 ==========
		m_autoState = AutoState::MovingToStart;
		UpdateAutoStatus(_T("Moving to start position..."));
		OutputDebugString(_T("[AutoThread] Moving to start position\r\n"));

		int32_t currentPos = 0;

		// ⭐ MOVE_ABS 사용
		if (!SendLinearCmd(CMD_TYPE::MOVE_ABS, m_nAutoStartPos, &currentPos)) {
			m_autoState = AutoState::Error;
			UpdateAutoStatus(_T("Error: Failed to move to start position"));
			goto cleanup;
		}

		m_nAutoCurrentPos = currentPos;

		CString log;
		log.Format(_T("[AutoThread] Moved to start position: %d\r\n"), currentPos);
		OutputDebugString(log);

		// ========== 3. 실험 루프 ==========
		m_autoState = AutoState::Running;
		m_nAutoCurrentStep = 0;

		for (int stepIndex = 0; stepIndex < m_nAutoTotalSteps; stepIndex++) {
			if (m_bIsAutoAbortRequested) {
				OutputDebugString(_T("[AutoThread] Aborted by user\r\n"));
				goto cleanup;
			}

			m_nAutoCurrentStep = stepIndex + 1;
			int currentTargetPos = m_nAutoStartPos + (stepIndex * m_nAutoStepInterval);

			// Status 업데이트 (10번마다)
			if (stepIndex % 10 == 0) {
				CString status;
				status.Format(_T("Running... Step %d/%d (Pos: %d)"),
					m_nAutoCurrentStep, m_nAutoTotalSteps, currentTargetPos);
				UpdateAutoStatus(status);
			}

			m_autoState = AutoState::Saving;

			// std::this_thread::sleep_for(std::chrono::milliseconds(30)); // MOD: optional settle time

			if (!SaveSynchronizedSample(currentPos)) { // MOD: save actual position returned by device
#ifdef _DEBUG
				OutputDebugString(_T("[AutoThread] Warning : Failed to save syncrhonized sample\r\n"));
#endif
			}

			// ===== 다음 위치로 이동 (마지막 스텝 제외) =====
			if (stepIndex < m_nAutoTotalSteps - 1) {
				m_autoState = AutoState::Running;

				// ⭐ MOVE_REL + FORWARD 사용
				if (!SendLinearCmd(CMD_TYPE::MOVE_REL, m_nAutoStepInterval,
					DIR_TYPE::FORWARD, &currentPos)) {
					m_autoState = AutoState::Error;
					UpdateAutoStatus(_T("Error: Failed to move Linear Stage"));
					goto cleanup;
				}

				m_nAutoCurrentPos = currentPos;

#ifdef _DEBUG
				if (stepIndex % 10 == 0) {
					log.Format(_T("[AutoThread] Step %d/%d at position %d (actual %d)\r\n"),
						m_nAutoCurrentStep, m_nAutoTotalSteps, currentTargetPos, currentPos); // MOD: log actual pos too
					OutputDebugString(log);
				}
#endif
			}
		}

		// ========== 4. 완료 ==========
		m_autoState = AutoState::Completed;
		UpdateAutoStatus(_T("Completed!"));

		OutputDebugString(_T("[AutoThread] Experiment completed successfully\r\n"));

		if (::IsWindow(m_hWnd)) {
			::PostMessage(m_hWnd, WM_COMMAND, MAKEWPARAM(IDC_AUTO_COMPLETED, 0), 0);

		}

	}
	catch (...) {
		m_autoState = AutoState::Error;
		UpdateAutoStatus(_T("Error: Exception occurred"));
		OutputDebugString(_T("[AutoThread] Exception occurred\r\n"));
	}

cleanup:
	CloseCSVFile();
	m_bIsAutoRunning = false;
	if (::IsWindow(m_hWnd)) {
		::PostMessage(m_hWnd, WM_COMMAND, MAKEWPARAM(IDC_AUTO_CLEANUP, 0), 0);
	}

	OutputDebugString(_T("[AutoThread] Exited\r\n"));
}

void CLNConsole20260106Dlg::UpdateAutoStatus(const CString& status)
{
	if (m_bIsUIShuttingDown.load()) return; // MOD
	if (!::IsWindow(m_hWnd)) return;        // MOD

	CString* pStr = new CString(status);   // MOD
	if (!pStr) return;                     // MOD

	if (!::PostMessage(m_hWnd, WM_AUTO_STATUS_UPDATE, 0, reinterpret_cast<LPARAM>(pStr))) { // MOD
		delete pStr; // MOD: PostMessage 실패 시 누수 방지
	}
}

bool CLNConsole20260106Dlg::SaveFrames(int position)
{
	try {
		// LatestData에서 프레임 복사
		cv::Mat frames[REQUIRED_CAMERA_COUNT];
		{
			std::lock_guard<std::mutex> lock(m_mutexLatestData);
			for (int i = 0; i < REQUIRED_CAMERA_COUNT; ++i) {
				if (!m_latestData.frames[i].empty()) {
					frames[i] = m_latestData.frames[i].clone();
				}
				else {
					OutputDebugString(_T("[SaveFrames] Warning: Empty frame\r\n"));
					return false;
				}
			}
		}

		// 파일 경로 생성
		CString filename0, filename1;
		filename0.Format(_T("%s\\Camera0\\pos_%05d.png"), m_cstrAutoSavePath, position);
		filename1.Format(_T("%s\\Camera1\\pos_%05d.png"), m_cstrAutoSavePath, position);

		// UTF-8 변환
		std::string path0 = CW2A(filename0, CP_UTF8);
		std::string path1 = CW2A(filename1, CP_UTF8);

		// 이미지 저장
		bool success0 = cv::imwrite(path0, frames[0]);
		bool success1 = cv::imwrite(path1, frames[1]);

		if (!success0 || !success1) {
			OutputDebugString(_T("[SaveFrames] Failed to write images\r\n"));
			return false;
		}

		return true;
	}
	catch (...) {
		OutputDebugString(_T("[SaveFrames] Exception occurred\r\n"));
		return false;
	}
}

bool CLNConsole20260106Dlg::SaveSensorData(int position)
{
	try {
		// CSV 파일이 열려있는지 확인
		if (!m_autoCSVFile.is_open()) {
			OutputDebugString(_T("[SaveSensorData] CSV file not open\r\n"));
			return false;
		}

		// LatestData에서 센서값 복사
		double sensorValues[6];
		{
			std::lock_guard<std::mutex> lock(m_mutexLatestData);
			for (int i = 0; i < 6; ++i) {
				sensorValues[i] = m_latestData.sensorValues[i];
			}
		}

		// 현재 시간 (실험 시작 대비 경과 시간, ms)
		auto now = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
			now - m_autoStartTime
		).count();

		// 데이터 기록 (한 줄 추가)
		m_autoCSVFile << elapsed << L","
			<< position << L","
			<< std::fixed << std::setprecision(6)
			<< sensorValues[0] << L","
			<< sensorValues[1] << L","
			<< sensorValues[2] << L","
			<< sensorValues[3] << L","
			<< sensorValues[4] << L","
			<< sensorValues[5] << L"\n";

		// 즉시 디스크에 쓰기 (데이터 손실 방지)
		m_autoCSVFile.flush();

		return true;
	}
	catch (...) {
		OutputDebugString(_T("[SaveSensorData] Exception occurred\r\n"));
		return false;
	}
}

bool CLNConsole20260106Dlg::CreateExperimentFolder()
{
	// 타임스탬프 기반 폴더 생성
	SYSTEMTIME st;
	GetLocalTime(&st);

	CString folderName;
	folderName.Format(_T("\\Exp_%04d%02d%02d_%02d%02d%02d"),
		st.wYear, st.wMonth, st.wDay,
		st.wHour, st.wMinute, st.wSecond);

	m_cstrAutoSavePath += folderName;

	// 폴더 생성
	if (!CreateDirectory(m_cstrAutoSavePath, NULL)) {
		DWORD error = GetLastError();
		if (error != ERROR_ALREADY_EXISTS) {
			OutputDebugString(_T("[Auto] Failed to create experiment folder\r\n"));
			return false;
		}
	}

	// 서브 폴더 생성
	CreateDirectory(m_cstrAutoSavePath + _T("\\Camera0"), NULL);
	CreateDirectory(m_cstrAutoSavePath + _T("\\Camera1"), NULL);

	OutputDebugString(_T("[Auto] Experiment folder created: ") + m_cstrAutoSavePath + _T("\r\n"));

	return true;
}

bool CLNConsole20260106Dlg::OpenCSVFile()
{
	try {
		CString filename;
		filename.Format(_T("%s\\sensor_data.csv"), m_cstrAutoSavePath);
		std::string csvPath = CW2A(filename, CP_UTF8);
		m_autoCSVFile.open(csvPath, std::ios::out | std::ios::trunc);

		if (!m_autoCSVFile.is_open()) {
			OutputDebugString(_T("[OpenCSVFile] Failed to open CSV file \r\n"));
			return false;
		}

		// dtCam, dtDaq 컬럼 추가
		if (m_displayMode == SensorDisplayMode::Voltage) {
			m_autoCSVFile << L"Timestamp(ms),Position,dtCam(ms),dtDaq(ms),Ch0(V),Ch1(V),Ch2(V),Ch3(V),Ch4(V),Ch5(V)\n";
		}
		else {
			m_autoCSVFile << L"Timestamp(ms),Position,dtCam(ms),dtDaq(ms),Fx(N),Fy(N),Fz(N),Tx(N-mm),Ty(N-mm),Tz(N-mm)\n";
		}

		m_autoStartTime = std::chrono::steady_clock::now();

		OutputDebugString(_T("[OpenCSVFile] CSV file opned successfully\r\n"));
		return true;

	}
	catch (...) {
		OutputDebugString(_T("[OpenCSVFile] Exception occurred\r\n"));
		return false;
	}
}



	//try {
	//	CString filename;
	//	filename.Format(_T("%s\\sensor_data.csv"), m_cstrAutoSavePath);

	//	// CSV 파일 열기 (append 모드 아님, 새로 생성)
	//	m_autoCSVFile.open(filename, std::ios::out | std::ios::trunc);

	//	if (!m_autoCSVFile.is_open()) {
	//		OutputDebugString(_T("[OpenCSVFile] Failed to open CSV file\r\n"));
	//		return false;
	//	}

	//	// 헤더 작성
	//	if (m_displayMode == SensorDisplayMode::Voltage) {
	//		m_autoCSVFile << L"Timestamp(ms),Position,Ch0(V),Ch1(V),Ch2(V),Ch3(V),Ch4(V),Ch5(V)\n";
	//	}
	//	else {
	//		m_autoCSVFile << L"Timestamp(ms),Position,Fx(N),Fy(N),Fz(N),Tx(N-mm),Ty(N-mm),Tz(N-mm)\n";
	//	}

	//	// 시작 시간 기록
	//	m_autoStartTime = std::chrono::steady_clock::now();

	//	OutputDebugString(_T("[OpenCSVFile] CSV file opened successfully\r\n"));
	//	return true;
	//}
	//catch (...) {
	//	OutputDebugString(_T("[OpenCSVFile] Exception occurred\r\n"));
	//	return false;
	//}
//}

void CLNConsole20260106Dlg::CloseCSVFile()
{
	if (m_autoCSVFile.is_open()) {
		m_autoCSVFile.flush();
		m_autoCSVFile.close();
		OutputDebugString(_T("[CloseCSVFile] CSV file closed\r\n"));
	}
}

bool CLNConsole20260106Dlg::SendLinearCmd_Move(int steps, LinearDirection direction)
{
	if (!m_bIsLinearConnected) {
		OutputDebugString(_T("[Linear] Not connected\r\n"));
		return false;
	}

	if (steps <= 0) {
		OutputDebugString(_T("[Linear] Invalid steps\r\n"));
		return false;
	}

	// TODO: 실제 시리얼 프로토콜 구현
	// 예시:
	// CString cmd;
	// if (direction == LinearDirection::Forward) {
	//     cmd.Format(_T("MOVE +%d\n"), steps);
	// } else {
	//     cmd.Format(_T("MOVE -%d\n"), steps);
	// }
	// theApp.m_SerialPort.Write(cmd);

	CString dirStr = (direction == LinearDirection::Forward) ? _T("Forward") : _T("Reverse");
	CString log;
	log.Format(_T("[Linear] Command: Move %d steps %s\r\n"), steps, dirStr);
	OutputDebugString(log);

	// 임시: 항상 성공
	return true;
}

bool CLNConsole20260106Dlg::SendLinearCmd_MoveTo(int absolutePosition)
{
	if (!m_bIsLinearConnected) {
		OutputDebugString(_T("[Linear] Not connected\r\n"));
		return false;
	}

	// TODO: 실제 시리얼 프로토콜 구현
	// 예시:
	// CString cmd;
	// cmd.Format(_T("MOVETO %d\n"), absolutePosition);
	// theApp.m_SerialPort.Write(cmd);

	CString log;
	log.Format(_T("[Linear] Command: Move to position %d\r\n"), absolutePosition);
	OutputDebugString(log);

	// 임시: 항상 성공
	return true;
}

bool CLNConsole20260106Dlg::WaitForLinearResponse(int& currentPosition, int timeouts)
{
	// TODO: 실제 시리얼 응답 대기 구현
	// 예시:
	// auto start = std::chrono::steady_clock::now();
	// while (elapsed < timeoutMs) {
	//     if (theApp.m_SerialPort.HasResponse()) {
	//         CString response = theApp.m_SerialPort.Read();
	//         // Parse response: "OK POS:12345"
	//         currentPosition = ParsePosition(response);
	//         return true;
	//     }
	//     Sleep(10);
	// }

	// 임시: 2초 대기 후 성공
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	currentPosition = m_nAutoCurrentPos;

	OutputDebugString(_T("[Linear] Response: Position ") + CString(std::to_wstring(currentPosition).c_str()) + _T("\r\n"));

	return true;
}

void CLNConsole20260106Dlg::OnAutoCompleted()
{
	AfxMessageBox(_T("Auto experiment completed successfully!"), MB_ICONINFORMATION);
}

void CLNConsole20260106Dlg::OnAutoCleanup()
{
	// UI 복원
	/*m_btnAutoRun.EnableWindow(TRUE);
	m_btnAutoAbort.EnableWindow(FALSE);
	m_editAutoStartPos.EnableWindow(TRUE);
	m_editAutoEndPos.EnableWindow(TRUE);
	m_editAutoStepInterval.EnableWindow(TRUE);
	m_btnAutoBrowsePath.EnableWindow(TRUE);*/

	// 스레드 정리
	if (m_threadAuto.joinable()) {
		m_threadAuto.join();
	}
	UpdateAllControls();
}

void CLNConsole20260106Dlg::BuildLinearPacket(uint8_t* packet, CMD_TYPE cmd, STATUS_TYPE status, uint8_t reserved, int32_t data)
{
	packet[IDX_HEADER] = HEADER;
	packet[IDX_CMD] = static_cast<uint8_t>(cmd);
	packet[IDX_STATUS] = static_cast<uint8_t>(status);
	packet[IDX_RESERVED] = reserved;
	packet[IDX_DATA_3] = static_cast<uint8_t>((data >> 24) & 0xFF);
	packet[IDX_DATA_2] = static_cast<uint8_t>((data >> 16) & 0xFF);
	packet[IDX_DATA_1] = static_cast<uint8_t>((data >> 8) & 0xFF);
	packet[IDX_DATA_0] = static_cast<uint8_t>(data & 0xFF);
	packet[IDX_CHECKSUM] = ComputeChecksum(cmd, status, reserved, data);
	packet[IDX_TAIL] = TAIL;
}

uint8_t CLNConsole20260106Dlg::ComputeChecksum(CMD_TYPE cmd, STATUS_TYPE status, uint8_t reserved, int32_t data)
{
	return static_cast<uint8_t>(cmd) ^
		static_cast<uint8_t>(status) ^
		reserved ^
		static_cast<uint8_t>((data >> 24) & 0xFF) ^
		static_cast<uint8_t>((data >> 16) & 0xFF) ^
		static_cast<uint8_t>((data >> 8) & 0xFF) ^
		static_cast<uint8_t>(data & 0xFF);
}

bool CLNConsole20260106Dlg::CheckPacketIntegrity(const uint8_t* packet)
{
	if (!packet) return false;
	if (packet[IDX_HEADER] != HEADER) return false;
	if (packet[IDX_TAIL] != TAIL) return false;
	return true;
}

bool CLNConsole20260106Dlg::VerifyChecksum(const uint8_t* packet)
{
	if (!packet) return false;

	CMD_TYPE cmd = ExtractCmd(packet);
	STATUS_TYPE status = ExtractStatus(packet);
	uint8_t reserved = ExtractReserved(packet);
	int32_t data = ExtractData(packet);

	uint8_t inputChecksum = packet[IDX_CHECKSUM];
	uint8_t computedChecksum = ComputeChecksum(cmd, status, reserved, data);

	return (inputChecksum == computedChecksum);
}

CLNConsole20260106Dlg::CMD_TYPE CLNConsole20260106Dlg::ExtractCmd(const uint8_t* packet)
{
	if (!packet) return CMD_TYPE::ERR;
	return static_cast<CMD_TYPE>(packet[IDX_CMD]);
}

CLNConsole20260106Dlg::STATUS_TYPE CLNConsole20260106Dlg::ExtractStatus(const uint8_t* packet)
{
	if (!packet) return STATUS_TYPE::ERR;
	return static_cast<STATUS_TYPE>(packet[IDX_STATUS]);
}

uint8_t CLNConsole20260106Dlg::ExtractReserved(const uint8_t* packet)
{
	if (!packet) return 0;
	return packet[IDX_RESERVED];
}

int32_t CLNConsole20260106Dlg::ExtractData(const uint8_t* packet)
{
	if (!packet) return 0;

	uint32_t raw = (static_cast<uint32_t>(packet[IDX_DATA_3]) << 24) |
		(static_cast<uint32_t>(packet[IDX_DATA_2]) << 16) |
		(static_cast<uint32_t>(packet[IDX_DATA_1]) << 8) |
		(static_cast<uint32_t>(packet[IDX_DATA_0]));

	return static_cast<int32_t>(raw);
}

bool CLNConsole20260106Dlg::SendLinearCmd(CMD_TYPE cmd, int32_t data, int32_t* outData)
{
	return SendLinearCmd(cmd, data, DIR_TYPE::FORWARD, outData);
}

bool CLNConsole20260106Dlg::SendLinearCmd(CMD_TYPE cmd, int32_t data, DIR_TYPE dir, int32_t* outData)
{
	if (!m_bIsLinearConnected || !m_SerialPort.IsOpen()) {
		OutputDebugString(_T("[SendCmd] Linear Stage not connected\r\n"));
		return false;
	}

	// Pending 초기화
	m_linearPending.cmd = cmd;
	m_linearPending.waiting = TRUE;
	m_linearPending.got = FALSE;
	m_linearPending.status = STATUS_TYPE::ERR;
	m_linearPending.data = 0;

	// 패킷 빌드
	uint8_t packet[PACKET_SIZE] = { 0 };
	BuildLinearPacket(packet, cmd, STATUS_TYPE::OK, static_cast<uint8_t>(dir), data);

	// 송신 데이터 출력
	CString debugTx;
	debugTx.Format(_T("[SendCmd] TX: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n"),
		packet[0], packet[1], packet[2], packet[3], packet[4],
		packet[5], packet[6], packet[7], packet[8], packet[9]);
	OutputDebugString(debugTx);

	// 패킷 송신
	DWORD written = 0;
	m_SerialPort.Write(packet, PACKET_SIZE, &written);

	if (written != PACKET_SIZE) {
		OutputDebugString(_T("[SendCmd] Warning: partial write\r\n"));
	}

#ifdef _DEBUG
	CString debug;
	debug.Format(_T("[SendCmd] Sent CMD=0x%02X, DATA=%d, DIR=%d\r\n"),
		static_cast<uint8_t>(cmd), data, static_cast<uint8_t>(dir));
	OutputDebugString(debug);
#endif

	// ACK 대기 (메시지 펌프 루프)
	ULONGLONG start = GetTickCount64();
	while (!m_linearPending.got) {
		// 타임아웃 체크 (10초)
		if (GetTickCount64() - start >= 60000) {
			m_linearPending.waiting = FALSE;
			OutputDebugString(_T("[SendCmd] Timeout waiting for ACK\r\n"));
			return false;
		}

		// 메시지 펌프 (UI 응답성 유지 + 시리얼 수신 처리)
		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Sleep(1);
	}

	// 결과 캡처
	if (outData) {
		*outData = m_linearPending.data;
	}

	m_linearPending.waiting = FALSE;

	bool success = (m_linearPending.status == STATUS_TYPE::OK);

#ifdef _DEBUG
	if (success) {
		CString debug;
		debug.Format(_T("[SendCmd] ACK OK, data=%d\r\n"), m_linearPending.data);
		OutputDebugString(debug);
	}
	else {
		OutputDebugString(_T("[SendCmd] ACK ERROR\r\n"));
	}
#endif

	return success;
}

void CLNConsole20260106Dlg::ProcessLinearPacket(const uint8_t* packet)
{
	CMD_TYPE cmd = ExtractCmd(packet);
	STATUS_TYPE status = ExtractStatus(packet);
	int32_t data = ExtractData(packet);

	// 패킷 내용 출력
	CString debugProcess;
	debugProcess.Format(_T("[Process] CMD=0x%02X, STATUS=0x%02X, DATA=%d\r\n"),
		static_cast<uint8_t>(cmd), static_cast<uint8_t>(status), data);
	OutputDebugString(debugProcess);

	// ACK 캡처
	if (m_linearPending.waiting &&
		!m_linearPending.got &&
		m_linearPending.cmd == cmd) {
		m_linearPending.status = status;
		m_linearPending.data = data;
		m_linearPending.got = TRUE;

		OutputDebugString(_T("[Serial] ACK captured\r\n"));
	}

	// UI 업데이트 (상태에 따라)
	if (status == STATUS_TYPE::OK) {
		CString str;

		switch (cmd) {
		case CMD_TYPE::GET_POS:
		case CMD_TYPE::MOVE_REL:
		case CMD_TYPE::MOVE_ABS:
		case CMD_TYPE::HOME:
			m_nLinearCurPos = data;
			str.Format(_T("%d"), m_nLinearCurPos);
			m_staticLinearCurPos.SetWindowText(str);
			break;

		case CMD_TYPE::GET_SPEED:
		case CMD_TYPE::SET_SPEED:
			m_nLinearSpeed = data;
			str.Format(_T("%d"), m_nLinearSpeed);
			m_staticLinearSpeed.SetWindowText(str);
			break;

		case CMD_TYPE::GET_MAX:
		case CMD_TYPE::SET_MAX:
			m_nLinearMaxPos = data;
			str.Format(_T("%d"), m_nLinearMaxPos);
			m_staticLinearMaxPos.SetWindowText(str);
			break;
		}
	}
}

void CLNConsole20260106Dlg::UpdateLinearControls()
{
	if (m_bIsLinearConnected) {
		// 연결됨: 제어 버튼 활성화
		GetDlgItem(BUTTON_LINEAR_SETZERO)->EnableWindow(TRUE);
		GetDlgItem(BUTTON_LINEAR_SETMAX)->EnableWindow(TRUE);
		GetDlgItem(BUTTON_LINEAR_SETSPEED)->EnableWindow(TRUE);
		GetDlgItem(BUTTON_LINEAR_FORWARD)->EnableWindow(TRUE);
		GetDlgItem(BUTTON_LINEAR_REVERSE)->EnableWindow(TRUE);
		GetDlgItem(BUTTON_LINEAR_HOME)->EnableWindow(TRUE);
		GetDlgItem(EDIT_LINEAR_SPEED)->EnableWindow(TRUE);
		GetDlgItem(EDIT_LINEAR_STEPS)->EnableWindow(TRUE);
	}
	else {
		// 연결 안 됨: 제어 버튼 비활성화
		GetDlgItem(BUTTON_LINEAR_SETZERO)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_LINEAR_SETMAX)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_LINEAR_SETSPEED)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_LINEAR_FORWARD)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_LINEAR_REVERSE)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_LINEAR_HOME)->EnableWindow(FALSE);
		GetDlgItem(EDIT_LINEAR_SPEED)->EnableWindow(FALSE);
		GetDlgItem(EDIT_LINEAR_STEPS)->EnableWindow(FALSE);
	}
}

void CLNConsole20260106Dlg::UpdateDAQControls()
{
	if (m_bIsDAQConnected) {
		// 연결됨
		GetDlgItem(BUTTON_DAQ_CALIBPATH)->EnableWindow(TRUE);
		GetDlgItem(BUTTON_DAQ_BIAS)->EnableWindow(TRUE);
		GetDlgItem(BUTTON_DAQ_UNBIAS)->EnableWindow(TRUE);
		GetDlgItem(RADIO_DAQ_VOLTAGE)->EnableWindow(TRUE);

		// Calibration 로드 여부에 따라 F/T Unit 활성화
		if (m_bIsDAQCalibrated) {
			GetDlgItem(RADIO_DAQ_UNIT)->EnableWindow(TRUE);
		}
		else {
			GetDlgItem(RADIO_DAQ_UNIT)->EnableWindow(FALSE);
			// Voltage 모드 강제
			m_radioDAQVoltage.SetCheck(BST_CHECKED);
			m_radioDAQUnit.SetCheck(BST_UNCHECKED);
			m_displayMode = SensorDisplayMode::Voltage;
		}
	}
	else {
		// 연결 안 됨
		GetDlgItem(BUTTON_DAQ_CALIBPATH)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_DAQ_BIAS)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_DAQ_UNBIAS)->EnableWindow(FALSE);
		GetDlgItem(RADIO_DAQ_VOLTAGE)->EnableWindow(FALSE);
		GetDlgItem(RADIO_DAQ_UNIT)->EnableWindow(FALSE);
	}
}

void CLNConsole20260106Dlg::UpdateAutoControls()
{
	// 세 장치 모두 연결되어야 Auto 실험 가능
	BOOL allConnected = m_bIsLinearConnected && m_bIsCameraConnected && m_bIsDAQConnected;

	if (m_bIsAutoRunning) {
		// 실험 진행 중: Abort만 활성화
		GetDlgItem(EDIT_AUTO_STARTPOS)->EnableWindow(FALSE);
		GetDlgItem(EDIT_AUTO_ENDPOS)->EnableWindow(FALSE);
		GetDlgItem(EDIT_AUTO_ENDPOS2)->EnableWindow(FALSE);  // Interval
		GetDlgItem(BUTTON_SAVE_PATH)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_AUTO_RUN)->EnableWindow(FALSE);
		GetDlgItem(BUTTON_AUTO_ABORT)->EnableWindow(TRUE);
	}
	else {
		// 실험 중 아님
		if (allConnected) {
			// 모든 장치 연결됨: Auto 실험 가능
			GetDlgItem(EDIT_AUTO_STARTPOS)->EnableWindow(TRUE);
			GetDlgItem(EDIT_AUTO_ENDPOS)->EnableWindow(TRUE);
			GetDlgItem(EDIT_AUTO_ENDPOS2)->EnableWindow(TRUE);
			GetDlgItem(BUTTON_SAVE_PATH)->EnableWindow(TRUE);
			GetDlgItem(BUTTON_AUTO_RUN)->EnableWindow(TRUE);
		}
		else {
			// 일부 장치 미연결: Auto 실험 불가
			GetDlgItem(EDIT_AUTO_STARTPOS)->EnableWindow(FALSE);
			GetDlgItem(EDIT_AUTO_ENDPOS)->EnableWindow(FALSE);
			GetDlgItem(EDIT_AUTO_ENDPOS2)->EnableWindow(FALSE);
			GetDlgItem(BUTTON_SAVE_PATH)->EnableWindow(FALSE);
			GetDlgItem(BUTTON_AUTO_RUN)->EnableWindow(FALSE);
		}

		GetDlgItem(BUTTON_AUTO_ABORT)->EnableWindow(FALSE);
	}
}

void CLNConsole20260106Dlg::UpdateAllControls()
{
	UpdateLinearControls();
	UpdateDAQControls();
	UpdateAutoControls();
}

LRESULT CLNConsole20260106Dlg::OnCameraInitComplete(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	if (m_bIsUIShuttingDown.load()) {
		OutputDebugString(_T("[OnCameraInitComplete] Ignored during shutdown\r\n"));
		return 0;
	}

	BOOL ok = (wParam != FALSE);

	if (ok) {
		// init 성공 메시지가 늦게 도착한 경우 방어
		if (!m_bIsCameraThreadRunning.load()) {
			ok = FALSE;
		}
	}

	// MOD: 사용자가 이미 Disconnect를 눌러서 체크가 풀린 상태면 "조용한 종료"로 간주
	const BOOL userAlreadyDisconnected = (m_checkCameraConnect.GetCheck() != BST_CHECKED); // MOD


	if (ok) {
		m_bIsCameraConnected = TRUE;
		m_staticCameraState.SetWindowTextW(_T("Connected"));

		// 연결 성공 후 UI 타이머 시작
		UpdateAllControls();
		AfxMessageBox(_T("Cameras connected!"));

		SetTimer(IDT_UI_UPDATE_TIMER, 33, nullptr);
	}
	else {
		// MOD: 사용자 Disconnect로 인한 종료 알림이면 조용히 상태만 갱신하고 종료
		if (userAlreadyDisconnected) { // MOD
			m_bIsCameraConnected = FALSE;
			m_staticCameraState.SetWindowTextW(_T("Disconnected"));
			UpdateAllControls();
			return 0;
		}


		m_bIsCameraConnected = FALSE;
		m_staticCameraState.SetWindowTextW(_T("Disconnected"));

		// 체크박스 롤백
		m_checkCameraConnect.SetCheck(BST_UNCHECKED);
		m_checkCameraConnect.SetWindowTextW(_T("Connect"));

		// ensure cameras are released (thread already stopped itself)
		ReleaseCameras();

		CString err;
		{
			std::lock_guard<std::mutex> lock(m_mutexCameraInit);
			err = m_strCameraInitError;
		}

		if (err.IsEmpty()) err = _T("Camera init failed.");
		AfxMessageBox(err, MB_ICONERROR);
		UpdateAllControls();
	}

	return 0;
}



void CLNConsole20260106Dlg::OnBnClickedCamConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL isChecked = m_checkCameraConnect.GetCheck();

	if (isChecked == BST_CHECKED) {
		if (InitializeCameras()) {
			m_checkCameraConnect.SetWindowTextW(_T("Disconnect"));
			StartCameraThread();
			UpdateAllControls();
		}
		else {
			StopCameraThread();
			ReleaseCameras();
			m_checkCameraConnect.SetCheck(BST_UNCHECKED);
			m_checkCameraConnect.SetWindowTextW(_T("Connect"));
			UpdateAllControls();
		}
	}
	else {
		StopCameraThread();
		ReleaseCameras();
		m_checkCameraConnect.SetWindowTextW(_T("Connect"));
		UpdateAllControls();
	}
}

LRESULT CLNConsole20260106Dlg::OnAutoStatusUpdate(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(wParam);

	CString* pStr = reinterpret_cast<CString*>(lParam); // MOD
	if (!pStr) return 0;

	if (m_staticAutoState.GetSafeHwnd()) {
		m_staticAutoState.SetWindowTextW(*pStr); // MOD
	}

	delete pStr; // MOD
	return 0;
}
