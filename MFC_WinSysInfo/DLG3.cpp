// DLG3.cpp: 实现文件
//

#include "pch.h"
#include "MFC_WinSysInfo.h"
#include "afxdialogex.h"
#include "DLG3.h"


// DLG3 对话框

IMPLEMENT_DYNAMIC(DLG3, CDialogEx)

DLG3::DLG3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG3, pParent)
{

}

DLG3::~DLG3()
{
}

void DLG3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list2);
}


BEGIN_MESSAGE_MAP(DLG3, CDialogEx)

END_MESSAGE_MAP()

BOOL DLG3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list2.InsertColumn(1, _T("盘符"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(2, _T("磁盘类型"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(3, _T("磁盘名称"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(4, _T("文件系统"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(5, _T("全部容量"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(6, _T("可用容量"), LVCFMT_LEFT, 200);
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT || LVS_EX_GRIDLINES);
	return TRUE;
}
// DLG3 消息处理程序

