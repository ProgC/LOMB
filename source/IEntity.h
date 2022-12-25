// IEntity.h: interface for the IEntity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IENTITY_H__6ECAF403_E74F_4BC7_8F2E_E5BF510D9C7E__INCLUDED_)
#define AFX_IENTITY_H__6ECAF403_E74F_4BC7_8F2E_E5BF510D9C7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>

enum CHARACTER_DIR {
	NORTH, EAST, SOUTH, WEST
};

class IEntity {
public:
	static enum ENTITY_TYPE {
		NONE,
		PLAYER,
		NPC,
		MONSTER,
		ITEM,
		BULLET,
	};
public:
	IEntity();
	virtual ~IEntity();

public:
	static bool CompareObj( IEntity* first, IEntity* second ) {
		return first->nWorldY < second->nWorldY;
	}
		
	virtual void Update() = 0;
	virtual void Render(int nXIndex, int nYIndex) = 0;	
	virtual void Hit() = 0;
	virtual int  Dead() = 0;
	
	ENTITY_TYPE GetEntityType() const {
		return EntityType;
	}

	void SetWorldX( float x ) {
		nWorldX = x;
	}
	void SetWorldY( float y ) {
		nWorldY = y;
	}
	// ȭ�� ��ǥ
	float GetScreenX(int MapXIndex) const {
		scx = (int)(nWorldX - (MapXIndex*160));
		return (float)scx;
	}
	float GetScreenY(int MapYIndex) const {
		scy = (int)(nWorldY - (MapYIndex*160));
		return (float)scy;
	}
	float GetWorldX() const {
		return nWorldX;
	}
	float GetWorldY() const {
		return nWorldY;
	}
	int GetWorldXIndex() const {
		return (int)(nWorldX / 160);
	}
	int GetWorldYIndex() const {
		return (int)(nWorldY / 160);
	}
	CHARACTER_DIR GetDir() {
		return nDir;
	}
	int GetEnergy() {
		return nEnergy;
	}	

	int GetRadForCollision() const {
		return nRad;
	}	

	// ���ӳ����� ������ ���� �� �ִ� ��� �ڷ�
public:
	ENTITY_TYPE EntityType;

	float nWorldX;
	float nWorldY;
	
	// ȭ�� �󿡼� ��ǥ
	mutable int scx;
	mutable int scy;
	
	// Entity�� ����
	CHARACTER_DIR nDir;
	
	int nEnergy;
	int nRad; // �浹 ������
};

#endif // !defined(AFX_IENTITY_H__6ECAF403_E74F_4BC7_8F2E_E5BF510D9C7E__INCLUDED_)
