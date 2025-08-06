#pragma once
#define SQL_MAX 256 //����sql��䳤�ȵ����ֵ
#include"StuInfo.h"

class SQLInterface
{
public:
	MYSQL_RES* res; //result Mysql�Ĳ�ѯ�������������
	MYSQL_ROW row; //��Ӧ����������
	MYSQL mysqlCon; //Connect
	char sql[SQL_MAX];  //�洢SQL���
	bool Connect_Mysql();	//�������ݿ�
	vector<StuInfo> Get_AllData();	//��ȡȫ�������ݿ���Ϣ
	bool AddData(StuInfo Info);
	bool DelData(StuInfo Info);
	bool UpDateInfo(StuInfo oldInfo, StuInfo newInfo);
	vector<StuInfo> SelectInfo(CString name);
	void Close_SQL();
};

