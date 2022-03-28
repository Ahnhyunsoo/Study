#include "stdafx.h"

class CObj
{
public:
	void	Render(void) { cout << "Obj" << endl; }
};
class CPlayer : public CObj
{
public:
	void	Print(void) { cout << "Player" << endl; }
};
class CThief : public CPlayer
{
public:
	void	Draw(void) { cout << "Thief" << endl; }
};

void main(void)
{
	/*CObj*		pObj = new CObj;

	 pObj->Render();	
	 pObj->Print();
	 pObj->Draw();*/
	
	/*CThief*		pThief	= new CThief;
	CPlayer*	pPlayer = pThief;
	CObj*		pObj	= pPlayer;

	 pPlayer->Render();
	 pPlayer->Print();
	 pPlayer->Draw();*/

	//CObj*		pObj = new CThief;
	
	//pObj->Render();
	//pObj->Print();
	//pObj->Draw();
}

