#include "MinerWife.h"
#include "MinerWifeStates.h"


//------------------------------ Constructor ----------------------------------
//-----------------------------------------------------------------------------
MinerWife::MinerWife(int id)
// Must have the same order than in declaration or silent the warning: -Wno-reorder
  :BaseGameEntity(id),
   _m_Location(home)
{
  // Setup the state machine.
  _m_pStateMachine = new StateMachine<MinerWife>(this);

  _m_pStateMachine->SetCurrentState(DoHouseWork::Instance());

  _m_pStateMachine->SetGlobalState(MinerWifeGlobalState::Instance());
}


//------------------------------------------------------------------------------
void MinerWife::Update()
{
	_m_pStateMachine->Update();
}
