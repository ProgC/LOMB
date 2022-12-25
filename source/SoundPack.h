// SoundPack.h: interface for the CSoundPack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOUNDPACK_H__5F091F94_F612_4F72_B638_FBE242070E58__INCLUDED_)
#define AFX_SOUNDPACK_H__5F091F94_F612_4F72_B638_FBE242070E58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "SDL_ttf.h"
#pragma warning ( disable : 4786 ) 

#include "Sdl.h"
#include "SDL_mixer.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

class CSoundPack {
public:
	CSoundPack();
	virtual ~CSoundPack();

	bool LoadSound();
	bool LoadSound( char* filename );
	
public:
	map< string, Mix_Chunk* > vecSoundMap;
};

#endif // !defined(AFX_SOUNDPACK_H__5F091F94_F612_4F72_B638_FBE242070E58__INCLUDED_)
