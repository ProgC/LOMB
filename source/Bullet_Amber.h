// Bullet_Amber.h: interface for the CBullet_Amber class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BULLET_AMBER_H__A0A056EB_D8E1_4022_8CDF_740555146CDF__INCLUDED_)
#define AFX_BULLET_AMBER_H__A0A056EB_D8E1_4022_8CDF_740555146CDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bullet.h"

class CBullet_Amber : public CBullet {
public:
	CBullet_Amber();
	virtual ~CBullet_Amber();

	void Init();
	void Update();
	void Render(int nXIndex, int nYIndex);

};

#endif // !defined(AFX_BULLET_AMBER_H__A0A056EB_D8E1_4022_8CDF_740555146CDF__INCLUDED_)
