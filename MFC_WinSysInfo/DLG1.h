#pragma once
#include "afxdialogex.h"


// DLG1 对话框

class DLG1 : public CDialogEx
{
	DECLARE_DYNAMIC(DLG1)

public:
	DLG1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG1();
	virtual BOOL OnInitDialog();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list1;
};
