// Inventory.cpp: implementation of the CInventory class.
//
//////////////////////////////////////////////////////////////////////


#include "Inventory.h"
#include "global.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInventory::CInventory()
{

}

CInventory::~CInventory()
{

}

void CInventory::Init() {
	CurrentBox[0] = 0; // AŰ Z
	CurrentBox[1] = 0; // BŰ X
	
	for ( int y = 0; y < 5; y++ ) {
		for ( int x = 0; x < 2; x++ ) {
			InvenBox[y][x] = 0;
		}
	}
}

bool CInventory::AddItem( int id ) {
	s_InventoryItem Item;
	Item.id = id;
	Item.value = 0;
	Item.howmany = 1;

	const s_Item* pItem = g_ItemDB.GetItem( id );
	char path[256];

	sprintf( path, "item/%s", pItem->ImageName );
	
	Item.ItemFrame.SetLoop( true );
	Item.ItemFrame.AddFrame( path, 1 );
	Item.ItemFrame.nMaxFrame = 1;
	Item.ItemFrame.nCurFrame = 0;
	
	vecItem.push_back( Item );
	return true;
}