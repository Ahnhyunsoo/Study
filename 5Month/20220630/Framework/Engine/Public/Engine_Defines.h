#pragma once
//이 헤더는 API때 Include헤더와 매우 유사함. 필요한 헤더들을 모두 포함해둔다.
//실제 cpp에서는 이 Engine_Defines만 포함해주면 이 안에 정의된 헤더들을 모두 포함하는 기능이다. 매우간편
#pragma warning (disable : 4005) //에러코드를 무시하는 pragma 쌤이 이것말고는 쓰지말라고 경고함 그냥 이런거다 하고 패스
#pragma warning (disable : 4251)
#include <d3d9.h>
#include <d3dx9.h>

#include <vector>
#include <list>
#include <map>
#include <algorithm>


#include <process.h>

#include "Engine_Macro.h"
#include "Engine_Struct.h"
#include "Engine_Typedef.h"
#include "Engine_Functor.h"
#include "Engine_Function.h"


#ifdef _DEBUG //만약 디버그모드라면

#define _CRTDBG_MAP_ALLOC // 메모리 릭을 체크해주는 기능
#include <stdlib.h> // 이기능을 사용하려면 stdlib와 crtdbg헤더가 필요하니 포함해준다.
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif

#endif // _DEBUG

using namespace std;
using namespace Engine;