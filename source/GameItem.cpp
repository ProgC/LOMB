#include "global.h"
#include "game.h"
#include "Item.h"
#include "Itemdata.h"

// ¾ÆÀÌÅÛÀ» ÁÂÇ¥¿¡ ¶³±º´Ù.
void CGame::AddItem( int nType, int nX, int nY ) {	
	Item* pItem = new Item();
	pItem->SetItemType( nType );
	pItem->SetWorldX( nX );
	pItem->SetWorldY( nY );
	pItem->Init();
	
	vecReserveAddEntity.push_back( pItem );
}
