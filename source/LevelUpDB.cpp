// LevelUpDB.cpp: implementation of the LevelUpDB class.
//
//////////////////////////////////////////////////////////////////////

#include "LevelUpDB.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LevelUpDB::LevelUpDB() {
	for ( int i = 0; i < 60; i++ ) {
		Data[i].Exp = ((i+1)*10);
	}

	Data[0].MaxHP = 1;
	Data[1].MaxHP = 10;
	Data[2].MaxHP = 13;
	Data[2].MaxHP = 16;
	
	Data[0].MaxMP = 10;
	Data[1].MaxMP = 10;
	Data[2].MaxMP = 15;
	Data[2].MaxMP = 20;
}

LevelUpDB::~LevelUpDB()
{

}
