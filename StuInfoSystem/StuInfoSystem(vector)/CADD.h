#pragma once
#include "afxdialogex.h"


// CADD 对话框

class CADD : public CDialogEx
{
	DECLARE_DYNAMIC(CADD)

public:
	CADD(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CADD();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIgadd };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()	
public:
	afx_msg void OnBnClickedOk();
	CString m_strname;
	CString m_strclass;
	CString m_strgender;
	CString m_strsocre1;
	CString m_strsocre2;
	CString m_strscore3;
};
