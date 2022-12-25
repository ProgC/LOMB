// Item.cpp: implementation of the Item class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Item.h"
#include "ItemData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Item::Item() {

}

Item::~Item() {

}

void Item::Init() {
	EntityType = IEntity::ITEM;

	nEnergy = 10;
	nRad = 5;

	const s_Item* pItem = g_ItemDB.GetItem( nItemType );
	char path[256];

	sprintf( path, "item/%s", pItem->ImageName );
	
	ItemFrame.SetLoop( true );
	ItemFrame.AddFrame( path, 1 );
	ItemFrame.nMaxFrame = 1;
	ItemFrame.nCurFrame = 0;

	oY = 10;

	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );

	if ( pItem ) {
		switch ( pItem->nID ) {
			case 0: // 돈
				Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/gold1.wav"],0);
			break;
			case 47: // 생명의 약
				Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/flippot.wav"],0);								
			break;

			case 48: // 마나의 약
				Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/flippot.wav"],0);				
			break;
		}
	}

		// 벡터에서 삭
}

void Item::Update() {
	scx = GetScreenX( g_Game.Stage.nXIndex );
	scy = GetScreenY( g_Game.Stage.nYIndex );
	
	oY -= (oY * 0.5);
	if ( oY < 0.5f ) oY = 0;
}

void Item::Render(int nXIndex, int nYIndex) {
	ItemFrame.DrawAni( scx , scy - oY);
}

bool Item::MoveNorth() {

	return false;
}

bool Item::MoveSouth() {

	return false;
}

bool Item::MoveEast() {

	return false;
}

bool Item::MoveWest() {

	return false;
}

bool Item::MoveBack() {

	return false;
}

void Item::Attack() {

}

void Item::Hit() {
	if ( g_Game.pKail->GetState() == Kail::STAND ) {
		nEnergy = 0;
		g_Game.pKail->Inventory.AddItem( nItemType );
	}
}

int Item::Dead() {
	// 종류에 따라서 플레이어에게 피드백을 준다.
	switch ( nItemType ) {
		case IT_MONEY:
			g_Game.pKail->GetMoney( 100 );
		break;
	}
	return 0;
}
