
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
	int m_time=0;
	int m_qsnum=0;
	int m_count=0;
	char m_symbol=0;

	CString m_qs1;
	CString m_qs2;
	CString m_qs3;
	CString m_qs4;
	CString m_qs5;
	CString m_qs6;
	CString m_qs7;
	CString m_qs8;
	CString m_qs9;
	CString m_qs10;
	CString m_qs12;
	CString m_qs11;
	CString m_qs13;
	CString m_qs14;
	CString m_qs15;
	CString m_qs16;
	CString m_qs17;
	CString m_qs18;
	CString m_qs19;
	CString m_qs20;
	CString m_as1;
	CString m_as2;
	CString m_as3;
	CString m_as4;
	CString m_as5;
	CString m_as6;
	CString m_as7;
	CString m_as8;
	CString m_as9;
	CString m_as10;
	CString m_as11;
	CString m_as12;
	CString m_as13;
	CString m_as14;
	CString m_as15;
	CString m_as16;
	CString m_as17;
	CString m_as18;
	CString m_as19;
	CString m_as20;
	CString m_tf1;
	CString m_tf2;
	CString m_tf3;
	CString m_tf4;
	CString m_tf5;
	CString m_tf6;
	CString m_tf7;
	CString m_tf8;
	CString m_tf9;
	CString m_tf10;
	CString m_tf11;
	CString m_tf12;
	CString m_tf13;
	CString m_tf14;
	CString m_tf15;
	CString m_tf16;
	CString m_tf17;
	CString m_tf18;
	CString m_tf19;
	CString m_tf20;
	CString m_score;
};
