#ifndef MINERWIFE_STATES_H
#define MINERWIFE_STATES_H

//------------------------------------------------------------------------
//
//  Name:   MinerWifeStates.h
//
//  Desc:   All the states that can be assigned to the `MinerWife` class
//
//  Private: All value or method which begin by `_` are private.
//
//  Origin: `Programming game AI by example` book with syntax changes.
//
//  Implementation: All wife wife state are implemented as Singleton.
//
//------------------------------------------------------------------------

#include "State.h"


class MinerWife;



//------------------------------------------------------------------------
//
//  Wife global state. Can happen at any time
//------------------------------------------------------------------------
class MinerWifeGlobalState : public State<MinerWife>
{
public:
  // This is a singleton.
  static MinerWifeGlobalState* Instance();

  // Global state do not have a enter/exit method.
  virtual void Enter(MinerWife* wife) {}

  virtual void Execute(MinerWife* wife);

  virtual void Exit(MinerWife* wife) {}

private:
  // Constructor must be private.
  MinerWifeGlobalState(){};

  // Copy ctor and assignment should be private too.
  MinerWifeGlobalState(const MinerWifeGlobalState&);
  MinerWifeGlobalState& operator=(const MinerWifeGlobalState&);
};


//------------------------------------------------------------------------
//
//  In this state the wife stay at home and do housework
//------------------------------------------------------------------------
class DoHouseWork : public State<MinerWife>
{
public:
  // This is a singleton.
  static DoHouseWork* Instance();

  virtual void Enter(MinerWife* wife);

  virtual void Execute(MinerWife* wife);

  virtual void Exit(MinerWife* wife);

private:
  // Constructor must be private.
  DoHouseWork(){};

  // Copy ctor and assignment should be private too.
  DoHouseWork(const DoHouseWork&);
  DoHouseWork& operator=(const DoHouseWork&);
};


//------------------------------------------------------------------------
//
//  In this state the wife visit the bathroom to pee
//------------------------------------------------------------------------
class VisitBathroom : public State<MinerWife>
{
public:
  // This is a singleton.
  static VisitBathroom* Instance();

  virtual void Enter(MinerWife* wife);

  virtual void Execute(MinerWife* wife);

  virtual void Exit(MinerWife* wife);

private:
  // Constructor must be private.
  VisitBathroom(){};

  // Copy ctor and assignment should be private too.
  VisitBathroom(const VisitBathroom&);
  VisitBathroom& operator=(const VisitBathroom&);
};
#endif
