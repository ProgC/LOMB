// Bullet_Amber.cpp: implementation of the CBullet_Amber class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Bullet_Amber.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBullet_Amber::CBullet_Amber()
{
	nItemType = CBullet::AMBER_BULLET;
	nRad = 6;
}

CBullet_Amber::~CBullet_Amber()
{

}

void CBullet_Amber::Init() {
	CBullet::Init();
	BulletFrame.SetLoop( true );
	BulletFrame.AddFrame( "evil/amber_bullet.bmp", 1 );
	BulletFrame.nMaxFrame = 1;
	BulletFrame.nCurFrame = 0;
}

void CBullet_Amber::Update() {
	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );

	nWorldX += mDir.x;
	nWorldY += mDir.y;
	
	if ( g_Game.Stage.IsBlock( this ) ) {
		nEnergy = 0;
	}
}

void CBullet_Amber::Render(int nXIndex, int nYIndex) {
	CBullet::Render( nXIndex, nYIndex );
}