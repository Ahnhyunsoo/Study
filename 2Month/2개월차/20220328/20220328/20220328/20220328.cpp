// 20220328.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"



/*
맴버함수앞에 friend키워드를 붙여주면 그 함수는 맴버변수에 접근할 수 있게만들어주는 문법이다.
class도 마찬가지 맴버변수로 friend class를 해주면 해당class에서 참조가 가능하다.
friend = 해당 변수에서 선언한 클래스의 private를 접근할 수 있게한다.
은닉화와 캡슐화를 파괴하는 문법이기 때문에 어쩔수없는 상황에만 사용하는게 좋다.

base 클래스 : 데이터를 물려주는 클래스 , 국내에서는 부모 클래스라고 표현을 많이 한다.
derived 클래스 : 데이터를 물려받는 클래스 , 자식 클래스라고 표현을 많이 한다.



1. 상속받을 땐 반드시 부모클래스의 헤더를 선언해야한다.
2. 자식클래스 옆에 public 객체명을 써준다. (private와 protected도 있지만 거의 안쓴다.)
3. 자식 클래스는 부모클래스의 데이터를 마음대로 쓸 수 있다. 부모클래스는 자식 클래스의 데이터를 쓸 수 없다.
부모가 자식꺼를 사용하지 못하는게 상속성 부모가 자식꺼를 사용할 수 있게 하는데 다형성
상속을 했든 안했든 private는 그 클래스 내에서만 사용가능하다.
이때 protected를 사용하면 상속받은 클래스는 허용한다.
상속이 부여받는게 아닌 상속받을 객체를 생성해서 데이터로 보유하고있는것이다.(메모리 공간을 공유하는게 아니다.)
상속 = 부모객체의 데이터를 생성해서 보유하고 사용하는것
같은 부모를 상속받더라도 데이터를 공유하는게 아니기 때문에 형제개념이 아니다. 맴버변수에는 항상 this포인터가 생략되어있다.
항상 선언된 위치 중심으로 같은공간에 있으면 같은공간의 값을 출력하고 같은공간에 없으면 다른공간의 것을 출력한다.
다른 공간의 값을 출력하고 싶으면 스코프 연산자를 통해서 어느구역에 있는 값인지 명시해주면 된다.
상속을 받으면 부모생성자 -> 자식생성자 소멸자 = 자식소멸자 -> 부모소멸자

이니셜 라이저를 통해 자식클래스와 부모클래스 연계해서 초기화 가능

상속의 조건
1. is-a   ( A is a B )	자식은 부모일수는 있으나 부모가 자식일 수는 없다. ex) 
사람 <- 학생 <- 학생회 (일반화) | 학생회는 학생이고 학생은 사람이다. 부모 = 공통적인것 , 자식 = 개별적인것 
사람->학생->학생회 (구체화) | 사람이 모두 학생은 아니고 학생이 모두 학생회는 아니다.
부모에 개별적인 기능을 만들필요가 없는게 상속받을시 부모데이터를 만들어서 사용하는것인데 
player 에서 필요했던 기능이 monster에선 필요없을수있으니 메모리 낭비가 일어난다. 그래서 공통적인 기능만 만든다.

2. has-a  ( A has a B )
포함을 해야한다. #include

부모는 자식의 데이터를 절대 사용할 수 없다.
정적 바인딩 = 컴파일 타이밍에 어떤 함수를 호출할 수 있는지 결정하는것

객체 포인터의 접근권한 (매우중요★)
상속이 어떻게 되어있는지만 파악하면 접근권한을 파악하는데 문제가없다.
자식은 부모꺼를 접근할수있고 부모는 자식꺼를 호출할 수 없다.
이 타이밍은 동적인타이밍이 아닌 정적인타이밍인 컴파일 타이밍에 결정된다.

내가 선언한 포인터에 따라서 호출가능한 함수가 컴파일타이밍에 결정되어있다.

상속시 부모객체를 내부적으로 생성해서 부모타입의 변수와 함수를 갖고있다.

상속시 부모생성자호출 자식생성자호출 소멸시에는 자식소멸자호출 부모소멸자호출 순으로 진행된다.

부모포인터는 어떤 형태이든 자식의 함수를 호출할 수 없다.
자식포인터는 어떤 형태이든 부모나 자기자신의 함수를 호출할 수 있다.
이거은 컴파일타이밍에 결정되는데 이것을
정적바인딩 or static바인딩 이라고 한다.

*/

class CA
{
private:
	int a;

protected:
	int b;
public:
	int c;
};

class CB : public CA
{
public:
	void Print() { cout << c << endl; }
};

class CC : protected CA
{
	
};



int main()
{
	
}

