
// MemoSystemDlg.h: 头文件
//

#pragma once
#include"CInterface.h"
#include"CADD.h"
#include"CUpdate.h"

// CMemoSystemDlg 对话框
class CMemoSystemDlg : public CDialogEx
{
// 构造
public:
	CMemoSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMOSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	bool isSaved = false;
	afx_msg void OnBnClickedButton2();
	CInterface m_interface;
	CString strfilepath;
	CADD dlgadd;
	CUpdate dlgupdate;
	void Display();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	CString m_strselectid;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
