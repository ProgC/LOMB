#include "MonAi.h"


CMonAi::CMonAi()
{
	InitMember();
}

CMonAi::~CMonAi()
{
}




VOID CMonAi::InitMember(VOID)
{
	m_Action		= MA_STAND;
	m_bPatrol		= FALSE;
	m_bHold			= FALSE;

	m_War			= MW_OBSERVATION;
	m_HP			= MHP_HIGH_HP;
	m_MP			= MMP_HIGH_MP;

	m_bTeamBattle	= FALSE;
	m_TeamPower		= MTP_NOT_KNOW;
	m_BattleFormation = MB_INDIVIDUAL_COMBAT;
}