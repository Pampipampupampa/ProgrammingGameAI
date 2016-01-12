#ifndef MINER_STATES_H
#define MINER_STATES_H

//------------------------------------------------------------------------
//
//  Name:   MinerStates.h
//
//  Desc:   All the states that can be assigned to the Miner class
//
//  Private: All value or method which begin by `_` are private.
//
//  Origin: `Programming game AI by example` book with syntax changes.
//
//  Implementation: All miner state are implemented as Singleton.
//
//------------------------------------------------------------------------

#include "State.h"


class Miner;


//------------------------------------------------------------------------
//
//  Miner global state.
//------------------------------------------------------------------------
class MinerGlobalState : public State<Miner>
{
public:
  // This is a singleton.
  static MinerGlobalState* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

private:
  // Constructor must be private.
  MinerGlobalState(){};

  // Copy ctor and assignment should be private too.
  MinerGlobalState(const MinerGlobalState&);
  MinerGlobalState& operator=(const MinerGlobalState&);

};



//------------------------------------------------------------------------
//
//  In this state the miner will walk to a goldmine and pick up a nugget
//  of gold. If the miner already has a nugget of gold he'll change state
//  to VisitBankAndDepositGold. If he gets thirsty he'll change state
//  to QuenchThirst
//------------------------------------------------------------------------
class EnterMineAndDigForNugget : public State<Miner>
{
public:
  // This is a singleton.
  static EnterMineAndDigForNugget* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

private:
  // Constructor must be private.
  EnterMineAndDigForNugget(){};

  // Copy ctor and assignment should be private too.
  EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
  EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);
};


//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the
//  miner is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class VisitBankAndDepositGold : public State<Miner>
{
public:
  // This is a singleton.
  static VisitBankAndDepositGold* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

private:
  // Constructor must be private.
  VisitBankAndDepositGold(){};

  // Copy ctor and assignment should be private too.
  VisitBankAndDepositGold(const VisitBankAndDepositGold&);
  VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);

};


//------------------------------------------------------------------------
//
//  Miner will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class GoHomeAndSleepUntilRested : public State<Miner>
{
public:
  // This is a singleton.
  static GoHomeAndSleepUntilRested* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

private:
  // Constructor must be private.
  GoHomeAndSleepUntilRested(){};

  // Copy ctor and assignment should be private too.
  GoHomeAndSleepUntilRested(const GoHomeAndSleepUntilRested&);
  GoHomeAndSleepUntilRested& operator=(const GoHomeAndSleepUntilRested&);

};


//------------------------------------------------------------------------
//
//  Miner thirsty and go to the bar to drink something.
//------------------------------------------------------------------------
class GoSaloonAndDrink : public State<Miner>
{
public:
  // This is a singleton.
  static GoSaloonAndDrink* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

private:
  // Constructor must be private.
  GoSaloonAndDrink(){};

  // Copy ctor and assignment should be private too.
  GoSaloonAndDrink(const GoSaloonAndDrink&);
  GoSaloonAndDrink& operator=(const GoSaloonAndDrink&);

};


//------------------------------------------------------------------------
//
//  Miner have to pee. Nature call is powerful ...
//------------------------------------------------------------------------
class GoPeeUntilFeelingGood : public State<Miner>
{
public:
  // This is a singleton.
  static GoPeeUntilFeelingGood* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

private:
  // Constructor must be private.
  GoPeeUntilFeelingGood(){};

  // Copy ctor and assignment should be private too.
  GoPeeUntilFeelingGood(const GoPeeUntilFeelingGood&);
  GoPeeUntilFeelingGood& operator=(const GoPeeUntilFeelingGood&);

};

#endif
