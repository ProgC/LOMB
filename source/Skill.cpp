// Skill.cpp: implementation of the CSkill class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Bullet.h"
#include "Skill.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int	CSkill::nMana[30];	  // 소요되는 마나

CSkill::CSkill() {
	nMana[0] = 3; // 뛰는데 드는 마나
	nMana[1] = 4; // 힐링하는데 드는 마나
	nMana[2] = 2; // 매직볼
}

CSkill::~CSkill() {

}

void CSkill::SetSkill( SKILL_TYPE nType_ ) {
	nType = nType_;

	switch ( nType ) {
		case RUN:
			SetTime( 3000 );
		break;

		case HEILLING:
			g_Game.pKail->TakeHealth();
		break;

		case MAGIC_BALL: 
			// 매직 볼을 만든다.
			// 레벨에 따라서 1개,2개,3개까지
			g_Game.AddBullet( CBullet::KAIL_MAGIC_BALL, g_Game.pKail->GetWorldX(), g_Game.pKail->GetWorldY(), 0 , 0 , g_Game.pKail->nDir );
		break;
	}
}

