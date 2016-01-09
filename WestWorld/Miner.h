#ifndef MINER_H
#define MINER_H

//------------------------------------------------------------------------
//
//  Name:   Miner.h
//
//  Desc:   A class defining a goldminer.
//
//  Private: All value or method which begin by `_` are private.
//
//  Origin: `Programming game AI by example` book with syntax changes.
//
//------------------------------------------------------------------------

#include <string>
// Used in corresponding cpp file.
#include <cassert>

#include "BaseGameEntity.h"
#include "Locations.h"

class State;

// The amount of gold a miner must have before he feels comfortable
const int ComfortLevel       = 5;
// The amount of nuggets a miner can carry
const int MaxNuggets         = 3;
// Above this value a miner is thirsty
const int ThirstLevel        = 5;
// Above this value a miner is sleepy
const int TirednessThreshold = 5;



class Miner : public BaseGameEntity
{
public:
  // Constructor.
  Miner(int id);

  // This must be implemented
  void Update ();

  // This method changes the current state to the new state. It first
  // calls the Exit() method of the current state, then assigns the
  // new state to _m_pCurrentState and finally calls the Entry()
  // method of the new state.
  void ChangeState (State* new_state);

  location_type Location () const {return _m_Location;}
  void          ChangeLocation (const location_type loc){_m_Location=loc;}

  int           GoldCarried () const {return _m_iGoldCarried;}
  bool          PocketsFull () const {return _m_iGoldCarried >= MaxNuggets;}
  void          SetGoldCarried (const int val){_m_iGoldCarried = val;}
  void          AddToGoldCarried (const int val);  // Initialization in cpp file

  void          DecreaseFatigue (){_m_iFatigue -= 1;}
  void          IncreaseFatigue (){_m_iFatigue += 1;}
  bool          Fatigued () const ;  // Initialization in cpp file

  int           Wealth () const {return _m_iMoneyInBank;}
  void          SetWealth (const int val){_m_iMoneyInBank = val;}
  void          AddToWealth (const int val);  // Initialization in cpp file

  void          BuyAndDrinkAWhiskey (){_m_iThirst = 0; _m_iMoneyInBank-=2;}
  bool          Thirsty () const ;  // Initialization in cpp file

private:
  location_type _m_Location;

  // How many nuggets the miner has in his pockets
  int _m_iGoldCarried;

  // How many nuggets the miner has in his bank
  int _m_iMoneyInBank;

  // The higher the value, the thirstier the miner
  int _m_iThirst;

  // The higher the value, the more tired the miner
  int _m_iFatigue;

  // Pointer to a singleton state
  State* _m_pCurrentState;

};

#endif
