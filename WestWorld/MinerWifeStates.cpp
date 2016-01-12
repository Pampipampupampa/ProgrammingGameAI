#include "MinerWifeStates.h"
#include "State.h"
#include "MinerWife.h"
#include "Locations.h"
#include "EntityNames.h"
#include "Helpers/utilities.h"

#include <iostream>
// Avoid namespace pollution
using std::cout;
using std::endl;

// // Use to change console output
// #define RESET_COLOR "\e[m"
// #define MAKE_GREEN "\e[32m"


//-----------------------------------------------------------------------Global state
MinerWifeGlobalState* MinerWifeGlobalState::Instance()
{
  static MinerWifeGlobalState instance;

  return &instance;
}


void MinerWifeGlobalState::Execute(MinerWife* wife)
{
  // Return a number between 0.0 and 1.0
  if (RandFloat() < 0.2)
  {
    wife->GetSM()->ChangeState(VisitBathroom::Instance());
  }
}


//------------------------------------------------------------------DoHouseWork state
DoHouseWork* DoHouseWork::Instance()
{
  static DoHouseWork instance;

  return &instance;
}

void DoHouseWork::Enter(MinerWife* wife)
{
}

void DoHouseWork::Execute(MinerWife* wife)
{
	// Miner wife makes randomly a task.
	// Change color.
	cout << "\033[35;1m";

	switch(RandInt(0,2))
	{
	case 0:
	  cout << GetNameOfEntity(wife->ID()) << ": Moppin' the floor" << endl;
	  break;

	case 1:
	  cout << GetNameOfEntity(wife->ID()) << ": Washin' the dishes" << endl;
	  break;

	case 2:
	  cout << GetNameOfEntity(wife->ID()) << ": Makin' the bed" << endl;
	  break;
	}
}

void DoHouseWork::Exit(MinerWife* wife)
{
}

//------------------------------------------------------------------VisitBathroom state
VisitBathroom* VisitBathroom::Instance()
{
  static VisitBathroom instance;

  return &instance;
}

void VisitBathroom::Enter(MinerWife* wife)
{
	// Change color.
	cout << "\033[35;1m";

  cout << GetNameOfEntity(wife->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose" << endl;
}

void VisitBathroom::Execute(MinerWife* wife)
{
	// Change color.
	cout << "\033[35;1m";

	// Go to pee and return to current state.
  cout << GetNameOfEntity(wife->ID()) << ": Ahhhhhh! Sweet relief!" << endl;
  wife->GetSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinerWife* wife)
{
	// Change color.
	cout << "\033[35;1m";

	cout << GetNameOfEntity(wife->ID()) << ": Leavin' the Jon" << endl;
}
