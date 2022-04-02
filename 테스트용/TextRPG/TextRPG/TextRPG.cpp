// TextRPG.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Main.h"

int main()
{
	Main m;
	m.exe();
    return 0;
}

/*
Player의 맴버변수
string m_ClassName  직업명
string m_Name      캐릭터 별명
int m_Damage	공격력
int m_MaxHp		최대 Hp
int m_NowHp		현재 Hp
int m_MaxMp		최대 Mp
int m_NowMp		현재 Mp
int m_MaxExp	최대 Exp
int m_NowExp	현재 Exp
int m_Level		레벨
int m_Gold		골드

Monster의 맴버변수

string m_Name      몬스터 별명
int m_Damage	공격력
int m_MaxHp		최대 Hp
int m_NowHp		현재 Hp
int m_MaxMp		최대 Mp
int m_NowMp		현재 Mp
int m_Exp		경험치
int m_Level		레벨
int m_Gold		골드

Monster의 맴버함수

void Input()	데이터 입력 함수
void Output()	데이터 출력 함수
void Get






Monster 클래스의 맴버변수

Skill (동적배열로 구현 일정레벨 달성시 동적할당 하고 스킬등록)


*/
