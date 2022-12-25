// Sprite.h: interface for the CSprite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRITE_H__AE3B4883_A707_44C2_ABE7_D0E24D094058__INCLUDED_)
#define AFX_SPRITE_H__AE3B4883_A707_44C2_ABE7_D0E24D094058__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning ( disable : 4786 ) 

#include "sdl.h"
#include <vector>
#include <string>
using namespace std;

class CSprite {
public:
	CSprite();
	virtual ~CSprite();
	
public:
	// 중심값
	int oX;
	int oY;
	
	// 이미지
	SDL_Surface* surface;
};

#endif // !defined(AFX_SPRITE_H__AE3B4883_A707_44C2_ABE7_D0E24D094058__INCLUDED_)
