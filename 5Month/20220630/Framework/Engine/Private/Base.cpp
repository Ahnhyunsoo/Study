#include "..\Public\Base.h"

CBase::CBase()
	:dwRefCnt(0) //변수를 0으로 초기화해줌 생성자에서 초기화해주기 때문에 대입연산을 안해도됨
{
}




unsigned long CBase::AddRef()
{
	return ++dwRefCnt; //래퍼런스 카운트를 증가시킨 후 리턴
}

unsigned long CBase::Release()
{
	if (dwRefCnt == 0)
	{
		Free(); //삭제의 흐름을 제어하기위해 프리함수를 먼저 호출해준다.
				//원래대로라면 무조건 자식의 소멸자를 호출한 후 부모의 소멸자를 호출하는데 Free함수를 사용하면
				//이 흐름을 제어할 수 있다.
		delete this; //Free함수를 호출한 후에 객체를 삭제해준다.

		return 0; //0을 리턴해서 삭제했다고 알려준다.
	}
	return dwRefCnt--; //후위연산으로 감소시키기 이전의 래퍼런스 카운트를 리턴해준다.
//왜냐하면 우선감소후 리턴해주면 래퍼런스카운트가 1이든 0이든 무조건 0이리턴되는데 
//이 때 호출한곳에서는 삭제시킨건지 감소시킨건지 판단이 불가능하기 때문이다.
}
