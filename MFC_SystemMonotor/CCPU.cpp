// CCPU.cpp: 实现文件
//

#include "pch.h"
#include "MFC_SystemMonotor.h"
#include "afxdialogex.h"
#include "CCPU.h"


// CCPU 对话框

IMPLEMENT_DYNAMIC(CCPU, CDialogEx)

CCPU::CCPU(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgCPU, pParent)
	, m_strcpu(_T(""))
{

}

CCPU::~CCPU()
{
}

void CCPU::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_TEXT_CPU, m_strcpu);
    DDX_Control(pDX, IDC_GRAPH_CPU, m_picCPU);
}


BEGIN_MESSAGE_MAP(CCPU, CDialogEx)
END_MESSAGE_MAP()



// CCPU 消息处理程序

void CCPU::UpdateCPU()
{
    FILETIME idletime, kerneltime, usertime;
    if (!GetSystemTimes(&idletime, &kerneltime, &usertime)) {
        TRACE(_T("GetSystemTimes failed"));
        return; // 获取失败直接返回
    }

    ULONGLONG idle = ((ULONGLONG)idletime.dwHighDateTime << 32) | idletime.dwLowDateTime;
    ULONGLONG kernel = ((ULONGLONG)kerneltime.dwHighDateTime << 32) | kerneltime.dwLowDateTime;
    ULONGLONG user = ((ULONGLONG)usertime.dwHighDateTime << 32) | usertime.dwLowDateTime;

    if (isFirstCall) 
    {
        lastidle = idle;
        lastkernel = kernel;
        lastuser = user;
        isFirstCall = FALSE;
        return; // 首次调用不计算
    }

    ULONGLONG sys = (kernel - lastkernel) + (user - lastuser);
    ULONGLONG idlediff = idle - lastidle;

    // 更新记录值
    lastidle = idle;
    lastkernel = kernel;
    lastuser = user;

    // 安全计算
    if (sys == 0)
    {
        usage = 0.0;
    }
    else 
    {
        double calc = 1.0 - ((double)idlediff / sys);
        usage = max(0.0, min(100.0, calc * 100.0)); // 限制在0-100范围内
    }
    TRACE(_T("idle=%llu, kernel=%llu, user=%llu, lastidle=%llu, lastkernel=%llu, lastuser=%llu,sys=%llu, idlediff=%llu, usage=%.1f%%\n"),
        idle, kernel, user,lastidle,lastkernel,lastuser, sys, idlediff, usage);
    m_strcpu.Format(_T("%.1f%%"), usage);
    m_cpuhistory.push_back(usage);
    if (m_cpuhistory.size() > MAX_POINT) 
    {
        m_cpuhistory.erase(m_cpuhistory.begin());
    }
    DrawCPUusage();
    UpdateData(FALSE);
   
}

void CCPU::DrawCPUusage()
{
    CDC* pDC = m_picCPU.GetDC();
    if (pDC == NULL)
    {
        return;
    }
    CRect rect;
    m_picCPU.GetClientRect(&rect);
    pDC->FillSolidRect(rect,RGB(255,255,255));
    pDC->MoveTo(rect.left,rect.bottom);
    pDC->LineTo(rect.right,rect.bottom);
    pDC->LineTo(rect.right, rect.top);
    if (m_cpuhistory.size() < 2)
    {
        return;
    }
    int margin = 5;
    int width = rect.Width () - margin * 2;
    int height = rect.Height() - margin * 2;
    int pointcount = (int)m_cpuhistory.size();
    double Xstep = (double)width / (MAX_POINT-1);
    CPen pen(PS_SOLID,2,RGB(0,100,200));
    CPen* pOldPen = pDC->SelectObject(&pen);
    for (int i = 1; i < pointcount; i++)
    {
        int x1 = margin + (int)(i - 1)*Xstep;
        int x2 = margin + (int)i * Xstep;
        int y1 = rect.bottom-margin-(int)(m_cpuhistory[i-1]/100*height);
        int y2 = rect.bottom - margin - (int)(m_cpuhistory[i ] /100* height);
        pDC->MoveTo(x1,y1);
        pDC->LineTo(x2,y2); 
    }
    pDC->SelectObject(pOldPen);
    ReleaseDC(pDC);
}

BOOL CCPU::OnInitDialog()
{
	CDialogEx::OnInitDialog();
    UpdateCPU();
    return TRUE;
}
