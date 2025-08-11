#include "pch.h"
#include "CInfo.h"

CInfo::CInfo()
{
}

CInfo::CInfo(int id, string lastname, string firstname, string date, string content):m_id(id),m_lastname(lastname),
m_firstname(firstname),m_date(date),m_content(content)
{
}

//�ı��ĵ����Կո���Ϊ�ָ�����
//void CInfo::Load(fstream& in)
//{
//	in >> m_id;
//	in >> m_lastname;
//	in >> m_firstname;
//	in >> m_date;
//	in >> m_content;
//}

// ���ߺ������� ",," �ָ�
static vector<string> SplitByDoubleComma(const string& str)
{
    vector<string> result;
    string delimiter = ",,";
    size_t start = 0;
    size_t pos;

    while ((pos = str.find(delimiter, start)) != string::npos)
    {
        result.push_back(str.substr(start, pos - start));
        start = pos + delimiter.length();
    }
    // ���һ���ֶ�
    result.push_back(str.substr(start));
    return result;
}

void CInfo::Load(fstream& in)
{
    string line;
    if (getline(in, line)) // ��һ����
    {
        vector<string> fields = SplitByDoubleComma(line);
        if (fields.size() == 5) 
        {
            m_id = atoi(fields[0].c_str());
            m_lastname = fields[1].c_str();
            m_firstname = fields[2].c_str();
            m_date = fields[3].c_str();
            m_content = fields[4].c_str();
        }
    }
}