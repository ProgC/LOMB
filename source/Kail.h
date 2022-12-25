// Kail.h: interface for the Kail class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KAIL_H__406B649A_31B2_43E6_9E7A_1075BF4E009A__INCLUDED_)
#define AFX_KAIL_H__406B649A_31B2_43E6_9E7A_1075BF4E009A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IEntity.h"
#include "MoveableEntity.h"
#include "AnimationFrame.h"

#include "Skill.h"
#include "Inventory.h"

class Kail : public CMoveableEntity {
public:
	static enum CHARACTER_STATE {
		STAND,
		ATTACK,
		SKILL
	};

public:
	Kail();
	virtual ~Kail();
	
	void Init();
	void Update();
	void Render(int nXIndex, int nYIndex);

	void InputA();
	void InputB();

	bool MoveNorth();
	bool MoveSouth();
	bool MoveEast();
	bool MoveWest();
	bool MoveBack();

	void Attack();
	void Skill( CSkill::SKILL_TYPE nType );
	void GetMoney( int nMoney_ );
	void UseItem( int index );

	void SetLevel();
	void TakeHealth();
	void TakeMana();

	CHARACTER_STATE GetState() const {
		return nState;
	}

	void Hit();
	int Dead();

	void ResetCharacterState() {
		nState = STAND;
	}

	void Recover();
public:
	CAnimationFrame WalkEast;
	CAnimationFrame WalkWest;
	CAnimationFrame WalkSouth;
	CAnimationFrame WalkNorth;

	CAnimationFrame AttackEast;
	CAnimationFrame AttackWest;
	CAnimationFrame AttackSouth;
	CAnimationFrame AttackNorth;

	CAnimationFrame SkillApply;

	CHARACTER_STATE nState;
	
	int nLevel;
	int nCurrentExp;
	int nNextExp;

	int nCurMana;
	
	int BaseSpeed;
	// 스피드 스킬
	int SkillSpeed;

	int nMoney;
	
	int nSelectedSkill;

	vector<CSkill*> vecSkill;
	CInventory		Inventory;
};

#endif // !defined(AFX_KAIL_H__406B649A_31B2_43E6_9E7A_1075BF4E009A__INCLUDED_)
