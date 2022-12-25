// Monster.h: interface for the Monster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MONSTER_H__D553D855_7107_4059_9974_48DF2E5E135C__INCLUDED_)
#define AFX_MONSTER_H__D553D855_7107_4059_9974_48DF2E5E135C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MoveableEntity.h"
#include "AnimationFrame.h"

class CMonster : public CMoveableEntity {
public:
	static enum MONSTER_TYPE {
		PUPU,
		SABI,
		PINK_PIG,
		BOSS_AMBER,
		BLUE_PIG,
	};

	static enum MONSTER_STATE {
		STAND,
		ATTACK,
		HIT
	};

public:
	CMonster();
	virtual ~CMonster();

	void Init();
	void SetPlayer( IEntity* p ) {
		pPlayer = p;
	}

	virtual void Update();
	virtual void Render(int nXIndex, int nYIndex);

	bool MoveNorth();
	bool MoveSouth();
	bool MoveEast();
	bool MoveWest();
	bool MoveBack();

	void SetMonsterType( MONSTER_TYPE type ) {
		nType = type;
	}

	virtual void Hit();
	virtual int Dead();

public:
	CAnimationFrame WalkEast;
	CAnimationFrame WalkWest;
	CAnimationFrame WalkSouth;
	CAnimationFrame WalkNorth;
	
	MONSTER_TYPE nType;
	MONSTER_STATE nState;
	DWORD TickCount;

	float nMoveSpeed;
	
	IEntity*		pPlayer;
	CHARACTER_DIR	WhenThePlayerDir;
	float			HitDelta;
};

#endif // !defined(AFX_MONSTER_H__D553D855_7107_4059_9974_48DF2E5E135C__INCLUDED_)
