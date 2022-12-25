// Map.h: interface for the CMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP_H__35561B45_7F5F_4E87_A209_64D966C4284E__INCLUDED_)
#define AFX_MAP_H__35561B45_7F5F_4E87_A209_64D966C4284E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// �̺�Ʈ�� ��� �����Ѵ�.
// ���� ��� 0���� ��ũ��Ʈ xx�� �ҷ� �´�.
// 1���� ���带 ����Ѵ�.
// 2���� ���� �̵��Ѵ�. ���...

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
	// ����, ���� 100
	// Ÿ�� ũ�� 16
	// ��ü ũ��� 160 x 160�̴�.
	
	CTileProperty m_Map[10][10];
	int nCountOfMob;
	vector<s_Mob> vecMob;

	int nCountOfNpc;
	vector<s_Npc> vecNpc;
};

#endif // !defined(AFX_MAP_H__35561B45_7F5F_4E87_A209_64D966C4284E__INCLUDED_)
