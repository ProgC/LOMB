// PinkPigAction.h: interface for the CPinkPigAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINKPIGACTION_H__68EC6B37_9471_4BC5_9F3E_71B79C64BF1B__INCLUDED_)
#define AFX_PINKPIGACTION_H__68EC6B37_9471_4BC5_9F3E_71B79C64BF1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KState.h"
class CMonsterAI;

class CPinkPigAction_Stand : public KState {
public:
	CPinkPigAction_Stand() { }
	//virtual ~CPinkPigAction_Stand();
	
public:
	  //this is a singleton
	  static CPinkPigAction_Stand* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

class CPinkPigAction_Battle : public KState {
public:
	CPinkPigAction_Battle() { }
	//virtual ~CPinkPigAction_Stand();
	
public:
	  //this is a singleton
	  static CPinkPigAction_Battle* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

class CPinkPigAction_BattleMissile : public KState {
public:
	CPinkPigAction_BattleMissile() { }
	//virtual ~CPinkPigAction_Stand();
	
public:
	  //this is a singleton
	  static CPinkPigAction_BattleMissile* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

#endif // !defined(AFX_PINKPIGACTION_H__68EC6B37_9471_4BC5_9F3E_71B79C64BF1B__INCLUDED_)
