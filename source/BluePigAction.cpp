// BluePigAction.cpp: implementation of the CBluePigAction class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "MonsterAI.h"
#include "BluePig.h"
#include "BluePigAction.h"

CBluePigAction_Stand* CBluePigAction_Stand::Instance() {
  static CBluePigAction_Stand instance;
  return &instance;
}

void CBluePigAction_Stand::Enter(CMonsterAI* pObj) {
	
}

void CBluePigAction_Stand::Execute(CMonsterAI* pObj) {
	// ������ �Ÿ��� �˻��ؼ� 3������ �з� �ȴ�.
	// ������ ���󰡼� (�׳� �ε����� �� �����ε� ����ϴ�)
	// �������� �ָ� �������� �̻��� ����
	// ��պ�� �Ÿ���
	
	CBluePig* pBluePig = (CBluePig*)pObj;

	Vector2D PlayerPos;
	Vector2D PigPos;
	PlayerPos.x = pObj->pPlayer->GetWorldX();
	PlayerPos.y = pObj->pPlayer->GetWorldY();
	PigPos.x = pBluePig->GetWorldX();
	PigPos.y = pBluePig->GetWorldY();

	double dLen = PigPos.Distance( PlayerPos );

	if ( dLen < pBluePig->GetFieldOfView() ) { // �Ÿ� �ȿ� �ִٸ� �������� ���� ��ȯ
		// 70%�� 
		pBluePig->ChangeState( CBluePigAction_Battle::Instance() );	
	} else {
		// ���� ���� �ٱ��� �ִٸ� �׳� ��� ��� �Ÿ���
		pBluePig->WalkNorth.NextAni();
		pBluePig->WalkSouth.NextAni();
		pBluePig->WalkEast.NextAni();
		pBluePig->WalkWest.NextAni();

		if ( rand() % 100 > 60 ) {
			int nD = (int)(rand() % 4);
			if ( nD == 0 ) pBluePig->MoveEast();
			if ( nD == 1 ) pBluePig->MoveWest();
			if ( nD == 2 ) pBluePig->MoveNorth();
			if ( nD == 3 ) pBluePig->MoveSouth();
		}
	}
}

void CBluePigAction_Stand::Exit(CMonsterAI* pObj) {
	
}


//======================================================
CBluePigAction_Battle* CBluePigAction_Battle::Instance() {
  static CBluePigAction_Battle instance;
  return &instance;
}

void CBluePigAction_Battle::Enter(CMonsterAI* pObj) {
	// �Ҹ��� �ѹ� ���� �ش�.
	Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/bluepig_att1.wav"],0);

	CBluePig* pBluePig = (CBluePig*)pObj;

	// �׸��� ���� ����
	Vector2D PlayerPos;
	Vector2D PigPos;
	PlayerPos.x = pObj->pPlayer->GetWorldX();
	PlayerPos.y = pObj->pPlayer->GetWorldY();
	PigPos.x = pBluePig->GetWorldX();
	PigPos.y = pBluePig->GetWorldY();

	float xLen = abs(PlayerPos.x-PigPos.x);
	float yLen = abs(PlayerPos.y-PigPos.y);
	
	pBluePig->Point[0].x = PlayerPos.x;
	pBluePig->Point[0].y = PlayerPos.y;

	pBluePig->dwAttackTime = GetTickCount();
}

void CBluePigAction_Battle::Execute(CMonsterAI* pObj) {
	// ������ �������� ���� �� �� ���� �ڴ�.
	CBluePig* pBluePig = (CBluePig*)pObj;

	// �ش� �������� �̵��ϱ� ���ؼ�
	int x = pBluePig->GetWorldX();
	int y = pBluePig->GetWorldY();
	
	Vector2D BossPosition(x,y);

	float fDist = BossPosition.Distance( pBluePig->Point[0] );

	if ( fDist < 3 ) {
		// �ش� ��ġ�� ����
		pBluePig->ChangeState(	CBluePigAction_Wait::Instance() );
		return;
	} else {
		float xLen = abs(x-pBluePig->Point[0].x);
		float yLen = abs(y-pBluePig->Point[0].y);
		
		//if ( xLen > yLen && yLen < 10) {
		if ( xLen > 1 ) {
			if ( x > pBluePig->Point[0].x ) {
				pBluePig->MoveWest();			
			} else { 
				pBluePig->MoveEast();
			}
		}

		if ( yLen > 1 ) {
			if ( y > pBluePig->Point[0].y ) {
				pBluePig->MoveNorth();			
			} else { 
				pBluePig->MoveSouth();
			}
		}
	}

	if ( GetTickCount() - pBluePig->dwAttackTime > 1000 ) {
		pBluePig->ChangeState( CBluePigAction_Wait::Instance() );
	}
}

void CBluePigAction_Battle::Exit(CMonsterAI* pObj) {
	
}


//===========================================================
CBluePigAction_Wait* CBluePigAction_Wait::Instance() {
	static CBluePigAction_Wait instance;
	return &instance;
}

void CBluePigAction_Wait::Enter(CMonsterAI* pObj) {
	// 2�ʰ� �����.
	CBluePig* pBluePig = (CBluePig*)pObj;
	pBluePig->dwAttackTime = GetTickCount();
}

void CBluePigAction_Wait::Execute(CMonsterAI* pObj) {
	// ������ �������� ���� �� �� ���� �ڴ�.
	CBluePig* pBluePig = (CBluePig*)pObj;

	if ( GetTickCount() - pBluePig->dwAttackTime > 500 ) {
		pBluePig->ChangeState( CBluePigAction_Stand::Instance() );
	}
}

void CBluePigAction_Wait::Exit(CMonsterAI* pObj) {
	
}
