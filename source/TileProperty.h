// TileProperty.h: interface for the CTileProperty class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TILEPROPERTY_H__44372CAA_5094_464A_A45D_4DC1E64F3050__INCLUDED_)
#define AFX_TILEPROPERTY_H__44372CAA_5094_464A_A45D_4DC1E64F3050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "sdl.h"

// Ÿ�� �Ӽ�
enum TILE {
	NOMOVE,
	MOVE
};

class CTileProperty {
public:
	CTileProperty();
	virtual ~CTileProperty();
	
public:
	int ImageNumber; // Ÿ�� ��ȣ
	int nCollision;  // 0�� �� �� ����, 1�� �� �� ����
	SDL_Surface* surface; // ������ �̹��� ������
	TILE Moveable; // 
	int nEventProperty; // �̺�Ʈ ��ȣ
};

#endif // !defined(AFX_TILEPROPERTY_H__44372CAA_5094_464A_A45D_4DC1E64F3050__INCLUDED_)
