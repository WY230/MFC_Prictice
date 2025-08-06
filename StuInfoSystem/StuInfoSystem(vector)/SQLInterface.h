#pragma once
#define SQL_MAX 256 //给定sql语句长度的最大值
#include"StuInfo.h"

class SQLInterface
{
public:
	MYSQL_RES* res; //result Mysql的查询结果保存在这里
	MYSQL_ROW row; //对应表中行数据
	MYSQL mysqlCon; //Connect
	char sql[SQL_MAX];  //存储SQL语句
	bool Connect_Mysql();	//连接数据库
	vector<StuInfo> Get_AllData();	//获取全部的数据库信息
	bool AddData(StuInfo Info);
	bool DelData(StuInfo Info);
	bool UpDateInfo(StuInfo oldInfo, StuInfo newInfo);
	vector<StuInfo> SelectInfo(CString name);
	void Close_SQL();
};

