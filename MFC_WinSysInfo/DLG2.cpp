// DLG2.cpp: 实现文件
//

#include "pch.h"
#include "MFC_WinSysInfo.h"
#include "afxdialogex.h"
#include "DLG2.h"
#include<windows.h>


// DLG2 对话框

IMPLEMENT_DYNAMIC(DLG2, CDialogEx)

DLG2::DLG2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG2, pParent)
	, m_wn(_T(""))
	, m_un(_T(""))
	, m_sd(_T(""))
	, m_cn(_T(""))
	, m_cs(_T(""))
	, m_ci(_T(""))
	, m_gm(_T(""))
	, m_eum(_T(""))
	, m_vm(_T(""))
	, m_euvm(_T(""))
{

}

DLG2::~DLG2()
{
}

void DLG2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WName, m_wn);
	DDX_Text(pDX, IDC_UserName, m_un);
	DDX_Text(pDX, IDC_SystemDirectory, m_sd);
	DDX_Text(pDX, IDC_CPUname, m_cn);
	DDX_Text(pDX, IDC_CPUspeed, m_cs);
	DDX_Text(pDX, IDC_CPUinfo, m_ci);
	DDX_Text(pDX, IDC_GlobalMemory, m_gm);
	DDX_Text(pDX, IDC_EnuseMemory, m_eum);
	DDX_Text(pDX, IDC_VirtualMemory, m_vm);
	DDX_Text(pDX, IDC_EnuseVMemory, m_euvm);
}


BEGIN_MESSAGE_MAP(DLG2, CDialogEx)
END_MESSAGE_MAP()
BOOL DLG2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
    HKEY hKey;
    // 打开注册表路径
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		_T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion"),
		0,
		KEY_READ,
		&hKey) == ERROR_SUCCESS)
	{
		TCHAR szProductName[256] = { 0 };
		TCHAR szUserName[256] = { 0 };
		TCHAR szSystemDirector[256] = { 0 };
		DWORD dwSize1 = sizeof(szProductName);
		DWORD dwSize2 = sizeof(szUserName);
		DWORD dwSize3 = sizeof(szSystemDirector);
		// Windows名称
		if (RegQueryValueEx(hKey,
			_T("ProductName"),
			NULL,
			NULL,
			(LPBYTE)szProductName,
			&dwSize1) == ERROR_SUCCESS)
		{
			m_wn = szProductName;
		}
		//用户名称
		if (RegQueryValueEx(hKey,
			_T("RegisteredOwner"),
			NULL,
			NULL,
			(LPBYTE)szUserName,
			&dwSize2) == ERROR_SUCCESS)
		{
			m_un = szUserName;
		}
		//读取系统所在文件夹
		if (RegQueryValueEx(hKey,
			_T("PathName"),
			NULL,
			NULL,
			(LPBYTE)szSystemDirector,
			&dwSize3) == ERROR_SUCCESS)
		{
			m_sd = szSystemDirector;
		}
		RegCloseKey(hKey);
	}
	//打开另一个注册表
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		_T("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0"),
		0,
		KEY_READ,
		&hKey) == ERROR_SUCCESS)
	{
		TCHAR szCPUName[256] = { 0 };
		DWORD dwCPUspeed = 0;
		TCHAR szCPUinfo[256] = { 0 };
		DWORD dwSize1 = sizeof(szCPUName);
		DWORD dwSize2 = sizeof(dwCPUspeed);
		DWORD dwSize3 = sizeof(szCPUinfo);
		//CPU名称
		if (RegQueryValueEx(hKey, _T("ProcessorNameString"), NULL, NULL, (LPBYTE)szCPUName, &dwSize1) == ERROR_SUCCESS)
		{
			m_cn = szCPUName;
		}
		//CPU速度
		if (RegQueryValueEx(hKey, _T("~MHz"), NULL, NULL, (LPBYTE)&dwCPUspeed, &dwSize2) == ERROR_SUCCESS)
		{
			m_cs.Format(_T("%u GHZ"), dwCPUspeed);
		}
		//CPU厂商信息
		if (RegQueryValueEx(hKey, _T("VendorIdentifier"), NULL, NULL, (LPBYTE)szCPUinfo, &dwSize3) == ERROR_SUCCESS)
		{
			m_ci = szCPUinfo;
		}
		RegCloseKey(hKey);
	}	
	//查内存
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	if (GlobalMemoryStatusEx(&status))
	{
		m_gm.Format(_T("%llu MB"), status.ullTotalPhys/(1024*1024));
		m_eum.Format(_T("%llu MB"), status.ullAvailPhys / (1024 * 1024));
		m_vm.Format(_T("%llu MB"), status.ullTotalVirtual / (1024 * 1024));
		m_euvm.Format(_T("%llu MB"), status.ullAvailVirtual / (1024 * 1024));
	}
	UpdateData(FALSE);
	return TRUE;
}

// DLG2 消息处理程序
