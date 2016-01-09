#include "Miner.h"
#include "MinerStates.h"


//-------------------- Constructor initialization list ------------------------
//-----------------------------------------------------------------------------
Miner::Miner(int id)
// Must have the same order than in declaration or silent the warning: -Wno-reorder
  :BaseGameEntity(id), _m_Location(home),  _m_iGoldCarried(0),
   _m_iMoneyInBank(0), _m_iThirst(0), _m_iFatigue(0),
   _m_pCurrentState(GoHomeAndSleepUntilRested::Instance())
{}


//--------------------------- ChangeState -------------------------------------
//-----------------------------------------------------------------------------
void Miner::ChangeState(State* pNewState)
{
  // Make sure both states are both valid before attempting to
  // call their methods
  assert (_m_pCurrentState && pNewState);

  // Call the exit method of the existing state
  _m_pCurrentState->Exit(this);

  // Change state to the new state
  _m_pCurrentState = pNewState;

  // Call the entry method of the new state
  _m_pCurrentState->Enter(this);
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
  if (_m_iThirst >= ThirstLevel){return true;}

  return false;
}


//-----------------------------------------------------------------------------
void Miner::Update()
{
  // Miner thirstier as each iteration (everybody need a bier, isn’t it ?)
  _m_iThirst += 1;

  if (_m_pCurrentState)
  {
    // Pass class element to State child class.
    _m_pCurrentState->Execute(this);
  }
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
