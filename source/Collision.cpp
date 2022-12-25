#include "global.h"
#include "game.h"
#include <math.h>
#include "Bullet.h"

double Distance( int x1, int y1, int x2, int y2 ) {
    return sqrt( powf( abs(x2 - x1), 2 ) + powf( abs(y2 - y1), 2 ) );
}

bool CollisionCircle( int ax, int ay, int bx, int by, int ar, int br ) {		
    if( Distance( ax, ay, bx, by ) < ( ar + br ) ) {
        return true;
    }
    return false;
}

void CGame::CollisionPlayerAttackWithObj( CMoveableEntity *pEvil ) {
	int nX = pKail->GetWorldX(); //GetScreenX( Stage[nStage].nXIndex );
	int nY = pKail->GetWorldY(); //GetScreenY( Stage[nStage].nYIndex );
	
	if ( pEvil->EntityType == IEntity::NPC ) return;
	
	switch ( pKail->nDir ) {
		case NORTH:
			if ( CollisionCircle( nX + 10, nY - 16, pEvil->GetWorldX(), pEvil->GetWorldY(), 12, pEvil->GetRadForCollision() ) ) {
				// 공격 범위 안에 들어왔다.
				// 뒤로 튕겨 준다.
				pEvil->Hit();
			}
		break;
		case SOUTH:
			if ( CollisionCircle( nX - 10, nY + 7, pEvil->GetWorldX(), pEvil->GetWorldY(), 11, pEvil->GetRadForCollision() ) ) {
				// 공격 범위 안에 들어왔다.
				// 뒤로 튕겨 준다.
				pEvil->Hit();
			}
		break;
		case EAST:
			if ( CollisionCircle( nX + 8, nY - 13, pEvil->GetWorldX(), pEvil->GetWorldY(), 11, pEvil->GetRadForCollision() ) ) {
				// 공격 범위 안에 들어왔다.
				// 뒤로 튕겨 준다.
				pEvil->Hit();
			}
		break;
		case WEST:
			if ( CollisionCircle( nX - 9, nY - 16, pEvil->GetWorldX(), pEvil->GetWorldY(), 11, pEvil->GetRadForCollision() ) ) {
				// 공격 범위 안에 들어왔다.
				// 뒤로 튕겨 준다.
				pEvil->Hit();
			}
		break;
	}
}

void CGame::CollisionPlayerWithObj( CMoveableEntity *pEvil ) {
	int nX = pKail->GetWorldX();
	int nY = pKail->GetWorldY();
	
//	pEvil->GetRadForCollision(), pBullet->GetRadForCollision() ) ) {

	if ( CollisionCircle( nX , nY , pEvil->GetWorldX(), pEvil->GetWorldY(), pKail->GetRadForCollision(), pEvil->GetRadForCollision() ) ) { // 10, 5 ) ) {
		switch ( pEvil->EntityType ) {
			case IEntity::NPC:
				pEvil->Hit();
			break;

			case IEntity::MONSTER:
				pKail->Hit();
				pEvil->Hit();
			break;
			case IEntity::ITEM:
				pEvil->Hit();
			break;

			case IEntity::BULLET:
				pEvil->Hit();
			break;
		}
	}
}

void CGame::CollisionBulletWithObj( CMoveableEntity *pEvil, CBullet* pBullet ) {
	int nX = pEvil->GetWorldX();
	int nY = pEvil->GetWorldY();
	
	if ( pEvil->EntityType == IEntity::NPC ) return;

	if ( CollisionCircle( nX , nY , pBullet->GetWorldX(), pBullet->GetWorldY(), 
		                  pEvil->GetRadForCollision(), pBullet->GetRadForCollision() ) ) {
		pEvil->Hit();
		pBullet->Hit();
	}
}