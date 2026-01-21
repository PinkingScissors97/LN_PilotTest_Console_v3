#pragma once
#include "SerialEx.h"

#define MAX_BUFF_SIZE 1024
#define PORT_OPEN_ERROR_STATUS1 1
#define PORT_OPEN_ERROR_STATUS2 2
#define DATA_RECV_MESSAGE WM_USER+1
#define PORT_OPEN_ERROR_MESSAGE DATA_RECV_MESSAGE+1
#define DATA_NULL 0x20


struct PortInfo
{
	CString Port;
	CSerial::EBaudrate Baudrate;
	CSerial::EDataBits Databits;
	CSerial::EParity Parity;
	CSerial::EStopBits Stopbits;
	CSerial::EHandshake Handshaking;
	bool Opened;
	void init()
	{
		Port.Format(_T("COM1"));
		Baudrate = CSerial::EBaudrate::EBaud9600;
		Databits = CSerial::EDataBits::EData8;
		Parity = CSerial::EParity::EParNone;
		Stopbits = CSerial::EStopBits::EStop1;
		Handshaking = CSerial::EHandshake::EHandshakeOff;
		Opened = false;
	}

	void SetInfo(PortInfo info)
	{
		this->Port = info.Port;
		this->Baudrate = info.Baudrate;
		this->Databits = info.Databits;
		this->Parity = info.Parity;
		this->Stopbits = info.Stopbits;
		this->Handshaking = info.Handshaking;
		Opened = false;
	}
};

class CSerialComm : public CSerialEx
{
public:
	CSerialComm();
	virtual ~CSerialComm();
	void SetMessageDest(HWND hWnd) { Message_hWnd = hWnd; }
	void SetAddress(DWORD num) { Departure_Address = num; }
	void OnEvent(EEvent eEvent, EError eError);

protected:
	HWND Message_hWnd;
	DWORD Departure_Address;
	char Recv_Data_Buff[MAX_BUFF_SIZE];
	DWORD Recv_Data_Length;
	PortInfo Info;

public:
	PortInfo GetPortInfo() { return Info; }
	void SetPortInfo(PortInfo info);
	void SetPortInfo(LPCTSTR lpszDevice, EBaudrate b = EBaudrate::EBaud1200, EDataBits d = EDataBits::EData8, EParity p = EParity::EParNone, EStopBits s = EStopBits::EStop1, EHandshake h = EHandshake::EHandshakeOff);
	bool Connect();
	bool Connect(PortInfo info);
	bool Connect(LPCTSTR lpszDevice, EBaudrate b = EBaudrate::EBaud1200, EDataBits d = EDataBits::EData8, EParity p = EParity::EParNone, EStopBits s = EStopBits::EStop1, EHandshake h = EHandshake::EHandshakeOff);
	void Disconnect();
	char* GetRcvData() { return Recv_Data_Buff; }
	int GetRcvBuffLength() { return Recv_Data_Length; }

	void OutputDebugRcvData();
};

