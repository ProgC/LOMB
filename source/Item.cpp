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
			case 0: // ��
				Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/gold1.wav"],0);
			break;
			case 47: // ������ ��
				Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/flippot.wav"],0);								
			break;

			case 48: // ������ ��
				Mix_PlayChannel(2,g_SoundPack.vecSoundMap["sound/flippot.wav"],0);				
			break;
		}
	}

		// ���Ϳ��� ��
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
	// ������ ���� �÷��̾�� �ǵ���� �ش�.
	switch ( nItemType ) {
		case IT_MONEY:
			g_Game.pKail->GetMoney( 100 );
		break;
	}
	return 0;
}
