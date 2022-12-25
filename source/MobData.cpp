// MobData.cpp: implementation of the CMobData class.
//
//////////////////////////////////////////////////////////////////////

#include "MobData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMobData::CMobData() {

}

CMobData::~CMobData() {

}

bool CMobData::LoadDB( const char* filename ) {
	FILE *fp = NULL;
	fp = fopen(filename,"rt");

	if ( !fp ) return false;
	
	char szBuffer[1024];
	char* token;
	char seps[]   = "\t";

	while(1) {
		if ( fgets(szBuffer, 1024, fp ) == NULL ) break;

		s_MobData* mob = new s_MobData;
		token = strtok( szBuffer, seps );
		mob->nID = atoi( token );

		token = strtok( NULL, seps );
		strcpy( mob->Name, token );

		token = strtok( NULL, seps );
		strcpy( mob->Desc, token );

		token = strtok( NULL, seps );
		mob->Energy = atoi( token );

		for ( int i = 0; i < 3; i++ ) {
			token = strtok( NULL, seps );
			mob->DropItem[i] = atoi( token );
		}

		vecMobData.push_back( mob );
	}

	if ( fp ) fclose( fp );
	return true;
}


