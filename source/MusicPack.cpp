// MusicPack.cpp: implementation of the CMusicPack class.
//
//////////////////////////////////////////////////////////////////////

#include "MusicPack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMusicPack::CMusicPack()
{

}

CMusicPack::~CMusicPack()
{

}

bool CMusicPack::LoadMusic() {
	LoadMusic( "music/z3lightw.mid" );
	LoadMusic( "music/forest_stage1.mid" );
	LoadMusic( "music/holes.mid" );
	LoadMusic( "music/GanondorfBattle.mid" );
	LoadMusic( "music/Ganondorf.mid" );
	LoadMusic( "music/Zelda1.mid" );
	LoadMusic( "music/Song_002.mid" );
	LoadMusic( "music/z64gerudo.mid" );
	return true;
}

bool CMusicPack::LoadMusic( char* filename ) {
	Mix_Music* p = Mix_LoadMUS( filename );
		
	pair< string , Mix_Music* > em;
	em.first = string(filename);
	em.second = p;

	vecMusicMap.insert( em );
	return true;
}

