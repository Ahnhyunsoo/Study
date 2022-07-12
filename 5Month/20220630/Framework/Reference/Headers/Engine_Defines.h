#pragma once
//�� ����� API�� Include����� �ſ� ������. �ʿ��� ������� ��� �����صд�.
//���� cpp������ �� Engine_Defines�� �������ָ� �� �ȿ� ���ǵ� ������� ��� �����ϴ� ����̴�. �ſ찣��
#pragma warning (disable : 4005) //�����ڵ带 �����ϴ� pragma ���� �̰͸���� ��������� ����� �׳� �̷��Ŵ� �ϰ� �н�
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


#ifdef _DEBUG //���� ����׸����

#define _CRTDBG_MAP_ALLOC // �޸� ���� üũ���ִ� ���
#include <stdlib.h> // �̱���� ����Ϸ��� stdlib�� crtdbg����� �ʿ��ϴ� �������ش�.
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif

#endif // _DEBUG

using namespace std;
using namespace Engine;