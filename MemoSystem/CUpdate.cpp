// CUpdate.cpp: 实现文件
//

#include "pch.h"
#include "MemoSystem.h"
#include "afxdialogex.h"
#include "CUpdate.h"


// CUpdate 对话框

IMPLEMENT_DYNAMIC(CUpdate, CDialogEx)

CUpdate::CUpdate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIgUpdate, pParent)
	, m_newid(_T(""))
	, m_newlastname(_T(""))
	, m_newfirstname(_T(""))
	, m_newdate(_T(""))
	, m_newcontect(_T(""))
{

}

CUpdate::~CUpdate()
{
}

void CUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_newid);
	DDX_Text(pDX, IDC_EDIT2, m_newlastname);
	DDX_Text(pDX, IDC_EDIT3, m_newfirstname);
	DDX_Text(pDX, IDC_EDIT4, m_newdate);
	DDX_Text(pDX, IDC_EDIT5, m_newcontect);
}


BEGIN_MESSAGE_MAP(CUpdate, CDialogEx)
	ON_BN_CLICKED(IDOK, &CUpdate::OnBnClickedOk)
END_MESSAGE_MAP()


// CUpdate 消息处理程序

void CUpdate::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_newid == _T("") || m_newlastname == _T("") || m_newfirstname == _T("") ||
		m_newdate == _T("") || m_newcontect == _T(""))
	{
		MessageBox(_T("您有输入为空"), _T("提示"));
		return;
	}
	CDialogEx::OnOK();
}
