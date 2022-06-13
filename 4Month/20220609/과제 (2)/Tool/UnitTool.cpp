// UnitTool.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "UnitTool.h"
#include "afxdialogex.h"


// CUnitTool ��ȭ �����Դϴ�.

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
	// DoDataExchange : UpdateData�Լ��� ȣ���� ������ �ڵ�ȣ��Ǵ� �Լ�


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


// CUnitTool �޽��� ó�����Դϴ�.


void CUnitTool::OnPushString()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);  // ���̾�α� �ڽ��κ��� �Է��� ������ ����
		
	m_strCopy = m_strTemp;

	UpdateData(FALSE);  // ������ ����� ������ ���̾�α� �ڽ��� �ݿ�

}


void CUnitTool::OnAdd_Charactor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	UNITDATA*		pUnit = new UNITDATA;

	pUnit->strName = m_strName;
	pUnit->iAttack = m_iAttack;
	pUnit->iHp = m_iHp;

	for (int i = 0; i < 3; ++i)
	{
		// GetCheck : ���� ���� ��ư�� üũ�Ǿ��ִ��� ���� �Ǵ�
		if (m_Radio[i].GetCheck())
		{
			pUnit->byJobIndex = i;
			break;
		}
	}

	// AddString : ����Ʈ �ڽ��� ���ڿ��� �߰� ��
	m_ListBox.AddString(pUnit->strName);

	m_MapUnitData.insert({pUnit->strName, pUnit});

	UpdateData(FALSE);
}


void CUnitTool::OnListBox()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString		strFindName;

	// GetCurSel : ���� ����Ʈ �ڽ����� ���õ� ���� �ε��� ���� ��ȯ
	int iSelect = m_ListBox.GetCurSel();

	// GetText : ���� �ε����� �ش��ϴ� ���ڿ��� ����Ʈ �ڽ��κ��� ����
	m_ListBox.GetText(iSelect, strFindName);

	auto	iter = m_MapUnitData.find(strFindName);

	if (iter == m_MapUnitData.end())
		return;

	m_strName = iter->second->strName;
	m_iAttack = iter->second->iAttack;
	m_iHp = iter->second->iHp;

	for (int i = 0; i < 3; ++i)
		m_Radio[i].SetCheck(FALSE);	// ��� ���� ��ư üũ ����

	m_Radio[iter->second->byJobIndex].SetCheck(TRUE);

	UpdateData(FALSE);
}


void CUnitTool::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	for_each(m_MapUnitData.begin(), m_MapUnitData.end(), CDeleteMap());
	m_MapUnitData.clear();

}


BOOL CUnitTool::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_Radio[0].SetCheck(TRUE); 

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CUnitTool::OnSaveClicked()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Save_Data();
}


void CUnitTool::OnLoadClicked()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Load_Data();
}


void CUnitTool::OnSearchClicked()
{
	UpdateData(TRUE);
	int count = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CUnitTool::Save_Data()
{
	
	//WriteFile(hFile, &wc, sizeof(wc), &dwByte, NULL); 

	HANDLE		hFile = CreateFile(L"../Data/UnitData.dat",			// ���� ��ο� �̸� ���
		GENERIC_WRITE,				// ���� ���� ��� (GENERIC_WRITE ���� ����, GENERIC_READ �б� ����)
		NULL,						// �������, ������ �����ִ� ���¿��� �ٸ� ���μ����� ������ �� ����� ���ΰ�, NULL�� ��� �������� �ʴ´�
		NULL,						// ���� �Ӽ�, �⺻��	
		CREATE_ALWAYS,				// ���� ���, CREATE_ALWAYS�� ������ ���ٸ� ����, �ִٸ� ���� ����, OPEN_EXISTING ������ ���� ��쿡�� ����
		FILE_ATTRIBUTE_NORMAL,		// ���� �Ӽ�(�б� ����, ���� ��), FILE_ATTRIBUTE_NORMAL �ƹ��� �Ӽ��� ���� �Ϲ� ���� ����
		NULL);						// �������� ������ �Ӽ��� ������ ���ø� ����, �츮�� ������� �ʾƼ� NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		// �˾� â�� ������ִ� ����� �Լ�
		// 1. �ڵ� 2. �˾� â�� �������ϴ� �޽��� 3. �˾� â �̸� 4. ��ư �Ӽ�
		AfxMessageBox(L"�������");
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

	// 3. ���� �Ҹ�
	CloseHandle(hFile);

	AfxMessageBox(L"���强��");
}

void CUnitTool::Load_Data()
{
	UpdateData(TRUE);  // ���̾�α� �ڽ��κ��� �Է��� ������ ����

	HANDLE		hFile = CreateFile(L"../Data/UnitData.dat",			// ���� ��ο� �̸� ���
		GENERIC_READ,				// ���� ���� ��� (GENERIC_WRITE ���� ����, GENERIC_READ �б� ����)
		NULL,						// �������, ������ �����ִ� ���¿��� �ٸ� ���μ����� ������ �� ����� ���ΰ�, NULL�� ��� �������� �ʴ´�
		NULL,						// ���� �Ӽ�, �⺻��	
		OPEN_EXISTING,				// ���� ���, CREATE_ALWAYS�� ������ ���ٸ� ����, �ִٸ� ���� ����, OPEN_EXISTING ������ ���� ��쿡�� ����
		FILE_ATTRIBUTE_NORMAL,		// ���� �Ӽ�(�б� ����, ���� ��), FILE_ATTRIBUTE_NORMAL �ƹ��� �Ӽ��� ���� �Ϲ� ���� ����
		NULL);						// �������� ������ �Ӽ��� ������ ���ø� ����, �츮�� ������� �ʾƼ� NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		// �˾� â�� ������ִ� ����� �Լ�
		// 1. �ڵ� 2. �˾� â�� �������ϴ� �޽��� 3. �˾� â �̸� 4. ��ư �Ӽ�
		AfxMessageBox(L"�ҷ��������");
		return;
	}

	// 2. ���� ����

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
		
		if (0 == dwByte)	// ���̻� ���� �����Ͱ� ���� ���
			break;
		
		delete[] pStr;

		m_ListBox.AddString(pData->strName);

		//m_MapUnitData.emplace(tInfo.strName, pData);

		//m_MapUnitData[tInfo.strName] = pData;
		
		m_MapUnitData.insert({ pData->strName, pData });
	}

	// 3. ���� �Ҹ�
	CloseHandle(hFile);

	AfxMessageBox(L"�ҷ����⼺��");

	UpdateData(FALSE);  // ������ ����� ������ ���̾�α� �ڽ��� �ݿ�

}