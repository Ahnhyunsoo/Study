// 20220321.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Player.h"


/*객체 : 클래스(자료형) + 인스턴스(메모리 상태)

클래스의 4대 속성 : 은닉화, 캡슐화, 상속성, 다형성
은닉화 : 클래스 내의 데이터(변수)와 기능(함수)을 외부로 부터 보호하는(숨기는) 성질을 의미
접근 제어 지시자 : private(내부접근허용), protected(자식은 허용, 외부허용X), public(내부,외부 모두 접근허용)
구조체 = 접근제어지시자의 디폴트값은 public 이다.
클래스 = 접근제어지시자의 디폴트값은 private 이다.
private의 변수에 접근하기 위해선 함수를 이용한 Get과 Set을 이용한 엑세스메소드를 사용한다.
캡슐화 : 관련있는 데이터와 기능을 한 클래스 안에 묶어서 관리하는 행위
은닉화와 캡슐화는 상호간의 보호작용이다.
캡슐화가 되어있으면 기능은 직접찾아봐야 알 수 있기 때문에 은닉화가 적용된 것 이다.
어떤기능이 있는지 유추할 수 있다 = 캡슐화
실제로 어떤기능이 있는지 알 수 없다 = 은닉화

*/



struct tagInfo
{

	int m_iA;  //구조체 맴버 변수
};



class Cobj  //CObject는(CButton,CEdit등) 예약클래스이다 때문에 이 이름으로 클래스명을 선언할 수 없다.
{
	int m_iB; //private 접근

private:	// 클래스 맴버 변수 public으로 접근 권한 변경

	int m_iA; //클래스 맴버 변수  헝가리안 표기법으로 보통 맴버변수앞에는 m_를 붙인다.

private:
	int m_iC;

public:
	// access method
	void Set_A(int _iA)
	{
		m_iA = _iA;
	}
	int Get_A(void)
	{
		return m_iA;
	}


public:
	void Render()
	{

		cout << m_iA << endl;
	}

	
	int m_iD;
//변수는 private 함수는 public으로 한다.
};

//int main()
//{
	/*tagInfo tInfo;
	tInfo.m_iA = 100;
	cout << tInfo.m_iA << endl;*/

	/*Cobj obj;

	CPlayer Player;
	Player.Draw();*/
	

	//obj.Set_A(40);
	//obj.Render();
	////int C = obj.Get_A;
	//cout << obj.Get_A() << endl;

	/*CPlayer* pPlayer = new CPlayer[3];
	delete[] pPlayer;
	pPlayer = nullptr;*/

	//return 0;
//}
// 과제 1. 성적표 프로그램을 클래스로 만들고 동적 배열로 구현하자
// 학생 3명을 입력받고 추가입력해서 몇명을 더 입력받겠습니까 해서 기존3명과 +2명의 인원까지 다 추가하기
//3명의 학생정보를 추가로 선언한 배열에 복사한후 기존의 배열은 지운다
// 절차 = 하다중심 객체 = 주어중심
// 클래스 = 학생클래스	입력받고 구동할 수 있는	게임클래스

//과제 2. 텍스트 알피지를 클래스로 만들어보기 (저장 불러오기는 안해도됨)
//클래스를 생성할 때 클래스 마법사를 사용하면 안된다. 헤더파일 cpp파일 직접 생성
