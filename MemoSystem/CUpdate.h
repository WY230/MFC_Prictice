#pragma once
#include "afxdialogex.h"


// CUpdate 对话框

class CUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdate)

public:
	CUpdate(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CUpdate();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIgUpdate };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_newid;
	CString m_newlastname;
	CString m_newfirstname;
	CString m_newdate;
	CString m_newcontect;
	afx_msg void OnBnClickedOk();
};
