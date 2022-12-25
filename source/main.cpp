#include "Global.h"
#include "IScene.h"
#include "Game.h"
#include "GameUI.h"

// 맵 띄우기
// 맵 끼리 연결
// 맵 에니메이션 클래스
// 케릭터 띄우기
// 케릭터 이동
// 케릭터 충돌
// 케릭터 vs 몹 충돌
// 몹 이동
// 아이템 처리

SDL_Surface *screen = NULL;
CSpritePack g_SpritePack;
CSoundPack  g_SoundPack;
CMusicPack  g_MusicPack;
CGame	    g_Game;
GameUI		g_GameUI;
CItemData	g_ItemDB;
CMobData    g_MobDB;
LevelUpDB   g_LevelDB;

bool InitGraphics() {
	SDL_ShowCursor(0);
//SDL_Rect **modes;
//modes=SDL_ListModes(NULL, SDL_HWSURFACE|SDL_FULLSCREEN);SDL_FULLSCREEN
//SCREEN_BPP
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 24, SDL_SWSURFACE /*| SDL_FULLSCREEN*/ );
    if( screen == NULL ) {
        return false;   
    }
    
    SDL_WM_SetCaption( "LOMB", NULL );
	return true;
}

void GameUpdate() {
	g_Game.GameUpdate();
}

void GameRender() {
	g_Game.GameRender();
	
	if( SDL_Flip( screen ) == -1 ) {
        return;
    }
}

int main( int argc, char* args[] ) {
    SDL_Init( SDL_INIT_EVERYTHING );
    

	// 한글 폰트를 읽자
	if ( !Read_Han_Font( "HAN.FNT" ) ) {
		MessageBox( NULL , "한글 폰트 파일이 존재하지 않습니다." , "Error" , MB_OK );
		return false;
	}
	
	// 영문 폰트를 읽어 들이자
	if ( !Read_Eng_Font( "ENG.FNT" ) ) {
		MessageBox( NULL , "영문 폰트 파일이 존재하지 않습니다." , "Warning" , MB_OK );
		return false;
	}
	
	// 조합형 폰트 구조를 읽자
	if ( !Load_Info( "HAN.INF" ) ) {
		MessageBox( NULL , "HAN.INF 파일이 존재하지 않아요" , "Warning" , MB_OK );
		return false;
	}

	g_ItemDB.LoadDB( "item/itemdb.txt" );
	g_MobDB.LoadDB( "evil/mob.txt" );

	if ( InitGraphics() ) {
		Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);
		
		g_SpritePack.LoadImage();
		g_SoundPack.LoadSound();
		g_MusicPack.LoadMusic();
		g_GameUI.Init();
		
		g_Game.UnSetBossStage();
		g_Game.Init(); // 처음에는 무조건 레벨 1부터 시작		
		
		while (1) {
			Sleep(30);
			GameUpdate();
			GameRender();
			
			if ( !g_Game.bGame ) break;

			// Poll for events, and handle the ones we care about.
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_KEYDOWN:
					
					break;
				case SDL_KEYUP:
					if (event.key.keysym.sym == SDLK_ESCAPE)
						return 0;
					break;
				case SDL_QUIT:
					return(0);
				}
			}
		}
	}
	
    SDL_Quit();    
	SDL_ShowCursor(1);
    return 0;    
}
