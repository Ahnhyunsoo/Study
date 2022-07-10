#pragma once

namespace Engine
{
	typedef struct tagGraphicDesc //디바이스장치 초기화할 때 넘기는 인자들을 담아놓기위한 구조체
	{
		enum WINMODE { MODE_FULL, MODE_WIN, MODE_END };

		HWND hWnd; //윈도우 핸들
		unsigned int iWinSizeX; // 윈도우 X 사이즈
		unsigned int iWinSizeY; // 윈도우 Y 사이즈
		WINMODE eWinMode; // 내가 설정한 윈도우모드 전체모드, 창모드가 있음
	}GRAPHICDESC;
}