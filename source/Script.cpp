// Script.cpp: implementation of the CScript class.
//
//////////////////////////////////////////////////////////////////////

#include "global.h"
#include "Script.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CScript::CScript() {

}

CScript::~CScript() {
	Release();
}

void CScript::Release() {
	bBitmapImage = false;
	mapVariable.clear();
}

void CScript::Init() {
	fp = NULL;
}

bool CScript::LoadVariable( char* filename ) {
	mapVariable.clear();
	
	FILE* fpLocal = NULL;

	fpLocal = fopen(filename, "rt" );

	if ( fpLocal == NULL ) return false;

	bool bLoop = true;
	char LocalBuffer[128];
	int nValue = 0;
	while(bLoop) {
		if ( fscanf( fpLocal, "%s %d\n" , LocalBuffer, &nValue ) == -1 ) {
			bLoop = false;
			continue;
		}
		
		// insert to map
		pair<string,int> em( LocalBuffer, nValue );
		mapVariable.insert( em );
	}
	
	if ( fpLocal ) fclose( fpLocal );
	return true;
}

bool CScript::LoadScript( char* filename ) {
	if ( fp != NULL ) {
		// 이미 열려 있는 것이 있다면
		if ( fp ) fclose( fp );
	}

	g_Game.GameState = CGame::SCRIPT;
	fp = fopen( filename, "rt" );
	if ( fp == NULL ) return false;
	
	CurrentState = CONTINUE;
	return true;
}

SCRIPT_STATE CScript::Step() {
	char Cmd[30];
	
	fgets( Buffer, 1024, fp );
	
	if ( feof(fp) ) {
		CurrentState = SCRIPT_END;
		return SCRIPT_END;
	}
	
	sscanf( Buffer, "%s", Cmd );

	CurrentCommand = SC_EMPTY;

	if ( strcmp( "calc" , Cmd ) == 0 ) {
	//	printf( "%s\n" , Buffer );
		CurrentState = CONTINUE;
		return CONTINUE;
	} else if ( strcmp( "gamecredit", Cmd) == 0 ) {		
		CurrentState = WAIT_END;
		g_Game.SetCredit();
		return WAIT_END;
	} else if ( strcmp( "func" , Cmd ) == 0 ) {
		// read func
		ReadFunc();
		CurrentState = CONTINUE;
		return CONTINUE;
	} else if ( strcmp( "//" , Cmd ) == 0 ) {
		CurrentState = CONTINUE;
		return CONTINUE;
	} else if ( strcmp( "map", Cmd ) == 0 ) {
		int len = strlen(Buffer);
		char* token = Buffer+strlen("map \"");
		Buffer[len-2] = '\0';

		char szMapName[128];
		sprintf( szMapName, "map/%s.dat", token );
		g_Game.LoadMap( szMapName );
		return CONTINUE;
	} else if ( strcmp( "fadein", Cmd ) == 0 ) {
		g_Game.FadeIn();
		CurrentState = WAIT_END;
		return WAIT_END;
	} else if ( strcmp( "fadeout", Cmd ) == 0 ) {
		g_Game.FadeOut();
		CurrentState = WAIT_END;
		return WAIT_END;
	} else if ( strcmp( "fadeoutgray", Cmd ) == 0 ) {
		g_Game.FadeOutGray();
		CurrentState = WAIT_END;
		return WAIT_END;
	} else if ( strcmp( "fadeinwhite", Cmd ) == 0 ) {
		g_Game.FadeInWhite();
		CurrentState = WAIT_END;
		return WAIT_END;
	} else if ( strcmp( "fadeoutwhite", Cmd ) == 0 ) {
		g_Game.FadeOutWhite();
		CurrentState = WAIT_END;
		return WAIT_END;


	} else if ( strcmp( "exitgame", Cmd ) == 0 ) {
		// 게임 종료
		g_Game.bGame = false;
		CurrentState = WAIT_END;		
		return WAIT_END;
	} else if ( strcmp( "showon", Cmd ) == 0 ) {
		// 비트맵 이미지를 보여준다.
		int len = strlen(Buffer);
		char* token = Buffer+strlen("showon \"");
		Buffer[len-2] = '\0';
		
		BitmapImage.Release();
		char szImageName[128];
		sprintf( szImageName, "img/%s.bmp", token );
		BitmapImage.AddFrame( szImageName, 1 );
		BitmapImage.nMaxFrame = 1;
		BitmapImage.nCurFrame = 0;

		CurrentCommand = SC_SHOW;
		CurrentState = CONTINUE;
		bBitmapImage = true;
		return CONTINUE;
	} else if ( strcmp( "showoff" , Cmd ) == 0 ) {
		// 비트맵을 꺼버린다.
		CurrentCommand = SC_EMPTY;
		bBitmapImage = false;
		CurrentState = CONTINUE;
		return CONTINUE;
	} else if ( strcmp( "musicon", Cmd ) == 0 ) {
		int len = strlen(Buffer);
		char* token = Buffer+strlen("musicon \"");
		Buffer[len-2] = '\0';
		
		char szMusicName[256];
		sprintf( szMusicName, "music/%s.mid", token );
		
		Mix_PlayMusic( g_MusicPack.vecMusicMap[szMusicName] , -1 );
		CurrentCommand = SC_EMPTY;
		CurrentState = CONTINUE;
		return CONTINUE;
	} else if ( strcmp( "musicoff", Cmd ) == 0 ) {
		// 음악을 끈다.
		Mix_HaltMusic();
		CurrentCommand = SC_EMPTY;
		CurrentState = CONTINUE;
		return CONTINUE;
	} else if ( strcmp( "print" , Cmd ) == 0 ) {
		int len = strlen(Buffer);
		char* token = Buffer+strlen("print \"");
		Buffer[len-2] = '\0';
		
		strcpy(TextBuffer, token );

		CurrentState = WAIT_KEYBOARD;
		CurrentCommand = SC_PRINT;
		return WAIT_KEYBOARD;
	} else if ( strcmp( "Narration", Cmd ) == 0 ) {
		int len = strlen(Buffer);
		char* token = Buffer+strlen("Narration \"");
		Buffer[len-2] = '\0';
		
		strcpy(TextBuffer, token );

		nCurNarrationLen = 0;
		nMaxNarrationLen = strlen( TextBuffer );

		CurrentState = WAIT_KEYBOARD;
		CurrentCommand = SC_NARRATION;
		return WAIT_KEYBOARD;
	} else if ( strcmp( "if" , Cmd ) == 0 ) {
		// if flag op value
		char flagName[128];
		char op[10];
		int nValue = 0;
		sscanf( Buffer, "%s %s %s %d\n" , Cmd, flagName, op, &nValue );

		if ( strcmp( op, ">" ) == 0 ) {
			if ( mapVariable[flagName] > nValue ) {
				// 그대로 실행한다.
			} else {
				// else를 찾는다.
				NextElse();
			}
		} else if ( strcmp( op, "<" ) == 0 ) {
			if ( mapVariable[flagName] < nValue ) {
				// 그대로 실행한다.
			} else {
				// else를 찾는다.
				NextElse();
			}
		} else if ( strcmp( op, ">=" ) == 0 ) {
			if ( mapVariable[flagName] >= nValue ) {
				// 그대로 실행한다.
			} else {
				// else를 찾는다.
				NextElse();
			}
		} else if ( strcmp( op, "<=" ) == 0 ) {
			if ( mapVariable[flagName] <= nValue ) {
				// 그대로 실행한다.
			} else {
				// else를 찾는다.
				NextElse();
			}
		} else if ( strcmp( op, "<>" ) == 0 ) {
			if ( mapVariable[flagName] != nValue ) {
				// 그대로 실행한다.
			} else {
				// else를 찾는다.
				NextElse();
			}
		} else if ( strcmp( op, "==" ) == 0 ) {
			int a = mapVariable[flagName];
			if ( mapVariable[flagName] == nValue ) {
				// 그대로 실행한다.
			} else {
				// else를 찾는다.
				NextElse();
			}
		}	
		CurrentState = CONTINUE;
		return CONTINUE;
	} else if ( strcmp( "goto" , Cmd ) == 0 ) {
		// goto label
		int a = 0;
		char AtPoint[128];
		
		sscanf( Buffer, "%s %s\n" , Cmd, AtPoint );
		GotoLabel( AtPoint );		
	} 
	
	CurrentState = CONTINUE;
	return CONTINUE;
}

void CScript::NextElse() {
	char Cmd[30];
	
	while(1) {
		fgets( Buffer, 1024, fp );
		
		if ( feof(fp) ) {
			CurrentState = SCRIPT_END;
			return;
		}
		
		sscanf( Buffer, "%s", Cmd );

		if ( strcmp( Cmd, "else" ) == 0 ) {
			return;
		}
	}
}

void CScript::GotoLabel( char* label ) {
	rewind(fp);
		
	char Cmd[30];
	
	while(1) {
		fgets( Buffer, 1024, fp );
		
		if ( feof(fp) ) {
			CurrentState = SCRIPT_END;
			return;
		}
		
		sscanf( Buffer, "%s", Cmd );

		if ( strcmp( Cmd, "label" ) == 0 ) {
			char l_label[128];
			sscanf( Buffer, "%s %s\n", Cmd, l_label );
			if ( strcmp( l_label, label ) == 0 ) {
				return;
			}
		}
	}
}

void CScript::ReadFunc() {
	char Cmd[128];
	char FuncName[128];
	char Variable[128];
	int mobID;
	int StageX;
	int StageY;	
	int value;
	
	sscanf( Buffer, "%s %s", Cmd, FuncName );

	if ( strcmp( FuncName, "checkmob" ) == 0 ) { // 해당 스테이지에 해당 몹이 있는지 없는지 검사
		sscanf( Buffer, "%s %s %d %d %d %s\n" , Cmd, FuncName, &mobID, &StageX, &StageY, Variable );
		if ( g_Game.IsDestoryedMob( mobID, StageX, StageY ) == 1 ) {
			mapVariable[Variable] = 1;
		} else {
			mapVariable[Variable] = 0;
		}
	} else if ( strcmp( FuncName, "setvariable" ) == 0 ) {		
		sscanf( Buffer, "%s %s %s %d\n" , Cmd, FuncName, Variable, &value );
		mapVariable[Variable] = value;
	}
}