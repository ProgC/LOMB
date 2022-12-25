// Stage.h: interface for the CStage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STAGE_H__0DF5ADEB_325E_4D11_BF0D_77C9F3998668__INCLUDED_)
#define AFX_STAGE_H__0DF5ADEB_325E_4D11_BF0D_77C9F3998668__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "sdl.h"
#include "map.h"

class IEntity;

class CStage {
public:
	CStage();
	virtual ~CStage();
	
	void Load(const char* filename);
	void Update();
	void Render();
	
	void Collision( IEntity* pChar );
	bool IsBlock( IEntity* pChar );
	bool IsOutOfScreen( IEntity* pChar );
	bool IsScrollArea( IEntity* pChar );
	
	bool ScrollUp();
	bool ScrollLeft();
	bool ScrollRight();
	bool ScrollDown();

	int GetStartX() const {
		return nStartX;
	}
	int GetStartY() const {
		return nStartY;
	}
	int GetEndX() const {
		return nEndX;
	}
	int GetEndY() const {
		return nEndY;
	}
public:
	// 스테이지는 5,5로 구현된다.
	CMap m_Stage[5][5];
	int nXIndex;
	int nYIndex;

	int nStartX;
	int nStartY;
	int nEndX;
	int nEndY;
};

#endif // !defined(AFX_STAGE_H__0DF5ADEB_325E_4D11_BF0D_77C9F3998668__INCLUDED_)
