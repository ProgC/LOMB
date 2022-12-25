#include "global.h"
#include "Game.h"
#include "Monster.h"
#include "MonsterAI.h"
#include "Boss_Amber.h"
#include "PinkPig.h"
#include "BluePig.h"
#include "Bullet.h"
#include "Npc.h"
#include "BulletFactory.h"

// stagex, stagey�� �ش��ϴ� mobID�� �˻��ؼ� ��� ������ 1�� ���� �ƴϸ� 0
bool CGame::IsDestoryedMob( int mobID, int stageX, int stageY ) {
	int i = 0;
	int nCountOfObject = vecObjList.size();

	for ( i = 0; i < nCountOfObject; i++ ) {
		if ( IEntity::MONSTER == vecObjList[i]->EntityType ) {
			if ( ((CMonster*)vecObjList[i])->nType == mobID ) {
				if ( ((CMonster*)vecObjList[i])->GetWorldXIndex() == stageX && 
					 ((CMonster*)vecObjList[i])->GetWorldYIndex() == stageY ) {
					return 0;
				}
			}			
		}
	}
	return 1;	
}

void CGame::AddMonster( int nMobID, int nX, int nY ) {
	CMonsterAI *pMonster = NULL;
	
	if ( nMobID == CMonster::PUPU ) {
		pMonster = new CMonsterAI();
	} else if ( nMobID == CMonster::SABI ) {
		pMonster = new CMonsterAI();
	} else if ( nMobID == CMonster::PINK_PIG ) {
		pMonster = new CPinkPig();
	} else if ( nMobID == CMonster::BOSS_AMBER ) {
		pMonster = new CBoss_Amber();
	} else if ( nMobID == CMonster::BLUE_PIG ) {
		pMonster = new CBluePig();
	}
		
	// ������ǥ ����
	pMonster->SetWorldX( nX );
	pMonster->SetWorldY( nY );
	
	pMonster->SetMonsterType( (CMonster::MONSTER_TYPE)nMobID );
	pMonster->Init();
	pMonster->SetPlayer( pKail );
	vecObjList.push_back( pMonster );
}

// �ڵ������� �˾Ƽ� ���� �͵�
void CGame::AddBullet( int BulletType, int nX, int nY  ) {
	CBullet *pBullet = NULL;

	CBulletFactory Factory;
	pBullet = Factory.MakeBullet( BulletType );
			
	// ������ǥ ����
	pBullet->SetWorldX( nX );
	pBullet->SetWorldY( nY );
	
	pBullet->Init();
	vecBulletList.push_back( pBullet );
}

void CGame::AddBullet( int BulletType, int nX, int nY, float nDx, float nDy ) {
	CBullet *pBullet = NULL;

	CBulletFactory Factory;
	pBullet = Factory.MakeBullet( BulletType );
	//pBullet = new CBullet();
		
	// ������ǥ ����
	pBullet->SetWorldX( nX );
	pBullet->SetWorldY( nY );
	pBullet->mDir.x = nDx;
	pBullet->mDir.y = nDy;
	
	//pBullet->SetBulletType( (CBullet::BULLET_TYPE)BulletType );
	pBullet->Init();
	vecBulletList.push_back( pBullet );
}

void CGame::AddBullet( int BulletType, int nX, int nY, float nDx, float nDy, CHARACTER_DIR dir ) {
	CBullet *pBullet = NULL;

	CBulletFactory Factory;
	pBullet = Factory.MakeBullet( BulletType );

	//pBullet = new CBullet();
		
	// ������ǥ ����
	pBullet->SetWorldX( nX );
	pBullet->SetWorldY( nY );
	pBullet->mDir.x = nDx;
	pBullet->mDir.y = nDy;
	pBullet->nDir = dir;
	
	//pBullet->SetBulletType( (CBullet::BULLET_TYPE)BulletType );
	pBullet->Init();
	vecBulletList.push_back( pBullet );
}

// npc�� �߰��Ѵ�.
void CGame::AddNpc( int nNpcID, int nX, int nY ) {
	CNpc *pNpc = new CNpc();
	
	// ������ǥ ����
	pNpc->SetWorldX( nX );
	pNpc->SetWorldY( nY );
	
	pNpc->SetNpcType( (CNpc::NPC_TYPE)nNpcID );
	pNpc->Init();
	pNpc->SetPlayer( pKail );
	vecObjList.push_back( pNpc );
}

