#include <iostream>

using namespace std;

void main(void)
{
	FILE* pfile = nullptr;
	FILE* cfile = nullptr;

	errno_t err = fopen_s(&pfile, "../Save/image.jpg", "rb");
	errno_t er = fopen_s(&cfile, "../Save/image2.jpg", "wb");
	if (err == 0)
	{
		cout << "파일 개방 성공" << endl;
		char a = 0;
		while (true)
		{
			int i = fread(&a, sizeof(char), 1, pfile);

			if (1 > i)
			{
				break;
			}
			
			fwrite(&a, sizeof(char), 1, cfile);

			
		}
		cout << "복사성공" << endl;
		fclose(pfile);
	}

	
	

}