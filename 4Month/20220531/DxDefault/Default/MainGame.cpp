#include "stdafx.h"
#include "MainGame.h"
#include "Monster.h"


CMainGame::CMainGame()
	: m_pPlayer(nullptr)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

	if (!m_pMonster)
	{
		m_pMonster = new CMonster;
		m_pMonster->Initialize();
	}

	dynamic_cast<CMonster*>(m_pMonster)->Set_Player(m_pPlayer);
	
}

void CMainGame::Update(void)
{
	m_pPlayer->Update();
	m_pMonster->Update();
}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_hDC);
	m_pMonster->Render(m_hDC);
}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);

	ReleaseDC(g_hWnd, m_hDC);	
}

/*
위치 = Pos 포스 포지션
방향 = Dir 디렉션 , Look
Normal = 법선 백터

백터는 크기와 방향이같으면 같다 (상등)

단위 벡터 = 크기가 1인 백터
벡터의 정규화


벡터의 뺄셈 = 몬스터가 따라오게 만들기

밑변과 높이를 빗변으로 나눠주면 빗변이 1인상태의 높이와 밑변이 나온다.
백터의 내적의 외적 (조건 : 반드시 두 방향 벡터가 있어야한다.)
내적 : 스칼라 곱 (결과가 상수의 형태로 나온다)

두 방향 벡터가 있을 때
단위벡터로 만들고 내적을 했을 때
스칼라를 아크코사인에 넣었을 때 끼인각(세타)이 나온다.

벡터의 내적 = 결과값으로 스칼라를 구해준다. (물리의 양을 나타내주는 실수)

두방향벡터를 내적했을 때 나오는것은 스칼라 (물리의양을나타내는 실수)
이 스칼라를 아크코사인에 넣어주면
세타가 나온다.
전제조건은 둘다 정규화된 단위벡터가 있을 때

내적을 수행해주는 다이렉트 함수가 존재한다.
기호가 ●이다
스칼라 = x*x` + y*y` + z*z`



외적 = 벡터 곱(결과로 벡터가 발생), 기호가 A X B , 외적의 결과

X	Y	Z
X`	Y`	Z`

기호가 X인이유는 서로 크로스하기때문
d2d에서 외적을 사용하지않는이유는 z축을 사용하지 않기때문
(Y * Z` - Z * Y` X * Z` - Z * X`, X * Y` - Y * X`)

외적을 통해서 새로운 축을 구할 수 있다.
x 와 y 는 고정된 좌표에서는 가능하지만 이동하면 좌표가 바뀌기때문에
외적을 통해서 바뀐위치의 좌표를 구해줘야한다.
이 때 두방향벡터를 이용해 외적으로 구해줄 수 있다.


내적의 결과는 스칼라 방향벡터(단위 벡터) 1로 구해줘야한다.
1. 내적을 이용해서 플레이어를 따라가는 몬스터를 구현하기
2. 사진속 P라는 좌표를 알고있는데 끼인각이 세타라고 알고있다.
저넺조건이 P의 좌표와 세타를 알고있다.
이동했을 때 Q의 좌표를 구하고 증명해라.
삼각함수만 이용해서 좌표를 구할 수 있다. 상수가 아니라 수식 상태로 나온다.
Q의 위치를 예측할수있는 공식을 구해라
힌트 : Z축 회전


P x y z 

Q x y z

angle A

x * cos(A) ,y * sin(A) , z

좌표상으로 봤을 때 x와 y가 모두 이동했으므로 z축을 기준으로 회전시켰다는걸 유추할 수 있다. 끝

고정된 좌표에 이동된 월드를 프레임마다 고뱋주니까 움직이는것처럼 보인다.

*/