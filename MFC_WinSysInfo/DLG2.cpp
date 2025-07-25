// DLG2.cpp: 实现文件
//

#include "pch.h"
#include "MFC_WinSysInfo.h"
#include "afxdialogex.h"
#include "DLG2.h"


// DLG2 对话框

IMPLEMENT_DYNAMIC(DLG2, CDialogEx)

DLG2::DLG2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG2, pParent)
	, m_wn(_T(""))
	, m_un(_T(""))
	, m_sd(_T(""))
	, m_cn(_T(""))
	, m_cs(_T(""))
	, m_ci(_T(""))
	, m_gm(_T(""))
	, m_eum(_T(""))
	, m_vm(_T(""))
	, m_euvm(_T(""))
{

}

DLG2::~DLG2()
{
}

void DLG2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WName, m_wn);
	DDX_Text(pDX, IDC_UserName, m_un);
	DDX_Text(pDX, IDC_SystemDirectory, m_sd);
	DDX_Text(pDX, IDC_CPUname, m_cn);
	DDX_Text(pDX, IDC_CPUspeed, m_cs);
	DDX_Text(pDX, IDC_CPUinfo, m_ci);
	DDX_Text(pDX, IDC_GlobalMemory, m_gm);
	DDX_Text(pDX, IDC_EnuseMemory, m_eum);
	DDX_Text(pDX, IDC_VirtualMemory, m_vm);
	DDX_Text(pDX, IDC_EnuseVMemory, m_euvm);
}


BEGIN_MESSAGE_MAP(DLG2, CDialogEx)
END_MESSAGE_MAP()
BOOL DLG2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	TCHAR computername(MAX_COMPUTERNAME_LENGTH + 1);
	return TRUE;
}

// DLG2 消息处理程序
