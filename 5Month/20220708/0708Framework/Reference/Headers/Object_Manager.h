#pragma once
/*
특정 레벨에서 사용되는 오브젝트들을 관리하는 클래스
보관하고 있는 객체들의 작업을 실행시켜준다.
여기 부분 상당히 복잡하니 집중해서 보길 바랍니다!
*/
#include "Base.h"

BEGIN(Engine)

class CObject_Manager final : public CBase
{
	DECLARE_SINGLETON(CObject_Manager)
private:
	CObject_Manager();
	virtual ~CObject_Manager() = default;

public:
	HRESULT Reserve_Container(_uint iNumLevels); //사본객체를 저장할 map의 배열을 생성해주는 함수 인자로 레벨의 갯수를 받는다.
	
	HRESULT Add_Prototype(const _tchar* pPrototypeTag, class CGameObject* pPrototype); 
	//원형객체를 map컨테이너에 추가해주는 함수
	//1인자 = map컨테이너에 저장할 태그(문자열key값), 2인자 = 저장할 원형객체

	HRESULT Add_GameObjectToLayer(const _tchar* pPrototypeTag, _uint iLevelIndex, const _tchar* pLayerTag, void* pArg = nullptr);
	//사본객체를 map컨테이너에 저장해주는 함수
	//1인자 = 원형객체의 태그(문자열key값), 2인자 : 어떤레벨인지, 3인자 : 사본객체를 저장할 태그(문자열key값), 4인자 = 원형객체를 복사받을 포인터

public:
	void Tick(_float fTimeDelta); //사본객체들의 Tick을 호출하는함수
	void LateTick(_float fTimeDelta); //사본객체들의 LateTIck을 호출하는함수
	void Clear(_uint iLevelIndex); //인자로 받은 레벨의 객체들을 삭제해주는 함수

private: 
	map<const _tchar*, class CGameObject*>			m_Prototypes; //원형 객체를 저장할 map컨테이너
	typedef map<const _tchar*, class CGameObject*>	PROTOTYPES; //typedef를 통한 재정의


private: 
	_uint											m_iNumLevels; //레벨의 갯수
	map<const _tchar*, class CLayer*>*				m_pLayers; //사본 객체를 저장할 map컨테이너
	/*여기서 *>*보고 뭐지 할수도 있는데 생각해보면 간단하다. 
	그냥 map컨테이너의 포인터이다. 왜 map컨테이너의 포인터를 맴버로 저장할까?
	동적배열로 생성했기 때문이다.
	레벨별로 레이어가 존재하고 레벨에 필요한 정보를 레이어에서 관리하기 때문에
	레벨의 갯수에 따라 배열의 크기도 변경되어야 하는데 동적배열이 아닌 일반배열로 선언하면 배열의 크기를
	변경할 수 없기 때문에 레벨의 갯수에 따라 배열의 크기를 조정하기 위해 동적배열로 생성한다.
	동적배열을 모르면... C++을 복습하자
	*/
	typedef map<const _tchar*, class CLayer*>		LAYERS; //typedef를 통한 재정의

private:
	class CGameObject* Find_Prototype(const _tchar* pPrototypeTag); //인자로받은 태그를 통해 원형객체를 검색
	class CLayer* Find_Layer(_uint iLevelIndex, const _tchar* pLayerTag); //인자를 통해 레이어가 존재하는지 검색

public:
	virtual void Free() override;
};

END