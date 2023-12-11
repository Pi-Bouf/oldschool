// 4StoryDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
//#include "HoverButton.h"
#include "GameSetting.h" // 게임 설정 창 띄우기

#include <d3d9.h>
#include <dxdiag.h>
#include <d3dx9.h>

#pragma comment(lib,"dxguid.lib")

typedef enum TMP_HACK_DETECT_TYPE
{
	TMP_HACK_NONE = 0,
	TMP_HACK_FOUND,
	TMP_HACK_TIMEOUT,
	TMP_HACK_INVALID_PE
} *LPTMP_HACK_DETECT_TYPE;

#define WM_RESTART_PATCH			(WM_USER + 109)
#define WM_STOP_DOWNLOAD			(WM_USER + 119)
#define WM_CLOSE_SESSION			(WM_USER + 120)

//	prepatch msg
#define WM_PREPATCH_RRESET			(WM_USER + 7110)
#define WM_PREPATCH_RQUIT			(WM_USER + 7111)

#define APP_EXT						_T(".exe")
#define APP_NAME					_T("My4Story")
#define BACKUP_EXT					_T("_bak")
#define PATH_DELIMETERS				_T("/\\")
#define REG_SUBKEY					_T("Software\\Zemi Interactive\\")
#define REG_VALUE_VERSION			_T("version")
#define REG_VALUE_LOCAL				_T("directory")
#define REG_VALUE_EXE				_T("exe")
#define REG_VALUE_PATCHSVR			_T("address")
#define REG_VALUE_PATCHPORT			_T("port")
#define REG_VALUE_DISCLAIMER		_T("disclaimer")
#define REG_VALUE_MODE				_T("mode")
#define PREPATCH_NAME				_T("4Story PrePatch")

#define DEFAULT_SCREEN_X			1024
#define DEFAULT_SCREEN_Y			768
//=====================================================================================
// 각국 버전마다 변경되야 하는 항목들
// String Table 의 Error Message 변경
#ifdef _GAMEFORGE
	#define HOMEPAGE_NAME				_T("http://www.google.com")
	#define LAUNCHERWEB_NAME			_T("http://www.google.fr")
	#define REG_COUNTRY					_T("")
	#define TOOLTIP_START				_T("Start the game")
	#define TOOLTIP_CLOSE				_T("Close the game")
	#define TOOLTIP_HOME				_T("Go to homepage")
	#define TOOLTIP_OPTION				_T("Set the option")
	#define TOOLTIP_PREPATCH			_T("Download next patch in advance")
	#define COUNTRY_CODE				_T("EU")
#endif

//=====================================================================================
#define PROGRESS_TYPE_DOWNLOAD		1
#define PROGRESS_TYPE_UNZIP			2
#define PROGRESS_TYPE_DEFAULT		3

#define FTP_USER					_T("pierre")
#define FTP_PASS					_T("Maitre.B05")

#define OPTION_LOW					0
#define OPTION_MID					1
#define OPTION_HI					2

typedef struct tagPATCHFILE
{
	DWORD m_dwVersion;
	CString m_strPath;
	CString m_strName;
	DWORD m_dwSize;
	DWORD m_dwBetaVer;
}PATCHFILE, *LPPATCHFILE;

struct UIButton
{
	CString m_strNormal;
	CString m_strDown;
	CString m_strOver;
	CString m_strDisable;
	CString m_strToolTip;
	int x;
	int y;
};

struct UISet
{
	BYTE m_Offset;
	CString m_strBG;
	COLORREF m_rgbAlpha;
	UIButton m_Home;
	UIButton m_Set;
	UIButton m_Connect;
	UIButton m_Close;
	UIButton m_PrePatch;
	
	COLORREF m_rgbCurrent;
	COLORREF m_rgbUnzip;
	RECT m_rtCurrent;

	COLORREF m_rgbTotal;
	RECT m_rtTotal;

	RECT m_rtView;

	void Default()
	{
		m_Offset = 0;

		m_Home.m_strToolTip = TOOLTIP_HOME;
		m_Set.m_strToolTip = TOOLTIP_OPTION;
		m_Connect.m_strToolTip = TOOLTIP_START;
		m_Close.m_strToolTip = TOOLTIP_CLOSE;
		m_PrePatch.m_strToolTip = TOOLTIP_PREPATCH;
		
		m_Home.x = 229;	m_Set.x = 367;	m_Connect.x = 505;	m_Close.x = 643;
		m_Home.y = m_Set.y = m_Connect.y = m_Close.y = 476;
		m_PrePatch.x = 749;
		m_PrePatch.y = 512;

		m_rgbCurrent = m_rgbTotal = RGB(0,169,157);
		m_rgbUnzip = RGB(180,40,100);
		m_rtCurrent = CRect(326, 431, 760, 439);
		m_rtTotal= CRect(326, 447, 760, 455);
		m_rtView = CRect(231, 92, 760, 405);
	};
};

typedef vector<LPPATCHFILE>			VPATCHFILE, *LPVPATCHFILE;

typedef struct tagD3DDEVICE
{
	LPDIRECT3D9 m_pD3D;
	D3DPRESENT_PARAMETERS m_vPRESENT;
}D3DDEVICE, *LPD3DDEVICE;

// CStoryDlg 대화 상자
class CStoryDlg : public CDialog
{
// 생성
public:
	CStoryDlg(CWnd* pParent = NULL);	// 표준 생성자
	~CStoryDlg();
	enum { IDD = IDD_STORY_DIALOG };
	enum {	DOWN_NONE = 1,	//	기본값
			DOWN_PREPATCH,	//	Pre패치
			DOWN_INCOMPRE,	//	Pre패치이어받기
			DOWN_ERR};		//	에러

	void OnConnect(int nErrorCode);
	void OnClose(int nErrorCode);
	DWORD OnReceive(CPacket * pPacket);
	void SessionStart(CString strIp, DWORD dwPort);
	void Say(CPacket * pPacket);

	void InitWeb();
	BYTE ReadRegistry();
	BYTE CopyRegistry();
	void LoadSkin();
	void SetControlPos();	// 컨트롤 위치 지정
	CString LoadString(int nID);
	BYTE WriteStartRegistry(BYTE bCheak);
	BYTE CheakStartRegistry();

	void DownloadEnd();
	void StartGame();

	static DWORD WINAPI _Download(LPVOID lpParam);
	DWORD Download();
	BYTE PrePatchCheak(LPPATCHFILE& pPatchFile, VPATCHFILE::iterator& itr);
	BYTE SetPath(LPPATCHFILE pPatchFile, BYTE bPatchType);
	DWORD OpenDownloadFile(LPPATCHFILE pPatchFile);
	void DownloadFinish();

	BYTE CreateDirectoryEx(CString strPath);
	void Progress(CString strName, DWORD dwSize, DWORD dwCurrent, __int64 nTotal, BYTE bType);
	int Unzip(LPCTSTR strZip, LPCTSTR strDirectory);
	void VerifyDirectory(LPCTSTR target, LPCTSTR path, BYTE bHaveFile);
	void CheckPatch();
	void RemoveDownloadDirectory();
	void RemoveOldPrePatch();
	void DeleteDirectory(LPCTSTR strPath);
	BYTE SetVersion(DWORD dwVersion);

	void InfoFileWrite();
	void InfoFileRead();
	BYTE FindPatchFile(CString lpPathName);
	void DownloadWrite(LPPATCHFILE pFile = NULL);
	BYTE DownloadRead(LPPATCHFILE pFile);
	BYTE LoadUXInfo();
	void UXSetting();

	BYTE LaunchTClient();
	BYTE BeginProtect();
	void EndProtect();
	void EndThread();
	void ProssesKillr(CString strProssName);

	void PrePatchQuit(BYTE bCOM = 0);

	BYTE WriteRegistry();
	void InitCAPS(); //컴퓨터 사양 검사
	BYTE InitDevice();
	void CollectResolution(); // 해상도 검사
	CString GetLocalString()	{return m_strLocal;	}
	
	void ShowSettingFrame();
	BYTE CheckIsFirst();

	DWORD OnCT_NEWPATCH_ACK(CPacket * pPacket);
	void SendCT_NEWPATCH_REQ();
	void SendCT_PATCHSTART_REQ();

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedButtonHomepage();
	afx_msg void OnBnClickedButtonSetting();
	afx_msg void OnBnClickedChkPrepatch()	{WriteStartRegistry((BYTE)m_chkPrePatch.GetCheck());};
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	virtual BOOL DestroyWindow();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	// 메시지 맵 함수를 생성했습니다.
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
	HICON		m_hIcon;
	//HBITMAP		hBmp;
	CImage		m_bSkin;
	CxSkinButton m_chkPrePatch;
	CWebBrowser2 m_webCtrl;

	CHSession	m_session;

	HANDLE		m_hDownload;
	VPATCHFILE	m_vPatchFile;	
	VPATCHFILE	m_vLocal;

	WORD		m_wPort;
	WORD		m_wGamePort;
	WORD		m_wFtpPort;
	DWORD		m_dwVersion;
	DWORD		m_dwNextVersion;
	DWORD		m_dwMinBetaVer;
	__int64		m_nPatchTotalSize;

	char		m_szPatchFileName[_MAX_PATH+1];
	CString		m_strAppName;
	CString 	m_strRegSubKey;
	CString 	m_strGame;
	CString 	m_strGameSvr;

	CString		m_strIP;
	CString		m_strLocal;
	CString		m_strDownload;
	CString		m_strFtpSvr;

	CString		m_strHompageURLForLuancher;
	CString		m_strNoticeURLForLuancher;
	CString		m_strSubkey;

	BYTE		m_bFirstPrePatch;
	BYTE		sFlag;
	BYTE		m_blPatchFileUpdate;
	BYTE		m_bDownloading;
	BYTE		m_bCancel;
	BYTE		m_bIsFtpConnecting;	
	BYTE		m_bFlash; // 버튼 깜박임
	BYTE		m_bProgressingColor;
	BYTE		m_bSecond;

	UISet		m_Ui;

public:
	static ULONGLONG m_lVIDEOMEM;
	static ULONGLONG m_lSYSMEM;

	CProgressCtrl m_progressCurrent;
	CProgressCtrl m_progressTotal;
	CxSkinButton m_bHome;
	CxSkinButton m_bSetting;
	CxSkinButton m_bOK;
	CxSkinButton m_bCANCEL;

	// 그래픽 설정 관련 변수
	DWORD m_dwWindowMode;
	DWORD m_dwShaderMode;
	DWORD m_dwCharMode;
	DWORD m_dwPaperMode;
	DWORD m_dwBackMode;

	D3DDEVICE m_Device;
	
////	게임포지 국가별 세팅
	void ReadURLFile();
	void ReadTextFile();
	void ReadDisclaimerFile();
	BYTE SetDisclaimer(BYTE bDisclaimer);

	CString		m_strDisclaimer;
	BYTE		m_bDisclaimer;

////	모듈가드
private:
	static DWORD WINAPI _MPThread( LPVOID lpParam);
	void MPThread();
	void SetHWND( HWND hWND);
	void SetRUN( BYTE bRUN);
	void HackMSG();
	void PostQUIT();
	BYTE GetRUN();

protected:
	CTModuleProtector m_vModuleGuard;

	CRITICAL_SECTION m_cs;
	HANDLE m_hMP;
	HWND m_hWND;
	BYTE m_bRUN;

public:
	BYTE m_bHACK;
};
