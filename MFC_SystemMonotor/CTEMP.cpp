// CTEMP.cpp: 实现文件
//

#include "pch.h"
#include "MFC_SystemMonotor.h"
#include "afxdialogex.h"
#include "CTEMP.h"


// CTEMP 对话框

IMPLEMENT_DYNAMIC(CTEMP, CDialogEx)

CTEMP::CTEMP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgTEMP, pParent)
	, m_strtemp(_T(""))
{

}

CTEMP::~CTEMP()
{
}

void CTEMP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT_TEMP, m_strtemp);
	DDX_Control(pDX, IDC_GRAPH_TEMP, m_picEMP);
}


BEGIN_MESSAGE_MAP(CTEMP, CDialogEx)
END_MESSAGE_MAP()


// CTEMP 消息处理程序
