// CADD.cpp: 实现文件
//

#include "pch.h"
#include "StuInfoSystem.h"
#include "afxdialogex.h"
#include "CADD.h"
#include"StuInfo.h"
#include"StuInfoSystemDlg.h"


// CADD 对话框

IMPLEMENT_DYNAMIC(CADD, CDialogEx)

CADD::CADD(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIgadd, pParent)
	, m_strname(_T(""))
	, m_strclass(_T(""))
	, m_strgender(_T(""))
	, m_strsocre1(_T(""))
	, m_strsocre2(_T(""))
	, m_strscore3(_T(""))
{

}

CADD::~CADD()
{
}

void CADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_strname);
	DDX_Text(pDX, IDC_EDIT3, m_strclass);
	DDX_Text(pDX, IDC_EDIT4, m_strgender);
	DDX_Text(pDX, IDC_EDIT5, m_strsocre1);
	DDX_Text(pDX, IDC_EDIT6, m_strsocre2);
	DDX_Text(pDX, IDC_EDIT7, m_strscore3);
}


BEGIN_MESSAGE_MAP(CADD, CDialogEx)
	ON_BN_CLICKED(IDOK, &CADD::OnBnClickedOk)
END_MESSAGE_MAP()


// CADD 消息处理程序

void CADD::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_strname == TEXT("") || m_strgender == TEXT(""))
	{
		MessageBox(TEXT("您有输入为空"),TEXT("提示"));
		return;
	}
	if (_ttof(m_strsocre1) < 0 || _ttof(m_strsocre1) > 100 || _ttof(m_strsocre2) < 0 || _ttof(m_strsocre2) > 100 ||
		_ttof(m_strscore3) < 0 || _ttof(m_strscore3) > 100)
	{
		MessageBox(TEXT("您的成绩输入有误"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}
