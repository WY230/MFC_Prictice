#include "pch.h"
#include "CInterface.h"

bool CInterface::Open(CString filepath)
{
	fstream in(filepath, ios::in);
	CInfo m_info;
	string line;
	if (in.is_open())
	{
		while (getline(in, line))
		{
			num++;
		}
		// �����ļ�ָ��
		in.clear();  // ���eof/fail״̬
		in.seekg(0); // �ص��ļ���ͷ
		for(int i=0;i <num;i++)
		{
			m_info.Load(in);
			Info.push_back(m_info);
		}
		in.close();
		return true;
	}

	return false;
}

//�ı��ĵ�(�Կո���Ϊ�ָ���)
//bool CInterface::Save(CString filepath)
//{
//	fstream out(filepath, ios::out);
//	if (out.is_open())
//	{
//		num = Info.size();
//		for (int i = 0; i < num; i++)
//		{
//			out << Info[i].m_id << "\t\t" << Info[i].m_lastname << "\t\t" << Info[i].m_firstname << "\t\t"
//				<< Info[i].m_date << "\t\t" << Info[i].m_content << endl;
//		}
//		out.close();
//		return true;
//	}
//	return false;
//}

//xlsxתΪcsv
bool CInterface::Save(CString filepath)
{
	fstream out(filepath, ios::out);
	if (out.is_open())
	{
		num = Info.size();
		for (int i = 0; i < num; i++)
		{
			out << Info[i].m_id << ",," << Info[i].m_lastname << ",," << Info[i].m_firstname << ",,"
				<< Info[i].m_date << ",," << Info[i].m_content << endl;
		}
		out.close();
		return true;
	}
	return false;
}

void CInterface::Add(CInfo info)
{
	Info.push_back(info);
	
	
}

void CInterface::Del(int index)
{
	Info.erase(Info.begin() +index );
	
}

void CInterface::Update(int index, CInfo info)
{
	Info[index] = info;
	
}

vector<CInfo> CInterface::Select(int id)
{
	for (int i = 0; i < Info.size(); i++)
	{
		if (Info[i].m_id == id)
		{
			selectresult.push_back(Info[i]);
		}
	}
	return selectresult;
}

