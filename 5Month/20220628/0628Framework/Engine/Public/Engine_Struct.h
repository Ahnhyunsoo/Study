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
		LPDIRECT3DTEXTURE9		pTexture;   // �� ��ü

		D3DXIMAGE_INFO			tImgInfo;	// ����ü

	}TEXINFO;

	enum TEXTYPE { TEX_SINGLE, TEX_MULTI, TEX_END };

}
