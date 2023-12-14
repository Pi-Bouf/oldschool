// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef STRICT
#define STRICT
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 일부 CString 생성자는 명시적으로 선언됩니다.

// ATL의 일반적이며 대개 안전하게 무시되는 일부 경고 메시지 숨김을 해제합니다.
#define _ATL_NO_COM_SUPPORT
#define _ATL_ALL_WARNINGS

#include "resource.h"

#include "TNetLib.h"
#include "NetCode.h"
#include "TPatchType.h"
#include "CTProtocol.h"
#include "DBAccess.h"
