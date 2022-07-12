#pragma once
/*
여기서 V란 Vertex 정점
I란 Index 내가 방문해야하는 인덱스 순서
이 클래스는 실제 모델들의 부모가 되는 클래스다.
여기서 모델이란 폴리곤으로 이루어진 모델을 말한다.
이미지든 큐브든 네모든 폴리곤을 통해서 이루어진다.
*/
#include "Component.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer abstract : public CComponent //Component를 상속받는 추상클래스 라이브러리화 시켜준다.
{
protected:
	CVIBuffer(LPDIRECT3DDEVICE9 pGraphic_device); //장치를 저장하는 원형 생성자
	CVIBuffer(const CVIBuffer& rhs); //원형을 인자로 받아 사본을 생성하는 복사생성자
	virtual ~CVIBuffer() = default; //소멸자 = {}

public:
	virtual HRESULT Initialize_Prototype() override;
	virtual HRESULT Initialize(void* pArg) override; // 여기서 pArg로 넣어준것을 사본에 저장할수있게 한다.
	virtual HRESULT Render();

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVB = nullptr; //버텍스 Com객체
	_uint m_iStride = 0; // 정점 하나의 Byte 크기
	_uint m_iNumVertices = 0; //정점이 몇개인가
	_ulong m_dwFVF = 0; //랜더링할 때 이 정점의 위치에 행렬을 곱해야한다. 그래서 이 정점이 어떻게 생겼는지 알려줘야한다.
	D3DPRIMITIVETYPE		m_ePrimitiveType;// 어떤 타입으로 그릴지 점, 라인, 삼각형 등등
	_uint					m_iNumPrimitive = 0; // 몇개의 도형으로 그릴건지 예를들어 삼각형으로 네모를 그리면 2개가 필요하다

protected:
	LPDIRECT3DINDEXBUFFER9	m_pIB = nullptr; // 인덱스 Com객체
	_uint					m_iIndexSizeofPrimitive = 0; // 도형하나가 갖고있는 인덱스의 갯수
	D3DFORMAT				m_eIndexFormat; //재정의됨 DX에서 제공해줌 



protected:
	HRESULT Create_VertexBuffer(); // 버텍스 Com객체 생성함수
	HRESULT Create_IndexBuffer(); // 인덱스 Com객체 생성함수

public:
	virtual CComponent* Clone(void* pArg) = 0;
	virtual void Free() override;
};

END