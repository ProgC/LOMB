// Npc.cpp: implementation of the CNpc class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Npc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNpc::CNpc() {
	
}

CNpc::~CNpc()
{

}

void CNpc::Init() {
	EntityType = IEntity::NPC;
	nState = STAND;
	nDir = SOUTH;
	
	switch ( nType ) {
		case SMITH:
			WalkEast.SetLoop( true );
			WalkEast.AddFrame( "npc/smith_walk_east_1.bmp",5);
			WalkEast.AddFrame( "npc/smith_walk_east_2.bmp",5 );
			WalkEast.nMaxFrame = 2;
			WalkEast.nCurFrame = 0;

			WalkWest.SetLoop( true );
			WalkWest.AddFrame( "npc/smith_walk_west_1.bmp",5);
			WalkWest.AddFrame( "npc/smith_walk_west_2.bmp",5);
			WalkWest.nMaxFrame = 2;
			WalkWest.nCurFrame = 0;

			WalkSouth.SetLoop( true );
			WalkSouth.AddFrame( "npc/smith_walk_south_1.bmp",5);
			WalkSouth.AddFrame( "npc/smith_walk_south_2.bmp",5);
			WalkSouth.nMaxFrame = 2;
			WalkSouth.nCurFrame = 0;

			WalkNorth.SetLoop( true );
			WalkNorth.AddFrame( "npc/smith_walk_north_1.bmp",5 );
			WalkNorth.AddFrame( "npc/smith_walk_north_2.bmp",5 );
			WalkNorth.nMaxFrame = 2;
			WalkNorth.nCurFrame = 0;

			nEnergy = 5;
			nRad = 6;
		break;
		
		case UJIN:
			WalkEast.SetLoop( true );
			WalkEast.AddFrame( "npc/jinia_walk_east_1.bmp",5);
			WalkEast.AddFrame( "npc/jinia_walk_east_2.bmp",5 );
			WalkEast.nMaxFrame = 2;
			WalkEast.nCurFrame = 0;

			WalkWest.SetLoop( true );
			WalkWest.AddFrame( "npc/jinia_walk_west_1.bmp",5);
			WalkWest.AddFrame( "npc/jinia_walk_west_2.bmp",5);
			WalkWest.nMaxFrame = 2;
			WalkWest.nCurFrame = 0;

			WalkSouth.SetLoop( true );
			WalkSouth.AddFrame( "npc/jinia_walk_south_1.bmp",5);
			WalkSouth.AddFrame( "npc/jinia_walk_south_2.bmp",5);
			WalkSouth.nMaxFrame = 2;
			WalkSouth.nCurFrame = 0;

			WalkNorth.SetLoop( true );
			WalkNorth.AddFrame( "npc/jinia_walk_north_1.bmp",5 );
			WalkNorth.AddFrame( "npc/jinia_walk_north_2.bmp",5 );
			WalkNorth.nMaxFrame = 2;
			WalkNorth.nCurFrame = 0;

			nEnergy = 5;
			nRad = 6;
		break;

		case EAN:
			WalkEast.SetLoop( true );
			WalkEast.AddFrame( "npc/ean_walk_east_1.bmp",5);
			WalkEast.AddFrame( "npc/ean_walk_east_2.bmp",5 );
			WalkEast.nMaxFrame = 2;
			WalkEast.nCurFrame = 0;

			WalkWest.SetLoop( true );
			WalkWest.AddFrame( "npc/ean_walk_west_1.bmp",5);
			WalkWest.AddFrame( "npc/ean_walk_west_2.bmp",5);
			WalkWest.nMaxFrame = 2;
			WalkWest.nCurFrame = 0;

			WalkSouth.SetLoop( true );
			WalkSouth.AddFrame( "npc/ean_walk_south_1.bmp",5);
			WalkSouth.AddFrame( "npc/ean_walk_south_2.bmp",5);
			WalkSouth.nMaxFrame = 2;
			WalkSouth.nCurFrame = 0;

			WalkNorth.SetLoop( true );
			WalkNorth.AddFrame( "npc/ean_walk_north_1.bmp",5 );
			WalkNorth.AddFrame( "npc/ean_walk_north_2.bmp",5 );
			WalkNorth.nMaxFrame = 2;
			WalkNorth.nCurFrame = 0;

			nEnergy = 5;
			nRad = 6;
		break;

		case ARTIUS:
			WalkEast.SetLoop( true );
			WalkEast.AddFrame( "npc/artius_walk_east_1.bmp",5);
			WalkEast.AddFrame( "npc/artius_walk_east_2.bmp",5 );
			WalkEast.nMaxFrame = 2;
			WalkEast.nCurFrame = 0;

			WalkWest.SetLoop( true );
			WalkWest.AddFrame( "npc/artius_walk_west_1.bmp",5);
			WalkWest.AddFrame( "npc/artius_walk_west_2.bmp",5);
			WalkWest.nMaxFrame = 2;
			WalkWest.nCurFrame = 0;

			WalkSouth.SetLoop( true );
			WalkSouth.AddFrame( "npc/artius_walk_south_1.bmp",5);
			WalkSouth.AddFrame( "npc/artius_walk_south_2.bmp",5);
			WalkSouth.nMaxFrame = 2;
			WalkSouth.nCurFrame = 0;

			WalkNorth.SetLoop( true );
			WalkNorth.AddFrame( "npc/artius_walk_north_1.bmp",5 );
			WalkNorth.AddFrame( "npc/artius_walk_north_2.bmp",5 );
			WalkNorth.nMaxFrame = 2;
			WalkNorth.nCurFrame = 0;

			nEnergy = 5;
			nRad = 6;
		break;

		case FISHGUY:
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
			nRad = 6;
		break;

		case KUO:
			WalkEast.SetLoop( true );
			WalkEast.AddFrame( "npc/kuo_walk_south_1.bmp",5);
			WalkEast.AddFrame( "npc/kuo_walk_south_2.bmp",5 );
			WalkEast.nMaxFrame = 2;
			WalkEast.nCurFrame = 0;

			WalkWest.SetLoop( true );
			WalkWest.AddFrame( "npc/kuo_walk_south_1.bmp",5);
			WalkWest.AddFrame( "npc/kuo_walk_south_2.bmp",5 );
			WalkWest.nMaxFrame = 2;
			WalkWest.nCurFrame = 0;

			WalkSouth.SetLoop( true );
			WalkSouth.AddFrame( "npc/kuo_walk_south_1.bmp",5);
			WalkSouth.AddFrame( "npc/kuo_walk_south_2.bmp",5 );
			WalkSouth.nMaxFrame = 2;
			WalkSouth.nCurFrame = 0;

			WalkNorth.SetLoop( true );
			WalkNorth.AddFrame( "npc/kuo_walk_south_1.bmp",5);
			WalkNorth.AddFrame( "npc/kuo_walk_south_2.bmp",5 );
			WalkNorth.nMaxFrame = 2;
			WalkNorth.nCurFrame = 0;
			
			nEnergy = 5;	
			nRad = 6;
		break;
	}
}

void CNpc::Update() {
	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );

	if (g_Game.Stage.nXIndex != (int)GetWorldX() / 160) return;
	if (g_Game.Stage.nYIndex != (int)GetWorldY() / 160) return;
	
	int nDeltaY = abs(pPlayer->GetWorldY() - GetWorldY());

	if ( nDeltaY > 6 ) {
		if ( pPlayer->GetWorldY() < GetWorldY() ) {
			nDir = NORTH;
		} else {
			nDir = SOUTH;
		}
	} else {
		if ( pPlayer->GetWorldX() < GetWorldX() ) {
		nDir = WEST;
		} else {
			nDir = EAST;
		}
	}
	

	if ( nState == STAND ) {
		switch ( nType ) {
			case SMITH: {
				WalkNorth.NextAni();
				WalkSouth.NextAni();
				WalkEast.NextAni();
				WalkWest.NextAni();
			}
			break;

			case UJIN:
				WalkNorth.NextAni();
				WalkSouth.NextAni();
				WalkEast.NextAni();
				WalkWest.NextAni();
			break;

			case EAN:
				WalkNorth.NextAni();
				WalkSouth.NextAni();
				WalkEast.NextAni();
				WalkWest.NextAni();
			break;

			case ARTIUS:
				WalkNorth.NextAni();
				WalkSouth.NextAni();
				WalkEast.NextAni();
				WalkWest.NextAni();
			break;

			case FISHGUY:
				WalkNorth.NextAni();
				WalkSouth.NextAni();
				WalkEast.NextAni();
				WalkWest.NextAni();
			break;

			case KUO:
				WalkNorth.NextAni();
				WalkSouth.NextAni();
				WalkEast.NextAni();
				WalkWest.NextAni();
			break;
		}
	} else if ( nState == HIT ) {
		switch ( WhenThePlayerDir ) {
			case NORTH:
				nWorldY -= HitDelta;
				if ( g_Game.Stage.IsBlock( this ) ) {
					nWorldY += HitDelta;
					HitDelta = 0;
				}
			break;
			case SOUTH:
				nWorldY += HitDelta;
				if ( g_Game.Stage.IsBlock( this ) ) {
					nWorldY -= HitDelta;
					HitDelta = 0;
				}
			break;
			case EAST:
				nWorldX += HitDelta;
				if ( g_Game.Stage.IsBlock( this ) ) {
					nWorldX -= HitDelta;
					HitDelta = 0;
				}
			break;
			case WEST:
				nWorldX -= HitDelta;
				if ( g_Game.Stage.IsBlock( this ) ) {
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
}

void CNpc::Render(int nXIndex, int nYIndex) {
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

bool CNpc::MoveNorth() {

	return false;
}

bool CNpc::MoveSouth() {

	return false;
}

bool CNpc::MoveEast() {

	return false;
}

bool CNpc::MoveWest() {

	return false;
}

bool CNpc::MoveBack() {

	return false;
}

void CNpc::Hit() {
	/*if ( nState != HIT ) {
		nState = HIT;
		TickCount = GetTickCount();
		WhenThePlayerDir = pPlayer->GetDir();
		HitDelta = 6;
	}*/

	// 플레이어를 반대편으로 민다.
	((Kail*)pPlayer)->MoveBack();
	
	switch ( nType ) {
		case SMITH:
			g_Game.pKail->ResetCharacterState();
			Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/call_1.wav"],0);
			switch ( g_Game.GetStage() ) {
				case 1:					
					g_Game.ProcessScript( "script/smith.txt" );
				break;
				case 2:
					g_Game.ProcessScript( "script/smith_2.txt" );
				break;
			}
		break;

		case UJIN:
			g_Game.pKail->ResetCharacterState();
			switch ( g_Game.GetStage() ) {
				case 1:
					g_Game.ProcessScript( "script/jinia.txt" );
				break;
				case 2:
					g_Game.ProcessScript( "script/jinia_2.txt" );
				break;
			}			
		break;

		case EAN:
			g_Game.pKail->ResetCharacterState();
			Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/call_2.wav"],0);
			switch ( g_Game.GetStage() ) {
				case 1:					
					g_Game.ProcessScript( "script/ean.txt" );
				break;
				case 2:
				break;
			}			
		break;

		case ARTIUS:
			g_Game.pKail->ResetCharacterState();
			Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/call_3.wav"],0);
			switch ( g_Game.GetStage() ) {
				case 1:
					g_Game.ProcessScript( "script/artius.txt" );
				break;
				case 2:
					g_Game.ProcessScript( "script/artius_2.txt" );
				break;
			}			
		break;

		case FISHGUY:
			g_Game.pKail->ResetCharacterState();
			g_Game.ProcessScript( "script/fishguy.txt" );
		break;

		case KUO:
			g_Game.pKail->ResetCharacterState();

			switch ( g_Game.GetStage() ) {
				case 2:
					g_Game.ProcessScript( "script/kuo_2.txt" );
				break;

			}
		break;
	}
	//g_Game.objScript.
}

int CNpc::Dead() {

	return 0;
}
