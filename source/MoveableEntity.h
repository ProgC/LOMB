// MoveableEntity.h: interface for the CMoveableEntity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVEABLEENTITY_H__447BA9DB_B720_4D49_8BFE_928F2F864FE8__INCLUDED_)
#define AFX_MOVEABLEENTITY_H__447BA9DB_B720_4D49_8BFE_928F2F864FE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IEntity.h"

class CMoveableEntity : public IEntity {
public:
	CMoveableEntity();
	virtual ~CMoveableEntity();

public:
	virtual bool MoveNorth() = 0;
	virtual bool MoveSouth() = 0;
	virtual bool MoveEast() = 0;
	virtual bool MoveWest() = 0;
	virtual bool MoveBack() = 0;
};

#endif // !defined(AFX_MOVEABLEENTITY_H__447BA9DB_B720_4D49_8BFE_928F2F864FE8__INCLUDED_)
