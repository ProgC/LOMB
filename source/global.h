#ifndef __GLOBAL_HEADER__
#define __GLOBAL_HEADER__

#include "SDL.h"
//#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <windows.h>
#include "SpritePack.h"
#include "SoundPack.h"
#include "MusicPack.h"
#include "TileProperty.h"
#include "Map.h"
#include "Stage.h"
#include "Game.h"
#include "GameUI.h"
#include "ItemData.h"
#include "MobData.h"
#include "LevelUPDB.h"
#include "Han.h" // 한글 폰트 출력 관련

#include <vector>
using namespace std;


const int SCREEN_WIDTH = 160;
const int SCREEN_HEIGHT = 176;//240;
const int SCREEN_BPP = 32;//32;

extern SDL_Surface *screen;
extern CSpritePack g_SpritePack;
extern CSoundPack  g_SoundPack;
extern CMusicPack  g_MusicPack;
extern CGame	   g_Game;
extern GameUI	   g_GameUI;
extern CItemData   g_ItemDB;
extern CMobData    g_MobDB;
extern LevelUpDB   g_LevelDB;

extern bool OldKey_InputZ;
extern bool NewKey_InputZ;
extern bool OldKey_InputX;
extern bool NewKey_InputX;

#endif
