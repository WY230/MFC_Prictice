#pragma once
class CMemory
{
public:
	string m_symbol;
	string m_type;
	string m_name;
	string m_filesystem;
	string m_totalmemory;
	string m_availmemory;
	CMemory();
	CMemory(string symbol, string type, string name, string filesystem, string totalmemory,
		string availmemory);

};

