#include "pch.h"
#include "CInterface.h"

bool CInterface::Open(CString filepath)
{
	fstream in(filepath, ios::in);
	CInfo m_info;
	if (in.is_open())
	{
		num ;  //记录有多少条数据
		in >> num; 
		for (int i = 0; i < num; i++)
		{
			m_info.Load(in);
			Info.push_back(m_info);
		}
		in.close();
		return true;
	}

	return false;
}

void CInterface::Add(CString filepath,CInfo info)
{
	Info.push_back(info);
	fstream out(filepath,ios::out);
	if (out.is_open())
	{
		num = Info.size();
		out << num << endl;
		for (int i = 0; i < num; i++)
		{
			out << Info[i].m_id << "\t\t" << Info[i].m_lastname << "\t\t" << Info[i].m_firstname << "\t\t"
				<< Info[i].m_date << "\t\t" << Info[i].m_content << endl;
		}
		out.close();
	}
	

	
}

void CInterface::Del(CString filepath,int index)
{
	Info.erase(Info.begin() +index );
	fstream out(filepath, ios::out);
	if (out.is_open())
	{
		num = Info.size();
		out << num << endl;
		for (int i = 0; i < num; i++)
		{
			out << Info[i].m_id << "\t\t" << Info[i].m_lastname << "\t\t" << Info[i].m_firstname << "\t\t"
				<< Info[i].m_date << "\t\t" << Info[i].m_content << endl;
		}
		out.close();
	}
}

void CInterface::Update(int index, CInfo info)
{
}

CInfo CInterface::Select(int id)
{
	return CInfo();
}

