#pragma once

#include "Include.h"

class CObj;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize(void);	// 데이터를 초기화하는 함수
	void		Update(void);		// 매 프레임마다 갱신하는 함수
	void		Render(void);		// 매 프레임마다 출력하는 함수
	void		Release(void);		// 객체 파괴 시 메모리 해제 함수
	void		CreateBullet(RECT bl);
	void		ShotBullet(wchar_t key, RECT rc);
	list<RECT> GetBullet() { return m_myBullet; }

private:
	HDC			m_DC;
	CObj*		m_pPlayer;
	list<RECT>		m_myBullet;

};

