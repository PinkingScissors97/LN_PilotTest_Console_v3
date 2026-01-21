// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가
#include "framework.h"

#include "SerialComm.h"
#include <vector>
#include "opencv2\opencv.hpp"
#include <thread>
#include <mutex>
#include <chrono>
#include <deque>
#include <dshow.h>
#include <comdef.h>
#include <algorithm>
#include <string>
#include "NIDAQmx.h"
#include <atomic>

#define IDC_AUTO_COMPLETED (WM_USER + 100)
#define IDC_AUTO_CLEANUP (WM_USER + 101)
#define WM_AUTO_STATUS_UPDATE (WM_USER + 102)

#define WM_SERIAL_RECEIVED (WM_USER + 200)

#define WM_CAMERA_INIT_COMPLETE (WM_USER + 300)
#define WM_DAQ_INIT_COMPLETE (WM_USER + 301)

#endif //PCH_H
