// Monster.cpp: implementation of the Monster class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Monster.h"
#include "misc\utils.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMonster::CMonster()
{
	pPlayer = NULL;
}

CMonster::~CMonster()
{

}

void CMonster::Init() {
	EntityType = IEntity::MONSTER;
	// 그래픽 데이터들 연결한다.
	if ( nType == PUPU ) {
		WalkEast.SetLoop( true );
		WalkEast.AddFrame( "evil/pupu_walk_east_1.bmp",5);
		WalkEast.AddFrame( "evil/pupu_walk_east_2.bmp",5 );
		WalkEast.nMaxFrame = 2;
		WalkEast.nCurFrame = 0;

		WalkWest.SetLoop( true );
		WalkWest.AddFrame( "evil/pupu_walk_west_1.bmp",5);
		WalkWest.AddFrame( "evil/pupu_walk_west_2.bmp",5);
		WalkWest.nMaxFrame = 2;
		WalkWest.nCurFrame = 0;

		WalkSouth.SetLoop( true );
		WalkSouth.AddFrame( "evil/pupu_walk_south_1.bmp",5);
		WalkSouth.AddFrame( "evil/pupu_walk_south_2.bmp",5);
		WalkSouth.nMaxFrame = 2;
		WalkSouth.nCurFrame = 0;

		WalkNorth.SetLoop( true );
		WalkNorth.AddFrame( "evil/pupu_walk_north_1.bmp",5 );
		WalkNorth.AddFrame( "evil/pupu_walk_north_2.bmp",5 );
		WalkNorth.nMaxFrame = 2;
		WalkNorth.nCurFrame = 0;

		nEnergy = 5;
		nMoveSpeed = 1;
		nRad = 7;
	} else if ( nType == PINK_PIG ) {
		WalkEast.SetLoop( true );
		WalkEast.AddFrame( "evil/pinkpig_walk_east_1.bmp",5);
		WalkEast.AddFrame( "evil/pinkpig_walk_east_2.bmp",5 );
		WalkEast.nMaxFrame = 2;
		WalkEast.nCurFrame = 0;

		WalkWest.SetLoop( true );
		WalkWest.AddFrame( "evil/pinkpig_walk_west_1.bmp",5);
		WalkWest.AddFrame( "evil/pinkpig_walk_west_2.bmp",5);
		WalkWest.nMaxFrame = 2;
		WalkWest.nCurFrame = 0;

		WalkSouth.SetLoop( true );
		WalkSouth.AddFrame( "evil/pinkpig_walk_south_1.bmp",5);
		WalkSouth.AddFrame( "evil/pinkpig_walk_south_2.bmp",5);
		WalkSouth.nMaxFrame = 2;
		WalkSouth.nCurFrame = 0;

		WalkNorth.SetLoop( true );
		WalkNorth.AddFrame( "evil/pinkpig_walk_north_1.bmp",5 );
		WalkNorth.AddFrame( "evil/pinkpig_walk_north_2.bmp",5 );
		WalkNorth.nMaxFrame = 2;
		WalkNorth.nCurFrame = 0;

		nEnergy = 20;
		nMoveSpeed = 0.7f;
		nRad = 10;
	} else if ( nType == BOSS_AMBER ) {
		WalkEast.SetLoop( true );
		WalkEast.AddFrame( "evil/amber_walk_east_1.bmp",5);
		WalkEast.AddFrame( "evil/amber_walk_east_2.bmp",5 );
		WalkEast.AddFrame( "evil/amber_walk_east_3.bmp",5 );
		WalkEast.nMaxFrame = 3;
		WalkEast.nCurFrame = 0;

		WalkWest.SetLoop( true );
		WalkWest.AddFrame( "evil/amber_walk_west_1.bmp",5);
		WalkWest.AddFrame( "evil/amber_walk_west_2.bmp",5);
		WalkWest.AddFrame( "evil/amber_walk_west_3.bmp",5);
		WalkWest.nMaxFrame = 3;
		WalkWest.nCurFrame = 0;

		WalkSouth.SetLoop( true );
		WalkSouth.AddFrame( "evil/amber_walk_south_1.bmp",5);
		WalkSouth.AddFrame( "evil/amber_walk_south_2.bmp",5);
		WalkSouth.nMaxFrame = 2;
		WalkSouth.nCurFrame = 0;

		WalkNorth.SetLoop( true );
		WalkNorth.AddFrame( "evil/amber_walk_north_1.bmp",5 );
		WalkNorth.AddFrame( "evil/amber_walk_north_2.bmp",5 );
		WalkNorth.nMaxFrame = 2;
		WalkNorth.nCurFrame = 0;

		nEnergy = 100;
		//nEnergy = 1;
		nMoveSpeed = 2;
		nRad = 10;
	} else if ( nType == SABI ) {
		
		nEnergy = 8;
	} else if ( nType == BLUE_PIG ) {
		WalkEast.SetLoop( true );
		WalkEast.AddFrame( "evil/bluepig_walk_east_1.bmp",5);
		WalkEast.AddFrame( "evil/bluepig_walk_east_2.bmp",5 );
		WalkEast.nMaxFrame = 2;
		WalkEast.nCurFrame = 0;

		WalkWest.SetLoop( true );
		WalkWest.AddFrame( "evil/bluepig_walk_west_1.bmp",5);
		WalkWest.AddFrame( "evil/bluepig_walk_west_2.bmp",5);
		WalkWest.nMaxFrame = 2;
		WalkWest.nCurFrame = 0;
		
		WalkSouth.SetLoop( true );
		WalkSouth.AddFrame( "evil/bluepig_walk_south_1.bmp",5);
		WalkSouth.AddFrame( "evil/bluepig_walk_south_2.bmp",5);
		WalkSouth.nMaxFrame = 2;
		WalkSouth.nCurFrame = 0;
		
		WalkNorth.SetLoop( true );
		WalkNorth.AddFrame( "evil/bluepig_walk_north_1.bmp",5 );
		WalkNorth.AddFrame( "evil/bluepig_walk_north_2.bmp",5 );
		WalkNorth.nMaxFrame = 2;
		WalkNorth.nCurFrame = 0;
		
		nEnergy = 20;
		nMoveSpeed = 2.0f;
		nRad = 10;
	}

	nDir = SOUTH;
	//nX = rand() % 160;
	//nY = rand() % 160;
	nState = STAND;
}

void CMonster::Update() {
	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );

	if (g_Game.Stage.nXIndex != (int)GetWorldX() / 160) return;
	if (g_Game.Stage.nYIndex != (int)GetWorldY() / 160) return;

	

	if ( nState == STAND ) {
		switch ( nType ) {
			case PUPU: {
				WalkNorth.NextAni();
				WalkSouth.NextAni();
				WalkEast.NextAni();
				WalkWest.NextAni();

				if ( rand() % 100 > 60 ) {
					int nD = (int)(rand() % 4);
					if ( nD == 0 ) MoveEast();
					if ( nD == 1 ) MoveWest();
					if ( nD == 2 ) MoveNorth();
					if ( nD == 3 ) MoveSouth();
				}
			}
			break;
		}
	} else if ( nState == ATTACK ) {

	} else if ( nState == HIT ) {
		switch ( WhenThePlayerDir ) {
			case NORTH:
				nWorldY -= HitDelta;
				if ( g_Game.Stage.IsBlock( this ) ) {
					nWorldY += HitDelta;
					HitDelta = 0;
				} else if ( g_Game.Stage.IsOutOfScreen( this ) )  {
					nWorldY += HitDelta;
					HitDelta = 0;
				}
			break;
			case SOUTH:
				nWorldY += HitDelta;
				if ( g_Game.Stage.IsBlock( this ) ) {
					nWorldY -= HitDelta;
					HitDelta = 0;
				} else if ( g_Game.Stage.IsOutOfScreen( this ) )  {
					nWorldY -= HitDelta;
					HitDelta = 0;
				}
			break;
			case EAST:
				nWorldX += HitDelta;
				if ( g_Game.Stage.IsBlock( this ) ) {
					nWorldX -= HitDelta;
					HitDelta = 0;
				} else if ( g_Game.Stage.IsOutOfScreen( this ) )  {
					nWorldX -= HitDelta;
					HitDelta = 0;
				}
			break;
			case WEST:
				nWorldX -= HitDelta;
				if ( g_Game.Stage.IsBlock( this ) ) {
					nWorldX += HitDelta;
					HitDelta = 0;
				} else if ( g_Game.Stage.IsOutOfScreen( this ) )  {
					nWorldX += HitDelta;
					HitDelta = 0;
				}

			break;
		}
		HitDelta *= 0.6f;
		if ( GetTickCount() - TickCount > 200 ) {
			nState = STAND;
		}
	}

	/*if ( nX < 0 ) nX = 0;
	if ( nY < 0 ) nY = 0;
	if ( nX > 160 ) nX = 160;
	if ( nY > 160 ) nY = 160;*/
}

void CMonster::Render(int nXIndex, int nYIndex) {
	switch ( nDir ) {
		case NORTH:
			WalkNorth.DrawAni( scx, scy );
		break;
		case EAST:
			WalkEast.DrawAni( scx, scy );
		break;
		case SOUTH:
			WalkSouth.DrawAni( scx, scy );
		break;
		case WEST:
			WalkWest.DrawAni( scx, scy );
		break;
	}
}

bool CMonster::MoveNorth() {
	bool bCol = false;
	nDir = NORTH;
	nWorldY -= nMoveSpeed;
	if ( g_Game.Stage.IsBlock( this ) ) {
		nWorldY += nMoveSpeed;
		bCol = true;
	}
	if ( scy < 16 ) nWorldY += nMoveSpeed;
	WalkNorth.NextAni();

	return bCol;
}

bool CMonster::MoveSouth() {
	bool bCol = false;
	nDir = SOUTH;
	nWorldY += nMoveSpeed;
	if ( g_Game.Stage.IsBlock( this ) ) {
		nWorldY -= nMoveSpeed;
		bCol = true;
	}
	if ( scy > 150 ) nWorldY -= nMoveSpeed;
	WalkSouth.NextAni();
	return bCol;
}

bool CMonster::MoveEast() {
	bool bCol = false;
	nDir = EAST;
	nWorldX += nMoveSpeed;
	if ( g_Game.Stage.IsBlock( this ) ) {
		nWorldX -= nMoveSpeed;
		bCol = true;
	}
	if ( scx > 150 ) nWorldX -= nMoveSpeed;
	WalkEast.NextAni();
	return bCol;
}

bool CMonster::MoveWest() {
	bool bCol = false;
	nDir = WEST;
	nWorldX -= nMoveSpeed;
	if ( g_Game.Stage.IsBlock( this ) ) {
		nWorldX += nMoveSpeed;
		bCol = true;
	}
	if ( scx < 16 ) nWorldX += nMoveSpeed;
	WalkWest.NextAni();
	return bCol;
}

bool CMonster::MoveBack() {
	bool bCol = false;

	return bCol;
}

void CMonster::Hit() {
	if ( nState != HIT ) {
		nState = HIT;
		TickCount = GetTickCount();
		WhenThePlayerDir = pPlayer->GetDir();
		HitDelta = 6;
		
		// 플레이어의 공격치
		nEnergy--;

		switch ( nType ) {
			case PUPU:
				Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/pupu_hit.wav"],0);
			break;
		}
		
		if ( nEnergy <= 0 ) {			
			switch ( nType ) {
				case PUPU:
					Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/pupu_die.wav"],0);
				break;				
			}
		}
	}
}

// 자신의 타입에 따라서 아이템을 준다.
int CMonster::Dead() {
	// 0번은 돈
	const s_MobData* mobdata = g_MobDB.GetMobData( (int)nType );

	int nRand = RandInt(1,100);
	int nItemIndex = 0;

	if ( nRand >= 90 ) {
		nItemIndex = mobdata->DropItem[0];
	} else if ( nRand >= 60 ) {
		nItemIndex = mobdata->DropItem[1];
	} else {
		nItemIndex = mobdata->DropItem[2];
	}
	
	g_Game.AddItem( nItemIndex, nWorldX, nWorldY );
	return 0;
}