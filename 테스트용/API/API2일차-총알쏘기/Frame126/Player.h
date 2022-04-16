#pragma once
#include "Obj.h"



class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void	Set_Bullet(list<CObj*>* pBullet)
	{
		m_pBullet = pBullet;
	}

	/*void	Set_Player(CObj* pPlayer)
	{
		m_pPlayer = pPlayer;
	}*/

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);
	CObj*		Create_Bullet(void);

private:
	typedef 		list<CObj*>	BULLETLIST;
	BULLETLIST*		m_pBullet = nullptr;

};

