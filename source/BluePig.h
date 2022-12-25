// BluePig.h: interface for the CBluePig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLUEPIG_H__9A78CBFC_932C_4135_97F2_8CA89CCFC6EA__INCLUDED_)
#define AFX_BLUEPIG_H__9A78CBFC_932C_4135_97F2_8CA89CCFC6EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "MonsterAI.h"
#include "Kstate.h"
#include "2D/vector2d.h"

class CBluePig : public CMonsterAI {
public:
	CBluePig();
	virtual ~CBluePig();

	inline int GetFieldOfView() const {
		return nFieldOfView;
	}
public:
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
	
	int nSelectedDir;
	int nFieldOfView;
};

#endif // !defined(AFX_BLUEPIG_H__9A78CBFC_932C_4135_97F2_8CA89CCFC6EA__INCLUDED_)
