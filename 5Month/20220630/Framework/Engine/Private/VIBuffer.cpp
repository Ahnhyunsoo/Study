#include "..\Public\VIBuffer.h"

CVIBuffer::CVIBuffer(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CComponent(pGraphic_Device) // ������ü ������ ��ġ�� ������
{
}

CVIBuffer::CVIBuffer(const CVIBuffer & rhs)
	: CComponent(rhs) // �������
	, m_pVB(rhs.m_pVB) // �纻��ü ������ ������ü������ ���� �������ش�.
	, m_iStride(rhs.m_iStride)
	, m_iNumVertices(rhs.m_iNumVertices)
	, m_dwFVF(rhs.m_dwFVF)
	, m_ePrimitiveType(rhs.m_ePrimitiveType)
	, m_iNumPrimitive(rhs.m_iNumPrimitive)
	, m_pIB(rhs.m_pIB)
	, m_iIndexSizeofPrimitive(rhs.m_iIndexSizeofPrimitive)
	, m_eIndexFormat(rhs.m_eIndexFormat)
{
	Safe_AddRef(m_pVB); // Com��ü�� �����ͱ� ������ ���۷��� ī��Ʈ�� ������Ų��.
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
	//1���� : ��� ° �ڿ��̳� ���� ���ؽ����۴� �ѹ��� �������� ���۸� ����� �� �ִ�. (3D���� ����Ʈ�� ���� �� �̿��Ѵ�.)
	//2���� : ���ؽ� Com��ü
	//3���� : 0�����ش� �׳�
	//4���� : ���� �ϳ��� ũ��

	m_pGraphic_Device->SetIndices(m_pIB);
	//1���� : �ε��� Com��ü

	m_pGraphic_Device->SetFVF(m_dwFVF);
	//1���� : ����·� �׸��� �����ص� ������ �ش�.



	// m_pGraphic_Device->DrawPrimitive(m_ePrimitiveType, 0, m_iNumPrimitive);
	m_pGraphic_Device->DrawIndexedPrimitive(m_ePrimitiveType, 0, 0, m_iNumVertices, 0, m_iNumPrimitive);
	//1���� : � Ÿ������ �׸���
	//2���� : �ε��� ���� �������� �׳� 0���� �ְ� �ñ��ϸ� ���۸�
	//3���� : �ε������ۿ��� �� �������� �ε��� 4���ָ� 4���ε������ͻ�� ���� 0���� ����.
	//4���� : ������ �����
	//5���� : Start�ε���
	//6���� : ��� �ﰢ������ �׸���

	return S_OK;
}

HRESULT CVIBuffer::Create_VertexBuffer()
{
	if (nullptr == m_pGraphic_Device)
		return E_FAIL;

	if (FAILED(m_pGraphic_Device->CreateVertexBuffer(m_iStride * m_iNumVertices, 0, m_dwFVF, D3DPOOL_MANAGED, &m_pVB, nullptr)))
		//1���� : ������ũ�� * ������ ����
		//2���� : ���������� �������� �׳� 0��������
		//3���� : ����·� �׸��� �ɹ������� ������ FVF
		//4���� : ���۸� ������� �������� MANAGED = �ڵ����� �����Ѵ�. DEFAULT���ָ� ������ VRAM�� �����Ѵ�.
		//5���� : ������ Com��ü�� ������ ����
		//6���� : �ڵ�����ε� nullptr�� �ش�.

		/*
		4���� ���� ���� 
		MANAGED = �ϰ� �˾Ƽ� �޸� ������ ��� �ǹ�
		�Ϲ� RAM���� VRAM�� �ν� ������.
		���̴��� ����ϸ� ����� ���ϴ� ������ CPU�� �ƴ� GPU�� �Ѵ�. �� �׷���ī�忡 �ִ� CPU�� �Ѵ�.
		�� �۾��� �����ص� �����͵��� VRAM�� �����ϴ°� �ӵ��� ������.
		������ VRAM�� ����޸� ����� �Ұ����ϴ�.
		������ MANAGE�� �ƴ϶� DEFAULT�� �ָ� ������ �׷���ī��� ����. (VRAM)
		������ ������ ���� DEFAULT�� ���� �ʴ´�. �ֳ��ϸ� VRAM�� ����޸� ����� �Ұ����ؼ� ������ �ʹ� �����ϴ�.
		Ư�� �������� �ݵ�� VRAM�� �Ҵ��ؾ��ϴ� �������� �����Ѵ�. 
		������ ������ �������� �� �����ؾ��� ��ü���� ���� DEFAULT�� �ƴ� MANAGE�� �������ش�.
		MANAGE�� ���ָ� ����̽��� �˾Ƽ� �Ǵ��ؼ� VRAM�� ��������� VRAM�� �����ϰ� ���������� RAM�� �����Ѵ�.
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
