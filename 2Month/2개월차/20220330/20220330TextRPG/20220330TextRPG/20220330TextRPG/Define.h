#pragma once

#define SAVE_DELETE(p) if(p) {delete p; p = nullptr;}
#define HP() static_cast<CPlayer*>(Maingame::m_pp)->GetDamage()
#define C()static_cast<CPlayer*>(Maingame::m_pp)
#define PrintP() Maingame::m_pp->Print()


