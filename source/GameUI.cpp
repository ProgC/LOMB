// GameUI.cpp: implementation of the GameUI class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "GameUI.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GameUI::GameUI() {
	nState = GAME;

	nFocusX = 0;
	nFocusY = 0;
}

GameUI::~GameUI()
{

}

void GameUI::Init() {
	UI_Game.AddFrame( "ui.bmp", 1 );
	UI_Game.nMaxFrame = 1;
	UI_Game.nCurFrame = 0;

	// 에너지 바
	UI_Game_Energy.AddFrame( "hp.bmp", 1 );
	UI_Game_Energy.nMaxFrame = 1;
	UI_Game_Energy.nCurFrame = 0;
	
	// 마나 
	UI_Game_Mana.AddFrame( "mp.bmp", 1 );
	UI_Game_Mana.nMaxFrame = 1;
	UI_Game_Mana.nCurFrame = 0;

	// 채팅 윈도우
	UI_ChatWindow.AddFrame( "textwindow.bmp", 1 );
	UI_ChatWindow.nMaxFrame = 1;
	UI_ChatWindow.nCurFrame = 0;

	UI_Inventory.AddFrame( "Inventory.bmp", 1 );
	UI_Inventory.nMaxFrame = 1;
	UI_Inventory.nCurFrame = 0;
	
	UI_Inventory_Focus.AddFrame( "Inventory_focus.bmp", 1 );
	UI_Inventory_Focus.nMaxFrame = 1;
	UI_Inventory_Focus.nCurFrame = 0;

	UI_Game_SelectedSkill.AddFrame( "ui_focus.bmp", 1 );
	UI_Game_SelectedSkill.nMaxFrame = 1;
	UI_Game_SelectedSkill.nCurFrame = 0;

//		CAnimationFrame UI_Game;
//	CAnimationFrame UI_Information;
}

void GameUI::Update() {
	switch ( nState ) {
		case GAME:
			//UI_Game.DrawAni( 0, 160 );
		break;

		case CHARACTER:
		break;

		case INVENTORY:
		break;
	}
}

void GameUI::InputLeft() {
	nFocusX--;
	if ( nFocusX < 0 ) nFocusX = 0;
	Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/select.wav"],0);
}

void GameUI::InputRight() {
	nFocusX++;
	if ( nFocusX > 14 ) nFocusX = 14;
	Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/select.wav"],0);
}

void GameUI::InputUp() {
	nFocusY--;
	if ( nFocusY < 0 ) nFocusY = 0;
	Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/select.wav"],0);
}

void GameUI::InputDown() {
	nFocusY++;
	if ( nFocusY > 9 ) nFocusY = 9;

	Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/select.wav"],0);
}

void GameUI::InputA() {
	// 해당 아이템을 먹던가 교체한다.
	
	int nCountOfItems = g_Game.pKail->Inventory.vecItem.size();

	const s_Item* pItem = NULL;

	for ( int i = 0; i < nCountOfItems; i++ ) {		
		if ( nFocusX == i%15 && nFocusY == i/15 ) {
			pItem = g_ItemDB.GetItem( g_Game.pKail->Inventory.vecItem[i].id );

			if ( pItem ) {
				g_Game.pKail->UseItem( i );
			}						
			return;
		}
	}

	// 해당 아이템을 사용한다.
	//if ( pItem ) {


	//}
}

void GameUI::InputB() {
	// 해당 아이템을 버린다.
}

void GameUI::Render() {
	switch ( nState ) {
		case GAME: {
			UI_Game.DrawAni(0,160);

			// 에너지 바
			Kail* pKail = g_Game.pKail;
			int curHP = pKail->GetEnergy();
			int maxHP = g_LevelDB.Data[pKail->nLevel].MaxHP;
			float GetWidth = 24 * (curHP / (float)maxHP);
			UI_Game_Energy.DrawAni(80,164,GetWidth,2);	

			int curMP = pKail->nCurMana;
			int maxMP = g_LevelDB.Data[pKail->nLevel].MaxMP;
			float GetMana = 24 * (curMP / (float)maxMP );
			UI_Game_Mana.DrawAni( 80, 169,GetMana,2 );

			if ( g_Game.GameState == CGame::SCRIPT ) {
				if ( g_Game.objScript.CurrentState == WAIT_KEYBOARD ) {
					UI_ChatWindow.DrawAni( 0 , 0 );
				}
			}

			// 스킬 선택창
			UI_Game_SelectedSkill.DrawAni( 108 + (g_Game.pKail->nSelectedSkill * 9), 160 + 3 );
			
		}
		break;

		case CHARACTER:
		break;

		case INVENTORY:
			UI_Inventory.DrawAni( 0 , 0 );

			RenderInventory();		
		break;
	}
}

void GameUI::RenderInventory() {
	// 카일이 가지고 있는 아이템을 모두 그려준다.
	int nCountOfItems = g_Game.pKail->Inventory.vecItem.size();
	
	// 가로 5칸
	// 세로 10칸
	// 30 pixel

	// 4,24부터
	// 가로 150픽셀
	// 세로 100
	const s_Item* pItem = NULL;

	for ( int i = 0; i < nCountOfItems; i++ ) {
		g_Game.pKail->Inventory.vecItem[i].ItemFrame.DrawAniWithoutOrigin( 4 + (i%15) * 10, 24 + (i/15) * 10 );

		if ( nFocusX == i%15 && nFocusY == i/15 ) {
			pItem = g_ItemDB.GetItem( g_Game.pKail->Inventory.vecItem[i].id );
		}
	}

	UI_Inventory_Focus.DrawAni( 4 + nFocusX * 10, 24 + nFocusY * 10 );

	// 포커스 되어 있는 아이템 설명글
	if ( pItem ) {
		PrintHan(0,100,(char*)pItem->Desc, 0, KS_1, 0x000000 );
	}	
}



