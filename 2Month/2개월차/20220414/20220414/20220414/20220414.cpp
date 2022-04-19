// 20220414.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "20220414.h"
#include <list>
#include <iostream>
#include <random>
#include "MainGame.h"

using namespace std;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY20220414, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY20220414));

    MSG msg;
	//msg.message = WM_NULL;

	CMainGame* pMainGame = new CMainGame;

	if (nullptr == pMainGame)
		return FALSE;

	pMainGame->Initialize();


    // 기본 메시지 루프입니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	//while (true)
	//{
	////PM_REMOVE : 메시지를 읽어옴과 동시에 메시지 큐에서 제거
	//	//PM_NOREMOVE : 메시지 큐에 메시지가 존재하는지만 파악, 만약 메시지를 얻어오려면
	//	//GetMessage를 다시 호출호출해야함
	//	if(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	//	{
	//		if (WM_QUIT == msg.message)
	//			break;

	//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
	//		{
	//			TranslateMessage(&msg);
	//			DispatchMessage(&msg);
	//		}
	//	}
	//	else
	//	{

	//		pMainGame->Update();
	//		pMainGame->Render();
	//		
	//	}쉐어드 위크드 유니크 = c++11이후의 스마트 포인터
	//스마트포인터는 메모리누수를 방지하기위해 만들었다.
	//	Safe_Delete<CMainGame*>(pMainGame);
		return (int)msg.wParam;
	
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY20220414));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY20220414);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT title{ 0,0,1200,800 };
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   400, 100, //출력하고자 하는 LEFT와 TOP의 좌표
	   title.right - title.left,
	   title.bottom - title.top,
	   nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

int sNum = 3;
RECT rc{ 550,680,600,730 };
RECT monster{ 470, 100, 670, 200 };
RECT monster2{ 470, 100, 650 , 190 };


void Star(HDC hdc, int x, int y)
{
	MoveToEx(hdc, x+10, y, nullptr);
	LineTo(hdc, x + 25,y - 35);
	LineTo(hdc, x + 40, y);
	LineTo(hdc, x+5 , y - 23);
	LineTo(hdc, x + 45, y - 23);
	LineTo(hdc, x+10 , y);
}

void Triangle(HDC hdc, int x, int y)
{
	MoveToEx(hdc, x + 5, y, nullptr);
	LineTo(hdc, x + 25, y - 35);
	LineTo(hdc, x + 45, y);
	LineTo(hdc, x + 5, y);
}


	



class Monster
{
private:
	HDC hdc;
	RECT monster;
	bool Die;

public:
	void CreateMonster();
	bool GetDie() { return Die; }
	void SetDie() { Die = true; }



public:
	Monster(HDC hdc, RECT monster)
		:hdc(hdc),monster(monster),Die(false)
	{

	}

};

void Monster::CreateMonster()
{
	if (Die == false)
	{
		Die = true;
	}
	Rectangle(hdc, monster.left, monster.top, monster.right, monster.bottom);
	MoveToEx(hdc, monster.left, monster.top, nullptr);
	LineTo(hdc, monster.left + 25, monster.top - 40);
	LineTo(hdc, monster.left + 50, monster.top);
	MoveToEx(hdc, monster.right, monster.top, nullptr);
	LineTo(hdc, monster.right - 25, monster.top - 40);
	LineTo(hdc, monster.right - 50, monster.top);
	MoveToEx(hdc, monster.right, monster.top, nullptr);
	Ellipse(hdc, monster.left + 10, monster.top + 10, monster.right - 10, monster.bottom - 10);
	MoveToEx(hdc, monster.right, monster.top, nullptr);
	Ellipse(hdc, monster.left + 70, monster.top + 25, monster.right - 70, monster.bottom - 25);
}



//AdjustWindowRect중요 제공하는 해상도쓰자!!
//텍스쳐도 앵간하면 2의n제곱 형태로 작성하는게좋다.
//창의 기본요소 프레임 뷰 도큐먼트
struct MYBULLET
{
	RECT a;
	wchar_t btype;
	int damage;
};

list<MYBULLET> m_BulletList;
list<wchar_t> myMonster;
TCHAR Hp[100];
TCHAR mName[30];
int hit = 0;



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:

		SetTimer(hWnd, 0, 0, 0);
		//SetTimer : 타이머를 설치하는 함수 1인자 윈도우 핸들 2인자 타이머의 id번호 여러개의 타이머가 존재할 수 있기 때문에 현재는 0번 타이머
		//3인자 타이머 주기 기본값으로 지정, 1000당 1초 4인자 null인 경우 wm_timer라는 메세지를 발생시킴
		break;

	case WM_TIMER:
	{
		InvalidateRect(hWnd, 0, true);
		
		
		

		//InvalidateRect : 윈도우 화면 갱신 함수, 함수 호출 시 wm_paint 메세지를 발생
		//1인자 = 갱싱할 윈도우 핸들 , 2인자 : 윈도우 안에서 갱신할 범위 지정, null인 경우 윈도우 전체 영역
		//3인자 : false냐 true냐에 다라 화면 갱신 상태 변경
	}
		break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);


			TCHAR score[30];	
			wsprintf(score ,TEXT("점수 : %d"), sNum);		
			TextOut(hdc, 10, 10, score, lstrlen(score));
			
			if (myMonster.empty() == 1)
			{
				wchar_t boss = wchar_t("보스");
				myMonster.push_back(boss);
			}
			for (auto& iter : myMonster)
			{
				if (iter == wchar_t("보스"))
				{				
					Monster m(hdc, monster);
					m.CreateMonster();
				}			
			}
			
			SetBkColor(hdc, RGB(255, 0, 0));
			wsprintf(Hp, TEXT("                                            "));
			TextOut(hdc, monster.left + 10, monster.top - 60, Hp, lstrlen(Hp+hit));
			SetBkColor(hdc, RGB(255, 255, 255));
			if (lstrlen(Hp + hit) <= 1)
			{
				
				
			}


			SetBkColor(hdc, RGB(0, 0, 0));
			SetTextColor(hdc, RGB(255, 0, 255));
			wsprintf(mName, TEXT("재간둥이"));	
			
			TextOut(hdc, monster.left+70, monster.top - 30, mName, lstrlen(mName));
			
							

			random_device random;
			mt19937 rd(random());
			uniform_int_distribution<int> range(1, 20);
			int rNum = range(rd);


			if (rNum % 2 == 1)
			{
				if (monster.left >= rNum)
				{
					monster.left -= rNum;
					monster.right -= rNum;
				}
			}
			else
			{
				if (monster.right <= 1200 - rNum)
				{
					monster.left += rNum;
					monster.right += rNum;
				}
			}
			


			for (auto iter = m_BulletList.begin(); iter != m_BulletList.end(); ++iter)
			{
				if (iter->btype == wchar_t("네모"))
				{
					Rectangle(hdc, iter->a.left + 10, iter->a.top + 10, iter->a.right - 10, iter->a.bottom - 10);
					iter->a.top -= 10;
					iter->a.bottom -= 10;
					if (iter->a.top <= monster.bottom && iter->a.left <= monster.right && iter->a.right >= monster.left)
					{
						m_BulletList.erase(iter);
						sNum += 1;
						hit += 1;
						
						break;
					}

				}

				else if (iter->btype == wchar_t("왼쪽"))
				{
					Rectangle(hdc, iter->a.left + 10, iter->a.top + 10, iter->a.right - 10, iter->a.bottom - 10);
					iter->a.left -= 10;
					iter->a.right -= 10;
			
					if (iter->a.top <= monster.bottom && iter->a.left <= monster.right && iter->a.right >= monster.left)
					{
						m_BulletList.erase(iter);
						sNum += 1;
						hit += 1;

						break;
					}

				}

				else if (iter->btype == wchar_t("오른쪽"))
				{
					Rectangle(hdc, iter->a.left + 10, iter->a.top + 10, iter->a.right - 10, iter->a.bottom - 10);
					iter->a.left += 10;
					iter->a.right += 10;

					if (iter->a.top <= monster.bottom && iter->a.left <= monster.right && iter->a.right >= monster.left)
					{
						m_BulletList.erase(iter);
						sNum += 1;
						hit += 1;

						break;
					}

				}

				else if (iter->btype == wchar_t("아래"))
				{
					Rectangle(hdc, iter->a.left + 10, iter->a.top + 10, iter->a.right - 10, iter->a.bottom - 10);
					iter->a.top += 10;
					iter->a.bottom += 10;

					if (iter->a.top <= monster.bottom && iter->a.left <= monster.right && iter->a.right >= monster.left)
					{
						m_BulletList.erase(iter);
						sNum += 1;
						hit += 1;

						break;
					}

				}
			
				else if (iter->btype == wchar_t("동그라미"))
				{
					Ellipse(hdc, iter->a.left + 10, iter->a.top + 10, iter->a.right - 10, iter->a.bottom - 10);
					iter->a.top -= 10;
					iter->a.bottom -= 10;
					if (iter->a.top <= monster.bottom && iter->a.left <= monster.right && iter->a.right >= monster.left)
					{
						m_BulletList.erase(iter);
						sNum += 1;
						hit += 1;
						break;
						
					}
				}
				else if (iter->btype == wchar_t("별"))
				{
					Star(hdc, iter->a.left, iter->a.top);
					iter->a.bottom -= 10;
					iter->a.top -= 10;
					if (iter->a.top <= monster.bottom && iter->a.left <= monster.right && iter->a.right >= monster.left)
					{
						m_BulletList.erase(iter);
						sNum += 1;
						hit += 1;
						break;
					
					}
					
				}
				else if(iter->btype == wchar_t("세모"))
				{
					Triangle(hdc, iter->a.left, iter->a.top);
					iter->a.top -= 10;
					iter->a.bottom -= 10;
					if (iter->a.top <= monster.bottom && iter->a.left <= monster.right && iter->a.right >= monster.left)
					{
						m_BulletList.erase(iter);
						sNum += 1;
						hit += 1;
						break;
					}
				}
				
				
			}

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		KillTimer(hWnd, 0);
        PostQuitMessage(0);
        break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		case VK_RIGHT:
			rc.left += 10;
			rc.right += 10;
			break;

		case VK_UP:
			rc.bottom -= 10;
			rc.top -= 10;
			break;

		case VK_LEFT:
			rc.left -= 10;
			rc.right -= 10;
			break;

		case VK_DOWN:
			rc.bottom += 10;
			rc.top += 10;
			break;

		case 'A':
			MYBULLET A;
			A.a = rc;
			A.damage = 1;
			A.btype = wchar_t("네모");
			m_BulletList.push_back(A);
			break;
			

		case 'S':
			MYBULLET S;
			S.a = rc;
			S.damage = 2;
			S.btype = wchar_t("세모");
			m_BulletList.push_back(S);
			break;


		case 'D':
			MYBULLET D;
			D.a = rc;
			D.damage = 3;
			D.btype = wchar_t("동그라미");
			m_BulletList.push_back(D);
			break;


		case 'F':
			MYBULLET F;
			F.a = rc;
			F.damage = 4;
			F.btype = wchar_t("별");
			m_BulletList.push_back(F);
			break;

		case 'Q':
			MYBULLET Q;
			Q.a = rc;
			Q.damage = 4;
			Q.btype = wchar_t("왼쪽");
			m_BulletList.push_back(Q);
			break;

		case 'W':
			MYBULLET W;
			W.a = rc;
			W.damage = 4;
			W.btype = wchar_t("오른쪽");
			m_BulletList.push_back(W);
			break;

		case 'E':
			MYBULLET E;
			E.a = rc;
			E.damage = 4;
			E.btype = wchar_t("아래");
			m_BulletList.push_back(E);
			break;

	
			
			break;
		
	


			



		}
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

#if(0)
 함수 실행이 종료되면 할당되었던 스택 메모리를 해제해야 하는데 함수를 호출한 호출원(caller)에서 해제할건지
 호출받은 파호출자(callee)에서 해제할것인가에 대한 주권판단의 개념
 __cdecl, __stdcall, __fastcall, thiscall , naked 등

__cdecl = 호출자에서 스택을 정리 , 가변인자다.
__stdcall = 피호출자에서 스택을 정리, 가변인자가 아니다.

 __cdecl = c, c++의 기본 호출 규약, 호출자에 해당하는 caller가 스택을 정리한다.
함수호출규약의 공통점은 자기 자신에게 어떤 매개변수가 들어온지 모른다. 가변인자가 가능한 함수
이로 인해 본인이 스택을 정리할 수 없다.
__stdcall
WIN32 api의 기본 호출 규약, 피호출자(callee)가 스택을 정리한다.
api에서 제공하는 대부분의 함수들처럼 __stdcall은 '고정 인자 함수' 이다.
매개변수가 고정되어 있다보니 어떤 데이터 타입이 들어올지 알고 있기 때문에
피호출자 본인이 스택을 정리할 수 있다.

__fastcall
함수 호출을 빠르게 처리하기 위한 호출 규약이다,
ecx와 edx라는 레지스터를 통해 저장된다. 레지스터를 사용하고 있다는 점때문에 함수 호출이 빠르다.

thiscall 
this 포인터를 인자로 넘겨받았을 때 사용하는 호출 규약이다.

#endif