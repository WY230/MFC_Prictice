
// MFC_WinSysInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_WinSysInfo.h"
#include "MFC_WinSysInfoDlg.h"
#include "afxdialogex.h"
#include"TabSheet.h"
#include"DLG1.h"
#include"DLG2.h"
#include"DLG3.h"
#include"CSoftWare.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCWinSysInfoDlg 对话框



CMFCWinSysInfoDlg::CMFCWinSysInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_WINSYSINFO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCWinSysInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CMFCWinSysInfoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCWinSysInfoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCWinSysInfoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCWinSysInfoDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCWinSysInfoDlg 消息处理程序

BOOL CMFCWinSysInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tab.AddPage(TEXT("系统信息"), &dlg1, IDD_DLG1);
	m_tab.AddPage(TEXT("移动存储信息"), &dlg2, IDD_DLG2);
	m_tab.AddPage(TEXT("Rar信息"), &dlg3, IDD_DLG3);
	m_tab.Show();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCWinSysInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCWinSysInfoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCWinSysInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCWinSysInfoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	dlg1.m_list1.DeleteAllItems();
	while (dlg1.m_list1.GetHeaderCtrl()->GetItemCount() > 0)
	{
		dlg1.m_list1.DeleteColumn(0);
	}
	dlg1.OnInitDialog();
	dlg2.OnInitDialog();
	dlg3.m_list2.DeleteAllItems();
	while (dlg3.m_list2.GetHeaderCtrl()->GetItemCount() > 0)
	{
		dlg3.m_list2.DeleteColumn(0);
	}
	dlg3.OnInitDialog();
}

void CMFCWinSysInfoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	SoftwareInfo = dlg1.Getsoftwareinfo();
	MemoryInfo = dlg3.GetMemoryInfo();
	UINT i;
	i = MessageBox(_T("是否全部保存"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		SaveSoftWareInofo();
		SaveMemoryInofo();
		SaveSystemInofo();
		isSaved = true;
		MessageBox(_T("保存成功！"), _T("提示"));
	}
}

bool CMFCWinSysInfoDlg::SaveSoftWareInofo()
{
	fstream out("SoftWareInfo.csv", ios::out);
	if (out.is_open())
	{
		out << "软件名称" << ",,,," << "版本号" << ",,,," << "生产厂商" << ",,,," << "安装路径" << endl;
		int num = SoftwareInfo.size();
		for (int i = 0; i < num; i++)
		{
			out << SoftwareInfo[i].m_softwarename << ",,,," << SoftwareInfo[i].m_version << ",,,," << SoftwareInfo[i].m_productor << ",,,,"
				<< SoftwareInfo[i].m_install <<endl;
		}
		out.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool CMFCWinSysInfoDlg::SaveMemoryInofo()
{
	fstream out("MemoryInfo.csv", ios::out);
	if (out.is_open())
	{
		out << "盘符" << ",," << "磁盘类型" << ",," << "磁盘名称" << ",," << "文件系统"
			<< ",," << "全部容量" << ",," << "可用容量" << endl;
		int num = MemoryInfo.size();
		for (int i = 0; i < num; i++)
		{
			out << MemoryInfo[i].m_symbol << ",," << MemoryInfo[i].m_type << ",," << MemoryInfo[i].m_name<< ",,"
				<< MemoryInfo[i].m_filesystem << ",," << MemoryInfo[i].m_totalmemory << ",," << MemoryInfo[i].m_availmemory << endl;
		}
		out.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool CMFCWinSysInfoDlg::SaveSystemInofo()
{
	fstream out("SystemInfo.csv", ios::out);
	if (out.is_open())
	{
		out << "windows名称：" <<",," << CW2A(dlg2.m_wn).m_psz << endl;
		out << "用户名：" << ",," <<CW2A(dlg2.m_un).m_psz<< endl;
		out << "系统所在文件夹：" << ",," <<CW2A(dlg2.m_sd).m_psz<< endl;
		out << "CPU名称：" << ",," <<CW2A(dlg2.m_cn).m_psz<< endl;
		out << "CPU速度：" << ",," <<CW2A(dlg2.m_cs).m_psz<< endl;
		out << "CPU厂商信息：" << ",," <<CW2A(dlg2.m_ci).m_psz<< endl;
		out << "主内存：" << ",," <<CW2A(dlg2.m_gm).m_psz<< endl;
		out << "主内存可使用量：" << ",," <<CW2A(dlg2.m_eum).m_psz << endl;
		out << "虚拟内存：" << ",," <<CW2A(dlg2.m_vm).m_psz<< endl;
		out << "虚拟内存可使用量:" << ",," <<CW2A(dlg2.m_euvm).m_psz << endl;
		out.close();
		return true;
	}
	else
	{
		return false;
	}
}
void CMFCWinSysInfoDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isSaved == false)
	{
		UINT i;
		i = MessageBox(_T("是否全部保存后退出？"),_T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			SoftwareInfo = dlg1.Getsoftwareinfo();
			MemoryInfo = dlg3.GetMemoryInfo();
			SaveSoftWareInofo();
			SaveSystemInofo();
			SaveMemoryInofo();
			MessageBox(_T("保存成功！"), _T("提示"));
			exit(0);
		}	
	}
	exit(0);
}
