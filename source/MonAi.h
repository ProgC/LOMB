#pragma once
#include <Windows.h>
#include "MonDefine.h"


class CMonAi
{
public:
	CMonAi();
	~CMonAi();
	VOID			InitMember(VOID);
protected:
	MONAI_ACTION	m_Action;
	BOOL			m_bPatrol;
	BOOL			m_bHold;

	MONAI_WAR		m_War;
	MONAI_HP		m_HP;
	MONAI_MP		m_MP;

	BOOL			m_bTeamBattle;
	MONAI_TEAM_BATTLE_POWER m_TeamPower;
	MONAI_BATTLE_FORMATION m_BattleFormation;

private:
};



