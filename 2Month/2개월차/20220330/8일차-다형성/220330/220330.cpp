// 220330.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#pragma region �������̵��� ���� �����Լ�

// 1. ���� �����Լ��� �� �ϳ��� �����ϴ� Ŭ������ ������ '�߻� Ŭ����'�� �Ѵ�.
// 2. �߻� Ŭ������ ��ü ������ �Ұ����ϴ�.
// 3. �θ� Ŭ������ ������ ���������Լ��� �ִٸ� ��� �ڽ� Ŭ������ �ݵ�� ��ü�� �����ؾ� �Ѵ�.

/*
class CObj abstract
{
public:
	virtual void	Render(void) = 0; // ���� �����Լ�(�������̵��� ���� �����Լ��ν��� �ٰŸ� ����� ����)
									  //virtual void	Render() { cout << "Obj" << endl; }
};


class CPlayer final : public CObj
{
	virtual void	Render() override { cout << "player" << endl; }
};

class CMonster : public CObj
{
	virtual void Render() {}
};


int main()
{

	// ���� ���ε�, �������̵�, �����Լ� �۵�����
	// �������̵� : �θ� Ŭ������ �����ͷ� �ڽ� Ŭ������ ����� ����ϰ��ϴ� ����

	//1. ����ȭ
	//2. ������

	CObj*		pObj = new CObj;

	pObj->CObj::Render();

	delete pObj;
	pObj = nullptr;

	CObj*		pMonster = new CMonster;
	
	return 0;
}
*/

#pragma endregion �������̵��� ���� �����Լ�

#pragma region ���� �Ҹ���

// ���� ����� �ߴٸ�(�θ� Ŭ������ �����Լ��� �ִٸ�) �θ�Ŭ������ �Ҹ��ڿ��� virtual Ű���带 �ݵ�� �ٿ��� 

/*
class CObj
{
private:
	int*		m_pA;

public:
	CObj() 
	{
		m_pA = new int;
		cout << "�θ� ������" << endl;
	}
	virtual ~CObj()
	{
		delete  m_pA;
		m_pA = nullptr;
		cout << "�θ� �Ҹ���" << endl;
	}
};

class CPlayer : public CObj 
{
private:
	int*		m_pB;

public:
	CPlayer()
	{
		m_pB = new int;
		cout << "�ڽ� ������" << endl;
	}
	virtual ~CPlayer()
	{
		delete  m_pB;
		m_pB = nullptr;
		cout << "�ڽ� �Ҹ���" << endl;
	}
};

void main(void)
{
	CObj*		pObj = new CPlayer;

	delete pObj;
	pObj = nullptr;

	//CPlayer		Player;
	//CObj*		pObj = &Player;

}*/


#pragma endregion ���� �Ҹ���

#pragma region ĳ����

/*
class CObj abstract
{
public:
	virtual void	Render(void) = 0;									 
};

class CPlayer final : public CObj
{
public:
	virtual void	Render() override { cout << "player" << endl; }

public:
	void			Print() { cout << "�Ϲ� �ڽ� �Լ�" << endl; }
};

class CMonster final : public CObj
{
public:
	virtual void Render() { cout << "Monster" << endl; }
};

void main(void)
{
	// 1. ĳ������ �������� ���� ����� ���� �߻��Ͽ� ���α׷� ������ �ӵ��� ���Ͻ�Ų��.
	// 2. cĳ������ ������ �� ��ȯ�� ����ϱ� ������ ���輺�� �ٺ��� ����.

	CObj*		pObj = new CPlayer; // �̰� ��ĳ���� �θ��ڷ����� �ڽİ�ü�� ��ڴ�

	((CPlayer*)pObj)->Print(); // down ĳ����, c�������� ĳ����(�� ��ȯ)

	delete pObj;
	pObj = nullptr;
}*/
#pragma endregion ĳ����

#pragma region C++ ĳ���� ������

class CObj
{
private:
	int		m_iA = 0;
public:
	virtual void Render() {}
};

class CPlayer : public CObj
{
private:
	int		m_iB = 0;
public:
	virtual void Render() { cout << m_iB << endl; }
};

void main(void)
{
	/*static_cast<��ȯ�ϰ� ���� �ڷ���>(��ȯ�� ������)
	dynamic_cast<>()
	const_cast<>()
	reinterpret_cast<>()*/

#pragma region static Cast
	// 1. static_cast : ������ ����ȯ�� ����, �츮�� �� ����� c��Ÿ�� ĳ����, ����ȯ ������ ������ �����̱� ������ static�̶� ��Ī�� �ٰ� ���� ĳ�����̶�� �Ҹ���.

	//int	iNumber = static_cast<int>(3.14f);

	// �������� ���� ĳ���� ���� 1
	//CPlayer*	pPlayer = new CPlayer;

	//CObj*		pObj = (CObj*)pPlayer;
	//CObj*		pObj = static_cast<CObj*>(pPlayer); // ����� �ƴ� ���¿��� �������� �� ��ȯ�� �Ұ����ϴ�. ��� ���� ������ �������� ������ ĳ����

	// �������� ���� ĳ���� ���� 2

	//CObj*		pObj = new CObj;
	//CPlayer*	pPlayer = pObj;		// ��ü �����ʹ� �θ�, �ڽ��� �Ǵ��� �� ����. ����ó�� ���� �� �� ���� ��Ȳ���� �ܼ� ���� �� ������ ������ �߻�
	//CPlayer*	pPlayer = static_cast<CPlayer*>(pObj); // �ٿ� ĳ����

	// static_cast�� ����
	// 1. �ӵ��� ����
	// 2. �Ϲ������� �ս��� ���(���� ������ ĳ���ÿ��� ��� ����)

	// static_cast�� ����
	// 1. �ڽ� ��ü �����Ϳ� �θ� ��ü�� ������ �ֵ��� ����ϴ� ������ ���� �ڵ������� �������� �ǹ��� ����(������ �� ��ȯ)
	// 2. ������ ������ ���� ĳ���ÿ� �ش��ϴ� ���� ��Ÿ�� �ÿ� Ÿ�� üũ�� ���� �ʾ� ������ ����ȯ�� ������ �Ұ���


#pragma endregion static Cast

#pragma region dynamic Cast

	// 2. dynamic_cast : �ݵ�� ���� �Լ��� �ϳ� �̻� ������ ��Ӱ����� �� �ٿ� ĳ������ �ϱ� ���� �뵵�� ���
	// �������� ���� ĳ������ ����� ��� nullptr �� ��ȯ�Ѵ�. �������� �Ҿ������� ��Ÿ�� �ÿ� üũ�� ���ֱ� ������ static_cast�� ���ϸ� �����ϴ�.
	
	// ���� ���� : �Ϲ� �ڷ����̳� �Ϲ� �����ʹ� ����� �� ����
	
	// �������� ���� �ٿ� ĳ����
	/*CObj*		pObj = new CObj;
	CPlayer*	pPlayer = dynamic_cast<CPlayer*>(pObj);

	if (nullptr == pPlayer)
	{
	cout << "�������� ���� ĳ����" << endl;
	}*/

	// ������ �ٿ� ĳ����
	//CObj*		pObj = new CPlayer;
	//CPlayer*	pPlayer = dynamic_cast<CPlayer*>(pObj);
	//pPlayer->Render();

	// �� ĳ������ ��
	//CPlayer*	pPlayer = new CPlayer;
	//CObj*		pObj = pPlayer;		// ������ �� ĳ����

	//CObj* pObj = dynamic_cast<CObj*>(pPlayer);
	//CObj* pObj = static_cast<CObj*>(pPlayer);

#pragma endregion dynamic Cast

#pragma region const Cast

	// const_cast : �����Ͱ� �����ϰ� �ִ� ���� �� ������ �Ұ����� �� �ٸ� �����͸� ���� ���� �� ������ ���� �Ͻ������� const ������ ���ܳ� �� �ִ�.
	// ��, ������ �Ǵ� ���۷��� ���� ����� �� �ִ�.

	/*int	iNum = 10;
	
	const int* p = &iNum;

	// *p = 20;

	int* pTemp = const_cast<int*>(p);

	*pTemp = 20;*/

#pragma endregion const Cast

#pragma region reinterpret Cast

	// reinterpret_cast : const �����͸� ������ ��� �������� ����ȯ�� ���, ������ �� ������ �� ��ȯ���� ���
	// ������ �� ���� ����� �ʷ��ϱ� ������ ����� �����ϴ� ���̴�.

	/*void	Render(void* pTemp)
	{
		int* pDest = (int*)pTemp;
		int* pDest = reinterpret_cast<int*>(pTemp);
		
		cout << (*pDest) << endl;
	}

	int		iTemp = 10;

	Render(&iTemp);*/


	int	iNum = 65;

	char*		p = reinterpret_cast<char*>(&iNum);

	cout << p << endl;


#pragma endregion reinterpret Cast	
}

#pragma endregion C++ ĳ���� ������


