// Bullet_Pink_Pig.h: interface for the CBullet_Pink_Pig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BULLET_PINK_PIG_H__D7230AEF_0F73_4DB6_9CBA_08ACDC89C3BC__INCLUDED_)
#define AFX_BULLET_PINK_PIG_H__D7230AEF_0F73_4DB6_9CBA_08ACDC89C3BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bullet.h"

class CBullet_Pink_Pig : public CBullet {
public:
	CBullet_Pink_Pig();
	virtual ~CBullet_Pink_Pig();

	void Init();
	void Update();
	void Render(int nXIndex, int nYIndex);
};

#endif // !defined(AFX_BULLET_PINK_PIG_H__D7230AEF_0F73_4DB6_9CBA_08ACDC89C3BC__INCLUDED_)
