#pragma once
/*
���⼭ V�� Vertex ����
I�� Index ���� �湮�ؾ��ϴ� �ε��� ����
�� Ŭ������ ���� �𵨵��� �θ� �Ǵ� Ŭ������.
���⼭ ���̶� ���������� �̷���� ���� ���Ѵ�.
�̹����� ť��� �׸�� �������� ���ؼ� �̷������.
*/
#include "Component.h"

BEGIN(Engine)

class ENGINE_DLL CVIBuffer abstract : public CComponent //Component�� ��ӹ޴� �߻�Ŭ���� ���̺귯��ȭ �����ش�.
{
protected:
	CVIBuffer(LPDIRECT3DDEVICE9 pGraphic_device); //��ġ�� �����ϴ� ���� ������
	CVIBuffer(const CVIBuffer& rhs); //������ ���ڷ� �޾� �纻�� �����ϴ� ���������
	virtual ~CVIBuffer() = default; //�Ҹ��� = {}

public:
	virtual HRESULT Initialize_Prototype() override;
	virtual HRESULT Initialize(void* pArg) override; // ���⼭ pArg�� �־��ذ��� �纻�� �����Ҽ��ְ� �Ѵ�.
	virtual HRESULT Render();

protected:
	LPDIRECT3DVERTEXBUFFER9 m_pVB = nullptr; //���ؽ� Com��ü
	_uint m_iStride = 0; // ���� �ϳ��� Byte ũ��
	_uint m_iNumVertices = 0; //������ ��ΰ�
	_ulong m_dwFVF = 0; //�������� �� �� ������ ��ġ�� ����� ���ؾ��Ѵ�. �׷��� �� ������ ��� ������� �˷�����Ѵ�.
	D3DPRIMITIVETYPE		m_ePrimitiveType;// � Ÿ������ �׸��� ��, ����, �ﰢ�� ���
	_uint					m_iNumPrimitive = 0; // ��� �������� �׸����� ������� �ﰢ������ �׸� �׸��� 2���� �ʿ��ϴ�

protected:
	LPDIRECT3DINDEXBUFFER9	m_pIB = nullptr; // �ε��� Com��ü
	_uint					m_iIndexSizeofPrimitive = 0; // �����ϳ��� �����ִ� �ε����� ����
	D3DFORMAT				m_eIndexFormat; //�����ǵ� DX���� �������� 



protected:
	HRESULT Create_VertexBuffer(); // ���ؽ� Com��ü �����Լ�
	HRESULT Create_IndexBuffer(); // �ε��� Com��ü �����Լ�

public:
	virtual CComponent* Clone(void* pArg) = 0;
	virtual void Free() override;
};

END