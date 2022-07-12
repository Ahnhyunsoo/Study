#include "..\Public\VIBuffer.h"

CVIBuffer::CVIBuffer(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CComponent(pGraphic_Device) // 원형객체 생성자 장치를 저장함
{
}

CVIBuffer::CVIBuffer(const CVIBuffer & rhs)
	: CComponent(rhs) // 복사생성
	, m_pVB(rhs.m_pVB) // 사본객체 변수에 원형객체변수의 값을 대입해준다.
	, m_iStride(rhs.m_iStride)
	, m_iNumVertices(rhs.m_iNumVertices)
	, m_dwFVF(rhs.m_dwFVF)
	, m_ePrimitiveType(rhs.m_ePrimitiveType)
	, m_iNumPrimitive(rhs.m_iNumPrimitive)
	, m_pIB(rhs.m_pIB)
	, m_iIndexSizeofPrimitive(rhs.m_iIndexSizeofPrimitive)
	, m_eIndexFormat(rhs.m_eIndexFormat)
{
	Safe_AddRef(m_pVB); // Com객체는 포인터기 때문에 래퍼런스 카운트를 증가시킨다.
	Safe_AddRef(m_pIB);

}

HRESULT CVIBuffer::Initialize_Prototype()
{
	return S_OK;
}

HRESULT CVIBuffer::Initialize(void * pArg)
{
	return S_OK;
}

HRESULT CVIBuffer::Render()
{
	if (nullptr == m_pGraphic_Device)
		return E_FAIL;

	m_pGraphic_Device->SetStreamSource(0, m_pVB, 0, m_iStride);
	//1인자 : 몇번 째 자원이냐 셋팅 버텍스버퍼는 한번에 여러개의 버퍼를 사용할 수 있다. (3D에서 이팩트를 만들 때 이용한다.)
	//2인자 : 버텍스 Com객체
	//3인자 : 0으로준다 그냥
	//4인자 : 정점 하나의 크기

	m_pGraphic_Device->SetIndices(m_pIB);
	//1인자 : 인덱스 Com객체

	m_pGraphic_Device->SetFVF(m_dwFVF);
	//1인자 : 어떤형태로 그릴지 저장해둔 변수로 준다.



	// m_pGraphic_Device->DrawPrimitive(m_ePrimitiveType, 0, m_iNumPrimitive);
	m_pGraphic_Device->DrawIndexedPrimitive(m_ePrimitiveType, 0, 0, m_iNumVertices, 0, m_iNumPrimitive);
	//1인자 : 어떤 타입으로 그릴지
	//2인자 : 인덱스 버퍼 관련인자 그냥 0으로 주고 궁금하면 구글링
	//3인자 : 인덱스버퍼에서 쓸 가장작은 인덱스 4로주면 4번인덱스부터사용 보통 0으로 주자.
	//4인자 : 정점이 몇개인지
	//5인자 : Start인덱스
	//6인자 : 몇개의 삼각형으로 그릴지

	return S_OK;
}

HRESULT CVIBuffer::Create_VertexBuffer()
{
	if (nullptr == m_pGraphic_Device)
		return E_FAIL;

	if (FAILED(m_pGraphic_Device->CreateVertexBuffer(m_iStride * m_iNumVertices, 0, m_dwFVF, D3DPOOL_MANAGED, &m_pVB, nullptr)))
		//1인자 : 정점의크기 * 정점의 갯수
		//2인자 : 정점버퍼의 종류설정 그냥 0으로주자
		//3인자 : 어떤형태로 그릴지 맴버변수로 저장한 FVF
		//4인자 : 버퍼를 어떤식으로 관리할지 MANAGED = 자동으로 관리한다. DEFAULT로주면 무조건 VRAM에 저장한다.
		//5인자 : 생성한 Com객체를 저장할 변수
		//6인자 : 핸들관련인데 nullptr로 준다.

		/*
		4인자 관련 설명 
		MANAGED = 니가 알아서 메모리 관리해 라는 의미
		일반 RAM보다 VRAM이 훨신 빠르다.
		쉐이더를 사용하면 행렬을 곱하는 연산을 CPU가 아닌 GPU가 한다. 즉 그래픽카드에 있는 CPU가 한다.
		이 작업만 생각해도 데이터들이 VRAM에 존재하는게 속도가 빠르다.
		하지만 VRAM은 가상메모리 사용이 불가능하다.
		설정을 MANAGE가 아니라 DEFAULT로 주면 무조건 그래픽카드로 간다. (VRAM)
		하지만 설정을 보통 DEFAULT로 하지 않는다. 왜냐하면 VRAM은 가상메모리 사용이 불가능해서 공간이 너무 협소하다.
		특정 정보들은 반드시 VRAM에 할당해야하는 정보들이 존재한다. 
		때문에 협소한 공간에서 꼭 저장해야할 객체들을 위해 DEFAULT가 아닌 MANAGE로 지정해준다.
		MANAGE로 해주면 디바이스가 알아서 판단해서 VRAM이 비어있으면 VRAM에 저장하고 꽉차있으면 RAM에 저장한다.
		*/
		return E_FAIL;

	return S_OK;
}

HRESULT CVIBuffer::Create_IndexBuffer()
{
	if (nullptr == m_pGraphic_Device)
		return E_FAIL;

	if (FAILED(m_pGraphic_Device->CreateIndexBuffer(m_iIndexSizeofPrimitive * m_iNumPrimitive, 0, m_eIndexFormat, D3DPOOL_MANAGED, &m_pIB, nullptr)))
		return E_FAIL;

	return S_OK;
}


void CVIBuffer::Free()
{
	__super::Free();

	Safe_Release(m_pVB);
	Safe_Release(m_pIB);
}
