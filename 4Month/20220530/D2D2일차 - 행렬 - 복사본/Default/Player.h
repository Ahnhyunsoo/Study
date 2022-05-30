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

	void		Key_Input(void);
	void Update_Rect();
	float m_fangle;

	int TankRight;
	int TankLeft;
	int TankTop;
	int TankBottom;


	D3DXVECTOR3 vLeftTop;
	D3DXVECTOR3 vRightTop;
	D3DXVECTOR3 vLeftBottom;
	D3DXVECTOR3 vRightBottom;

	D3DXVECTOR3 Origin[4];


/*

	D3DXVECTOR3		m_vPlayerPos;	// ¿ßƒ° ∫§≈Õ
	
	D3DXVECTOR3		m_vPlayerDir;	// πÊ«‚ ∫§≈Õ
	D3DXVECTOR3		m_vPlayerLook;	// πÊ«‚ ∫§≈Õ

	D3DXVECTOR3		m_vPlayerNormal;	// π˝º± ∫§≈Õ*/
};

	