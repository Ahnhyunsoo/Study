#pragma once
#include "Base.h"

/*
컴포넌트란?
객체에서 필요한 기능들을 만들어놓고 기존에 Is a 상속관계가 아닌 Has a 상속관계로 상속받게하여 
컴포넌트에 있는 기능들을 상속받은 객체에서 사용가능하게 하는 것
즉 객체에 필요한 기능을 미리 만들어 놓는 그릇 (클래스와 비슷하지만 엄연히 다름)

Is a 관계 와 Has a 관계란?
Is a 의 예시
Class Object : public CBase <<< 이건 Is a 관계이다. 즉 오브젝트가 CBase를 직접상속받는다는 뜻
Has a 의 예시
Class Object
{
private:
	CBase* Component; <<< 이건 Has a 관계이다. 즉 오브젝트가 CBase라는 컴포넌트를 포함하고 있는다는 뜻
}

여기서 상속의 개념을 확실히 잡고 가야하는데
상속이란? 상속받을 클래스의 메모리상의 주소를 갖고 있는게 상속이다.
즉 변수로 Has a 관계로 상속받아도 할당만 해주면 상속받은 것 이다.
is a 를 상속이라부르고 has a 를 포함이라 부르지만
둘다 상속의 방법이다. 상속이란 자신의 메모리안에 상속받은 클래스를 할당하는 행위이다.
*/

BEGIN(Engine)

class ENGINE_DLL CComponent abstract : public CBase
{
public:
	CComponent();
	virtual ~CComponent();
};

END