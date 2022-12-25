// Item.h: interface for the Item class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEM_H__96F1C463_355E_465B_B460_51A212327292__INCLUDED_)
#define AFX_ITEM_H__96F1C463_355E_465B_B460_51A212327292__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IEntity.h"
#include "MoveableEntity.h"
#include "AnimationFrame.h"

class Item : public CMoveableEntity {
public:
	static enum ITEM_TYPE { IT_MONEY, IT_DIARY };
public:
	Item();
	virtual ~Item();

public:
	void Init();
	void Update();
	void Render(int nXIndex, int nYIndex);

	bool MoveNorth();
	bool MoveSouth();
	bool MoveEast();
	bool MoveWest();
	bool MoveBack();
	
	void Attack();
	
	void Hit();
	int Dead();
public:
	void SetItemType( int nType_ ) {
		nItemType = nType_;
	}
public:
	int nItemType;
	CAnimationFrame ItemFrame;
	float oY;
};

#endif // !defined(AFX_ITEM_H__96F1C463_355E_465B_B460_51A212327292__INCLUDED_)
