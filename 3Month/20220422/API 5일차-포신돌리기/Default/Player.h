#pragma once
#include "Obj.h"
#include "Bullet.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void	Set_BulletList(list<CObj*>* pBullet)
	{
		m_pBullet = pBullet;
	}

public:
	virtual void Initialize(void) override;
	virtual int		Update(void) override;
	virtual		void	Late_Update(void);
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);


private:
	typedef list<CObj*>		BULLETLIST;
	BULLETLIST*				m_pBullet;

	POINT					m_tPosin;
	float					m_fDiagonal;
};

// 1. 플레이어 쉴드 구현(플레이어 중심으로 공전하는 위성 구현하기)
// 2. 스크류 미사일 구현
// 3. 플레이어를 따라다니는 몬스터 구현(역함수 사용)


// 함수		: 기능, Input과 Output이 존재		Y = F(X)	-> y = x + 1
// 삼각 함수  : 수학자들이 찾은 빗변, 밑변, 높이 사이에 관계를 의미, 끼인 각을 알면 각 사이에 접변들의 관계를 정리해 놓은 함수
