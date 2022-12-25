// Map.h: interface for the CMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP_H__35561B45_7F5F_4E87_A209_64D966C4284E__INCLUDED_)
#define AFX_MAP_H__35561B45_7F5F_4E87_A209_64D966C4284E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 이벤트를 모두 정의한다.
// 예를 들어 0번은 스크립트 xx를 불러 온다.
// 1번은 사운드를 출력한다.
// 2번은 맵을 이동한다. 등등...

#define ME_LOAD_BOSS_1 1

#include "TileProperty.h"
#include "IEntity.h"
#include "MoveableEntity.h"

typedef struct tagMob {
	int MobID;
	int nRespwan;
	int nWorldX;
	int nWorldY;
} s_Mob;

typedef struct tagNpc {
	int NpcID;
	int nWorldX;
	int nWorldY;
} s_Npc;

class CMap {
public:
	CMap();
	virtual ~CMap();
	
public:
	void LoadMap(FILE* fp);

	void Update();
	void Render();
	void Process( int nEvent );
public:
	// 가로, 세로 100
	// 타일 크기 16
	// 전체 크기는 160 x 160이다.
	
	CTileProperty m_Map[10][10];
	int nCountOfMob;
	vector<s_Mob> vecMob;

	int nCountOfNpc;
	vector<s_Npc> vecNpc;
};

#endif // !defined(AFX_MAP_H__35561B45_7F5F_4E87_A209_64D966C4284E__INCLUDED_)
