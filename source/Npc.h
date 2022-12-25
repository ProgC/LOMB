// Npc.h: interface for the CNpc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NPC_H__4E8B7ECA_4CF3_4F16_889D_C648DD8555D8__INCLUDED_)
#define AFX_NPC_H__4E8B7ECA_4CF3_4F16_889D_C648DD8555D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IEntity.h"
#include "MoveableEntity.h"
#include "AnimationFrame.h"

class CNpc : public CMoveableEntity {
public:
	static enum NPC_TYPE {
		SMITH,
		UJIN,
		EAN,
		ARTIUS,
		FISHGUY,
		KUO,
	};

	static enum NPC_STATE {
		STAND,
		ATTACK,
		HIT
	};

public:
	CNpc();
	virtual ~CNpc();

public:
	void Init();
	void SetPlayer( IEntity* p ) {
		pPlayer = p;
	}

	void Update();
	void Render(int nXIndex, int nYIndex);

	bool MoveNorth();
	bool MoveSouth();
	bool MoveEast();
	bool MoveWest();
	bool MoveBack();

	void SetNpcType( NPC_TYPE type ) {
		nType = type;
	}


	void Hit();
	int Dead();
	
public:
	CAnimationFrame WalkEast;
	CAnimationFrame WalkWest;
	CAnimationFrame WalkSouth;
	CAnimationFrame WalkNorth;
		
	NPC_TYPE nType;
	NPC_STATE nState;
	DWORD TickCount;
	CHARACTER_DIR	WhenThePlayerDir;

	IEntity*		pPlayer;
	float			HitDelta;
};

#endif // !defined(AFX_NPC_H__4E8B7ECA_4CF3_4F16_889D_C648DD8555D8__INCLUDED_)
