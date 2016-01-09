#include "Miner.h"


//------------------------------ Constructor ----------------------------------
//-----------------------------------------------------------------------------
Miner::Miner(int id)
// Must have the same order than in declaration or silent the warning: -Wno-reorder
  :BaseGameEntity(id), _m_Location(home),  _m_iGoldCarried(0),
   _m_iMoneyInBank(0), _m_iThirst(0), _m_iFatigue(0), _m_iPeeLevel(0)
{
  // Setup the state machine.
  _m_pStateMachine = new StateMachine<Miner>(this);
  _m_pStateMachine->SetCurrentState(GoHomeAndSleepUntilRested::Instance());
  _m_pStateMachine->SetGlobalState(GoPeeUntilFeelingGood::Instance());
}


//-----------------------------------------------------------------------------
void Miner::AddToGoldCarried(const int val)
{
  _m_iGoldCarried += val;

  if (_m_iGoldCarried < 0) _m_iGoldCarried = 0;
}


//-----------------------------------------------------------------------------
void Miner::AddToWealth(const int val)
{
  _m_iMoneyInBank += val;

  if (_m_iMoneyInBank < 0) _m_iMoneyInBank = 0;
}


//-----------------------------------------------------------------------------
bool Miner::Thirsty() const
{
  if (_m_iThirst >= ThirstLevel)
  {
    return true;
  }

  return false;
}


//-----------------------------------------------------------------------------
void Miner::Update()
{
  // Miner thirstier as each iteration (everybody need a bier, isn’t it ?)
  ++_m_iThirst;
  ++_m_iPeeLevel;

  // Let state machine update the state
  _m_pStateMachine->Update();
}


//-----------------------------------------------------------------------------
bool Miner::Fatigued() const
{
  if (_m_iFatigue > TirednessThreshold)
  {
      return true;
  }

  return false;
}


//-----------------------------------------------------------------------------
bool Miner::NeedToPee() const
{
  if (_m_iPeeLevel >= PeeThreshold)
  {
    return true;
  }

  return false;
}
