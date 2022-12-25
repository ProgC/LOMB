// Skill.cpp: implementation of the CSkill class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Bullet.h"
#include "Skill.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int	CSkill::nMana[30];	  // �ҿ�Ǵ� ����

CSkill::CSkill() {
	nMana[0] = 3; // �ٴµ� ��� ����
	nMana[1] = 4; // �����ϴµ� ��� ����
	nMana[2] = 2; // ������
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
			// ���� ���� �����.
			// ������ ���� 1��,2��,3������
			g_Game.AddBullet( CBullet::KAIL_MAGIC_BALL, g_Game.pKail->GetWorldX(), g_Game.pKail->GetWorldY(), 0 , 0 , g_Game.pKail->nDir );
		break;
	}
}

