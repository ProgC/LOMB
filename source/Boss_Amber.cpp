// Boss_Amber.cpp: implementation of the CBoss_Amber class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Boss_Amber.h"
#include "BossAmberAction.h"
#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBoss_Amber::CBoss_Amber() {
	g_Game.objScript.LoadScript( "script/boss_amber.txt" );


	m_pCurrentState = CBossAmber_Stand::Instance();

	Point[0].x = 32 + 8;
	Point[0].y = 32 + 8;

	Point[1].x = 32 + 8;
	Point[1].y = 112 + 8;

	Point[2].x = 112 + 8;
	Point[2].y = 112 + 8;

	Point[3].x = 112 + 8;
	Point[3].y = 32 + 8;

	PointX[0].x = 32 + 8;
	PointX[0].y = 32 + 8;

	PointX[1].x = 112 + 8;
	PointX[1].y = 112 + 8;

	PointX[2].x = 32 + 8;
	PointX[2].y = 112 + 8;

	PointX[3].x = 112 + 8;
	PointX[3].y = 32 + 8;
}

CBoss_Amber::~CBoss_Amber() {
	
}

void CBoss_Amber::Update() {
	CMonster::Update();
	m_pCurrentState->Execute( this );
}

void CBoss_Amber::Render(int nXIndex, int nYIndex) {
	CMonster::Render( nXIndex, nYIndex );
}

void CBoss_Amber::Hit() {
	CMonster::Hit();
	//Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/amber_hit.wav"],0);

	if ( HitDelta == 6 ) {
		int rd = (int)(rand() % 2);
		if ( rd == 0 )
			Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/amber_hit1.wav"],0);
		else
			Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/amber_hit2.wav"],0);
	}
}

int CBoss_Amber::Dead() {
	Mix_PlayChannel(1,g_SoundPack.vecSoundMap["sound/amber_die.wav"],0);
	g_Game.objScript.LoadScript( "script/boss_amber.txt" );
	return 0;
}


void CBoss_Amber::ChangeState(KState* pNewState) {
  assert (m_pCurrentState && pNewState);

  //call the exit method of the existing state
  m_pCurrentState->Exit(this);

  //change state to the new state
  m_pCurrentState = pNewState;

  //call the entry method of the new state
  m_pCurrentState->Enter(this);
}