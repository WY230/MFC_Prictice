#pragma once
#include "afxdialogex.h"


// DLG3 对话框

class DLG3 : public CDialogEx
{
	DECLARE_DYNAMIC(DLG3)

public:
	DLG3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG3();
	virtual BOOL OnInitDialog();
	void ShowDriveInfo();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list2;
	CString dlg3_C;
	CString dlg3_D;
	int index=0;
};
