#include "..\Public\TextManager.h"

IMPLEMENT_SINGLETON(CTextManager)

CTextManager::CTextManager()
{
}



const TEXINFO * CTextManager::Get_Texture(const TCHAR * pObjKey, const TCHAR * pStateKey, const int & iCount)
{
	auto		iter = find_if(m_MapTex.begin(), m_MapTex.end(), CTag_Finder(pObjKey));

	if (iter == m_MapTex.end())
		return nullptr;

	return iter->second->Get_Texture(pStateKey, iCount);
}

HRESULT CTextManager::InsertTexture(const TCHAR * pFilePath, TEXTYPE eType, const TCHAR * pObjKey, const TCHAR * pStateKey, const int & iCount)
{
	auto		iter = find_if(m_MapTex.begin(), m_MapTex.end(), CTag_Finder(pObjKey));

	if (iter == m_MapTex.end())
	{
		CTexture*	pTexture = nullptr;

		switch (eType)
		{
		case TEX_SINGLE:
			pTexture = new CSingleTexture;
			break;

		}

		if (FAILED(pTexture->InsertTexture(pFilePath, pStateKey, iCount)))
		{
			return E_FAIL;
		}
		m_MapTex.emplace(pObjKey, pTexture);
	}


	return S_OK;
}

void CTextManager::Free()
{
	for_each(m_MapTex.begin(), m_MapTex.end(), [](auto& MyPair) { Safe_Release<CTexture*>(MyPair.second); });
	m_MapTex.clear();
}
