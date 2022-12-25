// TileProperty.h: interface for the CTileProperty class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TILEPROPERTY_H__44372CAA_5094_464A_A45D_4DC1E64F3050__INCLUDED_)
#define AFX_TILEPROPERTY_H__44372CAA_5094_464A_A45D_4DC1E64F3050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "sdl.h"

// 타일 속성
enum TILE {
	NOMOVE,
	MOVE
};

class CTileProperty {
public:
	CTileProperty();
	virtual ~CTileProperty();
	
public:
	int ImageNumber; // 타일 번호
	int nCollision;  // 0은 갈 수 없음, 1은 갈 수 있음
	SDL_Surface* surface; // 실제의 이미지 포인터
	TILE Moveable; // 
	int nEventProperty; // 이벤트 번호
};

#endif // !defined(AFX_TILEPROPERTY_H__44372CAA_5094_464A_A45D_4DC1E64F3050__INCLUDED_)
