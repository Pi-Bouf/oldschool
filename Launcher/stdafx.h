// stdafx.h : �� ������� �ʰ� ���� ����ϴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������ 
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Windows ������� ���� ������ �ʴ� ������ ���ܽ�ŵ�ϴ�.
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

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

// MFC�� ���� �κа� ���� ������ ��� �޽����� ���� ����⸦ �����մϴ�.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ���
#include <afxext.h>         // MFC �ͽ��ټ�
#include <afxdisp.h>        // MFC �ڵ�ȭ Ŭ����

#include <afxdtctl.h>		// Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC ����
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Windows ���� ��Ʈ�ѿ� ���� MFC ����
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
