// BossAmberAction.cpp: implementation of the CBossAmberAction class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "MonsterAI.h"
#include "Boss_Amber.h"
#include "BossAmberAction.h"
#include "Bullet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBossAmber_Stand* CBossAmber_Stand::Instance() {
  static CBossAmber_Stand instance;
  return &instance;
}

void CBossAmber_Stand::Enter( CMonsterAI* pObj ) {
	
}

void CBossAmber_Stand::Execute( CMonsterAI* pObj ) {
	// ������ �˻�
	//int nEnergy = pObj->GetEnergy();
	
	int nr = rand() % 10;
	
	if ( nr > 6 )  { // ��� ����
		((CBoss_Amber*)pObj)->ChangeState(	CBossAmber_MoveTypeNormal::Instance() );		
	} else if ( nr > 2 ) { // �߰�
		((CBoss_Amber*)pObj)->ChangeState(	CBossAmber_MoveTypeX::Instance() );
	} else { // ����
		((CBoss_Amber*)pObj)->ChangeState(	CBossAmber_MoveTypeBullet::Instance() );
	}
}

void CBossAmber_Stand::Exit( CMonsterAI* pObj ) {

}


CBossAmber_MoveTypeNormal* CBossAmber_MoveTypeNormal::Instance() {
	static CBossAmber_MoveTypeNormal instance;
	return &instance;
}

void CBossAmber_MoveTypeNormal::Enter(CMonsterAI* pObj ) {
	// ȸ���� Ƚ���� �����Ѵ�.
	CBoss_Amber* pBoss = (CBoss_Amber*)pObj;

	pBoss->nSelectedCount = (int)(rand() % 5 );
	pBoss->nCurCount = 0;
	pBoss->nSelectedPointIndex = 0;
}

void CBossAmber_MoveTypeNormal::Execute( CMonsterAI* pObj ) {
	// Ƚ�� n�� �� �� ���� ȸ���Ѵ�.
	CBoss_Amber* pBoss = (CBoss_Amber*)pObj;
	Vector2D Point = pBoss->GetCurrentPoint();

	// �ش� �������� �̵��ϱ� ���ؼ�
	int x = pBoss->GetScreenX( 0 );
	int y = pBoss->GetScreenY( 0 );
	
	Vector2D BossPosition(x,y);

	float fDist = BossPosition.Distance( Point );

	if ( fDist < 3 ) {
		// �ش� ��ġ�� ����
		pBoss->nSelectedPointIndex++;
		if ( pBoss->nSelectedPointIndex > 3 ) {
			pBoss->nCurCount++;
			pBoss->nSelectedPointIndex = 0;
			if ( pBoss->nCurCount >= pBoss->nSelectedCount ) {
				// ��� ���� ���
				((CBoss_Amber*)pObj)->ChangeState(	CBossAmber_Stand::Instance() );
			}
		}
	} else {
		float xLen = abs(x-Point.x);
		float yLen = abs(y-Point.y);
		
		if ( xLen > yLen && yLen < 10) {
			if ( x > Point.x ) {
				pBoss->MoveWest();			
			} else { 
				pBoss->MoveEast();
			}
		} else {
			if ( y > Point.y ) {
				pBoss->MoveNorth();			
			} else { 
				pBoss->MoveSouth();
			}
		}
	}
}

void CBossAmber_MoveTypeNormal::Exit( CMonsterAI* pObj ) {

}

//
CBossAmber_MoveTypeX* CBossAmber_MoveTypeX::Instance() {
	static CBossAmber_MoveTypeX instance;
	return &instance;
}

void CBossAmber_MoveTypeX::Enter( CMonsterAI* pObj ) {
	CBoss_Amber* pBoss = (CBoss_Amber*)pObj;
	
	pBoss->nSelectedCount = (int)(rand() % 5 );
	pBoss->nCurCount = 0;
	pBoss->nSelectedPointIndex = 0;	
}

void CBossAmber_MoveTypeX::Execute( CMonsterAI* pObj ) {
	// Ƚ�� n�� �� �� ���� ȸ���Ѵ�.
	CBoss_Amber* pBoss = (CBoss_Amber*)pObj;
	Vector2D Point = pBoss->GetCurrentPointX();

	// �ش� �������� �̵��ϱ� ���ؼ�
	int x = pBoss->GetScreenX( 0 );
	int y = pBoss->GetScreenY( 0 );
	
	Vector2D BossPosition(x,y);

	float fDist = BossPosition.Distance( Point );

	if ( fDist < 3 ) {
		// �ش� ��ġ�� ����
		pBoss->nSelectedPointIndex++;
		if ( pBoss->nSelectedPointIndex > 3 ) {
			pBoss->nCurCount++;
			pBoss->nSelectedPointIndex = 0;
			if ( pBoss->nCurCount >= pBoss->nSelectedCount ) {
				// ��� ���� ���
				((CBoss_Amber*)pObj)->ChangeState(	CBossAmber_Stand::Instance() );
			}
		}
	} else {
		float xLen = abs(x-Point.x);
		float yLen = abs(y-Point.y);
		
		//if ( xLen > yLen && yLen < 10) {
		if ( xLen > 1 ) {
			if ( x > Point.x ) {
				pBoss->MoveWest();			
			} else { 
				pBoss->MoveEast();
			}
		}
		//} else {

		if ( yLen > 1 ) {
			if ( y > Point.y ) {
				pBoss->MoveNorth();			
			} else { 
				pBoss->MoveSouth();
			}
		}
		//}
	}
}

void CBossAmber_MoveTypeX::Exit( CMonsterAI* pObj ) {

}


//
CBossAmber_MoveTypeBullet* CBossAmber_MoveTypeBullet::Instance() {
	static CBossAmber_MoveTypeBullet instance;
	return &instance;
}

void CBossAmber_MoveTypeBullet::Enter( CMonsterAI* pObj ) {
	CBoss_Amber* pBoss = (CBoss_Amber*)pObj;
	
	pBoss->dwAttackTime = GetTickCount();
	
}

void CBossAmber_MoveTypeBullet::Execute( CMonsterAI* pObj ) {
	CBoss_Amber* pBoss = (CBoss_Amber*)pObj;
	
	if ( GetTickCount() - pBoss->dwAttackTime > 1500 ) {
		// �Ѿ��� �߻��Ѵ�.
		// 360���� �̻����� �߻��Ѵ�.
		int i = 0; 
		for ( i = 0; i < 360; i+=30 ) {		
			g_Game.AddBullet( CBullet::AMBER_BULLET, pBoss->GetWorldX(), pBoss->GetWorldY(), cos(i*3.14/180), sin(i*3.14/180) );
		}

		((CBoss_Amber*)pObj)->ChangeState(	CBossAmber_Stand::Instance() );
	}
}

void CBossAmber_MoveTypeBullet::Exit( CMonsterAI* pObj ) {

}