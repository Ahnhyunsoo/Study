#pragma once
class Student
{
private:

	string m_sName;
	int m_iKor;
	int m_iEn;
	int m_iMath;
	int m_iSum;
	float m_fAvg;

public:
	string GetName() { return m_sName; }
	void SetStudent(string _name, int _kor, int _en, int _math);
	void PrintStudent();
	Student();
	~Student();
};

