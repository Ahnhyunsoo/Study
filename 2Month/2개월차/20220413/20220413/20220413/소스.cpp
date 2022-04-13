#include <iostream>
#include <string>

using namespace std;

// 생성자는 명시된 생성자가 단 하나라도 있으면 디폴트 생성자가 호출되지 않는다.
//복사생성자 사용이유 : 다수의 객체를 생성할 때 속도적인 측면에서 이득이다. 메모리 블럭단위로 복사하기 때문
//함수의 매개변수나 반환값은 call by value 이므로 복사가 일어난다.

class Obj
{
public:
	virtual ~Obj()
	{

	}
};

virtual 키워드로 가상함수를 만드는 순간 가상함수포인터와 가상함수테이블이 생기는데
이 두개는 코드영역에 할당되고 이포인터의 주소를 알아낼 수 있는 방법은 없다.
오버라이딩 할 수있기때문에 데이터영역이 아닌 코드영역에 올라간다고 추론할 수 있다.

class template
. = 맴버 접근 연산자 
member variable
