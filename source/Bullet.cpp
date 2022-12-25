// Bullet.cpp: implementation of the CBullet class.
//
//////////////////////////////////////////////////////////////////////


#include "global.h"
#include "Bullet.h"

/////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBullet::CBullet()
{

}

CBullet::~CBullet()
{

}

void CBullet::Init() {
	EntityType = IEntity::BULLET;
	nEnergy = 1;
	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );


	oY = 0;
	fVelocity = 0;
}

void CBullet::Update() {

}

void CBullet::Render(int nXIndex, int nYIndex) {
	BulletFrame.DrawAni( scx , scy );
}

bool CBullet::MoveNorth() {

	return false;
}

bool CBullet::MoveSouth() {

	return false;
}

bool CBullet::MoveEast() {

	return false;
}

bool CBullet::MoveWest() {

	return false;
}

bool CBullet::MoveBack() {

	return false;
}

void CBullet::Attack() {

}

void CBullet::Hit() {
	//if ( g_Game.pKail->GetState() == Kail::STAND ) {
	nEnergy = 0;
	//}
}

int CBullet::Dead() {
	// 종류에 따라서 플레이어에게 피드백을 준다.
	switch ( nItemType ) {
		case AMBER_BULLET:
			//g_Game.pKail->GetMoney( 100 );

			// 에너지 깎기
		break;
	}

	return 0;
}
