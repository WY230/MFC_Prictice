#pragma once
#include"CInfo.h"
class CInterface
{
public:
	bool Open(CString filepath);

	void Add(CString filepath,CInfo info);
	void Del(CString filepath,int index);
	void Update(int index,CInfo info);
	CInfo Select(int id);
	int num;
	vector<CInfo> Info;
};

