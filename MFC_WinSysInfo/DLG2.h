#pragma once
#include "afxdialogex.h"


// DLG2 对话框

class DLG2 : public CDialogEx
{
	DECLARE_DYNAMIC(DLG2)

public:
	DLG2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG2();
	virtual BOOL OnInitDialog();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_wn;
	CString m_un;
	CString m_sd;
	CString m_cn;
	CString m_cs;
	CString m_ci;
	CString m_gm;
	CString m_eum;
	CString m_vm;
	CString m_euvm;
};
