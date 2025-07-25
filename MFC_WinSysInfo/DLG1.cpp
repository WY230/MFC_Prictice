// DLG1.cpp: 实现文件
//

#include "pch.h"
#include "MFC_WinSysInfo.h"
#include "afxdialogex.h"
#include "DLG1.h"


// DLG1 对话框

IMPLEMENT_DYNAMIC(DLG1, CDialogEx)

DLG1::DLG1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG1, pParent)
{

}

DLG1::~DLG1()
{
}

void DLG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(DLG1, CDialogEx)
END_MESSAGE_MAP()
BOOL DLG1::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list1.InsertColumn(1,_T("软件名称"),LVCFMT_LEFT,200);
	m_list1.InsertColumn(2, _T("版本号"), LVCFMT_LEFT, 200);
	m_list1.InsertColumn(3, _T("生产厂商"), LVCFMT_LEFT, 200);
	m_list1.InsertColumn(4, _T("安装路径"), LVCFMT_LEFT, 200);
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT || LVS_EX_GRIDLINES);
	return TRUE;
}

// DLG1 消息处理程序
