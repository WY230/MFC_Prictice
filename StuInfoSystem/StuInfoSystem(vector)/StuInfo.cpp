#include "pch.h"
#include "StuInfo.h"

StuInfo::StuInfo()
{
}

StuInfo::StuInfo(string name, string gender, int class_, double score1, double score2, double score3) :
	m_name(name), m_gender(gender), m_class_(class_), m_score1(score1), m_score2(score2), m_score3(score3)
{

}