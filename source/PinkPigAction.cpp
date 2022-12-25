// PinkPigAction.cpp: implementation of the CPinkPigAction class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "MonsterAI.h"
#include "PinkPig.h"
#include "BossAmberAction.h"
#include "PinkPigAction.h"
#include "Bullet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CPinkPigAction_Stand* CPinkPigAction_Stand::Instance() {
  static CPinkPigAction_Stand instance;
  return &instance;
}

void CPinkPigAction_Stand::Enter(CMonsterAI* pObj) {

}

void CPinkPigAction_Stand::Execute(CMonsterAI* pObj) {
	// ������ �Ÿ��� �˻��ؼ� 3������ �з� �ȴ�.
	// ������ ���󰡼� (�׳� �ε����� �� �����ε� ����ϴ�)
	// �������� �ָ� �������� �̻��� ����
	// ��պ�� �Ÿ���

	CPinkPig* pPinkPig = (CPinkPig*)pObj;

	Vector2D PlayerPos;
	Vector2D PigPos;
	PlayerPos.x = pObj->pPlayer->GetWorldX();
	PlayerPos.y = pObj->pPlayer->GetWorldY();
	PigPos.x = pPinkPig->GetWorldX();
	PigPos.y = pPinkPig->GetWorldY();

	double dLen = PigPos.Distance( PlayerPos );

	if ( dLen < pPinkPig->GetFieldOfView() ) { // �Ÿ� �ȿ� �ִٸ� �������� ���� ��ȯ
		// 70%�� 
		int nRnd = rand() % 100;
		if ( nRnd > 70 ) {
			pPinkPig->ChangeState( CPinkPigAction_Battle::Instance() );
		} else {
			pPinkPig->ChangeState( CPinkPigAction_BattleMissile::Instance() );
		}
	} else {
		// ���� ���� �ٱ��� �ִٸ� �׳� ��� ��� �Ÿ���
		pPinkPig->WalkNorth.NextAni();
		pPinkPig->WalkSouth.NextAni();
		pPinkPig->WalkEast.NextAni();
		pPinkPig->WalkWest.NextAni();

		if ( rand() % 100 > 60 ) {
			int nD = (int)(rand() % 4);
			if ( nD == 0 ) pPinkPig->MoveEast();
			if ( nD == 1 ) pPinkPig->MoveWest();
			if ( nD == 2 ) pPinkPig->MoveNorth();
			if ( nD == 3 ) pPinkPig->MoveSouth();
		}
	}
}

void CPinkPigAction_Stand::Exit(CMonsterAI* pObj) {
	
}

// �������� �ٰ����� ó��
CPinkPigAction_Battle* CPinkPigAction_Battle::Instance() {
  static CPinkPigAction_Battle instance;
  return &instance;
}

void CPinkPigAction_Battle::Enter(CMonsterAI* pObj) {
	CPinkPig* pPinkPig = (CPinkPig*)pObj;
	pPinkPig->dwAttackTime = GetTickCount();
}

void CPinkPigAction_Battle::Execute(CMonsterAI* pObj) {
	CPinkPig* pPinkPig = (CPinkPig*)pObj;

	if ( GetTickCount() - pPinkPig->dwAttackTime > 3000 ) {
		pPinkPig->ChangeState( CPinkPigAction_Stand::Instance() );
		return;
	}

	Vector2D PlayerPos;
	Vector2D PigPos;
	PlayerPos.x = pObj->pPlayer->GetWorldX();
	PlayerPos.y = pObj->pPlayer->GetWorldY();
	PigPos.x = pPinkPig->GetWorldX();
	PigPos.y = pPinkPig->GetWorldY();

	float xLen = abs(PlayerPos.x-PigPos.x);
	float yLen = abs(PlayerPos.y-PigPos.y);
	
	if ( xLen > yLen ) {
		if ( PlayerPos.x > PigPos.x ) {
			if ( pPinkPig->MoveEast() ) {
				pPinkPig->MoveSouth();
			}
		} else { 
			if ( pPinkPig->MoveWest() ) {
				pPinkPig->MoveNorth();
			}
		}
	} else {
		if ( PlayerPos.y > PigPos.y ) {
			if ( pPinkPig->MoveSouth() ) {
				pPinkPig->MoveEast();
			}
		} else { 
			if ( pPinkPig->MoveNorth() ) {
				pPinkPig->MoveWest();
			}
		}
	}
}

void CPinkPigAction_Battle::Exit(CMonsterAI* pObj) {
	
}

// �������� �������� �̻����� ������.
CPinkPigAction_BattleMissile* CPinkPigAction_BattleMissile::Instance() {
  static CPinkPigAction_BattleMissile instance;
  return &instance;
}

void CPinkPigAction_BattleMissile::Enter(CMonsterAI* pObj) {
	// � ������ ���� �Ǵ��Ѵ�.
	// �׳� �����̸鼭 �ε�����, �̻��� ������ ����
	CPinkPig* pPinkPig = (CPinkPig*)pObj;
	
	pPinkPig->dwAttackTime = GetTickCount();

	// �̻��� �߻�

	// ����
	Vector2D PlayerPos;
	Vector2D PigPos;
	PlayerPos.x = pObj->pPlayer->GetWorldX();
	PlayerPos.y = pObj->pPlayer->GetWorldY();
	PigPos.x = pPinkPig->GetWorldX();
	PigPos.y = pPinkPig->GetWorldY();

	Vector2D dir = PlayerPos - PigPos;
	dir.Normalize();
		
	CHARACTER_DIR SelectDir;

	float xLen = abs(PlayerPos.x-PigPos.x);
	float yLen = abs(PlayerPos.y-PigPos.y);
	
	if ( xLen > yLen ) {
		if ( PlayerPos.x > PigPos.x ) {
			SelectDir = EAST;
			pPinkPig->nDir = EAST;
		} else { 
			SelectDir = WEST;
			pPinkPig->nDir = WEST;
		}
	} else {
		if ( PlayerPos.y > PigPos.y ) {
			SelectDir = SOUTH;
			pPinkPig->nDir = SOUTH;
		} else { 
			SelectDir = NORTH;
			pPinkPig->nDir = NORTH;
		}
	}
	
	g_Game.AddBullet( CBullet::PINK_PIG_BULLET, pPinkPig->GetWorldX(), pPinkPig->GetWorldY(), dir.x, dir.y, SelectDir );
}

void CPinkPigAction_BattleMissile::Execute(CMonsterAI* pObj) {
	CPinkPig* pPinkPig = (CPinkPig*)pObj;
	
	if ( GetTickCount() - pPinkPig->dwAttackTime > 1000 ) {
		pPinkPig->ChangeState( CPinkPigAction_Stand::Instance() );
	}	
}

void CPinkPigAction_BattleMissile::Exit(CMonsterAI* pObj) {
	
}