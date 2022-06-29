#pragma once
namespace Engine
{
	typedef struct tagGraphicDesc
	{
		enum WINMODE { MODE_FULL, MODE_WIN, MODE_END };

		HWND hWnd;
		unsigned int iWinSizeX;
		unsigned int iWinSizeY;
		WINMODE eWinMode;

	}GRAPHICDESC;

	typedef struct tagTexture
	{
		LPDIRECT3DTEXTURE9		pTexture;   // 컴 객체

		D3DXIMAGE_INFO			tImgInfo;	// 구조체

	}TEXINFO;

	enum TEXTYPE { TEX_SINGLE, TEX_MULTI, TEX_END };

}
