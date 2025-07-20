
// MFC_Math_Exercise_GeneratorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_Math_Exercise_Generator.h"
#include "MFC_Math_Exercise_GeneratorDlg.h"
#include "afxdialogex.h"

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


// CMFC_Math_Exercise_GeneratorDlg 对话框



CMFC_Math_Exercise_GeneratorDlg::CMFC_Math_Exercise_GeneratorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY6__DIALOG, pParent)
	, m_qs1(_T(""))
	, m_qs2(_T(""))
	, m_qs3(_T(""))
	, m_qs4(_T(""))
	, m_qs5(_T(""))
	, m_qs6(_T(""))
	, m_qs7(_T(""))
	, m_qs8(_T(""))
	, m_qs9(_T(""))
	, m_qs10(_T(""))
	, m_qs12(_T(""))
	, m_qs11(_T(""))
	, m_qs13(_T(""))
	, m_qs14(_T(""))
	, m_qs15(_T(""))
	, m_qs16(_T(""))
	, m_qs17(_T(""))
	, m_qs18(_T(""))
	, m_qs19(_T(""))
	, m_qs20(_T(""))
	, m_as1(_T(""))
	, m_as2(_T(""))
	, m_as3(_T(""))
	, m_as4(_T(""))
	, m_as5(_T(""))
	, m_as6(_T(""))
	, m_as7(_T(""))
	, m_as8(_T(""))
	, m_as9(_T(""))
	, m_as10(_T(""))
	, m_as11(_T(""))
	, m_as12(_T(""))
	, m_as13(_T(""))
	, m_as14(_T(""))
	, m_as15(_T(""))
	, m_as16(_T(""))
	, m_as17(_T(""))
	, m_as18(_T(""))
	, m_as19(_T(""))
	, m_as20(_T(""))
	, m_tf1(_T(""))
	, m_tf2(_T(""))
	, m_tf3(_T(""))
	, m_tf4(_T(""))
	, m_tf5(_T(""))
	, m_tf6(_T(""))
	, m_tf7(_T(""))
	, m_tf8(_T(""))
	, m_tf9(_T(""))
	, m_tf10(_T(""))
	, m_tf11(_T(""))
	, m_tf12(_T(""))
	, m_tf13(_T(""))
	, m_tf14(_T(""))
	, m_tf15(_T(""))
	, m_tf16(_T(""))
	, m_tf17(_T(""))
	, m_tf18(_T(""))
	, m_tf19(_T(""))
	, m_tf20(_T(""))
	, m_score(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_Math_Exercise_GeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_QS1, m_qs1);
	DDX_Text(pDX, IDC_QS2, m_qs2);
	DDX_Text(pDX, IDC_QS3, m_qs3);
	DDX_Text(pDX, IDC_QS4, m_qs4);
	DDX_Text(pDX, IDC_QS5, m_qs5);
	DDX_Text(pDX, IDC_QS6, m_qs6);
	DDX_Text(pDX, IDC_QS7, m_qs7);
	DDX_Text(pDX, IDC_QS8, m_qs8);
	DDX_Text(pDX, IDC_QS9, m_qs9);
	DDX_Text(pDX, IDC_QS10, m_qs10);
	DDX_Text(pDX, IDC_QS12, m_qs12);
	DDX_Text(pDX, IDC_QS11, m_qs11);
	DDX_Text(pDX, IDC_QS13, m_qs13);
	DDX_Text(pDX, IDC_QS14, m_qs14);
	DDX_Text(pDX, IDC_QS15, m_qs15);
	DDX_Text(pDX, IDC_QS16, m_qs16);
	DDX_Text(pDX, IDC_QS17, m_qs17);
	DDX_Text(pDX, IDC_QS18, m_qs18);
	DDX_Text(pDX, IDC_QS19, m_qs19);
	DDX_Text(pDX, IDC_QS20, m_qs20);
	DDX_Text(pDX, IDC_AS1, m_as1);
	DDX_Text(pDX, IDC_AS2, m_as2);
	DDX_Text(pDX, IDC_AS3, m_as3);
	DDX_Text(pDX, IDC_AS4, m_as4);
	DDX_Text(pDX, IDC_AS5, m_as5);
	DDX_Text(pDX, IDC_AS6, m_as6);
	DDX_Text(pDX, IDC_AS7, m_as7);
	DDX_Text(pDX, IDC_AS8, m_as8);
	DDX_Text(pDX, IDC_AS9, m_as9);
	DDX_Text(pDX, IDC_AS10, m_as10);
	DDX_Text(pDX, IDC_AS11, m_as11);
	DDX_Text(pDX, IDC_AS12, m_as12);
	DDX_Text(pDX, IDC_AS13, m_as13);
	DDX_Text(pDX, IDC_AS14, m_as14);
	DDX_Text(pDX, IDC_AS15, m_as15);
	DDX_Text(pDX, IDC_AS16, m_as16);
	DDX_Text(pDX, IDC_AS17, m_as17);
	DDX_Text(pDX, IDC_AS18, m_as18);
	DDX_Text(pDX, IDC_AS19, m_as19);
	DDX_Text(pDX, IDC_AS20, m_as20);
	DDX_Text(pDX, IDC_TF1, m_tf1);
	DDX_Text(pDX, IDC_TF2, m_tf2);
	DDX_Text(pDX, IDC_TF3, m_tf3);
	DDX_Text(pDX, IDC_TF4, m_tf4);
	DDX_Text(pDX, IDC_TF5, m_tf5);
	DDX_Text(pDX, IDC_TF6, m_tf6);
	DDX_Text(pDX, IDC_TF7, m_tf7);
	DDX_Text(pDX, IDC_TF8, m_tf8);
	DDX_Text(pDX, IDC_TF9, m_tf9);
	DDX_Text(pDX, IDC_TF10, m_tf10);
	DDX_Text(pDX, IDC_TF11, m_tf11);
	DDX_Text(pDX, IDC_TF12, m_tf12);
	DDX_Text(pDX, IDC_TF13, m_tf13);
	DDX_Text(pDX, IDC_TF14, m_tf14);
	DDX_Text(pDX, IDC_TF15, m_tf15);
	DDX_Text(pDX, IDC_TF16, m_tf16);
	DDX_Text(pDX, IDC_TF17, m_tf17);
	DDX_Text(pDX, IDC_TF18, m_tf18);
	DDX_Text(pDX, IDC_TF19, m_tf19);
	DDX_Text(pDX, IDC_TF20, m_tf20);
	DDX_Text(pDX, IDC_SCORE, m_score);
}

BEGIN_MESSAGE_MAP(CMFC_Math_Exercise_GeneratorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFC_Math_Exercise_GeneratorDlg 消息处理程序

BOOL CMFC_Math_Exercise_GeneratorDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_Math_Exercise_GeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_Math_Exercise_GeneratorDlg::OnPaint()
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
HCURSOR CMFC_Math_Exercise_GeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

