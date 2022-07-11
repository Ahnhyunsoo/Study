#pragma once
namespace Client
{
	static const unsigned int g_iWinSizeX = 1280;
	static const unsigned int g_iWinSizeY = 720;

	enum LEVEL { LEVEL_STATIC, LEVEL_LOADING, LEVEL_LOGO, LEVEL_GAMEPLAY, LEVEL_END }; //로딩레벨구분하기위한 열거체
}

extern HWND g_hWnd; //오류 떠도 무시하기 다 구현하면 오류 사라짐

using namespace Client;
