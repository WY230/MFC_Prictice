#include "pch.h"
#include "SQLInterface.h"
#include "StuInfo.h"

bool SQLInterface::Connect_Mysql()
{
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "123456", "stuinfo",3306 , NULL, 0))
	{
		AfxMessageBox(_T("数据库访问失败!"));
		return false;
	}
	else
	{
		AfxMessageBox(_T("成功连接数据库！"));
		//设置字符集，使程序支持中文
		mysql_query(&mysqlCon, "SET NAMES 'GB2312'"); //解决从数据库中读取数据后的汉字乱码问题
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
		AfxMessageBox(_T("查询失败！"));
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
