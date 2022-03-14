#include <iostream>

using namespace std;

typedef struct C
{
	char Name[256] = {"dd"};
	int Hp = 100;
	int Damage = 10;

}CInfo, PCInfo;

typedef struct P
{
	char Name[256] = {};
	int Hp;
	int Damage;
}PInfo, PPInfo;

void main(void)
{
	CInfo c;
	CInfo Array[1];
	

	FILE* pfile = nullptr;
	errno_t err = fopen_s(&pfile, "../Save/save4.txt", "wb");
	if (err == 0)
	{

	cout << "파일개방 성공" << endl;
	fwrite(&c, sizeof(c), 1, pfile);
	

	int iArray[2]{ c.Hp,c.Damage };

	fwrite(c.Name, sizeof(c.Name), 1, pfile);
	fwrite(iArray, sizeof(iArray),1,pfile);
	
	fclose(pfile);

	}

	//CInfo c;
	//FILE* pfile = nullptr;
	//CInfo Array[1];
	//errno_t err = fopen_s(&pfile, "../Save/save3.txt", "rb");
	///*int iTemp[2] = {};
	//char cTemp[256] = {};*/
	//if (err == 0)
	//{
	//	cout << "파일개방 성공" << endl;
	//	
	//	fread(&c, sizeof(c), 1, pfile);
	//	/*fread(cTemp, sizeof(cTemp), 1, pfile);
	//	fread(iTemp, sizeof(iTemp), 1, pfile);*/

	//	fclose(pfile);
	//}
	//else
	//{
	//	cout << "파일개방 실패";
	//}

	//cout << c.Name << endl;
	//cout << c.Damage << endl;
	//cout << c.Hp << endl;

	/*cout << cTemp << endl;
	cout << iTemp[0] << endl;
	for (int i = 0; i < 2; ++i)
	{
		cout << iTemp[i] << endl;
	}*/


}