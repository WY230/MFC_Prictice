#pragma once
#include "afxdialogex.h"


// Cupdate 对话框

class Cupdate : public CDialogEx
{
	DECLARE_DYNAMIC(Cupdate)

public:
	Cupdate(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cupdate();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIgupdate };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_newname;
	CString m_newgender;
	CString m_newclass;
	CString m_newscore1;
	CString m_newscore2;
	CString m_newscore3;
	afx_msg void OnBnClickedOk();
};
