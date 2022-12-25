// SpritePack.h: interface for the CSpritePack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRITEPACK_H__373DB881_91FC_42E8_BE84_808B9448EB2B__INCLUDED_)
#define AFX_SPRITEPACK_H__373DB881_91FC_42E8_BE84_808B9448EB2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning ( disable : 4786 ) 

#include "SDL.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

#include "Sprite.h"

class CSpritePack {
public:
	CSpritePack();
	virtual ~CSpritePack();
	
	bool LoadImage();
	bool LoadImage( char* filename, int ox = 0, int oy = 0 );
	
public:
	map< string, CSprite* > vecImageMap;
	//vector<SDL_Surface*> vecImage;
};

#endif // !defined(AFX_SPRITEPACK_H__373DB881_91FC_42E8_BE84_808B9448EB2B__INCLUDED_)
