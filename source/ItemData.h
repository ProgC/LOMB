// ItemData.h: interface for the ItemData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEMDATA_H__620D9CC9_3EE3_4297_801B_2A7C09E381FD__INCLUDED_)
#define AFX_ITEMDATA_H__620D9CC9_3EE3_4297_801B_2A7C09E381FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using namespace std;

typedef struct tagItem {
	int  nID;		// 아이템 번호
	char Name[128]; // 아이템 이름
	char Desc[128]; // 아이템 설명
	char ImageName[128]; // 아이템 이미지
} s_Item;

class CItemData {
public:
	CItemData();
	virtual ~CItemData();

	static CItemData* Instance();  

	bool LoadDB( const char* filename );

	const s_Item* GetItem( int index ) {
		return vecItem[index];
	}
public:
	vector<s_Item*> vecItem;
};

#endif // !defined(AFX_ITEMDATA_H__620D9CC9_3EE3_4297_801B_2A7C09E381FD__INCLUDED_)
