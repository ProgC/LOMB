// Bullet.h: interface for the CBullet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BULLET_H__E6E015F6_3134_4B30_9365_EC6569AF013E__INCLUDED_)
#define AFX_BULLET_H__E6E015F6_3134_4B30_9365_EC6569AF013E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IEntity.h"
#include "MoveableEntity.h"
#include "AnimationFrame.h"
#include "2D/vector2d.h"

class CBullet : public CMoveableEntity {
public:
	CBullet();
	virtual ~CBullet();
public:
	static enum BULLET_TYPE { AMBER_BULLET, PINK_PIG_BULLET, KAIL_MAGIC_BALL };
	
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(int nXIndex, int nYIndex);

	bool MoveNorth();
	bool MoveSouth();
	bool MoveEast();
	bool MoveWest();
	bool MoveBack();

	void Attack();

    int WhoMadeThis() const {
		switch ( nItemType ) {
			case AMBER_BULLET:
				return 0;
			break;
			case PINK_PIG_BULLET:
				return 0;
			break;
			case KAIL_MAGIC_BALL:
				return 1;
			break;
		}

		return 0;
	}
	
	void Hit();
	int Dead();
public:
	void SetBulletType( int nType_ ) {
		nItemType = nType_;
	}
public:
	int nItemType;
	CAnimationFrame BulletFrame;
	float oY;
	Vector2D mDir;

	float fVelocity;
};

#endif // !defined(AFX_BULLET_H__E6E015F6_3134_4B30_9365_EC6569AF013E__INCLUDED_)
