#include "pch.h"
#include "SQLInterface.h"
#include "StuInfo.h"

bool SQLInterface::Connect_Mysql()
{
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "123456", "stuinfo",3306 , NULL, 0))
	{
		AfxMessageBox(_T("���ݿ����ʧ��!"));
		return false;
	}
	else
	{
		AfxMessageBox(_T("�ɹ��������ݿ⣡"));
		//�����ַ�����ʹ����֧������
		mysql_query(&mysqlCon, "SET NAMES 'GB2312'"); //��������ݿ��ж�ȡ���ݺ�ĺ�����������
	}
	return true;
}

vector<StuInfo> SQLInterface::Get_AllData()
{
	StuInfo stuinfo;
	vector<StuInfo> Info;
	snprintf(sql,SQL_MAX,"SELECT * FROM info1");
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	if (ret)
	{
		AfxMessageBox(_T("��ѯʧ�ܣ�"));
		return Info;
	}
	res = mysql_store_result(&mysqlCon);
	while (row=mysql_fetch_row(res))
	{
		stuinfo = StuInfo(row[0], row[1], atoi(row[2]), stod(row[3]), stod(row[4]), stod(row[5]));
		Info.push_back(stuinfo);
	}
	mysql_free_result(res);
	return Info;
	
}
