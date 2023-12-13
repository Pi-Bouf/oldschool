// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

typedef struct DXGI_JPEG_AC_HUFFMAN_TABLE {
	int CodeCounts[16];
	int CodeValues[162];
};

typedef struct DXGI_JPEG_DC_HUFFMAN_TABLE {
	int CodeCounts[12];
	int CodeValues[12];
};

typedef struct DXGI_JPEG_QUANTIZATION_TABLE {
	int Elements[64];
};

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes

#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#include <afxsock.h>
#include <direct.h>
#include <dbghelp.h>

#include <assert.h>
#include <fstream>
#include <iostream>
#include <tlhelp32.h>
#include <dxdiag.h>
#include <strsafe.h>
#include <winsvc.h>

#ifndef TEST_MODE
#include <XTrap4Client.h>
#endif

#if defined _DEBUG || TEST_MODE
#define NO_GAMEGUARD
#endif
#include "NPGameLib.h"

#include <T3D.h>
#include <CSProtocol.h>
#include <NetCode.h>
#include <TClientID.h>

#include <TChartType.h>
#include "TClientType.h"

#endif // _AFX_NO_AFXCMN_SUPPORT
