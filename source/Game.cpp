// Game.cpp: implementation of the CGame class.
//
//////////////////////////////////////////////////////////////////////

#pragma warning ( disable : 4786 )
#include <algorithm>
#include "global.h"
#include "Game.h"
#include "Monster.h"
#include "CreticalSection.h"
#include "Bullet.h"


using namespace std;

bool OldKey_InputZ;
bool NewKey_InputZ;
bool OldKey_InputX;
bool NewKey_InputX;
bool OldKey_InputI;
bool NewKey_InputI;

bool OldKey_InputQ;
bool NewKey_InputQ;
bool OldKey_InputW;
bool NewKey_InputW;
bool OldKey_InputE;
bool NewKey_InputE;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


// mmorpg처럼 마우스로 클릭해서 공격하게 만드는것도 재밌을 것 같다.

CGame::CGame() {
	
}

CGame::~CGame() {
	ReleaseData();
}

void CGame::Init() {	
	static CCreticalSection cs;
	cs.Lock();	
// 테스트

	//Mix_PlayMusic( g_MusicPack.vecMusicMap["music/z3lightw.mid"] , -1 );
	Mix_VolumeMusic( 64 );

	bGame = true;

	// 주인공 케릭터를 리스트에 넣는다.
	pKail = new Kail();
	pKail->Init();
	vecObjList.push_back( pKail );

	nStage = 1;
	Stage.Load("map/Stage1.dat");
	pKail->SetWorldX( Stage.GetStartX() );
	pKail->SetWorldY( Stage.GetStartY() );

	cs.UnLock();
	for ( int i = 0; i < 0; i++ ) {	
		CMonster *pMonster = new CMonster();
		
		// 월드좌표 셋팅
		pMonster->SetWorldX( rand() % 160 );
		pMonster->SetWorldY( rand() % 160 );
		
		pMonster->SetMonsterType( (CMonster::MONSTER_TYPE)0 );
		pMonster->Init();
		pMonster->SetPlayer( pKail );
		vecObjList.push_back( pMonster );
	}
	
	objScript.Init();
	objScript.LoadVariable( "variable.txt" );


	//objScript.LoadScript("script/intro.txt");
	objScript.LoadScript("script/prolog.txt");
}

void CGame::ReleaseData() {
	int nCountOfObject = vecObjList.size();
	int i = 0;
	for ( i = 0; i < nCountOfObject; i++ ) {
		delete vecObjList[i];
	}
	vecObjList.clear();

	for ( i = 0; i < vecBulletList.size(); i++ ) {
		delete vecBulletList[i];
	}
	vecBulletList.clear();
}

void CGame::ClearObject() {
	vector<CMoveableEntity*>::iterator itor;
	
	itor = vecObjList.begin();
	while( itor != vecObjList.end() ) {
		if ( (*itor) != pKail ) {
			delete *itor;
			*itor = NULL;
			itor = vecObjList.erase(itor);
		} else {
			itor++;
		}
	}
}

void CGame::GameUpdate() {
	static DWORD gTimeInput;

	if ( GetAsyncKeyState( 'Z' ) != 0 ) { // z키
		NewKey_InputZ = true;
	} else NewKey_InputZ = false;
	if ( GetAsyncKeyState( 'X' ) != 0 ) { // x키
		NewKey_InputX = true;
	} else NewKey_InputX = false;
	if ( GetAsyncKeyState( 'A' ) != 0 ) { // a키가 인벤토리
		NewKey_InputI = true;
	} else NewKey_InputI = false;

	if ( GetAsyncKeyState( 'Q' ) != 0 ) { // 첫번째 스킬
		NewKey_InputQ = true;
	} else NewKey_InputQ = false;

	if ( GetAsyncKeyState( 'W' ) != 0 ) { // 두번째 스킬
		NewKey_InputW = true;
	} else NewKey_InputW = false;

	if ( GetAsyncKeyState( 'E' ) != 0 ) { // 세번째 스킬
		NewKey_InputE = true;
	} else NewKey_InputE = false;
		
	if ( GetTickCount() - gTimeInput > 30 ) {
		// 입력 처리
		if ( GetAsyncKeyState( VK_UP ) != 0 ) {
			InputUp();
		}
		if ( GetAsyncKeyState( VK_DOWN ) != 0 ) {
			InputDown();
		}
		if ( GetAsyncKeyState( VK_LEFT ) != 0 ) {
			InputLeft();
		}
		if ( GetAsyncKeyState( VK_RIGHT ) != 0 ) {
			InputRight();
		}
		if ( !OldKey_InputZ && NewKey_InputZ  ) { // a키
			InputA();
		}
		if ( !OldKey_InputX && NewKey_InputX ) {
			InputB();
		}
		if ( !OldKey_InputI && NewKey_InputI ) {
			ViewInventory();
		}

		if ( !OldKey_InputQ && NewKey_InputQ ) {
			pKail->nSelectedSkill = 0;
		}
		if ( !OldKey_InputW && NewKey_InputW ) {
			pKail->nSelectedSkill = 1;
		}
		if ( !OldKey_InputE && NewKey_InputE ) {
			pKail->nSelectedSkill = 2;
		}

		gTimeInput = GetTickCount();
	}

	switch ( GameState ) {
		case GAME:		
			UpdateGame();
		break;
		case SCRIPT:			
			UpdateScript();
		break;
		case INVENTORY:
			g_GameUI.Update();			
		break;

		case CREDIT:
			UpdateGameCredit();
		break;
	}
	Effect.Update();

	OldKey_InputZ = NewKey_InputZ;
	OldKey_InputX = NewKey_InputX;
	OldKey_InputI = NewKey_InputI;


	OldKey_InputQ = NewKey_InputQ;
	OldKey_InputW = NewKey_InputW;
	OldKey_InputE = NewKey_InputE;
}

void CGame::GameRender() {
	switch ( GameState ) {
		case GAME:
			RenderGame();
			Effect.Render();
		break;
		case SCRIPT:
			RenderScript();
			Effect.Render();
		break;
		case INVENTORY:
			RenderGame();
			Effect.Render();
		break;

		case CREDIT:
			RenderGameCredit();
		break;
	}	
}

void CGame::UpdateGame() {
	if ( !bGame ) return;


	static CCreticalSection cs;
	cs.Lock();	



	Stage.IsScrollArea( pKail );
	Stage.Update();
	
	int nCountOfObject = vecObjList.size();
	int nCountOfBullet = vecBulletList.size();
	int i = 0;


	for ( i = 0; i < nCountOfObject; i++ ) {
		vecObjList[i]->Update();
	}

	for ( i = 0; i < nCountOfBullet; i++ ) {
		vecBulletList[i]->Update();
	}
		
	// 충돌 처리
	if ( Kail::ATTACK == pKail->GetState() ) {
		int i = 0;
		for ( i = 0; i < nCountOfObject; i++ ) {
			if ( pKail != vecObjList[i] ) {
				CollisionPlayerAttackWithObj( vecObjList[i] );
			}
		}		

		for ( i = 0; i < nCountOfBullet; i++ ) {
			if ( pKail != vecBulletList[i] ) {
				CollisionPlayerAttackWithObj( vecBulletList[i] );
			}
		}
	}



	for ( i = 0; i < nCountOfObject; i++ ) {
		// 플레이어와 Entity
		if ( pKail != vecObjList[i] ) {
			CollisionPlayerWithObj( vecObjList[i] );
		}		
	}

	for ( i = 0; i < nCountOfBullet; i++ ) {
		if ( ((CBullet*)vecBulletList[i])->WhoMadeThis() == 0 ) {
			CollisionPlayerWithObj( vecBulletList[i] );
		} else if ( ((CBullet*)vecBulletList[i])->WhoMadeThis() == 1 ) {
			// 적과 해당 총알
			for ( int j = 0; j < nCountOfObject; j++ ) {
				if ( vecObjList[j] != pKail ) {
					CollisionBulletWithObj( vecObjList[j], (CBullet*)vecBulletList[i] );
				}
			}		
		}
	}
	
	// 오브젝트를 Y축으로 정렬한다.
	sort( vecObjList.begin(), vecObjList.end(), IEntity::CompareObj );
	
	// 에너지 없는 것들은 리스트에서 없앤다.
	vector<CMoveableEntity*>::iterator itor;
	
	itor = vecObjList.begin();
	while( itor != vecObjList.end() ) {
		if ( (*itor)->GetEnergy() <= 0 ) {
			if ( (*itor)->Dead() == 0 ) {
				delete *itor;
				*itor = NULL;
				itor = vecObjList.erase(itor);
			} else {
				itor++;
			}
		} else {
			itor++;
		}
	}

	itor = vecBulletList.begin();
	while( itor != vecBulletList.end() ) {
		if ( (*itor)->GetEnergy() <= 0 ) {
			(*itor)->Dead();
			delete *itor;
			*itor = NULL;
			itor = vecBulletList.erase(itor);
		} else {
			itor++;
		}
	}

	int nCountOfAddEntity = vecReserveAddEntity.size();
	for ( i = 0; i < nCountOfAddEntity; i++ ) {
		vecObjList.push_back( vecReserveAddEntity[i] );
	}
	vecReserveAddEntity.clear();
		
	g_GameUI.Update();



	cs.UnLock();
}

void CGame::RenderGame() {
	if ( !bGame ) return;
	
	Stage.Render();
	
	int nCountOfObject = vecObjList.size();
	for ( int i = 0; i < nCountOfObject; i++ ) {
		vecObjList[i]->Render(Stage.nXIndex,Stage.nYIndex);
	}	

	int nCountOfBullet = vecBulletList.size();
	for ( i = 0; i < nCountOfBullet; i++ ) {
		vecBulletList[i]->Render(Stage.nXIndex,Stage.nYIndex);
	}	
	

	g_GameUI.Render();
}

void CGame::UpdateScript() {
	if ( GetAsyncKeyState( 'Z' ) != 0 ) { // a키
		NewKey_InputZ = true;
	} else NewKey_InputZ = false;
	if ( GetAsyncKeyState( 'X' ) != 0 ) { // b키
		NewKey_InputX = true;
	} else NewKey_InputX = false;

	if ( OldKey_InputZ == false && NewKey_InputZ == true ) {
		objScript.CurrentState = CONTINUE;

		if ( objScript.GetCurCommand() == SC_NARRATION ) {
			if ( !objScript.IsEndNarration() ) {
				objScript.CurrentState = WAIT_KEYBOARD;
			}
		}

		if ( !Effect.GetEnd() ) {
			objScript.CurrentState = WAIT_END;
		}
	}
		
	if ( objScript.CurrentState == CONTINUE ) {
		do {
			Sleep(1);
			objScript.Step();
		} while( objScript.CurrentState == CONTINUE );
	}
	
	OldKey_InputZ = NewKey_InputZ;
	OldKey_InputX = NewKey_InputX;

	if ( objScript.CurrentState == SCRIPT_END ) {
		GameState = GAME;
	}

	if ( objScript.CurrentState == WAIT_KEYBOARD ) {
		if ( objScript.GetCurCommand() == SC_NARRATION ) {
			objScript.NextWord();
		}
	}
}

void CGame::RenderScript() {
	if ( !bGame ) return;
	

	Stage.Render();	
	int nCountOfObject = vecObjList.size();
	for ( int i = 0; i < nCountOfObject; i++ ) {
		vecObjList[i]->Render(Stage.nXIndex,Stage.nYIndex);
	}		
	g_GameUI.Render();

	if ( objScript.bBitmapImage ) {
		objScript.BitmapImage.DrawAni(0,0,160,160);
	}
	
	if ( objScript.CurrentState == WAIT_KEYBOARD ) {
		if ( objScript.GetCurCommand() == SC_PRINT ) {
			PrintHanWithShadow(7,11,objScript.TextBuffer, 0, KS_1, 0xffffffff );
		} else if ( objScript.GetCurCommand() == SC_NARRATION ) {
			PrintHanWithShadowLen(7,11,objScript.TextBuffer, 0, KS_1, 0xffffffff, objScript.nCurNarrationLen );
		}
	}
}

void CGame::SetCredit() {
	GameState = CREDIT;
	fCreditY = 160;
	GameCredit.AddFrame( "img/background_credit.bmp", 1 );
	GameCredit.nMaxFrame = 1;
	GameCredit.nCurFrame = 0;
}

void CGame::UpdateGameCredit() {
	fCreditY -= 0.5f;

	if ( fCreditY < -700 ) {
		bGame = false;
	}
}

void CGame::RenderGameCredit() {	
	GameCredit.DrawAni( 0, fCreditY );
}

void CGame::InputUp() {
	switch ( GameState ) {
		case GAME: {
			if ( pKail ) 
				pKail->MoveNorth();
		}
		break;		

		case INVENTORY:
			g_GameUI.InputUp();
		break;
	}
}

void CGame::InputDown() {
	switch ( GameState ) {
		case GAME: {
			if ( pKail ) 
				pKail->MoveSouth();
		}
		break;

		case INVENTORY:
			g_GameUI.InputDown();
		break;
	}		
}

void CGame::InputLeft() {
	switch ( GameState ) {
		case GAME: {
			if ( pKail ) 
				pKail->MoveWest();
		}
		break;

		case INVENTORY:
			g_GameUI.InputLeft();
		break;

	}
}

void CGame::InputRight() {
	switch ( GameState ) {
		case GAME: {
			if ( pKail ) 
				pKail->MoveEast();
		}
		break;

		case INVENTORY:
			g_GameUI.InputRight();
		break;
	}
		
}

void CGame::InputA() {
	switch ( GameState ) {
		case GAME: {
			if ( pKail ) 
				pKail->InputA();
		}
		break;
		case INVENTORY:
			g_GameUI.InputA();
		break;
	}
			
}

void CGame::InputB() {
	switch ( GameState ) {
		case GAME: {
			if ( pKail ) 
				pKail->InputB();
		}
		break;
		case INVENTORY:
			g_GameUI.InputB();
		break;
	}		
}

CMoveableEntity* CGame::GetNearThisPointInEvil( Vector2D& Pos ) {
	int nCountOfObject = vecObjList.size();
	int i = 0;

	CMoveableEntity* pEntity = NULL;
	double dLen = 9999;

	Vector2D targetPos;
	for ( i = 0; i < nCountOfObject; i++ ) {
		if ( vecObjList[i]->GetEntityType() == IEntity::MONSTER ) {
		//if ( pKail != vecObjList[i] ) {
			targetPos.x = vecObjList[i]->GetWorldX();
			targetPos.y = vecObjList[i]->GetWorldY();
			
			if ( Pos.Distance( targetPos ) < dLen ) {
				pEntity = vecObjList[i];
				dLen = Pos.Distance( targetPos );
			}
		}
	}
	return pEntity;
}

void CGame::ProcessScript( char* filename ) {
	GameState = SCRIPT;
	objScript.LoadScript( filename );
}


void CGame::FadeIn() {
	Effect.SetFadeIn();
}

void CGame::FadeOut() {
	Effect.SetFadeOut();
}

void CGame::FadeOutGray() {
	Effect.SetFadeOutGray();
}

void CGame::FadeInWhite() {
	Effect.SetFadeInWhite();
}
void CGame::FadeOutWhite() {
	Effect.SetFadeOutWhite();
}

void CGame::LoadMap( const char* filename ) {	
	UnSetBossStage();

	ClearObject();
	
	if ( strcmp( filename, "map/stage1.dat" ) == 0 ) {
		nStage = 1;
	} else if ( strcmp( filename, "map/stage2.dat" ) == 0 ) {
		nStage = 2;
	} else if ( strcmp( filename, "map/boss1.dat" ) == 0 ) {
		nStage = 1;
		g_Game.SetBossStage();
	} else if ( strcmp( filename, "map/stage3.dat" ) == 0 ) {
		nStage = 3;
	}
	
	Stage.Load(filename);
	pKail->SetWorldX( Stage.GetStartX() );
	pKail->SetWorldY( Stage.GetStartY() );
	pKail->Update();
}

void CGame::KailDead() {
	// 보스전이라면 스테이지를 넘긴다.
	Mix_HaltMusic();
	
	if ( GetBossStage() ) {
		switch ( nStage ) {
			case 1:
				pKail->Recover();
				ProcessScript( "script/exit_stage1.txt" );
			break;
			case 2:
				pKail->Recover();
				ProcessScript( "script/exit_stage2.txt" );				
			break;
		}
	} else {
		ProcessScript( "script/exit_game.txt" );
	}
}

void CGame::ViewInventory() {
	if ( GameState != INVENTORY ) {
		// 이전 상태 기록
		PrevState = GameState;
		GameState = INVENTORY;
		g_GameUI.nState = GameUI::INVENTORY;
	} else {
		GameState = PrevState;		
		g_GameUI.nState = GameUI::GAME;
	}
}
