#pragma once
#include "Engine_Defines.h" //작성한 Engine_Defines헤더를포함해준다. CBase클래스는
		//모든 클래스가 상속받는 최상위 부모클래스이기때문에 CBase를 상속받으면 Engine_Defines가 정의되어있는거나 다름없다.

BEGIN(Engine)
//ENGINE_DLL = DLL클래스를 라이브러리화 시키기위한 기능 ( Engine_Macro에 정의되어있음 )
class ENGINE_DLL CBase abstract 		//모든 클래스들이 상속받는 최상위 부모클래스 래퍼런스카운트를 관리해줌 
									//Free가 순사가상함수이니 abstract키워드를 붙여 추상클래스화 시켜줌.(순수가상함수가 1개라도 있으면 그 클래스는 추상클래스화 시켜야한다.)
									//추상클래스는 객체를 생성할 수 없다.
{
protected: // 앞으로 생성자와 소멸자는 Create를 통해서 생성하기 때문에 public으로 선언하지 않음
	CBase();
	virtual ~CBase() = default;   // (= default) = {}를 뜻함
								//즉 아무기능없이 몸체만 놓을거면 cpp에 작성하지 않고 헤더에 = default를 해주자
public:
	unsigned long AddRef(); //래퍼런스 카운트를 증가시키는 함수
	unsigned long Release(); // 조건에 따라서 래퍼런스 카운트를 감소, 래퍼런스카운트를 삭제 시키는 함수

protected:
	unsigned long dwRefCnt; //래퍼런스 카운트를 저장하는 변수

public:
	virtual void Free() = 0; //Free는 삭제의 흐름을 제어하기위한 코드이기 때문에 순수가상함수로 만든다.
							//즉 순수가상함수이기 때문에 자식에서 꼭 몸체를 정의해줘야한다.

};

END

