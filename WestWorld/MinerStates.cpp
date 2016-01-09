#include "MinerStates.h"
#include "State.h"
#include "Miner.h"
#include "Locations.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;
using std::endl;


// // Define this to output to a file
// #ifdef TEXTOUTPUT
// #include <fstream>
// extern std::ofstream os;  // Need to search the meaning of this.
// #define cout os
// #endif



//--------------------------------------methods for EnterMineAndDigForNugget
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
// Constructor which always return the same instance --> Singleton
{
  static EnterMineAndDigForNugget instance;

  return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* p_Miner)
{
  // If the miner is not already located at the goldmine, he must
  // change location to the gold mine
  if (p_Miner->Location() != goldmine)
  {
    // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << GetNameOfEntity(p_Miner->ID()) << ": " << "Walkin' to the goldmine" << endl;

    p_Miner->ChangeLocation(goldmine);
  }
}


void EnterMineAndDigForNugget::Execute(Miner* p_Miner)
{
  // The miner digs for gold until he is carrying in excess of MaxNuggets.
  // If he gets thirsty during his digging he packs up work for a while and
  // changes state to go to the saloon for a whiskey.
  p_Miner->AddToGoldCarried(1);

  p_Miner->IncreaseFatigue();

  // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << GetNameOfEntity(p_Miner->ID()) << ": " << "Pickin' up a nugget" << endl;

  // If enough gold mined, go and put it in the bank
  if (p_Miner->PocketsFull())
  {
    p_Miner->ChangeState(VisitBankAndDepositGold::Instance());
  }

  if (p_Miner->Thirsty())
  {
    p_Miner->ChangeState(GoSaloonAndDrink::Instance());
  }
}


void EnterMineAndDigForNugget::Exit(Miner* p_Miner)
{
  // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << GetNameOfEntity(p_Miner->ID()) << ": "
       << "Ah'm leavin' the goldmine with mah pockets full o' sweet gold" << endl;
}



//--------------------------------------methods for VisitBankAndDepositGold
VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
// Constructor which always return the same instance --> Singleton
{
  static VisitBankAndDepositGold instance;

  return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* p_Miner)
{
  // On entry the miner makes sure he is located at the bank
  if (p_Miner->Location() != bank)
  {
    // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << GetNameOfEntity(p_Miner->ID()) << ": " << "Goin' to the bank. Yes siree" << endl;

    p_Miner->ChangeLocation(bank);
  }
}


void VisitBankAndDepositGold::Execute(Miner* p_Miner)
{

  // Deposit the gold
  p_Miner->AddToWealth(p_Miner->GoldCarried());

  p_Miner->SetGoldCarried(0);

  // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << GetNameOfEntity(p_Miner->ID()) << ": "
       << "Depositing gold. Total savings now: "<< p_Miner->Wealth() << endl;

  // Wealthy enough to have a well earned rest?
  if (p_Miner->Wealth() >= ComfortLevel)
  {
    // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << GetNameOfEntity(p_Miner->ID()) << ": "
         << "WooHoo! Rich enough for now. Back home to mah li'lle lady" << endl;

    p_Miner->ChangeState(GoHomeAndSleepUntilRested::Instance());
  }

  // Otherwise get more gold
  else
  {
    p_Miner->ChangeState(EnterMineAndDigForNugget::Instance());
  }
}


void VisitBankAndDepositGold::Exit(Miner* p_Miner)
{
  // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << GetNameOfEntity(p_Miner->ID()) << ": " << "Leavin' the bank" << endl;
}



//--------------------------------------methods for GoHomeAndSleepUntilRested
GoHomeAndSleepUntilRested* GoHomeAndSleepUntilRested::Instance()
// Constructor which always return the same instance --> Singleton
{
  static GoHomeAndSleepUntilRested instance;

  return &instance;
}

void GoHomeAndSleepUntilRested::Enter(Miner* p_Miner)
{
  if (p_Miner->Location() != home)
  {
    // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << GetNameOfEntity(p_Miner->ID()) << ": " << "Walkin' home" << endl;

    p_Miner->ChangeLocation(home);
  }
}


void GoHomeAndSleepUntilRested::Execute(Miner* p_Miner)
{
  // If miner is not fatigued start to dig for nuggets again.
  if (!p_Miner->Fatigued())  // Pay attention to `!`.
  {
    // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << GetNameOfEntity(p_Miner->ID()) << ": "
          << "What a God darn fantastic nap! Time to find more gold" << endl;

     p_Miner->ChangeState(EnterMineAndDigForNugget::Instance());
  }

  else
  {
    // Sleep
    p_Miner->DecreaseFatigue();

    // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << GetNameOfEntity(p_Miner->ID()) << ": " << "ZZZZ... " << endl;
  }
}

void GoHomeAndSleepUntilRested::Exit(Miner* pMiner)
{
  // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the house" << endl;
}


//--------------------------------------methods for GoSaloonAndDrink
GoSaloonAndDrink* GoSaloonAndDrink::Instance()
// Constructor which always return the same instance --> Singleton
{
  static GoSaloonAndDrink instance;

  return &instance;
}


void GoSaloonAndDrink::Enter(Miner* p_Miner)
{
  if (p_Miner->Location() != saloon)
  {
    p_Miner->ChangeLocation(saloon);

    // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << GetNameOfEntity(p_Miner->ID()) << ": " << "Boy, ah sure is thusty! Walking to the saloon" << endl;
  }
}

void GoSaloonAndDrink::Execute(Miner* p_Miner)
{
   if (p_Miner->Thirsty())
   {
     p_Miner->BuyAndDrinkAWhiskey();

     // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
     cout << GetNameOfEntity(p_Miner->ID()) << ": " << "That's mighty fine sippin liquer" << endl;

     p_Miner->ChangeState(EnterMineAndDigForNugget::Instance());
  }

  else
  {
    // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "ERROR!\nERROR!\nERROR!" << endl;
  }
}

void GoSaloonAndDrink::Exit(Miner* p_Miner)
{
  // SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << GetNameOfEntity(p_Miner->ID()) << ": " << "Leaving the saloon, feelin' good" << endl;
}
