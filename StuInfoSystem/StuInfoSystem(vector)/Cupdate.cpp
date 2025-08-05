// Cupdate.cpp: 实现文件
//

#include "pch.h"
#include "StuInfoSystem.h"
#include "afxdialogex.h"
#include "Cupdate.h"


// Cupdate 对话框

IMPLEMENT_DYNAMIC(Cupdate, CDialogEx)

Cupdate::Cupdate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIgupdate, pParent)
	, m_newname(_T(""))
	, m_newclass(_T(""))
	, m_newscore1(_T(""))
	, m_newscore2(_T(""))
	, m_newscore3(_T(""))
{

}

Cupdate::~Cupdate()
{
}

void Cupdate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_newname);
	DDX_Text(pDX, IDC_EDIT2, m_newgender);
	DDX_Text(pDX, IDC_EDIT3, m_newclass);
	DDX_Text(pDX, IDC_EDIT4, m_newscore1);
	DDX_Text(pDX, IDC_EDIT5, m_newscore2);
	DDX_Text(pDX, IDC_EDIT6, m_newscore3);
}


BEGIN_MESSAGE_MAP(Cupdate, CDialogEx)
	ON_BN_CLICKED(IDOK, &Cupdate::OnBnClickedOk)
END_MESSAGE_MAP()


// Cupdate 消息处理程序

void Cupdate::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_newname == _T("") || m_newgender == _T(""))
	{
		MessageBox(_T("您的输入为空！"), _T("提示"));
		return;
	}
	else if (_ttof(m_newscore1) < 0 || _ttof(m_newscore1) > 100 || _ttof(m_newscore2) < 0 || _ttof(m_newscore2) > 100
		|| _ttof(m_newscore3) < 0 || _ttof(m_newscore3) > 100)
	{
		MessageBox(_T("您的输入有误！"), _T("提示"));
		return;
	}
	CDialogEx::OnOK();
}
