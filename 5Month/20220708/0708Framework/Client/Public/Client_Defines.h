#pragma once
namespace Client
{
	static const unsigned int g_iWinSizeX = 1280;
	static const unsigned int g_iWinSizeY = 720;

	enum LEVEL { LEVEL_STATIC, LEVEL_LOADING, LEVEL_LOGO, LEVEL_GAMEPLAY, LEVEL_END }; //�ε����������ϱ����� ����ü
}

extern HWND g_hWnd; //���� ���� �����ϱ� �� �����ϸ� ���� �����

using namespace Client;
