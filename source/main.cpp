#include "Global.h"
#include "IScene.h"
#include "Game.h"
#include "GameUI.h"

// �� ����
// �� ���� ����
// �� ���ϸ��̼� Ŭ����
// �ɸ��� ����
// �ɸ��� �̵�
// �ɸ��� �浹
// �ɸ��� vs �� �浹
// �� �̵�
// ������ ó��

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
    

	// �ѱ� ��Ʈ�� ����
	if ( !Read_Han_Font( "HAN.FNT" ) ) {
		MessageBox( NULL , "�ѱ� ��Ʈ ������ �������� �ʽ��ϴ�." , "Error" , MB_OK );
		return false;
	}
	
	// ���� ��Ʈ�� �о� ������
	if ( !Read_Eng_Font( "ENG.FNT" ) ) {
		MessageBox( NULL , "���� ��Ʈ ������ �������� �ʽ��ϴ�." , "Warning" , MB_OK );
		return false;
	}
	
	// ������ ��Ʈ ������ ����
	if ( !Load_Info( "HAN.INF" ) ) {
		MessageBox( NULL , "HAN.INF ������ �������� �ʾƿ�" , "Warning" , MB_OK );
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
		g_Game.Init(); // ó������ ������ ���� 1���� ����		
		
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
