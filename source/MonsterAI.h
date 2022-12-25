#pragma once
#include "Monster.h"
#include "MonAi.h"

class CMonsterAI : public CMonster {
public:
	CMonsterAI();
	~CMonsterAI();

protected:
	CMonAi		m_MonAI;
private:
};