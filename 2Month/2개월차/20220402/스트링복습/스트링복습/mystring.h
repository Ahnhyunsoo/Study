#pragma once
class mystring
{
private:
	char* m_str;
	int Size = 0;
public:
	
	void operator << (mystring& rstr);
	//mystring& operator = (mystring& rstr);

	mystring();
	mystring(char* str);
	mystring(mystring& rstring);
	
	~mystring();

public:
	char*		Get_String()
	{
		if (m_str)
			return m_str;

		return "";
	}
};

mystring mycout;


