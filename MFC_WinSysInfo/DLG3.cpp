// DLG3.cpp: 实现文件
//

#include "pch.h"
#include "MFC_WinSysInfo.h"
#include "afxdialogex.h"
#include "DLG3.h"


// DLG3 对话框

IMPLEMENT_DYNAMIC(DLG3, CDialogEx)

DLG3::DLG3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG3, pParent)
    , dlg3_C(_T(""))
    , dlg3_D(_T(""))
{

}

DLG3::~DLG3()
{
}

void DLG3::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, m_list2);
    DDX_Text(pDX, IDC_Dlg3_C, dlg3_C);
    DDX_Text(pDX, IDC_Dlg3_D, dlg3_D);
    DDX_Control(pDX, IDC_CHECK1, m_check2);
}


BEGIN_MESSAGE_MAP(DLG3, CDialogEx)

    ON_BN_CLICKED(IDC_CHECK1, &DLG3::OnBnClickedCheck1)
END_MESSAGE_MAP()

void DLG3::ShowDriveInfo()
{
    m_list2.DeleteAllItems();
    TCHAR szDrives[256] = { 0 };
    DWORD dwSize = GetLogicalDriveStrings(256, szDrives);
    TCHAR* pDrive = szDrives;
    while (*pDrive)
    {
        // 1. 获取盘符
        CString strDrive = pDrive;

        // 2. 获取驱动器类型
        UINT type = GetDriveType(pDrive);
        CString strType;
        switch (type)
        {
        case DRIVE_REMOVABLE: strType = _T("可移动磁盘"); break;
        case DRIVE_FIXED: strType = _T("硬盘"); break;
        case DRIVE_REMOTE: strType = _T("网络驱动器"); break;
        case DRIVE_CDROM: strType = _T("光驱"); break;
        case DRIVE_RAMDISK: strType = _T("RAM磁盘"); break;
        default: strType = _T("未知类型"); break;
        }

        // 3. 卷标名称
        TCHAR volumeName[MAX_PATH] = { 0 };
        TCHAR fileSystem[MAX_PATH] = { 0 };
        DWORD serialNumber;
        GetVolumeInformation(
            pDrive, volumeName, MAX_PATH,
            &serialNumber, NULL,NULL,
            fileSystem, MAX_PATH
        );

        // 4. 总容量与可用容量（单位转换为 MB）
        ULARGE_INTEGER freeBytesAvailable, totalBytes, totalFreeBytes;
        GetDiskFreeSpaceEx(pDrive, &freeBytesAvailable, &totalBytes, &totalFreeBytes);

        CString strTotal, strFree;
        if (m_check2.GetCheck() == BST_CHECKED)
        {
            strTotal.Format(_T("%.2f GB"), (double)totalBytes.QuadPart / (1024 * 1024*1024));
            strFree.Format(_T("%.2f GB"), (double)totalFreeBytes.QuadPart / (1024 * 1024*1024));
        }
        else
        {
            strTotal.Format(_T("%.2f MB"), (double)totalBytes.QuadPart / (1024 * 1024));
            strFree.Format(_T("%.2f MB"), (double)totalFreeBytes.QuadPart / (1024 * 1024));
        }
      
        // 5. 添加到 m_list2
        index = m_list2.InsertItem(m_list2.GetItemCount(), strDrive);
        m_list2.SetItemText(index, 1, strType);
        m_list2.SetItemText(index, 2, volumeName);
        m_list2.SetItemText(index, 3, fileSystem);
        m_list2.SetItemText(index, 4, strTotal);
        m_list2.SetItemText(index, 5, strFree);
        pDrive += _tcslen(pDrive) + 1;
    }
    m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
}

void DLG3::ShowMemoryInfo()
{
    int row1 = -1, row2 = -1;  // 初始化为-1
    for (int i = 0; i < index + 1; ++i)
    {
        CString text = m_list2.GetItemText(i, 0);
        if (text.CompareNoCase(_T("C:\\")) == 0)
        {
            row1 = i;
        }
        else if (text.CompareNoCase(_T("D:\\")) == 0)
        {
            row2 = i;
        }
        // 调试输出实际内容
        TRACE(_T("!!!!!!!Row %d: [%s]\n"), i, text);
    }
    TRACE(_T("查找结果: row1=%d, row2=%d\n"), row1, row2);
    // 确保找到对应的行
    if (row1 != -1)
    {
        if (m_check2.GetCheck() == BST_CHECKED)
        {
            dlg3_C.Format(_T("总容量%s,可用容量%s"),
                (LPCTSTR)m_list2.GetItemText(row1, 4),
                (LPCTSTR)m_list2.GetItemText(row1, 5));
        }
        else
        {
            dlg3_C.Format(_T("总容量%s,可用容量%s"), 
                (LPCTSTR)m_list2.GetItemText(row1, 4),
                (LPCTSTR)m_list2.GetItemText(row1, 5));
        }

    }
    else
    {
        dlg3_C = _T("C盘信息未找到");
    }

    if (row2 != -1)
    {
        if (m_check2.GetCheck() == BST_CHECKED)
        {
            dlg3_D.Format(_T("总容量%s,可用容量%s"), (LPCTSTR)m_list2.GetItemText(row2, 4),
                (LPCTSTR)m_list2.GetItemText(row2, 5));
        }
        else
        {
            dlg3_D.Format(_T("总容量%s,可用容量%s"), (LPCTSTR)m_list2.GetItemText(row2, 4),
                (LPCTSTR)m_list2.GetItemText(row2, 5));
        }

    }
    else
    {
        dlg3_D = _T("D盘信息未找到");
    }
  
    UpdateData(FALSE);
}

vector<CMemory> DLG3::GetMemoryInfo()
{
    vector<CMemory> Infoarr;
    int num = m_list2.GetItemCount();
    if (num == 0)
    {
        return Infoarr;
    }
    for (int i = 0; i < num; i++)
    {
        CMemory info(
            CW2A(m_list2.GetItemText(i, 0)).m_psz,
            CW2A(m_list2.GetItemText(i, 1)).m_psz,
            CW2A(m_list2.GetItemText(i, 2)).m_psz,
            CW2A(m_list2.GetItemText(i, 3)).m_psz,
            CW2A(m_list2.GetItemText(i, 4)).m_psz,
            CW2A(m_list2.GetItemText(i, 5)).m_psz
          
        );
        Infoarr.push_back(info);
    }
    return Infoarr;
}

BOOL DLG3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list2.InsertColumn(1, _T("盘符"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(2, _T("磁盘类型"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(3, _T("磁盘名称"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(4, _T("文件系统"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(5, _T("全部容量"), LVCFMT_LEFT, 200);
	m_list2.InsertColumn(6, _T("可用容量"), LVCFMT_LEFT, 200);
    ShowDriveInfo();
    ShowMemoryInfo();
    return TRUE;
}
// DLG3 消息处理程序


void DLG3::OnBnClickedCheck1()
{
    // TODO: 在此添加控件通知处理程序代码
   
    ShowDriveInfo();
    ShowMemoryInfo();
   
}
