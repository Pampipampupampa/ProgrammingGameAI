#include "MinerStates.h"
#include "State.h"
#include "Miner.h"
#include "Locations.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;
using std::endl;


//--------------------------------------methods for MinerGlobalState
MinerGlobalState* MinerGlobalState::Instance()
// Constructor which always return the same instance --> Singleton
{
  static MinerGlobalState instance;

  return &instance;
}


void MinerGlobalState::Enter(Miner* p_miner){}

void MinerGlobalState::Execute(Miner* p_miner)
{
  if (p_miner->NeedToPee() && p_miner->Location() == saloon)
  {
    p_miner->GetSM()->ChangeState(GoPeeUntilFeelingGood::Instance());
  }
}

void MinerGlobalState::Exit(Miner* p_miner){}


//--------------------------------------methods for EnterMineAndDigForNugget
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
// Constructor which always return the same instance --> Singleton
{
  static EnterMineAndDigForNugget instance;

  return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  // If the miner is not already located at the goldmine, he must
  // change location to the gold mine
  if (p_miner->Location() != goldmine)
  {
    cout << GetNameOfEntity(p_miner->ID()) << ": " << "Walkin' to the goldmine" << endl;

    p_miner->ChangeLocation(goldmine);
  }
}


void EnterMineAndDigForNugget::Execute(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  // The miner digs for gold until he is carrying in excess of MaxNuggets.
  // If he gets thirsty during his digging he packs up work for a while and
  // changes state to go to the saloon for a whiskey.
  p_miner->AddToGoldCarried(1);

  p_miner->IncreaseFatigue();

  cout << GetNameOfEntity(p_miner->ID()) << ": " << "Pickin' up a nugget" << endl;

  // If enough gold mined, go and put it in the bank
  if (p_miner->PocketsFull())
  {
    p_miner->GetSM()->ChangeState(VisitBankAndDepositGold::Instance());
  }

  if (p_miner->Thirsty())
  {
    p_miner->GetSM()->ChangeState(GoSaloonAndDrink::Instance());
  }
}


void EnterMineAndDigForNugget::Exit(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";
  cout << GetNameOfEntity(p_miner->ID()) << ": "
       << "Ah'm leavin' the goldmine with mah pockets full o' sweet gold" << endl;
}



//--------------------------------------methods for VisitBankAndDepositGold
VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
// Constructor which always return the same instance --> Singleton
{
  static VisitBankAndDepositGold instance;

  return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  // On entry the miner makes sure he is located at the bank
  if (p_miner->Location() != bank)
  {
    cout << GetNameOfEntity(p_miner->ID()) << ": " << "Goin' to the bank. Yes siree" << endl;

    p_miner->ChangeLocation(bank);
  }
}


void VisitBankAndDepositGold::Execute(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  // Deposit the gold
  p_miner->AddToWealth(p_miner->GoldCarried());

  p_miner->SetGoldCarried(0);

  cout << GetNameOfEntity(p_miner->ID()) << ": "
       << "Depositing gold. Total savings now: "<< p_miner->Wealth() << endl;

  // Wealthy enough to have a well earned rest?
  if (p_miner->Wealth() >= ComfortLevel)
  {
    cout << GetNameOfEntity(p_miner->ID()) << ": "
         << "WooHoo! Rich enough for now. Back home to mah li'lle lady" << endl;

    p_miner->GetSM()->ChangeState(GoHomeAndSleepUntilRested::Instance());
  }

  // Otherwise get more gold
  else
  {
    p_miner->GetSM()->ChangeState(EnterMineAndDigForNugget::Instance());
  }
}


void VisitBankAndDepositGold::Exit(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";
  cout << GetNameOfEntity(p_miner->ID()) << ": " << "Leavin' the bank" << endl;
}



//--------------------------------------methods for GoHomeAndSleepUntilRested
GoHomeAndSleepUntilRested* GoHomeAndSleepUntilRested::Instance()
// Constructor which always return the same instance --> Singleton
{
  static GoHomeAndSleepUntilRested instance;

  return &instance;
}

void GoHomeAndSleepUntilRested::Enter(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  if (p_miner->Location() != home)
  {
    cout << GetNameOfEntity(p_miner->ID()) << ": " << "Walkin' home" << endl;

    p_miner->ChangeLocation(home);
  }
}


void GoHomeAndSleepUntilRested::Execute(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  // If miner is not fatigued start to dig for nuggets again.
  if (!p_miner->Fatigued())  // Pay attention to `!`.
  {
    cout << GetNameOfEntity(p_miner->ID()) << ": "
          << "What a God darn fantastic nap! Time to find more gold" << endl;

     p_miner->GetSM()->ChangeState(EnterMineAndDigForNugget::Instance());
  }

  else
  {
    // Sleep
    p_miner->DecreaseFatigue();

    cout << GetNameOfEntity(p_miner->ID()) << ": " << "ZZZZ... " << endl;
  }
}

void GoHomeAndSleepUntilRested::Exit(Miner* pMiner)
{
  // Change color.
  cout << "\033[32m";
  cout << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the house" << endl;
}


//--------------------------------------methods for GoSaloonAndDrink
GoSaloonAndDrink* GoSaloonAndDrink::Instance()
// Constructor which always return the same instance --> Singleton
{
  static GoSaloonAndDrink instance;

  return &instance;
}


void GoSaloonAndDrink::Enter(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  if (p_miner->Location() != saloon)
  {
    p_miner->ChangeLocation(saloon);

    cout << GetNameOfEntity(p_miner->ID()) << ": " << "Boy, ah sure is thusty! Walking to the saloon" << endl;
  }
}

void GoSaloonAndDrink::Execute(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  if (p_miner->Thirsty())
  {
    p_miner->BuyAndDrinkAWhiskey();

    cout << GetNameOfEntity(p_miner->ID()) << ": " << "That's mighty fine sippin liquer" << endl;

    p_miner->GetSM()->ChangeState(EnterMineAndDigForNugget::Instance());
  }

  else
  {
    cout << "ERROR!\nERROR!\nERROR!" << endl;
  }
}

void GoSaloonAndDrink::Exit(Miner* p_miner)
{
  cout << GetNameOfEntity(p_miner->ID()) << ": " << "Leaving the saloon, feelin' good" << endl;
}


//--------------------------------------methods for GoPeeUntilFeelingGood
GoPeeUntilFeelingGood* GoPeeUntilFeelingGood::Instance()
// Constructor which always return the same instance --> Singleton
{
  static GoPeeUntilFeelingGood instance;

  return &instance;
}


void GoPeeUntilFeelingGood::Enter(Miner* p_miner)
{
  // Change color.
  cout << "\033[32m";

  cout << GetNameOfEntity(p_miner->ID()) << ": Walkin' to the Jon ..." << endl;
}

void GoPeeUntilFeelingGood::Execute(Miner* p_miner)
{
  // Reset pee level and go back to previous state.
  p_miner->SetPeeLevel(0);
  p_miner->GetSM()->RevertToPreviousState();
}

void GoPeeUntilFeelingGood::Exit(Miner* p_miner){}
