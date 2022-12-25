// ItemData.cpp: implementation of the ItemData class.
//
//////////////////////////////////////////////////////////////////////

//#include <afx.h>
//#include <afxwin.h>
#include <string.h>
#include "ItemData.h"
//#include "CSpreadSheet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CItemData::CItemData() {
		
}

CItemData::~CItemData() {

}

CItemData* CItemData::Instance() {
	static CItemData Data;
	return &Data;
}

bool CItemData::LoadDB( const char* filename ) {
	FILE *fp = NULL;
	fp = fopen(filename,"rt");

	if ( !fp ) return false;
	
	char szBuffer[1024];
	char* token;
	char seps[]   = "\t";

	while(1) {
		if ( fgets(szBuffer, 1024, fp ) == NULL ) break;

		s_Item* item = new s_Item;
		token = strtok( szBuffer, seps );
		item->nID = atoi( token );

		token = strtok( NULL, seps );
		strcpy( item->Name, token );

		token = strtok( NULL, seps );
		strcpy( item->Desc, token );

		token = strtok( NULL, seps );
		strcpy( item->ImageName, token );
		
		vecItem.push_back( item );
	}

	if ( fp ) fclose( fp );
	return true;
}
