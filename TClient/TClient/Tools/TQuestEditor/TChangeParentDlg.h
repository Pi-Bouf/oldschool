#pragma once


// CTChangeParentDlg 대화 상자입니다.

class CTChangeParentDlg : public CDialog
{
	DECLARE_DYNAMIC(CTChangeParentDlg)

public:
	CTChangeParentDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTChangeParentDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CHGPARENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	DWORD m_dwParentID;
};
