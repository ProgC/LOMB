// Map.cpp: implementation of the CMap class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Map.h"
#include "CreticalSection.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CMap::CMap() {

}

CMap::~CMap() {
	
}

void CMap::LoadMap(FILE* fp) {
	char szBuffer[128];
	
	static CCreticalSection cs;
	cs.Lock();	

	for ( int y = 0; y < 10; y++ ) {
		for ( int x = 0; x < 10; x++ ) {
			fread( &m_Map[y][x].ImageNumber, 1, sizeof(int), fp );
			fread( &m_Map[y][x].nCollision, 1, sizeof(int), fp );
			fread( &m_Map[y][x].nEventProperty, 1, sizeof(int), fp );
			
			sprintf( szBuffer, "map/%d.bmp" , m_Map[y][x].ImageNumber );
			m_Map[y][x].Moveable = MOVE;
			m_Map[y][x].surface = g_SpritePack.vecImageMap[szBuffer]->surface;
		}
	}
	
	int i = 0;
	fread( &nCountOfMob, 1, sizeof(int), fp );
	
	for ( i = 0; i < nCountOfMob; i++ ) {
		s_Mob mob;
		fread( &mob.MobID, 1,sizeof(int), fp );
		fread( &mob.nRespwan, 1,sizeof(int), fp );
		fread( &mob.nWorldX, 1,sizeof(int), fp );
		fread( &mob.nWorldY, 1,sizeof(int), fp );
		
		vecMob.push_back( mob );
		
		// 월드에 찍는다.
		g_Game.AddMonster( mob.MobID, mob.nWorldX, mob.nWorldY );		
	}


	fread( &nCountOfNpc, 1, sizeof(int), fp );	
	for ( i = 0; i < nCountOfNpc; i++ ) {
		s_Npc npc;
		fread( &npc.NpcID, 1,sizeof(int), fp );
		fread( &npc.nWorldX, 1,sizeof(int), fp );
		fread( &npc.nWorldY, 1,sizeof(int), fp );
		
		vecNpc.push_back( npc );
		
		// 월드에 찍는다.
		g_Game.AddNpc( npc.NpcID, npc.nWorldX, npc.nWorldY );
	}
	cs.UnLock();
}

void CMap::Update() {
	
}

void CMap::Render() {
	for ( int y = 0; y < 10; y++ ) {
		for ( int x = 0; x < 10; x++ ) {
		    SDL_Rect offset;
    
			//Give the offsets to the rectangle
			offset.x = x * 16;
			offset.y = y * 16;
			
			//Blit the surface
			SDL_BlitSurface( m_Map[y][x].surface, NULL, screen, &offset );			
		}
	}
}

void CMap::Process( int nEvent ) {
	switch ( nEvent ) {
		case 1: // boss_1
			// 새로운 맵을 읽는다.
			//g_Game.LoadMap(  "map/boss1.dat" );
			//g_Game.SetBossStage();
			g_Game.ProcessScript( "script/dun1.txt" );
		break;

		case 2: // dungun 1
			g_Game.ProcessScript( "script/dun2.txt" );
			//g_Game.LoadMap( "map/dun1.dat" );
			//g_Game.UnSetBossStage();			
			// 스크립트를 진행한다. 쿠오아주머니와 이야기를 해야 들어갈 수 있다.
			
		break;

		case 3:
			g_Game.ProcessScript( "script/dun3.txt" );
		break;
	}
}


