// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__944DD3E7_59CF_4318_BAE1_015912087125__INCLUDED_)
#define AFX_STDAFX_H__944DD3E7_59CF_4318_BAE1_015912087125__INCLUDED_

#pragma warning( disable : 4786 4530 4503)

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

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

#include <afx.h>
#include <afxwin.h>
#include <afxsock.h>
#include <T3D.h>
#include <zlib.h>
#include <shlwapi.h>
#include <Psapi.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__944DD3E7_59CF_4318_BAE1_015912087125__INCLUDED_)
