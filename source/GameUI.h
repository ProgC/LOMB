// GameUI.h: interface for the GameUI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEUI_H__F3CE949E_95E1_41DD_8BA7_ED3ACF24DB5A__INCLUDED_)
#define AFX_GAMEUI_H__F3CE949E_95E1_41DD_8BA7_ED3ACF24DB5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AnimationFrame.h"

class GameUI {
public:
	static enum UI_STATE {
		GAME,
		CHARACTER,
		INVENTORY
	};
public:
	GameUI();
	virtual ~GameUI();
	
	void Init();
	void Update();
	void InputLeft();
	void InputRight();
	void InputUp();
	void InputDown();
	void InputA();
	void InputB();


	void Render();
	void RenderInventory();
public:
	UI_STATE nState;
	CAnimationFrame UI_Game;
	

	CAnimationFrame UI_Information;

	CAnimationFrame UI_Game_Energy;
	CAnimationFrame UI_Game_Mana;
	CAnimationFrame UI_Game_SelectedSkill;

	CAnimationFrame UI_ChatWindow;


	CAnimationFrame UI_Inventory;
	CAnimationFrame UI_Inventory_Focus;

	int nFocusX;
	int nFocusY;
};

#endif // !defined(AFX_GAMEUI_H__F3CE949E_95E1_41DD_8BA7_ED3ACF24DB5A__INCLUDED_)
