// Bullet_Pink_Pig.cpp: implementation of the CBullet_Pink_Pig class.
//
//////////////////////////////////////////////////////////////////////
#include "global.h"
#include "Bullet_Pink_Pig.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBullet_Pink_Pig::CBullet_Pink_Pig() {
	nItemType = CBullet::PINK_PIG_BULLET;
	nRad = 9;
}

CBullet_Pink_Pig::~CBullet_Pink_Pig() {

}

void CBullet_Pink_Pig::Init() {
	CBullet::Init();

	switch ( nDir ) {
		case EAST:
			BulletFrame.SetLoop( true );
			BulletFrame.AddFrame( "evil/pinkpig_bullet_east.bmp", 1 );
			BulletFrame.nMaxFrame = 1;
			BulletFrame.nCurFrame = 0;
		break;
		case WEST:
			BulletFrame.SetLoop( true );
			BulletFrame.AddFrame( "evil/pinkpig_bullet_west.bmp", 1 );
			BulletFrame.nMaxFrame = 1;
			BulletFrame.nCurFrame = 0;
		break;
		case NORTH:
			BulletFrame.SetLoop( true );
			BulletFrame.AddFrame( "evil/pinkpig_bullet_north.bmp", 1 );
			BulletFrame.nMaxFrame = 1;
			BulletFrame.nCurFrame = 0;
		break;
		case SOUTH:
			BulletFrame.SetLoop( true );
			BulletFrame.AddFrame( "evil/pinkpig_bullet_south.bmp", 1 );
			BulletFrame.nMaxFrame = 1;
			BulletFrame.nCurFrame = 0;
		break;
	}
}

void CBullet_Pink_Pig::Update() {
	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );

	nWorldX += mDir.x;
	nWorldY += mDir.y;
	
	if ( g_Game.Stage.IsBlock( this ) ) {
		nEnergy = 0;
	}
}

void CBullet_Pink_Pig::Render(int nXIndex, int nYIndex) {
	CBullet::Render( nXIndex, nYIndex );
}
