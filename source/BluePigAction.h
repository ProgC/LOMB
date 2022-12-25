// BluePigAction.h: interface for the CBluePigAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLUEPIGACTION_H__788F7F66_2AFC_4D81_B2F8_4D28DA2EC0A7__INCLUDED_)
#define AFX_BLUEPIGACTION_H__788F7F66_2AFC_4D81_B2F8_4D28DA2EC0A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "KState.h"
class CMonsterAI;


class CBluePigAction_Stand : public KState {
public:
	CBluePigAction_Stand() { }
	//virtual ~CPinkPigAction_Stand();
	
public:
	  //this is a singleton
	  static CBluePigAction_Stand* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

class CBluePigAction_Battle : public KState {
public:
	CBluePigAction_Battle() { }
	//virtual ~CPinkPigAction_Stand();
	
public:
	  //this is a singleton
	  static CBluePigAction_Battle* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

class CBluePigAction_Wait : public KState {
public:
	CBluePigAction_Wait() { }
	//virtual ~CPinkPigAction_Stand();
	
public:
	  //this is a singleton
	  static CBluePigAction_Wait* Instance();  
	  void Enter(CMonsterAI* pObj);
	  void Execute(CMonsterAI* pObj);
	  void Exit(CMonsterAI* pObj);
};

#endif // !defined(AFX_BLUEPIGACTION_H__788F7F66_2AFC_4D81_B2F8_4D28DA2EC0A7__INCLUDED_)
