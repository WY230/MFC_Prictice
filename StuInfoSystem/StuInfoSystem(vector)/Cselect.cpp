// Cselect.cpp: 实现文件
//

#include "pch.h"
#include "StuInfoSystem.h"
#include "afxdialogex.h"
#include "Cselect.h"


// Cselect 对话框

IMPLEMENT_DYNAMIC(Cselect, CDialogEx)

Cselect::Cselect(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIgSelect, pParent)
	, m_select_name(_T(""))
{

}

Cselect::~Cselect()
{
}

void Cselect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_select_name);
}


BEGIN_MESSAGE_MAP(Cselect, CDialogEx)
	ON_BN_CLICKED(IDOK, &Cselect::OnBnClickedOk)
END_MESSAGE_MAP()


// Cselect 消息处理程序

void Cselect::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_select_name == _T(""))
	{
		MessageBox(_T("您的输入为空!"), _T("提示"));
		return;
	}
	CDialogEx::OnOK();
}
