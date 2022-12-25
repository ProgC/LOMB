#ifndef STATE_H
#define STATE_H
//------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//  Use   : ProgC (2006.12.25)
//
//------------------------------------------------------------------------

class CMonsterAI;

class KState {
public:
  virtual ~KState(){}

  //this will execute when the state is entered
  virtual void Enter(CMonsterAI*)=0;

  //this is the state's normal update function
  virtual void Execute(CMonsterAI*)=0;

  //this will execute when the state is exited. (My word, isn't
  //life full of surprises... ;o))
  virtual void Exit(CMonsterAI*)=0;
};

#endif