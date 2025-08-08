#pragma once
#include"CInfo.h"
class CInterface
{
public:
	bool Open(CString filepath);
	bool Save(CString filepath);
	void Add(CInfo info);
	void Del(int index);
	void Update(int index,CInfo info);
	vector<CInfo> Select(int id);
	int num;
	vector<CInfo> Info;
	vector<CInfo> selectresult;
};

