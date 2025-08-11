#include "pch.h"
#include "CMemory.h"

CMemory::CMemory()
{
}

CMemory::CMemory(string symbol, string type, string name, string filesystem, string totalmemory, string availmemory):
	m_symbol(symbol),m_type(type),m_name(name),m_filesystem(filesystem), m_totalmemory(totalmemory), m_availmemory(availmemory)
{
}
