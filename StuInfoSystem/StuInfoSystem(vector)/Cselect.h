#pragma once
#include "afxdialogex.h"


// Cselect 对话框

class Cselect : public CDialogEx
{
	DECLARE_DYNAMIC(Cselect)

public:
	Cselect(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cselect();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIgSelect };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_select_name;
};
