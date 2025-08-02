// CMEM.cpp: 实现文件
//

#include "pch.h"
#include "MFC_SystemMonotor.h"
#include "afxdialogex.h"
#include "CMEM.h"


// CMEM 对话框

IMPLEMENT_DYNAMIC(CMEM, CDialogEx)

CMEM::CMEM(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgMEM, pParent)
	, m_strmem(_T(""))
{

}

CMEM::~CMEM()
{
}

void CMEM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT_MEM, m_strmem);
	DDX_Control(pDX, IDC_GRAPH_MEM, m_picMEM);
}


BEGIN_MESSAGE_MAP(CMEM, CDialogEx)
END_MESSAGE_MAP()


// CMEM 消息处理程序

BOOL CMEM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	UpdateMEM();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CMEM::UpdateMEM()
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	if (GlobalMemoryStatusEx(&status))
	{
		m_strmem.Format(_T("%u%%"), status.dwMemoryLoad);
	}
	m_memhistory.push_back(status.dwMemoryLoad);
	if (m_memhistory.size()> MAX_POINT)
	{
		m_memhistory.erase(m_memhistory.begin());
	}
	DrawMEMusage();
	UpdateData(FALSE);
}

void CMEM::DrawMEMusage()
{
	CDC* pDC = m_picMEM.GetDC();
	if (pDC == NULL)
	{
		return;
	}
	CRect rect;
	m_picMEM.GetClientRect(&rect);
	pDC->FillSolidRect(rect,RGB(255,255,255));
	pDC->MoveTo(rect.left,rect.bottom);
	pDC->LineTo(rect.right,rect.bottom);
	pDC->LineTo(rect.left,rect.bottom);
	if (m_memhistory.size() < 2)
	{
		return;
	}
	int margin = 5;
	int width = rect.Width() - margin * 2;
	int height = rect.Height() - margin * 2;
	int pointcount = (int)m_memhistory.size();
	double Xstep = (double)width / (MAX_POINT - 1);
	CPen pen (PS_SOLID,2,RGB(0,100,200));
	CPen* poldpen = pDC->SelectObject(&pen);
	for (int i=1;i<pointcount;i++)
	{
		int x1 = margin + (i - 1) * Xstep;
		int x2 = margin + i * Xstep;
		int y1 = rect.Height() - margin - (m_memhistory[i-1]/100 * height);
		int y2 = rect.Height() - margin - (m_memhistory[i ]/100 * height);
		pDC->MoveTo(x1,y1);
		pDC->LineTo(x2, y2);
	}
	pDC->SelectObject(poldpen);
	ReleaseDC(pDC);
}
