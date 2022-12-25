// MusicPack.h: interface for the CMusicPack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MUSICPACK_H__9F1BEC61_F20F_4CB7_A471_1C110CAF28CA__INCLUDED_)
#define AFX_MUSICPACK_H__9F1BEC61_F20F_4CB7_A471_1C110CAF28CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning ( disable : 4786 ) 

#include "Sdl.h"
#include "SDL_mixer.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

class CMusicPack {
public:
	CMusicPack();
	virtual ~CMusicPack();

	bool LoadMusic();
	bool LoadMusic( char* filename );
	
public:
	map< string, Mix_Music* > vecMusicMap;

};

#endif // !defined(AFX_MUSICPACK_H__9F1BEC61_F20F_4CB7_A471_1C110CAF28CA__INCLUDED_)
