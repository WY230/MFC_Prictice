
// MemoSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MemoSystem.h"
#include "MemoSystemDlg.h"
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


// CMemoSystemDlg 对话框



CMemoSystemDlg::CMemoSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMOSYSTEM_DIALOG, pParent)
	, m_strselectid(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemoSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_strselectid);
}

BEGIN_MESSAGE_MAP(CMemoSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMemoSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMemoSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMemoSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMemoSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMemoSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CMemoSystemDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON6, &CMemoSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMemoSystemDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CMemoSystemDlg 消息处理程序

BOOL CMemoSystemDlg::OnInitDialog()
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
	m_list.InsertColumn(0,_T("编号"), LVCFMT_LEFT,150);
	m_list.InsertColumn(1, _T("姓氏"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(2, _T("名字"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(3, _T("日期"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(4, _T("内容"), LVCFMT_LEFT, 600);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMemoSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMemoSystemDlg::OnPaint()
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
HCURSOR CMemoSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMemoSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString filter;
	filter = "文本文档(*.txt)|*.txt|全部文档(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter,this);
	if (dlg.DoModal() == IDOK)
	{
		strfilepath = dlg.GetPathName();
		//MessageBox(strfilepath);
		m_interface.Open(strfilepath);
		Display();
		
	}

}

void CMemoSystemDlg::Display()
{
	m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < m_interface.Info.size(); i++)
	{
		str.Format(_T("%d"), m_interface.Info[i].m_id);
		m_list.InsertItem(i, str);
		str.Format(_T("%s"), m_interface.Info[i].m_lastname.c_str());
		m_list.SetItemText(i, 1, str);
		str.Format(_T("%s"), m_interface.Info[i].m_firstname.c_str());
		m_list.SetItemText(i, 2, str);
		str.Format(_T("%s"), m_interface.Info[i].m_date.c_str());
		m_list.SetItemText(i, 3, str);
		str.Format(_T("%s"), m_interface.Info[i].m_content.c_str());
		m_list.SetItemText(i, 4, str);
	}
}

void CMemoSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlgadd.DoModal() == IDOK)
	{
		m_interface.Add(CInfo(atoi(dlgadd.m_strid),dlgadd.m_strlastname.GetBuffer(), dlgadd.m_strfirstname.GetBuffer(),
		dlgadd.m_strdate.GetBuffer(), dlgadd.m_strcontent.GetBuffer()));
		isSaved = false;
		MessageBox(_T("添加成功！"), _T("提示"));
		Display();
		dlgadd.m_strid.Empty();
		dlgadd.m_strlastname.Empty();
		dlgadd.m_strfirstname.Empty();
		dlgadd.m_strdate.Empty();
		dlgadd.m_strcontent.Empty();
	}

}

void CMemoSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	if (index == -1)
	{
		MessageBox(_T("请选择要删除的行"), _T("提示"));
		return;
	}
	else
	{
		UINT i;
		i = MessageBox(_T("确定要删除所选行的信息吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES) 
		{
			m_interface.Del( index);
			isSaved = false;
			MessageBox(_T("删除成功！"), _T("提示"));
			m_list.SetSelectionMark(-1);
			Display();
		}
		else
		{
			m_list.SetSelectionMark(-1);
			return;
		}
		
	}
	
}

void CMemoSystemDlg::OnBnClickedButton3()
{
	
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	
	if (index == -1)
	{
		MessageBox(_T("请选择要修改的行"), _T("提示"));
		return;
	}
	else
	{
		dlgupdate.m_newid.Format(_T("%d"), m_interface.Info[index].m_id);
		dlgupdate.m_newlastname.Format(_T("%s"), m_interface.Info[index].m_lastname.c_str());
		dlgupdate.m_newfirstname.Format(_T("%s"), m_interface.Info[index].m_firstname.c_str());
		dlgupdate.m_newdate.Format(_T("%s"), m_interface.Info[index].m_date.c_str());
		dlgupdate.m_newcontect.Format(_T("%s"), m_interface.Info[index].m_content.c_str());
		UpdateData(false);
		if (dlgupdate.DoModal() == IDOK)
		{
			CInfo info = CInfo(atoi(dlgupdate.m_newid), dlgupdate.m_newlastname.GetBuffer(), dlgupdate.m_newfirstname.GetBuffer(),
			dlgupdate.m_newdate.GetBuffer(), dlgupdate.m_newcontect.GetBuffer());
			m_interface.Update(index, info);
			UINT i;
			i = MessageBox(_T("确定要修改所选行的信息吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES)
			{
				isSaved = false;
				MessageBox(_T("修改成功！"), _T("提示"));
				m_list.SetSelectionMark(-1);
				Display();
			}
			
		}
		else
		{
			m_list.SetSelectionMark(-1);
			//MessageBox(_T("123！"), _T("提示"));
			return;
		}
			
	}
}

void CMemoSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_strselectid == "")
	{
		MessageBox(_T("请输入要查找的id"), _T("提示"));
		return;
	}
	else
	{
		int index = atoi(m_strselectid);
		m_interface.Select(index);
		if (m_interface.selectresult.size() > 0)
		{
			m_list.DeleteAllItems();
			CString str;
			for (int i = 0; i < m_interface.selectresult.size(); i++)
			{
				str.Format(_T("%d"), m_interface.selectresult[i].m_id);
				m_list.InsertItem(i, str);
				str.Format(_T("%s"), m_interface.selectresult[i].m_lastname.c_str());
				m_list.SetItemText(i, 1, str);
				str.Format(_T("%s"), m_interface.selectresult[i].m_firstname.c_str());
				m_list.SetItemText(i, 2, str);
				str.Format(_T("%s"), m_interface.selectresult[i].m_date.c_str());
				m_list.SetItemText(i, 3, str);
				str.Format(_T("%s"), m_interface.selectresult[i].m_content.c_str());
				m_list.SetItemText(i, 4, str);
			}
			m_interface.selectresult.clear();
			m_strselectid.Empty();
			UpdateData(FALSE);
		}
		else
		{
			MessageBox(_T("没有找到该编号的信息！"), _T("提示"));
			return;
		}
	}
	
}

void CMemoSystemDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	Display();
}

void CMemoSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_interface.Save(strfilepath))
	{
		isSaved = true;
		MessageBox(_T("保存成功"), _T("提示"));
		
	}
	else
	{
		MessageBox(_T("保存失败"), _T("提示"));
		return;
	}
}

void CMemoSystemDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isSaved == false)
	{
		UINT i;
		i = MessageBox(_T("是否保存？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			OnBnClickedButton6();
			exit(0);

		}
		else
		{
			exit(0);
		}
	}
	else
	{
		exit(0);
	}
	
}
