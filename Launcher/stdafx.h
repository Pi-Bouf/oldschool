// stdafx.h : 잘 변경되지 않고 자주 사용하는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Windows 헤더에서 거의 사용되지 않는 내용을 제외시킵니다.
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

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소
#include <afxext.h>         // MFC 익스텐션
#include <afxdisp.h>        // MFC 자동화 클래스

#include <afxdtctl.h>		// Internet Explorer 4 공용 컨트롤에 대한 MFC 지원
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Windows 공용 컨트롤에 대한 MFC 지원
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <map>
#include <queue>
using namespace std;

#include <afxinet.h>
#include <afxsock.h>
#include <winsvc.h>
#include <direct.h>
#include <Tlhelp32.h>
#include "atlimage.h"
#include "xSkinButton.h"

#include "Packet.h"
#include "CTProtocol.h"
#include "HSession.h"
#include "webbrowser2.h"
#include "T3D.h"
#include "4Story.h"
#include "4StoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
