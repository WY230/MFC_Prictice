
// MFC_Math_Exercise_GeneratorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_Math_Exercise_Generator.h"
#include "MFC_Math_Exercise_GeneratorDlg.h"
#include "afxdialogex.h"
#include <ctime>  // 包含 time() 函数


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
const int CMFC_Math_Exercise_GeneratorDlg::IDC_QS_ARRAY[20] = {
	IDC_QS1, IDC_QS2, IDC_QS3, IDC_QS4, IDC_QS5,
	IDC_QS6, IDC_QS7, IDC_QS8, IDC_QS9, IDC_QS10,
	IDC_QS11, IDC_QS12, IDC_QS13, IDC_QS14, IDC_QS15,
	IDC_QS16, IDC_QS17, IDC_QS18, IDC_QS19, IDC_QS20
};
const int CMFC_Math_Exercise_GeneratorDlg::IDC_AS_ARRAY[20] = {
	IDC_AS1, IDC_AS2, IDC_AS3, IDC_AS4, IDC_AS5,
	IDC_AS6, IDC_AS7, IDC_AS8, IDC_AS9, IDC_AS10,
	IDC_AS11, IDC_AS12, IDC_AS13, IDC_AS14, IDC_AS15,
	IDC_AS16, IDC_AS17, IDC_AS18, IDC_AS19, IDC_AS20
};
const int CMFC_Math_Exercise_GeneratorDlg::IDC_TF_ARRAY[20] = {
	IDC_TF1, IDC_TF2, IDC_TF3, IDC_TF4, IDC_TF5,
	IDC_TF6, IDC_TF7, IDC_TF8, IDC_TF9, IDC_TF10,
	IDC_TF11, IDC_TF12, IDC_TF13, IDC_TF14, IDC_TF15,
	IDC_TF16, IDC_TF17, IDC_TF18, IDC_TF19, IDC_TF20
};
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
	: CDialogEx(IDD_MY6__DIALOG, pParent),m_score(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_Math_Exercise_GeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	for (int i = 0; i < 20; i++)
	{
		DDX_Text(pDX, IDC_QS_ARRAY[i], m_qs[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		DDX_Text(pDX, IDC_AS_ARRAY[i], m_as[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		DDX_Text(pDX, IDC_TF_ARRAY[i], m_tf[i]);
	}
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
	srand(time(NULL));
	Createmyqs();
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
//随机生成2和3作为每道题目的运算次数
int CMFC_Math_Exercise_GeneratorDlg::Createtime()
{
	
	return 2 + rand() % 2;
}
//生成随机运算符
void CMFC_Math_Exercise_GeneratorDlg::Createsymbol(CString& m_str)
{
	char symbol[] = { '+','-','*','/' };
		m_str = symbol[0 + rand() % 4];
}
//生成随机数字
void CMFC_Math_Exercise_GeneratorDlg::Createnum(CString& m_str)
{
	
		int num=0+ rand() % 100;
		 m_str.Format(_T("%d"), num);
	
}
//生成算题
void CMFC_Math_Exercise_GeneratorDlg::Createmyqs()
{
	
	for (int n=0; n < 20; n++)
	{
		int i = Createtime();
		for (int j = 0; j < i; j++)
		{
			if (j == 0)
			{
				Createnum(m_strnum);
				m_qs[n] = m_strnum;
				m_result = _wtof(m_strnum);
			}
			else
			{
				Createnum(m_strnum);
				m_num1 = _wtof(m_strnum);
				if (m_num1 != 0)
				{
					Createsymbol(m_strsymbol);

				}
				else
				{
					Createsymbol(m_strsymbol);
					while (m_strsymbol == "/")
					{
						Createsymbol(m_strsymbol);
					}
				}
				m_qs[n] += m_strsymbol;
				m_qs[n] += m_strnum;
				
			}
			
		}
	}
	UpdateData(FALSE);
}
