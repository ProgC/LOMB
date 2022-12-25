// Game.h: interface for the CGame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAME_H__1D62F0B3_D5DA_44A9_AED8_BDC9AEA7A5BE__INCLUDED_)
#define AFX_GAME_H__1D62F0B3_D5DA_44A9_AED8_BDC9AEA7A5BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IEntity.h"
#include "MoveableEntity.h"
#include "Kail.h"
#include "Script.h"
#include "SceneEffect.h"
#include "2D/vector2d.h"

// game은 IScene을 상속받아서 상위 SceneMgr에 의해서 관리된다.

class CBullet;

class CGame {
public:
	static enum GAME_STATE {
		GAME,
		SCRIPT,
		INVENTORY,
		GAMEOVER,
		CREDIT,
	};
	
public:
	CGame();
	virtual ~CGame();
	
	void Init();
	void ReleaseData();
	void ClearObject();

public:
	void GameUpdate();
	void GameRender();

	void UpdateGame();
	void RenderGame();
	void UpdateScript();
	void RenderScript();

	void SetCredit();
	void UpdateGameCredit();
	void RenderGameCredit();
		
	void InputUp();
	void InputDown();
	void InputLeft();
	void InputRight();
	
	void InputA();
	void InputB();
	
	void CollisionPlayerWithObj( CMoveableEntity *pEvil );
	void CollisionPlayerAttackWithObj( CMoveableEntity *pEvil );
	void CollisionBulletWithObj( CMoveableEntity *pEvil, CBullet* pBullet );
	
	CStage* GetCurrentStage() {
		return &Stage;
	}

	inline int GetStage() const {
		return nStage;
	}

	// 아이템을 좌표에 떨군다.
	void AddItem( int nType, int nX, int nY );
	// 몬스터를 추가한다.
	void AddMonster( int nMobID, int nX, int nY );
	// npc를 추가한다.
	void AddNpc( int nNpcID, int nX, int nY );

	void AddBullet( int BulletType, int nX, int nY  );
	void AddBullet( int BulletType, int nX, int nY, float nDx, float nDy );
	void AddBullet( int BulletType, int nX, int nY, float nDx, float nDy , CHARACTER_DIR dir);
	
	CMoveableEntity* GetNearThisPointInEvil( Vector2D& Pos );

	// 스크립트 관련 메소드
	CScript objScript;
	void ProcessScript( char* filename );
	
	void FadeIn();
	void FadeOut();
	void FadeOutGray();
	void FadeInWhite();
	void FadeOutWhite();

	bool IsDestoryedMob( int mobID, int stageX, int stageY );

	const IEntity* GetPlayer() {
		return pKail;
	}

	void SetBossStage() {
		bBossStage = true;
	}
	void UnSetBossStage() {
		bBossStage = false;
	}
	inline bool GetBossStage() const {
		return bBossStage;
	}

	void LoadMap( const char* filename );

	void KailDead();

	void ViewInventory();
public:
	GAME_STATE GameState;
	GAME_STATE PrevState;
	CSceneEffect Effect;
	
	bool bGame;
	CStage Stage; // 스테이지는 5개로 만든다.
	int nStage;
	bool bBossStage;

	Kail* pKail;
	vector<CMoveableEntity*> vecObjList;
	vector<CMoveableEntity*> vecBulletList;
	vector<CMoveableEntity*> vecReserveAddEntity;
	
	float fCreditY;
	CAnimationFrame GameCredit;
};

#endif // !defined(AFX_GAME_H__1D62F0B3_D5DA_44A9_AED8_BDC9AEA7A5BE__INCLUDED_)
