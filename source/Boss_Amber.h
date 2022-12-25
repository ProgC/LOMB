// Boss_Amber.h: interface for the CBoss_Amber class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOSS_AMBER_H__40577818_0D9C_4EB2_B133_D8CD1294DCFB__INCLUDED_)
#define AFX_BOSS_AMBER_H__40577818_0D9C_4EB2_B133_D8CD1294DCFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MonsterAI.h"
#include "Kstate.h"
#include "2D/vector2d.h"

class CBoss_Amber : public CMonsterAI {
public:
	CBoss_Amber();
	virtual ~CBoss_Amber();

	Vector2D GetCurrentPoint() {
		return Point[nSelectedPointIndex];
	}
	Vector2D GetCurrentPointX() {
		return PointX[nSelectedPointIndex];
	}
public:	
	void Update();
	void Render(int nXIndex, int nYIndex);
	void Hit();
	int Dead();

	void ChangeState(KState* new_state);

	KState*                m_pCurrentState;
	int nSelectedCount;
	int nCurCount;
	int nSelectedPointIndex;

	Vector2D Point[4];
	Vector2D PointX[4];
	DWORD dwAttackTime;
};

#endif // !defined(AFX_BOSS_AMBER_H__40577818_0D9C_4EB2_B133_D8CD1294DCFB__INCLUDED_)
