#pragma once
#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CTexture abstract : public CBase
{
protected:
	CTexture();
	virtual ~CTexture() = default;

public:
	virtual const TEXINFO* Get_Texture(const TCHAR* pStateKey = L"", const int& iCount = 0) = 0;

public:
	virtual HRESULT InsertTexture(const TCHAR* pFilePath,
		const TCHAR* pStateKey = L"",
		const int& iCount = 0) = 0;

	virtual void Free() override;
};

END

