#pragma once

extern int		g_iNumber; // extern 키워드를 사용하면 외부에 존재한다는 것을 알리는 문법적 행위인 것이지 실제 메모리를 할당하지는 않는다.

// extern 전역 변수 또는 전역 함수의 형태를 여러 파일 공간에서 공유하여 사용할 수 있게 만드는 문법
// extern 만 모아놓은 파일을 제작하는 것이 사용상 편리할 수 있다.
// extern을 사용할 때 변수인 경우 자료형과 변수 이름이 동일해야 한다. 또, extern이 붙은 변수는 선언과 동시에 초기화가 불가능하다.

maingame 전역변수 a 선언을 했는데
field에서 a를 쓰고싶은거네

define

int b;



extern int b;

b = 0;

extern int g_iNumber
g_iNumber = 0;