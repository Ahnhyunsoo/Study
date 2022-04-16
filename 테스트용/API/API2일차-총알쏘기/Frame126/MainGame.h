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

private:
	HDC			m_DC;
	CObj*		m_pPlayer;
	list<CObj*>	m_BulletList;
};

// 1. W,A,S,D 키를 누르면 각 방향으로 미사일 발사하기
// 2. 전체 화면보다 가로로 100, 세로로 100씩 작은 사각형을 만들고 범위를 벗어나면 미사일을 메모리에서 삭제