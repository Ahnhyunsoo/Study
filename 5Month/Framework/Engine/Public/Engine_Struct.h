#pragma once

namespace Engine
{
	typedef struct tagGraphicDesc //����̽���ġ �ʱ�ȭ�� �� �ѱ�� ���ڵ��� ��Ƴ������� ����ü
	{
		enum WINMODE { MODE_FULL, MODE_WIN, MODE_END };

		HWND hWnd; //������ �ڵ�
		unsigned int iWinSizeX; // ������ X ������
		unsigned int iWinSizeY; // ������ Y ������
		WINMODE eWinMode; // ���� ������ �������� ��ü���, â��尡 ����
	}GRAPHICDESC;
}