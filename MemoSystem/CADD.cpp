// CADD.cpp: 实现文件
//

#include "pch.h"
#include "MemoSystem.h"
#include "afxdialogex.h"
#include "CADD.h"


// CADD 对话框

IMPLEMENT_DYNAMIC(CADD, CDialogEx)

CADD::CADD(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgAdd, pParent)
	, m_strid(_T(""))
	, m_strlastname(_T(""))
	, m_strfirstname(_T(""))
	, m_strdate(_T(""))
	, m_strcontent(_T(""))
{

}

CADD::~CADD()
{
}

void CADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_strid);
	DDX_Text(pDX, IDC_EDIT1, m_strlastname);
	DDX_Text(pDX, IDC_EDIT6, m_strfirstname);
	DDX_Text(pDX, IDC_EDIT4, m_strdate);
	DDX_Text(pDX, IDC_EDIT5, m_strcontent);
}


BEGIN_MESSAGE_MAP(CADD, CDialogEx)
	ON_BN_CLICKED(IDOK, &CADD::OnBnClickedOk)
END_MESSAGE_MAP()


// CADD 消息处理程序

void CADD::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_strid == _T("") || m_strlastname == _T("") || m_strfirstname == _T("") || m_strdate == _T("") || m_strcontent == _T(""))
	{
		MessageBox(_T("您有输入为空"), _T("提示"));
		return;
	}
	CDialogEx::OnOK();
}
