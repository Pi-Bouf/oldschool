// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������ 
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef STRICT
#define STRICT
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

// ATL�� �Ϲ����̸� �밳 �����ϰ� ���õǴ� �Ϻ� ��� �޽��� ������ �����մϴ�.
#define _ATL_NO_COM_SUPPORT
#define _ATL_ALL_WARNINGS
#define _USE_MATH_DEFINES

#include <atltime.h>
#include "resource.h"
#include <TNetLib.h>

#include "TControlType.h"
#include "SSProtocol.h"
#include "CTProtocol.h"
#include "MWProtocol.h"
#include "NetCode.h"
#include "DBAccess.h"
#include "PlatformUsage.h"