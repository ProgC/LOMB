// Bullet_MagicBall.h: interface for the Bullet_MagicBall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BULLET_MAGICBALL_H__29DB43DE_26B5_402C_8F6A_CA8FF83CBF99__INCLUDED_)
#define AFX_BULLET_MAGICBALL_H__29DB43DE_26B5_402C_8F6A_CA8FF83CBF99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bullet.h"

class CBullet_MagicBall : public CBullet {
public:
	CBullet_MagicBall();
	virtual ~CBullet_MagicBall();

	void Init();
	void Update();
	void Render(int nXIndex, int nYIndex);

private:
	Vector2D m_Pos[3]; // 2개의 현재 위치
	Vector2D m_Vel[3]; // 2개 객체
	Vector2D m_Acc[3]; // 가속

	CAnimationFrame SecondBulletFrame[5];
};

#endif // !defined(AFX_BULLET_MAGICBALL_H__29DB43DE_26B5_402C_8F6A_CA8FF83CBF99__INCLUDED_)
