
// MFC_SystemMonotorDlg.h: 头文件
//

#pragma once
#include"CCPU.h"
#include"CMEM.h"
#include"CTEMP.h"
#include"TabSheet.h"
#include "afxdialogex.h"


// CMFCSystemMonotorDlg 对话框
class CMFCSystemMonotorDlg : public CDialogEx
{
// 构造
public:
	CMFCSystemMonotorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_SYSTEMMONOTOR_DIALOG };
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
	CTabSheet m_tab;
	CCPU m_cpu;
	CMEM m_mem;
	CTEMP m_temp;
	//DWORD lastrefreshtime = 0;
	virtual void OnTimer(UINT_PTR nIDEvent);
};
