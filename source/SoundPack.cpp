// SoundPack.cpp: implementation of the CSoundPack class.
//
//////////////////////////////////////////////////////////////////////

#include "SoundPack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSoundPack::CSoundPack()
{

}

CSoundPack::~CSoundPack() {
	
}

bool CSoundPack::LoadSound() {
	LoadSound( "sound/sword1.wav" );
	LoadSound( "sound/sword2.wav" );
	LoadSound( "sound/sword3.wav" );

	LoadSound( "sound/pupu_die.wav" );
	LoadSound( "sound/pupu_hit.wav" );
	LoadSound( "sound/skill1.wav" );


	LoadSound( "sound/pinkpig_hit1.wav" );
	LoadSound( "sound/pinkpig_hit2.wav" );
	LoadSound( "sound/pinkpig_die.wav" );

	LoadSound( "sound/bluepig_hit1.wav" );
	LoadSound( "sound/bluepig_hit2.wav" );
	LoadSound( "sound/bluepig_att1.wav" );
	LoadSound( "sound/bluepig_die1.wav" );
	
	LoadSound( "sound/amber_hit1.wav" );
	LoadSound( "sound/amber_hit2.wav" );
	LoadSound( "sound/amber_att1.wav" );
	LoadSound( "sound/amber_die.wav" );

	LoadSound( "sound/select.wav" );

	LoadSound( "sound/call_1.wav" );
	LoadSound( "sound/call_2.wav" );
	LoadSound( "sound/call_3.wav" );

	LoadSound( "sound/potion.wav" );
	LoadSound( "sound/flippot.wav" );	
	LoadSound( "sound/gold1.wav" );	
	return true;
}

bool CSoundPack::LoadSound( char* filename ) {
	Mix_Chunk* p = Mix_LoadWAV( filename );
	
	pair< string , Mix_Chunk* > em;
	em.first = string(filename);
	em.second = p;

	vecSoundMap.insert( em );
	return true;
}


