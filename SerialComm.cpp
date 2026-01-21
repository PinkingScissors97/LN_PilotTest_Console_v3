#include "pch.h"
#include "SerialComm.h"


CSerialComm::CSerialComm()
{
	Info.init();
	Recv_Data_Length = 0;
}

CSerialComm::~CSerialComm()
{
	if (Info.Opened)
	{
		StopListener();
		Info.init();
		Close();
	}
}

void CSerialComm::OnEvent(EEvent eEvent, EError eError) {
	if (eEvent == EEventRecv) {
		//OutputDebugString(_T("OnEvent\r\n"));
		if (Message_hWnd == NULL) {
			OutputDebugString(_T("Error: Message_hWnd is NULL!"));
			return;
		}

		memset(Recv_Data_Buff, 0x00, sizeof(char) * (MAX_BUFF_SIZE));
		DWORD rcv_Length = 0;
		Read(Recv_Data_Buff, MAX_BUFF_SIZE, &rcv_Length);
		Recv_Data_Length += rcv_Length;
		SendMessage(Message_hWnd, WM_SERIAL_RECEIVED, MAKEWPARAM(Departure_Address, 0), MAKELPARAM(rcv_Length, 0));
	}
}



void CSerialComm::SetPortInfo(PortInfo info)
{
	SetPortInfo(info.Port, info.Baudrate, info.Databits, info.Parity, info.Stopbits, info.Handshaking);
}

void CSerialComm::SetPortInfo(LPCTSTR lpszDevice, EBaudrate b, EDataBits d, EParity p, EStopBits s, EHandshake h)
{
	Info.Port = lpszDevice;
	Info.Baudrate = b;
	Info.Databits = d;
	Info.Parity = p;
	Info.Stopbits = s;
	Info.Handshaking = h;
}

bool CSerialComm::Connect()
{
	return Connect(Info);
}

bool CSerialComm::Connect(PortInfo info)
{
	return Connect(info.Port, info.Baudrate, info.Databits, info.Parity, info.Stopbits, info.Handshaking);
}

bool CSerialComm::Connect(LPCTSTR lpszDevice, EBaudrate b, EDataBits d, EParity p, EStopBits s, EHandshake h)
{
	SetPortInfo(lpszDevice, b, d, p, s, h);
	if (CheckPort(Info.Port) != CSerialEx::EPortAvailable)
	{
		SendMessage(Message_hWnd, PORT_OPEN_ERROR_MESSAGE, MAKEWPARAM(Departure_Address, 0), MAKELPARAM(0, PORT_OPEN_ERROR_STATUS1));
		Info.Opened = false;
		return Info.Opened;
	}

	if (Open(Info.Port) != ERROR_SUCCESS)
	{
		SendMessage(Message_hWnd, PORT_OPEN_ERROR_MESSAGE, MAKEWPARAM(Departure_Address, 0), MAKELPARAM(0, PORT_OPEN_ERROR_STATUS2));
		Info.Opened = false;
	}
	else
	{
		Setup(Info.Baudrate, Info.Databits, Info.Parity, Info.Stopbits);
		SetupHandshaking(Info.Handshaking);
		Info.Opened = true;
		SetMask();
		StartListener();
	}
	return Info.Opened;
}

void CSerialComm::Disconnect()
{
	Close();
	Info.Opened = false;
}

void CSerialComm::OutputDebugRcvData()
{
	CString temp, Result;
	for (int i = 0; i < Recv_Data_Length; i++) {
		temp.Format(_T("0x%02x "), Recv_Data_Buff[i]);
		Result += temp;
	}
	Result += _T("\r\n");
	OutputDebugString(Result);
}
