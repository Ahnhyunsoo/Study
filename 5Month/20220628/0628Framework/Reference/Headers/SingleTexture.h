#pragma once
#include "Texture.h"

BEGIN(Engine)

class CSingleTexture final : public CTexture
{
public:
	CSingleTexture();
	virtual ~CSingleTexture() = default;

public:
	virtual const TEXINFO* Get_Texture(const TCHAR* pStateKey = L"", const int& iCount = 0) override { return m_pTexInfo; }

public:
	virtual HRESULT InsertTexture(const TCHAR* pFilePath, const TCHAR* pStateKey = L"", const int& iCount = 0) override;
	virtual void Free(void) override;

private:
	TEXINFO*			m_pTexInfo;
};

END

