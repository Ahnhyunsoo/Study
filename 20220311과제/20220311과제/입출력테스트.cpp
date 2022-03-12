#include <iostream>

using namespace std;

typedef struct C
{
	char Name[256] = {};
	int Hp = 1001;
	int Damage = 101;
	

}CInfo ,PCInfo;

typedef struct P
{
	char Name[256] = {};
	int Hp;
	int Damage;
}PInfo ,PPInfo;

void main(void)
{
	/*CInfo c;

	FILE* pfile = nullptr;
	errno_t err = fopen_s(&pfile, "../Save/save2.txt", "wb");
	if (err == 0)
	{
		
		cout << "파일개방 성공" << endl;
		
		int iArray[2]{ c.Hp,c.Damage };
		fwrite(c.Name, sizeof(c.Name), 1, pfile);
		fwrite(iArray, sizeof(iArray),1,pfile);
		fclose(pfile);
		
	}*/

	CInfo c;
	FILE* pfile = nullptr;
	errno_t err = fopen_s(&pfile, "../Save/save1.txt", "rb");
	int iTemp[2] = {};
	char cTemp[256] = {};
	if (err == 0)
	{
		cout << "파일개방 성공" << endl;
		
		fread(cTemp, sizeof(cTemp), 1, pfile);
		fread(iTemp, sizeof(iTemp), 1, pfile);
		
		fclose(pfile);
	}
	else
	{
		cout << "파일개방 실패";
	}
	strcpy_s(c.Name, sizeof(c.Name), cTemp);

	cout << c.Name << endl;
	
	for (int i = 0; i < 2; ++i)
	{
		cout << iTemp[i] << endl;
	}

		/*c.Damage = iTemp[0];
		c.Hp = iTemp[1];
		cout << c.Damage << endl;
		cout << c.Hp << endl;*/
	
}