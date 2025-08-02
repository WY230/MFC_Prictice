#pragma once
#include "afxdialogex.h"


// CTEMP 对话框

class CTEMP : public CDialogEx
{
	DECLARE_DYNAMIC(CTEMP)

public:
	CTEMP(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTEMP();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgTEMP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_strtemp;
	CStatic m_picEMP;
};
