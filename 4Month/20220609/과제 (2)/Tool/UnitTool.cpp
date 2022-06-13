// UnitTool.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tool.h"
#include "UnitTool.h"
#include "afxdialogex.h"


// CUnitTool 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUnitTool, CDialog)

CUnitTool::CUnitTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_UNITTOOL, pParent)
	, m_strTemp(_T(""))
	, m_strCopy(_T(""))
	, m_strName(_T(""))
	, m_iHp(0)
	, m_iAttack(0)
	, m_iTest(0)
{

}

CUnitTool::~CUnitTool()
{
}

void CUnitTool::DoDataExchange(CDataExchange* pDX)
{
	// DoDataExchange : UpdateData함수를 호출할 때마다 자동호출되는 함수


	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_strTemp);
	DDX_Text(pDX, IDC_EDIT2, m_strCopy);
	DDX_Text(pDX, IDC_EDIT3, m_strName);
	DDX_Text(pDX, IDC_EDIT4, m_iHp);
	DDX_Text(pDX, IDC_EDIT5, m_iAttack);
	DDX_Text(pDX, IDC_EDIT6, m_strSearch);
	DDX_Text(pDX, IDC_EDIT7, m_iTest);

	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_RADIO1, m_Radio[0]);
	DDX_Control(pDX, IDC_RADIO2, m_Radio[1]);
	DDX_Control(pDX, IDC_RADIO3, m_Radio[2]);

	DDX_Control(pDX, IDC_CHECK1, m_Check[0]);
	DDX_Control(pDX, IDC_CHECK2, m_Check[1]);
	DDX_Control(pDX, IDC_CHECK3, m_Check[2]);
	
}


BEGIN_MESSAGE_MAP(CUnitTool, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CUnitTool::OnPushString)
	ON_BN_CLICKED(IDC_BUTTON2, &CUnitTool::OnAdd_Charactor)
	ON_LBN_SELCHANGE(IDC_LIST1, &CUnitTool::OnListBox)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON3, &CUnitTool::OnSaveClicked)
	ON_BN_CLICKED(IDC_BUTTON4, &CUnitTool::OnLoadClicked)
	ON_BN_CLICKED(IDC_BUTTON5, &CUnitTool::OnSearchClicked)
	ON_BN_CLICKED(IDC_BUTTON6, &CUnitTool::OnDeleteClicked)
END_MESSAGE_MAP()


// CUnitTool 메시지 처리기입니다.


void CUnitTool::OnPushString()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);  // 다이얼로그 박스로부터 입려된 값들을 얻어옴
		
	m_strCopy = m_strTemp;

	UpdateData(FALSE);  // 변수에 저장된 값들을 다이얼로그 박스에 반영

}


void CUnitTool::OnAdd_Charactor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	UNITDATA*		pUnit = new UNITDATA;

	pUnit->strName = m_strName;
	pUnit->iAttack = m_iAttack;
	pUnit->iHp = m_iHp;

	for (int i = 0; i < 3; ++i)
	{
		// GetCheck : 현재 라디오 버튼이 체크되어있는지 유무 판단
		if (m_Radio[i].GetCheck())
		{
			pUnit->byJobIndex = i;
			break;
		}
	}

	// AddString : 리스트 박스에 문자열을 추가 함
	m_ListBox.AddString(pUnit->strName);

	m_MapUnitData.insert({pUnit->strName, pUnit});

	UpdateData(FALSE);
}


void CUnitTool::OnListBox()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString		strFindName;

	// GetCurSel : 현재 리스트 박스에서 선택된 셀의 인덱스 값을 반환
	int iSelect = m_ListBox.GetCurSel();

	// GetText : 현재 인덱스에 해당하는 문자열을 리스트 박스로부터 얻어옴
	m_ListBox.GetText(iSelect, strFindName);

	auto	iter = m_MapUnitData.find(strFindName);

	if (iter == m_MapUnitData.end())
		return;

	m_strName = iter->second->strName;
	m_iAttack = iter->second->iAttack;
	m_iHp = iter->second->iHp;

	for (int i = 0; i < 3; ++i)
		m_Radio[i].SetCheck(FALSE);	// 모든 라디오 버튼 체크 해제

	m_Radio[iter->second->byJobIndex].SetCheck(TRUE);

	UpdateData(FALSE);
}


void CUnitTool::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	for_each(m_MapUnitData.begin(), m_MapUnitData.end(), CDeleteMap());
	m_MapUnitData.clear();

}


BOOL CUnitTool::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_Radio[0].SetCheck(TRUE); 

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CUnitTool::OnSaveClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Save_Data();
}


void CUnitTool::OnLoadClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Load_Data();
}


void CUnitTool::OnSearchClicked()
{
	UpdateData(TRUE);
	int count = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_ListBox.SetCurSel(5);
	for (auto& iter : m_MapUnitData)
	{
		if (iter.first == m_strSearch)
		{		
			m_ListBox.SetCurSel(count);
			m_Radio[iter.second->byJobIndex].SetCheck(true);			
			m_strName = iter.second->strName;
			m_iAttack = iter.second->iAttack;
			m_iHp = iter.second->iHp;			
		}
		++count;
	}
	UpdateData(FALSE);
}
 


void CUnitTool::OnDeleteClicked()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CUnitTool::Save_Data()
{
	
	//WriteFile(hFile, &wc, sizeof(wc), &dwByte, NULL); 

	HANDLE		hFile = CreateFile(L"../Data/UnitData.dat",			// 파일 경로와 이름 명시
		GENERIC_WRITE,				// 파일 접근 모드 (GENERIC_WRITE 쓰기 전용, GENERIC_READ 읽기 전용)
		NULL,						// 공유방식, 파일이 열려있는 상태에서 다른 프로세스가 오픈할 때 허용할 것인가, NULL인 경우 공유하지 않는다
		NULL,						// 보안 속성, 기본값	
		CREATE_ALWAYS,				// 생성 방식, CREATE_ALWAYS는 파일이 없다면 생성, 있다면 덮어 쓰기, OPEN_EXISTING 파일이 있을 경우에면 열기
		FILE_ATTRIBUTE_NORMAL,		// 파일 속성(읽기 전용, 숨기 등), FILE_ATTRIBUTE_NORMAL 아무런 속성이 없는 일반 파일 생성
		NULL);						// 생성도리 파일의 속성을 제공할 템플릿 파일, 우리는 사용하지 않아서 NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		// 팝업 창을 출력해주는 기능의 함수
		// 1. 핸들 2. 팝업 창에 띄우고자하는 메시지 3. 팝업 창 이름 4. 버튼 속성
		AfxMessageBox(L"저장실패");
		return;
	}
	

	DWORD		dwByte = 0;
	
	for (auto& iter : m_MapUnitData)
	{
		int iLength = (iter.second->strName.GetLength() + 1) * sizeof(TCHAR);

		/*string str;
		str.c_str();
		char;

		wstring str2;
		str2.c_str();*/

		CString str1;
		str1.GetString();
		

		WriteFile(hFile, &iLength, sizeof(int), &dwByte, nullptr);
		WriteFile(hFile, iter.second->strName.GetString(), iLength, &dwByte, nullptr);
		WriteFile(hFile, &iter.second->iAttack, sizeof(int), &dwByte, nullptr);
		WriteFile(hFile, &iter.second->iHp, sizeof(int), &dwByte, nullptr);
		WriteFile(hFile, &iter.second->byItem, sizeof(BYTE), &dwByte, nullptr);
		WriteFile(hFile, &iter.second->byJobIndex, sizeof(BYTE), &dwByte, nullptr);
	}

	// 3. 파일 소멸
	CloseHandle(hFile);

	AfxMessageBox(L"저장성공");
}

void CUnitTool::Load_Data()
{
	UpdateData(TRUE);  // 다이얼로그 박스로부터 입려된 값들을 얻어옴

	HANDLE		hFile = CreateFile(L"../Data/UnitData.dat",			// 파일 경로와 이름 명시
		GENERIC_READ,				// 파일 접근 모드 (GENERIC_WRITE 쓰기 전용, GENERIC_READ 읽기 전용)
		NULL,						// 공유방식, 파일이 열려있는 상태에서 다른 프로세스가 오픈할 때 허용할 것인가, NULL인 경우 공유하지 않는다
		NULL,						// 보안 속성, 기본값	
		OPEN_EXISTING,				// 생성 방식, CREATE_ALWAYS는 파일이 없다면 생성, 있다면 덮어 쓰기, OPEN_EXISTING 파일이 있을 경우에면 열기
		FILE_ATTRIBUTE_NORMAL,		// 파일 속성(읽기 전용, 숨기 등), FILE_ATTRIBUTE_NORMAL 아무런 속성이 없는 일반 파일 생성
		NULL);						// 생성도리 파일의 속성을 제공할 템플릿 파일, 우리는 사용하지 않아서 NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		// 팝업 창을 출력해주는 기능의 함수
		// 1. 핸들 2. 팝업 창에 띄우고자하는 메시지 3. 팝업 창 이름 4. 버튼 속성
		AfxMessageBox(L"불러오기실패");
		return;
	}

	// 2. 파일 쓰기

	for (auto& iter : m_MapUnitData)
	{
		Safe_Delete(iter.second);
		
	}
	m_ListBox.ResetContent();
	m_MapUnitData.clear();



	DWORD		dwByte = 0;

	int iLength = 0;

	while (true)
	{
		UNITDATA* pData = new UNITDATA;

		ReadFile(hFile, &iLength, sizeof(int), &dwByte, nullptr);
		TCHAR* pStr = new TCHAR[iLength];
		ZeroMemory(pStr, sizeof(TCHAR) * iLength);
		ReadFile(hFile, pStr, iLength, &dwByte, nullptr);

		CString strName = pStr;
		pData->strName = strName;

		ReadFile(hFile, &pData->iAttack, sizeof(int), &dwByte, nullptr);
		ReadFile(hFile, &pData->iHp, sizeof(int), &dwByte, nullptr);
		ReadFile(hFile, &pData->byItem, sizeof(BYTE), &dwByte, nullptr);
		ReadFile(hFile, &pData->byJobIndex, sizeof(BYTE), &dwByte, nullptr);
		
		if (0 == dwByte)	// 더이상 읽을 데이터가 없을 경우
			break;
		
		delete[] pStr;

		m_ListBox.AddString(pData->strName);

		//m_MapUnitData.emplace(tInfo.strName, pData);

		//m_MapUnitData[tInfo.strName] = pData;
		
		m_MapUnitData.insert({ pData->strName, pData });
	}

	// 3. 파일 소멸
	CloseHandle(hFile);

	AfxMessageBox(L"불러오기성공");

	UpdateData(FALSE);  // 변수에 저장된 값들을 다이얼로그 박스에 반영

}