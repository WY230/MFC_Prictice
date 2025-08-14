
// DrawingSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DrawingSystem.h"
#include "DrawingSystemDlg.h"
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


// CDrawingSystemDlg 对话框



CDrawingSystemDlg::CDrawingSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRAWINGSYSTEM_DIALOG, pParent)
	, m_LineWidth(0)
	, m_LineType(0)
	, m_text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawingSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_LineWidth);
	DDX_Radio(pDX, IDC_RADIO2, m_LineType);
	DDX_Control(pDX, IDC_COMBO2, m_fill);
	DDX_Control(pDX, IDC_COMBO3, m_DrawingMode);
	DDX_Text(pDX, IDC_EDIT2, m_text);
}

BEGIN_MESSAGE_MAP(CDrawingSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDrawingSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDrawingSystemDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CDrawingSystemDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO2, &CDrawingSystemDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDrawingSystemDlg::OnBnClickedRadio3)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_CBN_SELCHANGE(IDC_COMBO3, &CDrawingSystemDlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON3, &CDrawingSystemDlg::OnBnClickedButton3)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON4, &CDrawingSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDrawingSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDrawingSystemDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CDrawingSystemDlg 消息处理程序

BOOL CDrawingSystemDlg::OnInitDialog()
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
	Linecolor = RGB(0, 0, 255);
	Shapecolor = RGB(255, 0, 0);
	m_LineWidth = 5;
	UpdateData(FALSE);
	m_fill.AddString(_T("有填充"));
	m_fill.AddString(_T("无填充"));
	m_fill.SetCurSel(1);
	m_DrawingMode.AddString(_T("画点"));
	m_DrawingMode.AddString(_T("画线"));
	m_DrawingMode.AddString(_T("画椭圆"));
	m_DrawingMode.AddString(_T("画矩形"));
	m_DrawingMode.AddString(_T("自由绘制"));
	m_DrawingMode.SetCurSel(1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDrawingSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDrawingSystemDlg::OnPaint()
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
	//	//绘制点
	//	CPaintDC dc(this);
	//	dc.SetPixel(50,50,RGB(255,0,0)); //在坐标为（50，50）的地方画一个点
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDrawingSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDrawingSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CColorDialog colordlg(Linecolor);
	if (colordlg.DoModal() == IDOK)
	{
		Linecolor = colordlg.GetColor();
	}
}

void CDrawingSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog colordlg(Shapecolor);
	if (colordlg.DoModal() == IDOK)
	{
		Shapecolor = colordlg.GetColor();
	}
}

void CDrawingSystemDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}

void CDrawingSystemDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	LineType = PS_SOLID;
}

void CDrawingSystemDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	LineType = PS_DASH;
}

void CDrawingSystemDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//绘制点
	CClientDC dc(this);
	Downpoint = point;
	if (m_mode==OwnerDrawingMode)
	{
		startdrawing = true;
		LastMouseMove = point;
	}
	else if (m_mode == TextInsertMode)
	{
		dc.TextOut(point.x,point.y,m_text);
		OnCbnSelchangeCombo3();//切换回原来的模式
	}
	OnCbnSelchangeCombo3();
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CDrawingSystemDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Uppoint = point;
	switch (m_mode)
	{
		case PointMode:
		{
			PaintPoint();
			break;
		}
		case LineMode:
		{
			PaintLine();
			break;
		}
		case EllispeMode:
		{
			PaintEllispe();
			break;
		}
		case RectangleMode:
		{
			PaintRect();
			break;
		}
		case OwnerDrawingMode:
		{
			startdrawing = false;
			break;
		}
		default:
		{
			break;
		}
	}
	
	
	CDialogEx::OnLButtonUp(nFlags, point);
}

void CDrawingSystemDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_DrawingMode.GetCurSel())
	{
		case 0:
		{
			m_mode = PointMode;
			break;
		}
		case 1:
		{
			m_mode = LineMode;
			break;
		}
		case 2:
		{
			m_mode = EllispeMode;
			break;
		}
		case 3:
		{
			m_mode = RectangleMode;
			break;
		}
		case 4:
		{
			m_mode = OwnerDrawingMode;
			break;
		}
		default:
		{
			break;
		}
	}	
}

void CDrawingSystemDlg::PaintPoint()
{
	CClientDC dc(this);
	CPen pen(LineType, m_LineWidth, Linecolor);
	CPen* oldpen = dc.SelectObject(&pen);
	dc.MoveTo(Downpoint.x, Downpoint.y);
	dc.LineTo(Downpoint.x, Downpoint.y);
	dc.SelectObject(oldpen);
}

void CDrawingSystemDlg::PaintLine()
{
	CClientDC dc(this);
	CPen pen(LineType, m_LineWidth, Linecolor);
	CPen* oldpen = dc.SelectObject(&pen);
	dc.MoveTo(Downpoint.x, Downpoint.y);
	dc.LineTo(Uppoint.x, Uppoint.y);
	dc.SelectObject(oldpen);
}

void CDrawingSystemDlg::PaintEllispe()
{
	CClientDC dc(this);
	CPen pen(LineType, m_LineWidth, Linecolor);
	CPen* oldpen = dc.SelectObject(&pen);
	CBrush brush;
	CBrush* poldbrush = NULL;
	if (m_fill.GetCurSel() == 0)
	{
		brush.CreateSolidBrush(Shapecolor);
		poldbrush = dc.SelectObject(&brush);
		dc.Ellipse(Downpoint.x, Downpoint.y, Uppoint.x, Uppoint.y);
	}
	else if (m_fill.GetCurSel() == 1)
	{
		brush.CreateStockObject(NULL_BRUSH);//创建透明画刷
		poldbrush = dc.SelectObject(&brush);
		dc.Ellipse(Downpoint.x, Downpoint.y, Uppoint.x, Uppoint.y);

	}
	dc.SelectObject(oldpen);
	dc.SelectObject(poldbrush);
}

void CDrawingSystemDlg::PaintRect()
{
	CClientDC dc(this);
	CPen pen(LineType, m_LineWidth, Linecolor);
	CPen* oldpen = dc.SelectObject(&pen);
	CBrush brush;
	CBrush* poldbrush = NULL;
	if (m_fill.GetCurSel() == 0)
	{
		brush.CreateSolidBrush(Shapecolor);
		poldbrush = dc.SelectObject(&brush);
		dc.Rectangle(Downpoint.x, Downpoint.y, Uppoint.x, Uppoint.y);
	}
	else if (m_fill.GetCurSel() == 1)
	{
		brush.CreateStockObject(NULL_BRUSH);//创建透明画刷
		poldbrush = dc.SelectObject(&brush);
		dc.Rectangle(Downpoint.x, Downpoint.y, Uppoint.x, Uppoint.y);

	}
	dc.SelectObject(oldpen);
	dc.SelectObject(poldbrush);
}


void CDrawingSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
}

void CDrawingSystemDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (startdrawing)
	{
		CClientDC dc(this);
		CPen pen(LineType, m_LineWidth, Linecolor);
		CPen* poldpen = dc.SelectObject(&pen);
		dc.MoveTo(LastMouseMove.x, LastMouseMove.y);
		dc.LineTo(point.x, point.y);
		LastMouseMove = point;	
		dc.SelectObject(poldpen);
	}

	CDialogEx::OnMouseMove(nFlags, point);
	
}

void CDrawingSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_mode = TextInsertMode;
	UpdateData(TRUE);
	MessageBox(_T("请左键点击对话框选择插入文字的位置！"), _T("提示"));
}

void CDrawingSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_mode = ImageMode;
	CString strFilePath;
	CString filter = _T("图片（*.png）|*.png|全部文件（*.*）|*.*||");
	CFileDialog dlg(TRUE, NULL,NULL, 0, filter, this);
	if (dlg.DoModal() == IDOK)
	{
		strFilePath = dlg.GetPathName();
		CClientDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		CImage Image;
		Image.Load(strFilePath);
		Image.BitBlt(dc,0,0,rect.Width(),rect.Height(),0,0);
		Image.Destroy();
	}
	
}

void CDrawingSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right-rect.left, rect.bottom-rect.top);//创建一个与dc中的画纸rect兼容的空白画纸hbitmap
	HDC hdc = CreateCompatibleDC(dc);//创建一个与dc兼容的系统画布hdc
	HBITMAP holdmap = (HBITMAP)SelectObject(hdc, hbitmap); //将空白的画纸hbitmap与内存画布hdc关联起来，即将画纸放到画布上
	BitBlt(hdc, 0, 0, rect.right-rect.left, rect.bottom - rect.top, dc,0, 0, SRCCOPY);//将dc上的画拷贝到hdc上，将相当于hbitmap上有内容了
	CImage image;
	image.Attach(hbitmap);//将HBITMAP类的hbitmap交给CImage管理，因为CImage才有Save函数可以将其保存起来
	CString fileter = _T("位图文件（*.bmp）|*.bmp|JPEG图像文件|*.jpg|GIF图像文件|*.gif|PNG图像文件|*.png|其他格式（*.*）|*.*||");
	CFileDialog dlg(FALSE,_T("bmp"), _T("ipaint1.bmp"), 0, fileter, this);
	if (dlg.DoModal() == IDOK)
	{
		CString strfilename;
		CString strextension;
		strfilename = dlg.m_ofn.lpstrFile;  //获取用户选择或输入的完整文件名
		if (dlg.m_ofn.nFileExtension == 0)//dlg.m_ofn.nFileExtension == 0表示用户没有输入拓展名
		{
			switch (dlg.m_ofn.nFilterIndex)
			{
			case 1:
				strextension = "bmp"; break;
			case 2:
				strextension = "jpg"; break;
			case 3:
				strextension = "gif"; break;
			case 4:
				strextension = "png"; break;
			default:
				break;
			}
			strfilename = strfilename + "." + strextension;
		}
		CString savefilepath = strfilename;
		HRESULT hresult = image.Save(savefilepath);//用hresult接收保存的返回值，判断是否保存成功
		if (FAILED(hresult))
		{
			MessageBox(_T("保存图像失败！"), _T("提示"));
		}
		else
		{
			MessageBox(_T("保存图像成功！"), _T("提示"));
		}
		image.Detach();//HBITMAP将CImage对hbitmap的管理权收回
		SelectObject(hdc,holdmap);
		DeleteObject(hbitmap);
		DeleteDC(hdc);
	}
}
