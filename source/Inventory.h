// Inventory.h: interface for the CInventory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INVENTORY_H__35031AA7_17F1_48E6_AE06_903B4A009CEE__INCLUDED_)
#define AFX_INVENTORY_H__35031AA7_17F1_48E6_AE06_903B4A009CEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AnimationFrame.h"
#include <vector>
using namespace std;

typedef struct InventoryItem {
	int id;
	int value;
	int howmany;
	CAnimationFrame ItemFrame;
} s_InventoryItem;

class CInventory {
public:
	CInventory();
	virtual ~CInventory();

	bool AddItem( int id );
public:
	void Init();
	
	int CurrentBox[2];
	int InvenBox[5][2];
	
	vector<s_InventoryItem> vecItem;
};

#endif // !defined(AFX_INVENTORY_H__35031AA7_17F1_48E6_AE06_903B4A009CEE__INCLUDED_)
