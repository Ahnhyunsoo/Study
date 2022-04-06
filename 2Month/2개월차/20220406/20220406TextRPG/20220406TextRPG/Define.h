#pragma once
#define SAVE_DELETE(p) if(p) {delete p; p = nullptr;}
#define p Game::m_pp
#define iv Game::m_pp->Getip()->GetInven()
