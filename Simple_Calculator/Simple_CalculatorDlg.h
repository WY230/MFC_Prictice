
// Simple_CalculatorDlg.h: 头文件
//

#pragma once


// CSimple_CalculatorDlg 对话框
class CSimple_CalculatorDlg : public CDialogEx
{
// 构造
public:
	CSimple_CalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_strtemp;
	char m_symbol=0;
	double m_num1=0.0;
	double m_result=0.0;
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtn0();
private:
	CString m_strresult;
	CString m_strshow;
	bool m_isFirstNumber=TRUE;
public:
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnSub();
	afx_msg void OnBnClickedBtnMul();
	afx_msg void OnBnClickedBtnChu();
	afx_msg void OnBnClickedBtnEqual();
	afx_msg void OnBnClickedBtnDot();
	afx_msg void OnBnClickedBtnPn();
};
