// BluePig.cpp: implementation of the CBluePig class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "BluePig.h"
#include "BluePigAction.h"

CBluePig::CBluePig() {
	m_pCurrentState = CBluePigAction_Stand::Instance();

	nFieldOfView = 120;
}

CBluePig::~CBluePig() {
	
}

void CBluePig::Update() {
	CMonster::Update();
	
	if (g_Game.Stage.nXIndex != (int)GetWorldX() / 160) return;
	if (g_Game.Stage.nYIndex != (int)GetWorldY() / 160) return;

	m_pCurrentState->Execute( this );
}

void CBluePig::Render(int nXIndex, int nYIndex) {
	CMonster::Render( nXIndex, nYIndex );
}

void CBluePig::Hit() {
	CMonster::Hit();

	if ( HitDelta == 6 ) {
		int rd = (int)(rand() % 2);
		if ( rd == 0 )
			Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/bluepig_hit1.wav"],0);
		else
			Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/bluepig_hit1.wav"],0);
	}
}

int CBluePig::Dead() {
	//g_Game.objScript.LoadScript( "script/boss_amber.txt" );
	CMonster::Dead();

	Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/bluepig_die1.wav"],0);
	return 0;
}

void CBluePig::ChangeState(KState* pNewState) {
	assert (m_pCurrentState && pNewState);

	//call the exit method of the existing state
	m_pCurrentState->Exit(this);

	//change state to the new state
	m_pCurrentState = pNewState;

	//call the entry method of the new state
	m_pCurrentState->Enter(this);
}