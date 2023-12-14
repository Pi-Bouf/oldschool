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

//
//	Log Server	UDP Send Define
//
#define	DEF_UDPLOG
#define	DEF_UDPLOGGUILD


#include "resource.h"

#include <TNetLib.h>
#include <NetCode.h>
#include <TMapType.h>
#include <SSProtocol.h>
#include <CSProtocol.h>
#include <CTProtocol.h>
#include <DMProtocol.h>
#include <MWProtocol.h>
#include <DBAccess.h>

#ifdef DEF_UDPLOG
	#include "UdpSocket.h"
#endif
