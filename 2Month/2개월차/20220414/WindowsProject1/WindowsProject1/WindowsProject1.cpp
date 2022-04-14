// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject1.h"
#include <list>

using namespace std;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
//함수호출 규약에 대해 공부해 오시오 __stdcall 콜러 콜리 호출한 호출원과 호출된 피호출원
ATOM                MyRegisterClass(HINSTANCE hInstance); //창생성관련함수
BOOL                InitInstance(HINSTANCE, int); // 주 프로그램창을 만드는 함수
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM); // 이벤트를 처리하는 함수
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM); // 쓸데없는 함수 
//wWinMain = 문자열은 2바이트로 통일 유니코드를 사용한다.
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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
   RECT rc{ 0,0,800,600 };
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
     600, 200, //출력하고자 하는 LEFT와 TOP의 좌표
       rc.right - rc.left,
       rc.bottom - rc.top,
       nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd); // 창을 갱신해라

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

RECT rc{ 100,100,200,200 };
//
list<RECT> m_BulletList;
//list<int*, int> bl;
//RECT bl{ rc.left,rc.top,50,50 };

//Ellipse bb{rc.left,rc.top,50,50 };



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

        InvalidateRect(hWnd, 0, true);
        //InvalidateRect : 윈도우 화면 갱신 함수, 함수 호출 시 wm_paint 메세지를 발생
        //1인자 = 갱싱할 윈도우 핸들 , 2인자 : 윈도우 안에서 갱신할 범위 지정, null인 경우 윈도우 전체 영역
        //3인자 : false냐 true냐에 다라 화면 갱신 상태 변경

        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
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
            //MoveToEx(hdc, 100, 100, nullptr); //여기부터 그리겠다
            //LineTo(hdc, 200, 200); // 여기까지 그려라
            //MoveToEx(hdc, 200, 200, nullptr);
            //LineTo(hdc, 200, 300);
            /*MoveToEx(hdc, 100, 100, nullptr);
            LineTo(hdc, 200, 100);
            LineTo(hdc, 200, 200);
            LineTo(hdc, 100, 200);
            LineTo(hdc, 100, 100);*/
            
            //사각형 그리기 함수
            Rectangle(hdc, rc.left, rc.top,rc.right,rc.bottom);
            for (auto& iter : m_BulletList)
            {
                Ellipse(hdc, iter.left, iter.top, iter.right, iter.bottom);
                iter.top -= 10;
                iter.bottom -= 10;
            }

            //총알을 4방향으로 쏠수있게
            // 방향키로 w누르면 위로 d누르면 오른쪽으로 a 누르면 왼쪽으로 s누르면 아래로 쏴라
           //Ellipse(hdc, rc.left, rc.top, 50, 50);
            
            
            //원 그리기 함수
            //Ellipse(hdc, 300, 300, 400, 400);
            
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
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

        case VK_SPACE:

            m_BulletList.push_back(rc);
            break;
        }
        break;

    

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
