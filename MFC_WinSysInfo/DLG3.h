#pragma once
#include "afxdialogex.h"


// DLG3 对话框

class DLG3 : public CDialogEx
{
	DECLARE_DYNAMIC(DLG3)

public:
	DLG3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLG3();
	virtual BOOL OnInitDialog();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list2;
};
