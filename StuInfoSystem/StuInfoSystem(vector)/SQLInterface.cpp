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

bool SQLInterface::AddData(StuInfo Info)
{
	snprintf(sql,SQL_MAX,"INSERT INTO info1 values('%s','%s','%d','%lf','%lf','%lf')"
		,Info.m_name.c_str(), Info.m_gender.c_str(), Info.m_class_, Info.m_score1, Info.m_score2, Info.m_score3);
	//CString strDebug;
	//strDebug.Format(_T("SQL: %hs"), sql);  // ��ʾ���ɵ�SQL
	//AfxMessageBox(strDebug);
	int ret = mysql_real_query(&mysqlCon,sql,(unsigned long)strlen(sql));
	if (ret)
	{
		CString errMsg;
		errMsg.Format(_T("���ʧ�ܣ�MySQL����: %s"), mysql_error(&mysqlCon));
		AfxMessageBox(errMsg); // ��ʾ�������
		return false;
	}
	return true;
}

bool SQLInterface::DelData(StuInfo Info)
{
	snprintf(sql, SQL_MAX, "delete from info1 where name='%s'",Info.m_name.c_str() );
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	if (ret)
	{
		CString errMsg;
		CString strSQL;
		strSQL.Format(_T("����SQL: %hs"), sql);
		AfxMessageBox(strSQL);
		errMsg.Format(_T("ɾ��ʧ�ܣ�MySQL����: %s"), mysql_error(&mysqlCon));
		AfxMessageBox(errMsg); // ��ʾ�������
		return false;
	}
	return true;
}

bool SQLInterface::UpDateInfo(StuInfo oldInfo, StuInfo newInfo)
{
	snprintf(sql, SQL_MAX, "UPDATE info1 SET NAME='%s',gender='%s',class_=%d,score1=%lf,score2=%lf,score3=%lf where name='%s' "
		, newInfo.m_name.c_str(), newInfo.m_gender.c_str(), newInfo.m_class_, newInfo.m_score1, newInfo.m_score2, newInfo.m_score3,oldInfo.m_name.c_str());
	//CString strDebug;
	//strDebug.Format(_T("SQL: %hs"), sql);  // ��ʾ���ɵ�SQL
	//AfxMessageBox(strDebug);
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	if (ret)
	{
		CString errMsg;
		errMsg.Format(_T("�޸�ʧ�ܣ�MySQL����: %s"), mysql_error(&mysqlCon));
		AfxMessageBox(errMsg); // ��ʾ�������
		return false;
	}
	return true;
}

vector<StuInfo> SQLInterface::SelectInfo(CString name)
{
	vector<StuInfo> result;
	snprintf(sql, SQL_MAX, "select * from info1 where name='%s'",name.GetBuffer());
	int ret = mysql_real_query(&mysqlCon,sql,(unsigned long)strlen(sql));
	CString strSQL;
	strSQL.Format(_T("����SQL: %hs"), sql);
	AfxMessageBox(strSQL);
	if (ret)
	{
		CString errMsg;
		errMsg.Format(_T("����ʧ�ܣ�MySQL����%s"),mysql_error(&mysqlCon) );
		AfxMessageBox(errMsg);
		return result;
	}
	res = mysql_store_result(&mysqlCon);
	while (row = mysql_fetch_row(res))
	{
		StuInfo stuinfo = StuInfo(row[0],row[1],atoi(row[2]),_ttof(row[3]), _ttof(row[4]), _ttof(row[5]));
		result.push_back(stuinfo);
	}
	return result;
}

void SQLInterface::Close_SQL()
{
	mysql_close(&mysqlCon);
}

