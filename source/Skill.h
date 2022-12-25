// Skill.h: interface for the CSkill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKILL_H__AFC8D4AB_6DBC_41A1_9F4E_6B183ED9E995__INCLUDED_)
#define AFX_SKILL_H__AFC8D4AB_6DBC_41A1_9F4E_6B183ED9E995__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>

class CSkill {
public:
	static enum SKILL_TYPE {
		RUN,
		HEILLING,
		MAGIC_BALL,
	};

public:
	CSkill();
	virtual ~CSkill();

	void Update();
	
	void SetSkill( SKILL_TYPE nType_ );
	void SetTime( DWORD second ) {
		nSaveTick = GetTickCount();
		nTickCount = second+ 3000;
	}
public:
	SKILL_TYPE		nType;
	DWORD			nTickCount; // 몇 초 동안
	DWORD			nSaveTick;
	static int		nMana[30];	  // 소요되는 마나
};

#endif // !defined(AFX_SKILL_H__AFC8D4AB_6DBC_41A1_9F4E_6B183ED9E995__INCLUDED_)
