// DLG1.cpp: 实现文件
//

#include "pch.h"
#include "MFC_WinSysInfo.h"
#include "afxdialogex.h"
#include "DLG1.h"


// DLG1 对话框

IMPLEMENT_DYNAMIC(DLG1, CDialogEx)

DLG1::DLG1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG1, pParent)
{

}

DLG1::~DLG1()
{
}

void DLG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(DLG1, CDialogEx)
END_MESSAGE_MAP()

void DLG1::EnumInstalledSoftware()
{
    HKEY hUninstallKey = NULL;
    HKEY hAppKey = NULL;
    TCHAR szDisplayName[256] = { 0 };
    TCHAR szDisplayVersion[256] = { 0 };
    TCHAR szPublisher[256] = { 0 };
    TCHAR szInstallLocation[512] = { 0 };
    TCHAR szSubKeyName[512] = { 0 };
    DWORD dwSize;
    DWORD dwIndex = 0;
    int nItem = 0;
    // 打开注册表的路径
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE,
        _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall"),
        0, KEY_READ, &hUninstallKey) != ERROR_SUCCESS)
        return;

    while (true)
    {
        dwSize = sizeof(szSubKeyName);
        if (RegEnumKeyEx(hUninstallKey, dwIndex, szSubKeyName, &dwSize, NULL, NULL, NULL, NULL) != ERROR_SUCCESS)
        {
            break;
        }
        else if (RegEnumKeyEx(hUninstallKey, dwIndex, szSubKeyName, &dwSize, NULL, NULL, NULL, NULL) == ERROR_NO_MORE_ITEMS)
        {
            break;
        }
        // 拼接子项路径
        CString subKeyPath = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\") + CString(szSubKeyName);

        // 打开子项
        if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, subKeyPath, 0, KEY_READ, &hAppKey) == ERROR_SUCCESS)
        {
            // 获取软件名称
            dwSize = sizeof(szDisplayName);
            if (RegQueryValueEx(hAppKey, _T("DisplayName"), NULL, NULL, (LPBYTE)szDisplayName, &dwSize) == ERROR_SUCCESS)
            {
                // 获取版本号
                dwSize = sizeof(szDisplayVersion);
                if (RegQueryValueEx(hAppKey, _T("DisplayVersion"), NULL, NULL, (LPBYTE)szDisplayVersion, &dwSize) != ERROR_SUCCESS)
                {
                    lstrcpy(szDisplayVersion, _T(""));
                }
               // 获取厂商
                dwSize = sizeof(szPublisher);
                if (RegQueryValueEx(hAppKey, _T("Publisher"), NULL, NULL, (LPBYTE)szPublisher, &dwSize) != ERROR_SUCCESS)
                {
                    lstrcpy(szPublisher, _T(""));
                }
                // 获取安装路径
                dwSize = sizeof(szInstallLocation);
                if (RegQueryValueEx(hAppKey, _T("InstallLocation"), NULL, NULL, (LPBYTE)szInstallLocation, &dwSize) != ERROR_SUCCESS)
                {
                        if (RegQueryValueEx(hAppKey, _T("UninstallString"), NULL, NULL, (LPBYTE)szInstallLocation, &dwSize) != ERROR_SUCCESS)
                        {
                            lstrcpy(szInstallLocation, _T(""));
                        }
                }
                // 添加到列表控件
                m_list1.InsertItem(nItem, szDisplayName);
                m_list1.SetItemText(nItem, 1, szDisplayVersion);
                m_list1.SetItemText(nItem, 2, szPublisher);
                m_list1.SetItemText(nItem, 3, szInstallLocation);
                nItem++;
            }
            RegCloseKey(hAppKey);
        }
        dwIndex++;
    }
    RegCloseKey(hUninstallKey);
    
}

BOOL DLG1::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list1.InsertColumn(0,_T("软件名称"),LVCFMT_LEFT,200);
	m_list1.InsertColumn(1, _T("版本号"), LVCFMT_LEFT, 200);
	m_list1.InsertColumn(2, _T("生产厂商"), LVCFMT_LEFT, 200);
	m_list1.InsertColumn(3, _T("安装路径"), LVCFMT_LEFT, 200);
    EnumInstalledSoftware();
	m_list1.SetExtendedStyle( LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;
}

// DLG1 消息处理程序
