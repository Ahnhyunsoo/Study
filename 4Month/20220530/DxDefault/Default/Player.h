#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void Update_Tank();

private:
	D3DXVECTOR3 TankPos;
	D3DXVECTOR3 TankDir;
	D3DXVECTOR3 GunPos;

	int TankRight;
	int TankLeft;
	int TankTop;
	int TankBottom;

	D3DXVECTOR3	m_ptTank[4];
	D3DXVECTOR3	m_ptOriginTank[4];
	float m_TankAngle;

	float angle;
	void		Key_Input(void);
};

