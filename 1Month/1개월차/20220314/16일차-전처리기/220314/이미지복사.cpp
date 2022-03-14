#include <iostream>

using namespace std;

void main(void)
{
	FILE*		fInput = NULL;
	FILE*		fOutput = NULL;

	errno_t		err_Input = fopen_s(&fInput, "../Data/Image.jpg", "rb");

	errno_t		err_Output = fopen_s(&fOutput, "../Data/Copy2.jpg", "wb");

	/*if (0 == err_Input)
	{
		cout << "원본 파일 개방 성공" << endl;

		if (0 == err_Output)
		{
			while (0 == feof(fInput))
			{
				char	ch = 0;
				
				fread(&ch, sizeof(char), 1, fInput);

				fwrite(&ch, sizeof(char), 1, fOutput);
			}

			cout << "파일 복사 성공!" << endl;
			fclose(fOutput);
		}
		else
		{
			cout << "사본 파일 개방 실패" << endl;
		}
		
		
		fclose(fInput);
	}
	else
		cout << "원본 파일 개방 실패" << endl;*/


	/*fseek(fInput, 0, SEEK_END);
	
	int iIndex = ftell(fInput);

	fseek(fInput, 0, SEEK_SET);

	char*	pch = new char[iIndex];

	fread(pch, sizeof(char), iIndex, fInput);
	fwrite(pch, sizeof(char), iIndex, fOutput);

	cout << "파일 복사 성공!" << endl;
	fclose(fOutput);

	delete[] pch;
	pch = nullptr;

	fclose(fInput);*/
}