
// MFC_Math_Exercise_GeneratorDlg.h: 头文件
//

#pragma once


// CMFC_Math_Exercise_GeneratorDlg 对话框
class CMFC_Math_Exercise_GeneratorDlg : public CDialogEx
{
// 构造
public:
	CMFC_Math_Exercise_GeneratorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY6__DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	int m_time[20] = {0};
	int m_num1 = 0;
	int count=0;
	CString m_strsymbol[5];
	CString m_strnum[5];
	double m_result[20] = {0};
	CString m_qs[20];
	CString m_as[20];
	CString m_tf[20];
	CString m_score=0;
	// 定义控件ID数组
	static const int IDC_QS_ARRAY[20];
	static const int IDC_AS_ARRAY[20];
	static const int IDC_TF_ARRAY[20];
	int Createtime();
	void Createnum(CString &m_str);
	void Createsymbol(CString& m_str);
	void Createmyqs(CString m_symbol[5], CString m_num[5],int m_time[20]);
	void Calculateqs();

public:
	afx_msg void OnBnClickedBtnshow();
	afx_msg void OnBnClickedBtncommit();
};
