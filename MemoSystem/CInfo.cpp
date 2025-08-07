#include "pch.h"
#include "CInfo.h"

CInfo::CInfo()
{
}

CInfo::CInfo(int id, string lastname, string firstname, string date, string content):m_id(id),m_lastname(lastname),
m_firstname(firstname),m_date(date),m_content(content)
{
}

void CInfo::Load(fstream& in)
{
	in >> m_id;
	in >> m_lastname;
	in >> m_firstname;
	in >> m_date;
	in >> m_content;
}
