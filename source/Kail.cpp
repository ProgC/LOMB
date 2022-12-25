// Kail.cpp: implementation of the Kail class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Skill.h"
#include "Kail.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Kail::Kail()
{

}

Kail::~Kail()
{

}

void Kail::Init() {
	EntityType = IEntity::PLAYER;

	// 걷는 동작
	int WalkFrame = 1;
	WalkEast.SetLoop( true );
	WalkEast.AddFrame( "char/zelda_walk_east_1.bmp", WalkFrame );
	WalkEast.AddFrame( "char/zelda_walk_east_2.bmp", WalkFrame );
	WalkEast.nMaxFrame = 2;
	WalkEast.nCurFrame = 0;

	WalkWest.SetLoop( true );
	WalkWest.AddFrame( "char/zelda_walk_west_1.bmp", WalkFrame );
	WalkWest.AddFrame( "char/zelda_walk_west_2.bmp", WalkFrame );
	WalkWest.nMaxFrame = 2;
	WalkWest.nCurFrame = 0;

	WalkSouth.SetLoop( true );
	WalkSouth.AddFrame( "char/zelda_walk_south_1.bmp", WalkFrame );
	WalkSouth.AddFrame( "char/zelda_walk_south_2.bmp", WalkFrame );
	WalkSouth.nMaxFrame = 2;
	WalkSouth.nCurFrame = 0;

	WalkNorth.SetLoop( true );
	WalkNorth.AddFrame( "char/zelda_walk_north_1.bmp", WalkFrame );
	WalkNorth.AddFrame( "char/zelda_walk_north_2.bmp", WalkFrame );
	WalkNorth.nMaxFrame = 2;
	WalkNorth.nCurFrame = 0;

	// 때리는 동작
	int AttackFrame = 1;
	AttackEast.SetLoop( false );
	AttackEast.AddFrame( "char/zelda_attack_east_1.bmp", AttackFrame );
	AttackEast.AddFrame( "char/zelda_attack_east_2.bmp", AttackFrame );
	AttackEast.AddFrame( "char/zelda_attack_east_3.bmp", AttackFrame );
	AttackEast.nMaxFrame = 3;
	AttackEast.nCurFrame = 0;

	AttackWest.SetLoop( false );
	AttackWest.AddFrame( "char/zelda_attack_west_1.bmp", AttackFrame );
	AttackWest.AddFrame( "char/zelda_attack_west_2.bmp", AttackFrame );
	AttackWest.AddFrame( "char/zelda_attack_west_3.bmp", AttackFrame );
	AttackWest.nMaxFrame = 3;
	AttackWest.nCurFrame = 0;

	AttackSouth.SetLoop( false );
	AttackSouth.AddFrame( "char/zelda_attack_south_1.bmp", AttackFrame );
	AttackSouth.AddFrame( "char/zelda_attack_south_2.bmp", AttackFrame );
	AttackSouth.AddFrame( "char/zelda_attack_south_3.bmp", AttackFrame );
	AttackSouth.nMaxFrame = 3;
	AttackSouth.nCurFrame = 0;
	
	AttackNorth.SetLoop( false );
	AttackNorth.AddFrame( "char/zelda_attack_north_1.bmp", AttackFrame );
	AttackNorth.AddFrame( "char/zelda_attack_north_2.bmp", AttackFrame );
	AttackNorth.AddFrame( "char/zelda_attack_north_3.bmp", AttackFrame );
	AttackNorth.nMaxFrame = 3;
	AttackNorth.nCurFrame = 0;

	// 스킬 시전
	SkillApply.SetLoop( false );
	SkillApply.AddFrame( "char/zelda_skill_1.bmp", 10 );
	SkillApply.AddFrame( "char/zelda_skill_2.bmp", 10 );
	SkillApply.nMaxFrame = 2;
	SkillApply.nCurFrame = 0;

	// data init
	nWorldX = 80;
	nWorldY = 80;
	
	nDir = SOUTH;

	nLevel = 1;
	//nEnergy = 10;
	//nCurrentExp = 0;
	//nNextExp = 100;
	//nCurMana = 10;
	SetLevel();
	nMoney = 0;
	
	nState = STAND;

	// 기본 선택 스킬
	nSelectedSkill = 0;
	
	// 기본 스피드
	BaseSpeed = 2;
	// 스피드 업
	SkillSpeed = 0;

	Inventory.Init();

	nRad = 6;
	
}

void Kail::Update() {
	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );
		
	int nCountOfSkill = vecSkill.size();
	for ( int i = 0; i < nCountOfSkill; i++ ) {
		switch ( vecSkill[i]->nType ) {
			case CSkill::RUN:
				SkillSpeed = 1;
			break;
		}
	}

	// 시간이 지나면 삭제 한다.
	vector<CSkill*>::iterator itor;

	itor = vecSkill.begin();
	while( itor != vecSkill.end() ) {
		if ( GetTickCount() - (*itor)->nSaveTick > (*itor)->nTickCount ) {
			switch ( (*itor)->nType ) {
				case CSkill::RUN:
					SkillSpeed = 0;
				break;
			}
			vecSkill.erase(itor);
		} else {
			itor++;
		}
	}


	if ( nState == STAND ) {
	
	} else if ( nState == ATTACK ) {
		AttackNorth.NextAni();
		AttackSouth.NextAni();
		AttackWest.NextAni();
		AttackEast.NextAni();

		switch ( nDir ) {
			case NORTH:				
				if ( AttackNorth.GetEnd() ) {
					nState = STAND;
				}
			break;
			case EAST:
				if ( AttackEast.GetEnd() ) {
					nState = STAND;
				}
			break;
			case SOUTH:
				if ( AttackSouth.GetEnd() ) {
					nState = STAND;
				}
			break;
			case WEST:
				if ( AttackWest.GetEnd() ) {
					nState = STAND;
				}
			break;
		}
	} else if ( nState == SKILL ) {
		SkillApply.NextAni();

		if ( SkillApply.GetEnd() ) {
			nState = STAND;
		}
	}
}

void Kail::Render(int nXIndex, int nYIndex) {
	if ( nState == STAND ) {
		switch ( nDir ) {
			case NORTH:
				WalkNorth.DrawAni( scx, scy );
			break;
			case EAST:
				WalkEast.DrawAni( scx, scy);
			break;
			case SOUTH:
				WalkSouth.DrawAni( scx, scy);
			break;
			case WEST:
				WalkWest.DrawAni( scx, scy );
			break;
		}
	} else if ( nState == ATTACK ) {
		switch ( nDir ) {
			case NORTH:
				AttackNorth.DrawAni( scx,scy );
			break;
			case EAST:
				AttackEast.DrawAni( scx,scy );
			break;
			case SOUTH:
				AttackSouth.DrawAni( scx,scy );
			break;
			case WEST:
				AttackWest.DrawAni( scx,scy );
			break;
		}
	} else if ( nState == SKILL ) {
		SkillApply.DrawAni( scx,scy );
	}
}

void Kail::InputA() {
	Attack();
}

void Kail::InputB() {
	//Skill(CSkill::RUN);

	switch ( nSelectedSkill ) {
		case 0:
			Skill(CSkill::RUN);
		break;
		case 1:
			Skill(CSkill::HEILLING);
		break;
		case 2:
			Skill(CSkill::MAGIC_BALL);
		break;
	}
}

bool Kail::MoveNorth() {
	bool bCol = false;
	if ( nState == SKILL ) return bCol;

	//int BaseSpeed = 2;
	int CurSpeed = BaseSpeed + SkillSpeed;

	nDir = NORTH;
	nWorldY -= CurSpeed;
	if ( g_Game.Stage.IsBlock( this ) ) {
		nWorldY += CurSpeed;
		bCol = true;
	} else {
		if ( scy < 3 ) {
			nWorldY += CurSpeed;
		}
	}
	WalkNorth.NextAni();
	return bCol;
}

bool Kail::MoveSouth() {
	bool bCol = false;
	if ( nState == SKILL ) return bCol;

	//int BaseSpeed = 1;
	int CurSpeed = BaseSpeed + SkillSpeed;

	nDir = SOUTH;
	nWorldY += CurSpeed;
	if ( g_Game.Stage.IsBlock( this ) ) {
		nWorldY -= CurSpeed;
		bCol = true;
	} else {
		if ( scy > 157 ) {
			nWorldY -= CurSpeed;
		}
	}
	WalkSouth.NextAni();
	return bCol;
}

bool Kail::MoveEast() {
	bool bCol = false;
	if ( nState == SKILL ) return bCol;

	//int BaseSpeed = 1;
	int CurSpeed = BaseSpeed + SkillSpeed;

	nDir = EAST;
	nWorldX += CurSpeed;
	if ( g_Game.Stage.IsBlock( this ) ) {
		nWorldX -= CurSpeed;
		bCol = true;
	} else {
		if ( scx > 157 ) {
			nWorldX -= CurSpeed;
		}
	}
	WalkEast.NextAni();
	return bCol;
}

bool Kail::MoveWest() {
	bool bCol = false;
	if ( nState == SKILL ) return bCol;

	//int BaseSpeed = 1;
	int CurSpeed = BaseSpeed + SkillSpeed;

	nDir = WEST;
	nWorldX -= CurSpeed;
	if ( g_Game.Stage.IsBlock( this ) ) {
		nWorldX += CurSpeed;
		bCol = true;
	} else {
		if ( scx < 3 ) {
			nWorldX += CurSpeed;
		}
	}
	WalkWest.NextAni();
	return bCol;
}

bool Kail::MoveBack() {
	bool bCol = false;

	//int BaseSpeed = 1;
	int CurSpeed = BaseSpeed + SkillSpeed;

	switch ( nDir ) {
		case EAST:			
			MoveWest();
			MoveWest();
			nDir = EAST;
		break;

		case WEST:
			MoveEast();
			MoveEast();
			nDir = WEST;
		break;

		case NORTH:
			MoveSouth();
			MoveSouth();
			nDir = NORTH;
		break;

		case SOUTH:
			MoveNorth();
			MoveNorth();
			nDir = SOUTH;
		break;
	}
	return bCol;
}

void Kail::Attack() {
	if ( nState == STAND ) {
		nState = ATTACK;
		AttackSouth.ResetAni();
		AttackNorth.ResetAni();
		AttackEast.ResetAni();
		AttackWest.ResetAni();

		// 사운드
		int rd = (int)(rand() % 3);
		if ( rd == 0 )
			Mix_PlayChannel(0,g_SoundPack.vecSoundMap["sound/sword1.wav"],0);
		else if ( rd == 1 )
			Mix_PlayChannel(0,g_SoundPack.vecSoundMap["sound/sword2.wav"],0);
		else if ( rd == 2 )
			Mix_PlayChannel(0,g_SoundPack.vecSoundMap["sound/sword3.wav"],0);
		else
			Mix_PlayChannel(0,g_SoundPack.vecSoundMap["sound/sword3.wav"],0);
		
	}
}

// 스킬 시전
void Kail::Skill( CSkill::SKILL_TYPE nType ) {
	if ( nState != SKILL ) {
		// skill db에서 현재 마나로 쓸 수 있는지 검사한다.
		nCurMana -= CSkill::nMana[(int)nType];
		// 마나 처리
		if ( nCurMana > 0 ) {
			nState = SKILL;
			SkillApply.ResetAni();
			Mix_PlayChannel(0,g_SoundPack.vecSoundMap["sound/skill1.wav"],0);

			// Skill을 넣어 준다.
			CSkill* pSkill = new CSkill();
			pSkill->SetSkill( nType );
			vecSkill.push_back( pSkill );
		} else {
			nCurMana = 0;
		}
	}
}

void Kail::GetMoney( int nMoney_ ) {
	nMoney += nMoney_;
}

void Kail::UseItem( int index ) {
	const s_Item* pItem = NULL;
	pItem = g_ItemDB.GetItem( Inventory.vecItem[index].id );

	if ( pItem ) {
		switch ( pItem->nID ) {
			case 47: // 생명의 약
				Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/potion.wav"],0);
				TakeHealth();
				
			break;

			case 48: // 마나의 약
				Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/potion.wav"],0);
				TakeMana();

			break;
		}

		// 벡터에서 삭제
		Inventory.vecItem.erase( Inventory.vecItem.begin() + index );
	}
}

void Kail::SetLevel() {
	nEnergy = g_LevelDB.Data[nLevel].MaxHP;
	nCurMana = g_LevelDB.Data[nLevel].MaxMP;
	nCurrentExp = 0;
	nNextExp = g_LevelDB.Data[nLevel].Exp;

}

void Kail::TakeHealth() {
	nEnergy += 5;
	if ( nEnergy > g_LevelDB.Data[nLevel].MaxHP ) {
		nEnergy = g_LevelDB.Data[nLevel].MaxHP;
	}
}

void Kail::TakeMana() {
	nCurMana += 10;

	if ( nCurMana > g_LevelDB.Data[nLevel].MaxMP ) {
		nCurMana = g_LevelDB.Data[nLevel].MaxMP;
	}
}

void Kail::Hit() {
	nEnergy--;
}

int Kail::Dead() {
	// 상황에 맞추어서 게임을 끝내던가 스테이지를 증가시키던가 한다.
	g_Game.KailDead();
	return 1;
}

void Kail::Recover() {
	nEnergy = 10;
	nState = STAND;
}