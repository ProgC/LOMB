// PinkPig.h: interface for the CPinkPig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINKPIG_H__AEADFA18_A4B4_4B9B_8209_C0C8A0AAE68C__INCLUDED_)
#define AFX_PINKPIG_H__AEADFA18_A4B4_4B9B_8209_C0C8A0AAE68C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MonsterAI.h"
#include "Kstate.h"
#include "2D/vector2d.h"

class CPinkPig : public CMonsterAI {
public:
	CPinkPig();
	virtual ~CPinkPig();
	
	Vector2D GetCurrentPoint() {
		return Point[nSelectedPointIndex];
	}
	Vector2D GetCurrentPointX() {
		return PointX[nSelectedPointIndex];
	}

	inline int GetFieldOfView() const {
		return nFieldOfView;
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
	
	int nFieldOfView;
};

#endif // !defined(AFX_PINKPIG_H__AEADFA18_A4B4_4B9B_8209_C0C8A0AAE68C__INCLUDED_)
