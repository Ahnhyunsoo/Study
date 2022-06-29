#pragma once
#include "SingleTexture.h"

BEGIN(Engine)

class CTextManager final : public CBase
{
	DECLARE_SINGLETON(CTextManager)

private:
	CTextManager();
	virtual ~CTextManager() = default;

public:
	const TEXINFO*	Get_Texture(const TCHAR* pObjKey,
		const TCHAR* pStateKey = L"",
		const int& iCount = 0);

public:
	HRESULT		InsertTexture(const TCHAR* pFilePath,	// �ؽ�ó ���� ���
		TEXTYPE	eType,
		const TCHAR* pObjKey,
		const TCHAR* pStateKey = L"",
		const int& iCount = 0);

	virtual void Free() override;

private:
	map<wstring, CTexture*>		m_MapTex;
};

END

