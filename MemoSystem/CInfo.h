#pragma once
class CInfo
{
public:
	int m_id;
	string m_lastname;
	string m_firstname;
	string m_date;
	string m_content;
	CInfo();
	CInfo(int id, string lastname, string firstname, string date, string content);
	void Load(fstream& in);

};

