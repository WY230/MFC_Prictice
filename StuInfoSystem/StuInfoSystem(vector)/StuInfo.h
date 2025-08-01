#pragma once
class StuInfo
{
public:
	string m_name="";
	string m_gender="";
	int m_class_;
	double m_score1;
	double m_score2;
	double m_score3;

	StuInfo();
	StuInfo(string name, string gender, int class_, double score1, double score2, double score3);
};

