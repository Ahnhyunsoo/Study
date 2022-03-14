#include <iostream>

using namespace std;

#pragma region �ؽ�Ʈ ��� ����� �Լ�

/*
void main(void)
{
	// ���� �Լ� : ����(�����͸� �����ϱ� ���� �޸� ��)�� ���� ���� �뵵�� �Լ�
	// ���� : ������ �ǹ̰� �ƴ϶� ���� �������� ���������� ������ �̵���Ű�� ���� �ǹ�

	// ��� ���� ���� �Լ� : fflush(stdout);

	// �Է� ���۸� ����� �ϴ� ����

	/ *char	szID[8] = "";
	char	szName[16] = "";

	fgets(szID, sizeof(szID), stdin);

	while ('\n' != getchar());

	fgets(szName, sizeof(szName), stdin);

	fputs(szID, stdout);
	fputs(szName, stdout);* /

}*/

#pragma endregion �ؽ�Ʈ ��� ����� �Լ�

#pragma region ���̳ʸ� ��� ����� �Լ�

void main(void)
{
	// �ܼ� ������� ��� ��Ʈ�� ����, �Ҹ��� �ü���� �˾Ƽ� ���������. ��Ʈ�� ��ü�� �ý��� �ڿ��̱� ������ �����ϴ�.
	// ���� ������� ��� �ڵ��� ���� ����, �Ҹ� �ؾ��ϱ� ������ �̿� ���õ� �Լ����� �˾ƾ� �� �ʿ䰡 �ִ�.

	// ���̳ʸ� ��� ����� : ���� �ڷ����� ���� �Ǵ� �ҷ����� �ϱ� ���� ����Ѵ�.

	// ���� ������� �⺻ ���� : ���� -> ���� �Ǵ� �б� -> �Ҹ�

	// fopen_s();	// ��Ʈ�� ���� �Լ�(���� ���� �Լ�)
	// ���� ���� , �б� ����
	// fclose(); // ��Ʈ�� �Ҹ� �Լ�(���� �Ҹ� �Լ�)


	//errno_t fopen_s(FILE** _Stream,		char const* _FileName, char const* _Mode);
					// 1���� : output����, 2���� : ������ �ִ� ��ġ������ ��ο� ���ϸ�, 3���� : ��带 ����
	
#pragma region ���� ���

	FILE*		pFile = nullptr;

	errno_t err = fopen_s(&pFile, "../Data/Test.txt", "wt");

	if (0 == err)	// ���� ���� ����
	{
		fputs("World", pFile);

		cout << "���� ���� ����" << endl;

		fclose(pFile);
	}
	else
		cout << "���� ���� ����" << endl;

#pragma endregion ���� ���
	
#pragma region ���� �Է�

	/*FILE*	pFile = nullptr;

	errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");

	char	szBuf[32] = "";

	if (0 == err)
	{
		fgets(szBuf, sizeof(szBuf), pFile);		// ���� �Է�
		fputs(szBuf, stdout);					// �ܼ� ���

		cout << "���� ���� ����" << endl;
		fclose(pFile);
	}
	else
		cout << "���� ���� ����" << endl;*/


#pragma endregion ���� �Է�
	
#pragma region �׽�Ʈ

	/*FILE*		pFile = nullptr;

	char	szBuf[32] = "Hello";

	errno_t err = fopen_s(&pFile, "../Data/Test.txt", "wt");

	if (0 == err)	// ���� ���� ����
	{
		fputs(szBuf, pFile);

		cout << "���� ���� ����" << endl;

		fclose(pFile);
	}
	else
		cout << "���� ���� ����" << endl;*/

	/*FILE*		pFile = nullptr;

	int		ch = 0;

	errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");

	if (0 == err)	// ���� ���� ����
	{
		ch = fgetc(pFile);
		fputc(ch, stdout);

		while ('\0' != ch)		// ���� ����¿��� ���ڿ��� ���� null���ڷ� �Ǵ��ϴ� ���� �ƴ϶� eof�� ���ؼ� �Ǵ��� �� �ִ�.
		{
			ch = fgetc(pFile);
			fputc(ch, stdout);
		}
		
		fclose(pFile);
	}
	else
		cout << "���� ���� ����" << endl;*/
	
	//cout << "hello" << endl;
	//cout << "world" << endl;

	// c���� �ؽ�Ʈ ��� ��� �� \n �ü������ �ٸ� ����� ���� �ȴ�.

	// ������: "\r\n"(carriage return�� �⺻ ����)
	// unix : "\n"
	// Mac  : "\r" 

#pragma endregion �׽�Ʈ

#pragma region �����ϴ� ���� �Լ�

/*
fseek(1, 2, 3) : ������ ������ ���ϴ� ����Ʈ ����ŭ �õ���Ű�� �Լ�

1���� : ������ ��Ʈ��
2���� : ����Ʈ ��
3���� : �ɼ�(SEEK_SET ó������ SEEK_CUR ���� ������Ʈ ��ġ���� SEEK_END ������ ������)*/

// ftell(��Ʈ��) : ���� ������Ʈ�� ��ġ�� �˷��ִ� �Լ�
// feof(��Ʈ��) : ������ ���� ������ �˷��ִ� �Լ�

#pragma endregion �����ϴ� ���� �Լ�

int		iArray[5] = { 1, 2, 3, 4, 5 };

	/*FILE*		pFile = nullptr;

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "wb");


	// ���̳ʸ� ��� ���� ���� �Լ�
	// size_t fwrite(const void* pBuffer, size_t Size, size_t Count, FILE* stream);

	if (0 == err)	// ���� ���� ����
	{
		fwrite(iArray, sizeof(iArray), 1, pFile);
		// fwrite(iArray, sizeof(int), 5, pFile);

		cout << "���� ���� ����" << endl;

		fclose(pFile);
	}
	else
		cout << "���� ���� ����" << endl;*/

	//FILE*		pLoadFile = nullptr;

	//errno_t errLoad = fopen_s(&pLoadFile, "../Data/Save.txt", "rb");

	//// ���̳ʸ� ��� �б� ���� �Լ�
	//// size_t fread(const void* pBuffer, size_t Size, size_t Count, FILE* stream);
	//
	//int	iTemp[5] = {};

	//if (0 == errLoad)	// ���� ���� ����
	//{
	//	fread(iTemp, sizeof(iTemp), 1, pLoadFile);
	//	// fwrite(iArray, sizeof(int), 5, pFile);

	//	cout << "���� ���� ����" << endl;
	//	fclose(pLoadFile);
	//}
	//else
	//	cout << "���� ���� ����" << endl;

	//for (int i = 0; i < 5; ++i)
	//	cout << iTemp[i] << endl; 
}

#pragma endregion ���̳ʸ� ��� ����� �Լ�

// 1. textRPG�� ����. �ҷ����� ��� �����ϱ�
// 2.
