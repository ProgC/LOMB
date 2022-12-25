// BossAmberAction.h: interface for the CBossAmberAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOSSAMBERACTION_H__83AB3F21_6043_445C_879D_67438003354D__INCLUDED_)
#define AFX_BOSSAMBERACTION_H__83AB3F21_6043_445C_879D_67438003354D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "KState.h"

class CMonsterAI;

class CBossAmber_Stand : public KState {
public:
	CBossAmber_Stand() { }
public:
	  //this is a singleton
	  static CBossAmber_Stand* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

class CBossAmber_MoveTypeNormal : public KState {
public:
	CBossAmber_MoveTypeNormal() { }
public:
	  //this is a singleton
	  static CBossAmber_MoveTypeNormal* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

class CBossAmber_MoveTypeX : public KState {
public:
	CBossAmber_MoveTypeX() { }
public:
	  //this is a singleton
	  static CBossAmber_MoveTypeX* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

class CBossAmber_MoveTypeBullet : public KState {
public:
	CBossAmber_MoveTypeBullet() { }
public:
	  //this is a singleton
	  static CBossAmber_MoveTypeBullet* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

#endif // !defined(AFX_BOSSAMBERACTION_H__83AB3F21_6043_445C_879D_67438003354D__INCLUDED_)
