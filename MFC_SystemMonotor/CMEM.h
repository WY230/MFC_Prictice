#pragma once
#include "afxdialogex.h"


// CMEM 对话框

class CMEM : public CDialogEx
{
	DECLARE_DYNAMIC(CMEM)

public:
	CMEM(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMEM();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgMEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_strmem;
public:
	virtual BOOL OnInitDialog();
	void UpdateMEM();
	void DrawMEMusage();
	vector<double> m_memhistory;
	CStatic m_picMEM;
};
