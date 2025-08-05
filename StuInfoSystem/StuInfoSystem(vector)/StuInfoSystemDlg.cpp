﻿
// StuInfoSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "StuInfoSystem.h"
#include "StuInfoSystemDlg.h"
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


// CStuInfoSystemDlg 对话框



CStuInfoSystemDlg::CStuInfoSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUINFOSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStuInfoSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CStuInfoSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CStuInfoSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CStuInfoSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &CStuInfoSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStuInfoSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CStuInfoSystemDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CStuInfoSystemDlg 消息处理程序

BOOL CStuInfoSystemDlg::OnInitDialog()
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
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,_T("姓名"),LVCFMT_LEFT,150);
	m_list.InsertColumn(1, _T("性别"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(2, _T("班级"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(3, _T("语文"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(4, _T("数学"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(5, _T("英语"), LVCFMT_LEFT, 150);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStuInfoSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStuInfoSystemDlg::OnPaint()
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
HCURSOR CStuInfoSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStuInfoSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//m_list.DeleteAllItems();
	if (SQL.Connect_Mysql())
	{
		DisplayData();
	}
	else
	{
		return;
	}
}

void CStuInfoSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

void CStuInfoSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlgadd.DoModal() == IDOK) //在dlgadd里点击确定按钮
	{
		if (SQL.AddData(StuInfo(dlgadd.m_strname.GetBuffer(), dlgadd.m_strgender.GetBuffer(),
			atoi(dlgadd.m_strclass), _ttof(dlgadd.m_strsocre1), _ttof(dlgadd.m_strsocre2),
			_ttof(dlgadd.m_strscore3))))
		{
			MessageBox(_T("添加成功！"),_T("提示"));
			Info.push_back(StuInfo(dlgadd.m_strname.GetBuffer(), dlgadd.m_strgender.GetBuffer(),
				atoi(dlgadd.m_strclass), _ttof(dlgadd.m_strsocre1), _ttof(dlgadd.m_strsocre2),
				_ttof(dlgadd.m_strscore3)));
			dlgadd.m_strname.ReleaseBuffer();
			dlgadd.m_strgender.ReleaseBuffer();
			dlgadd.m_strname.Empty();
			dlgadd.m_strgender.Empty();
			dlgadd.m_strclass.Empty();
			dlgadd.m_strsocre1.Empty();
			dlgadd.m_strsocre2.Empty();
			dlgadd.m_strscore3.Empty();
		}
		DisplayData();
		
	}
}
void CStuInfoSystemDlg::DisplayData()
{
	m_list.DeleteAllItems();
	Info = SQL.Get_AllData();
	CString str;
	for (int i = 0; i < Info.size(); i++)
	{
		m_list.InsertItem(i, Info[i].m_name.c_str());//将string类型变量转变为MFC支持的C语言中的char*
		m_list.SetItemText(i, 1, Info[i].m_gender.c_str());
		str.Format(_T("%d"), Info[i].m_class_);
		m_list.SetItemText(i, 2, str);
		str.Format(_T("%.1f"), Info[i].m_score1);
		m_list.SetItemText(i, 3, str);
		str.Format(_T("%.1f"), Info[i].m_score2);
		m_list.SetItemText(i, 4, str);
		str.Format(_T("%.1f"), Info[i].m_score3);
		m_list.SetItemText(i, 5, str);
	}
}

void CStuInfoSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int Index = m_list.GetSelectionMark();
	if (Index == -1)
	{
		MessageBox(_T("请先选择要删除的数据"),_T("提示"));
		return;
	}
	else
	{
		UINT i;
		i = MessageBox(_T("确定要删除这条信息吗？"),_T("提示"),MB_YESNO|MB_ICONQUESTION);
		if (i == IDYES)
		{
			if (SQL.DelData(Info[Index]))
			{
				
				MessageBox(_T("删除成功！"),_T("提示"));
				Info.erase(Info.begin() + Index);
			}
		}
	}
	DisplayData();
}

void CStuInfoSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	
	int Index = m_list.GetSelectionMark();
	if (Index == -1)
	{
		MessageBox(_T("请选择要修改信息的学生数据"),_T("提示"));
		return;
	}
	else
	{
		
		dlgupdate.m_newname = Info[Index].m_name.c_str();
		dlgupdate.m_newgender = Info[Index].m_gender.c_str();
		dlgupdate.m_newclass.Format(_T("%d"), Info[Index].m_class_);
		dlgupdate.m_newscore1.Format(_T("%lf"), Info[Index].m_score1);
		dlgupdate.m_newscore2.Format(_T("%lf"), Info[Index].m_score2);
		dlgupdate.m_newscore3.Format(_T("%lf"), Info[Index].m_score3);
		UpdateData(FALSE);
		if(dlgupdate.DoModal()==IDOK)
		{ 
			if (SQL.UpDateInfo(Info[Index], StuInfo(dlgupdate.m_newname.GetBuffer(), dlgupdate.m_newgender.GetBuffer(),
				atoi(dlgupdate.m_newclass), _ttof(dlgupdate.m_newscore1), _ttof(dlgupdate.m_newscore2),
				_ttof(dlgupdate.m_newscore3))))
			{
				MessageBox(_T("修改成功！"), _T("提示"));
				Info[Index] = StuInfo(dlgupdate.m_newname.GetBuffer(), dlgupdate.m_newgender.GetBuffer(),
					atoi(dlgupdate.m_newclass), _ttof(dlgupdate.m_newscore1), _ttof(dlgupdate.m_newscore2),
					_ttof(dlgupdate.m_newscore3));
				dlgupdate.m_newname.ReleaseBuffer();
				dlgupdate.m_newgender.ReleaseBuffer();
			}
		}
		DisplayData();
	}	
}
