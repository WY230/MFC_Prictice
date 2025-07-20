
// Simple_CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Simple_Calculator.h"
#include "Simple_CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimple_CalculatorDlg 对话框



CSimple_CalculatorDlg::CSimple_CalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_strshow(_T(""))
	, m_strresult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimple_CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT_SHOW, m_strshow);
	DDX_Text(pDX, IDC_TEXT_RESULT, m_strresult);
}

BEGIN_MESSAGE_MAP(CSimple_CalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CSimple_CalculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_1, &CSimple_CalculatorDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN_2, &CSimple_CalculatorDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN_3, &CSimple_CalculatorDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN_4, &CSimple_CalculatorDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN_5, &CSimple_CalculatorDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(IDC_BTN_6, &CSimple_CalculatorDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(IDC_BTN_7, &CSimple_CalculatorDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(IDC_BTN_8, &CSimple_CalculatorDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(IDC_BTN_9, &CSimple_CalculatorDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(IDC_BTN_0, &CSimple_CalculatorDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CSimple_CalculatorDlg::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_BACK, &CSimple_CalculatorDlg::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_BTN_ADD, &CSimple_CalculatorDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_SUB, &CSimple_CalculatorDlg::OnBnClickedBtnSub)
	ON_BN_CLICKED(IDC_BTN_MUL, &CSimple_CalculatorDlg::OnBnClickedBtnMul)
	ON_BN_CLICKED(IDC_BTN_CHU, &CSimple_CalculatorDlg::OnBnClickedBtnChu)
	ON_BN_CLICKED(IDC_BTN_EQUAL, &CSimple_CalculatorDlg::OnBnClickedBtnEqual)
	ON_BN_CLICKED(IDC_BTN_DOT, &CSimple_CalculatorDlg::OnBnClickedBtnDot)
	ON_BN_CLICKED(IDC_BTN_PN, &CSimple_CalculatorDlg::OnBnClickedBtnPn)
END_MESSAGE_MAP()


// CSimple_CalculatorDlg 消息处理程序

BOOL CSimple_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	/*if (m_strshow.IsEmpty())
	{
		m_strshow = L"0";
		UpdateData(FALSE);
	}
	*/
	if (m_isFirstNumber)
	{
		m_strshow = L"0";
		m_strresult = L"0";
		UpdateData(FALSE);
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSimple_CalculatorDlg::OnPaint()
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
HCURSOR CSimple_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSimple_CalculatorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}

void CSimple_CalculatorDlg::OnBnClickedBtn1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"1";
	m_strresult += L"1";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"2";
	m_strresult += L"2";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"3";
	m_strresult += L"3";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"4";
	m_strresult += L"4";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"5";
	m_strresult += L"5";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"6";
	m_strresult += L"6";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"7";
	m_strresult += L"7";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"8";
	m_strresult += L"8";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"9";
	m_strresult += L"9";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtn0()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_strresult == L"0")
	{
		m_strresult.Empty();
		m_strshow.Empty();
	}
	m_strshow += L"0";
	m_strresult += L"0";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtnClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strshow.Empty();
	m_strresult.Empty();
	m_strtemp.Empty();
	m_num1 = 0;
	m_result = 0;
	m_strresult = L"0";
	m_strshow = L"0";
	m_symbol = 0;
	m_isFirstNumber = TRUE;
	UpdateData(FALSE);

}

void CSimple_CalculatorDlg::OnBnClickedBtnBack()
{
	// TODO: 在此添加控件通知处理程序代码
	 if (m_strshow.GetLength()==1)
	{
		m_strshow = L"0";
		m_strresult = L"0";
		m_isFirstNumber = TRUE;
	
	}
	else
	{
		m_strshow = m_strshow.Left(m_strshow.GetLength() - 1);
		m_strresult = m_strshow.Left(m_strresult.GetLength() - 1);
	}
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_symbol)
	{
		case 0:
		case '+':
		{
			if (m_isFirstNumber)
			{
				m_result = 0;
				m_isFirstNumber = FALSE;
			}

			m_num1 = _wtof(m_strresult);
			m_result += m_num1;
			m_strresult.Format(_T("%f"), m_result);
			m_strshow = m_strresult + L"+";
			m_strresult.Empty();
			UpdateData(FALSE);
			break;
		}
		case '-':
		{
			OnBnClickedBtnSub();
			OnBnClickedBtnBack();
			m_symbol = '+';
			OnBnClickedBtnAdd();
			break;
		}
		case'*':
		{
			OnBnClickedBtnMul();
			OnBnClickedBtnBack();
			m_symbol = '+';
			OnBnClickedBtnAdd();
			break;
		}
		case'/':
		{
			OnBnClickedBtnChu();
			OnBnClickedBtnBack();
			m_symbol = '+';
			OnBnClickedBtnAdd();
			break;
		}
	}
		m_symbol = '+';
	

}

void CSimple_CalculatorDlg::OnBnClickedBtnSub()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_symbol)
	{
		case 0:
		case '-':
		{
			if (m_isFirstNumber)
			{
				m_num1 = 0;
				m_result = _wtof(m_strresult);
				m_isFirstNumber = FALSE;
			}
			else
			{
				m_num1 = _wtof(m_strresult);
			}
			m_result = m_result - m_num1;
			m_strresult.Format(_T("%f"), m_result);
			m_strshow = m_strresult + L"-";
			m_strresult.Empty();
			UpdateData(FALSE);
			break;
		}
		case'+':
		{
			OnBnClickedBtnAdd();
			OnBnClickedBtnBack();
			m_symbol = '-';
			OnBnClickedBtnSub();
			break;
		}
		case'*':
		{
			OnBnClickedBtnMul();
			OnBnClickedBtnBack();
			m_symbol = '-';
			OnBnClickedBtnSub();
			break;
		}OnBnClickedBtnBack();
		case'/':
		{
			OnBnClickedBtnChu();
			OnBnClickedBtnBack();
			m_symbol = '-';
			OnBnClickedBtnSub();
			break;
		}

	}
	m_symbol = '-';
}

void CSimple_CalculatorDlg::OnBnClickedBtnMul()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_symbol)
	{
		case 0:
		case '*':
		{
			if (m_isFirstNumber)
			{
				m_result = _wtof(m_strresult);
				m_isFirstNumber = FALSE;
			}
			else
			{
				m_num1 = _wtof(m_strresult);
				m_result = m_result * m_num1;
			}
			m_strresult.Format(_T("%f"), m_result);
			m_strshow = m_strresult + L"*";
			m_strresult.Empty();
			UpdateData(FALSE);
			break;
		}
		case'+':
		{
			OnBnClickedBtnAdd();
			OnBnClickedBtnBack();
			m_symbol = '*';
			m_strresult.Format(_T("%f"), m_result);
			m_result = 1;
			OnBnClickedBtnMul();
			break;
		}
		case'-':
		{
			OnBnClickedBtnSub();
			OnBnClickedBtnBack();
			m_symbol = '*';
			m_strresult.Format(_T("%f"), m_result);
			m_result = 1;
			OnBnClickedBtnMul();
			break;
		}
		case'/':
		{
			OnBnClickedBtnChu();
			OnBnClickedBtnBack();
			m_symbol = '*';
			m_strresult.Format(_T("%f"), m_result);
			m_result = 1;
			OnBnClickedBtnMul();
			break;
		}

	}
	m_symbol = '*';
}

void CSimple_CalculatorDlg::OnBnClickedBtnChu()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_symbol)
	{
		case 0:
		case '/':
		{
			if (m_isFirstNumber)
			{
				m_result = _wtof(m_strresult);
				m_isFirstNumber = FALSE;
			}
			else
			{
			m_num1 = _wtof(m_strresult);
			m_result = m_result / m_num1;
			}
			m_strresult.Format(_T("%f"), m_result);
			m_strshow = m_strresult + L"/";
			m_strresult.Empty();
			UpdateData(FALSE);
			break;
		}
		case'+':
		{
			OnBnClickedBtnAdd();
			OnBnClickedBtnBack();
			m_symbol = '/';
			m_strresult = L"1";
			OnBnClickedBtnChu();
			break;
		}
		case'-':
		{
			OnBnClickedBtnSub();
			OnBnClickedBtnBack();
			m_symbol = '/';
			m_strresult = L"1";
			OnBnClickedBtnChu();
			break;
		}
		case'*':
		{
			OnBnClickedBtnMul();
			OnBnClickedBtnBack();
			m_symbol = '/';
			m_strresult = L"1";
			OnBnClickedBtnChu();
			break;
		}

	}
	m_symbol = '/';
}

void CSimple_CalculatorDlg::OnBnClickedBtnEqual()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_symbol!=0)
	{
		switch (m_symbol)
		{
		case0:
			{
				break;
			}
		case'+':
		{
			OnBnClickedBtnAdd();
			break;
		}
		case'-':
		{
			OnBnClickedBtnSub();
			break;
		}
		case'*':
		{
			OnBnClickedBtnMul();
			break;
		}
		case'/':
		{
			OnBnClickedBtnMul();
			break;
		}
		}
		OnBnClickedBtnBack();
		m_strresult = m_strshow;
		m_strshow.Empty();
		UpdateData(FALSE);
		m_symbol = 0;
		m_isFirstNumber = TRUE;
	}
	
}

void CSimple_CalculatorDlg::OnBnClickedBtnDot()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strshow = m_strshow + L".";
	m_strresult += L".";
	UpdateData(FALSE);
}

void CSimple_CalculatorDlg::OnBnClickedBtnPn()
{
	// TODO: 在此添加控件通知处理程序代码
	if (_wtof(m_strresult) != 0)
	{
		OnBnClickedBtnEqual();
		m_num1 = _wtof(m_strresult);
		m_result = -m_num1;
		m_strresult.Format(_T("%f"), m_result);
		m_strshow.Format(_T("%f"), m_result);
		UpdateData(FALSE);
	}
		
}
