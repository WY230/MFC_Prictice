#pragma once
#include "afxdialogex.h"
#include"pch.h"

// CCPU 对话框

class CCPU : public CDialogEx
{
	DECLARE_DYNAMIC(CCPU)

public:
	CCPU(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCPU();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgCPU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void UpdateCPU();
	void DrawCPUusage();
private:
	CString m_strcpu;
	ULONGLONG lastidle = 0;
	ULONGLONG lastkernel = 0;
	ULONGLONG lastuser = 0;
	double usage = 0;
	BOOL isFirstCall = true;
	vector<double> m_cpuhistory;
	CStatic m_picCPU;
};
