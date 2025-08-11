#include "pch.h"
#include "CSoftWare.h"

CSoftWare::CSoftWare()
{
}

CSoftWare::CSoftWare(string softwarename, string version, string productor, string install) :
	m_softwarename(softwarename),m_version(version),m_productor(productor),m_install(install)
{
}
