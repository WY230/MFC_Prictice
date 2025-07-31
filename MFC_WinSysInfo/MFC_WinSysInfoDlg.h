
// MFC_WinSysInfoDlg.h: 头文件
//

#pragma once
#include"TabSheet.h"
#include"DLG1.h"
#include"DLG2.h"
#include"DLG3.h"

// CMFCWinSysInfoDlg 对话框
class CMFCWinSysInfoDlg : public CDialogEx
{
// 构造
public:
	CMFCWinSysInfoDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_WINSYSINFO_DIALOG };
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
private:
	CTabSheet m_tab;
	DLG1 dlg1;
	DLG2 dlg2;
	DLG3 dlg3;
public:
	afx_msg void OnBnClickedButton1();

	afx_msg void OnBnClickedButton2();
};
