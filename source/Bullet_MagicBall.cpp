// Bullet_MagicBall.cpp: implementation of the Bullet_MagicBall class.
//
//////////////////////////////////////////////////////////////////////
#include "global.h"
#include "Bullet_MagicBall.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBullet_MagicBall::CBullet_MagicBall() {
	nItemType = CBullet::KAIL_MAGIC_BALL;
	nRad = 5;
}

CBullet_MagicBall::~CBullet_MagicBall() {

}

void CBullet_MagicBall::Init() {
	CBullet::Init();
	BulletFrame.SetLoop( true );
	BulletFrame.AddFrame( "char/magic_ball_1.bmp", 1 );
	BulletFrame.nMaxFrame = 1;
	BulletFrame.nCurFrame = 0;

	SecondBulletFrame[0].SetLoop( true );
	SecondBulletFrame[0].AddFrame( "char/magic_ball_2.bmp", 2 );
	SecondBulletFrame[0].nMaxFrame = 1;
	SecondBulletFrame[0].nCurFrame = 0;

	SecondBulletFrame[1].SetLoop( true );
	SecondBulletFrame[1].AddFrame( "char/magic_ball_3.bmp", 2 );
	SecondBulletFrame[1].nMaxFrame = 1;
	SecondBulletFrame[1].nCurFrame = 0;
	

	switch ( nDir ) {
		case EAST:
			m_Vel[0].x = 10;
			m_Vel[0].y = 0;
		break;
		case WEST:
			m_Vel[0].x = -10;
			m_Vel[0].y = 0;
		break;
		case NORTH:
			m_Vel[0].x = 0;
			m_Vel[0].y = -10;
		break;
		case SOUTH:
			m_Vel[0].x = 0;
			m_Vel[0].y = 10;
		break;
	}


	m_Pos[0].x = nWorldX;
	m_Pos[0].y = nWorldY;

	m_Pos[1].x = nWorldX;
	m_Pos[1].y = nWorldY;
	
	m_Pos[2].x = nWorldX;
	m_Pos[2].y = nWorldY;
	
	m_Acc[0].x = 0;
	m_Acc[0].y = 0;
	m_Acc[1].x = 0;
	m_Acc[1].y = 0;
	m_Acc[2].x = 0;
	m_Acc[2].y = 0;
}

void CBullet_MagicBall::Update() {
	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );

	// 가장 가까운 적들의 위치를 찾아서 이동한다.
	for ( int i = 0; i < 3; i++ ) {
		m_Vel[i] += m_Acc[i] * 0.3f;
		m_Pos[i] += m_Vel[i] * 0.3f;

		if ( m_Vel[i].Length() > 8 ) {
			m_Vel[i].Normalize();
			m_Vel[i] *= 8;
		}
	}

	CMoveableEntity* pEntity = g_Game.GetNearThisPointInEvil( m_Pos[0] );

	nWorldX = m_Pos[0].x;
	nWorldY = m_Pos[0].y;

	if ( pEntity ) {
		Vector2D pT( pEntity->GetWorldX() - m_Pos[0].x, 
					 pEntity->GetWorldY() - m_Pos[0].y );
		
		pT.Normalize();

		m_Acc[0] += pT * 2.0f;
		/*m_Acc[0].Normalize();
		m_Acc[0] *= 5;*/
	}
	
	float fLen = 0;
	m_Vel[1] = m_Pos[0] - m_Pos[1];
	fLen = (float)m_Vel[1].Length();
	m_Vel[1].Normalize();
	m_Vel[1] *= fLen * 0.9f;
	
	
	m_Vel[2] = m_Pos[1] - m_Pos[2];	
	fLen = (float)m_Vel[2].Length();
	m_Vel[2].Normalize();
	m_Vel[2] *= fLen * 0.8f;
	
	/*if ( g_Game.Stage.IsBlock( this ) ) {
		nEnergy = 0;
	}*/
}

void CBullet_MagicBall::Render(int nXIndex, int nYIndex) {
	CBullet::Render( nXIndex, nYIndex );
	
	for ( int i = 0; i < 2; i++ ) {
		SecondBulletFrame[i].DrawAni( m_Pos[i+1].x - (g_Game.Stage.nXIndex*160),
									  m_Pos[i+1].y - (g_Game.Stage.nYIndex*160) );
	}	
}
