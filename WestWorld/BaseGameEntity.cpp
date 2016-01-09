// Corresponding header.
#include "BaseGameEntity.h"
// Assertion headers.
#include <cassert>

// Initialize unique next id (class variable scope)
int BaseGameEntity::_m_iNextValidID = 0;


//----------------------------- _SetID -----------------------------------------
//
//  This must be called within each constructor to make sure the ID is set
//  correctly. It verifies that the value passed to the method is greater
//  or equal to the next valid ID, before setting the ID and incrementing
//  the next valid ID
//-----------------------------------------------------------------------------
void BaseGameEntity::_SetID(int val)
{
  // Make sure the val is equal to or greater than the next available ID
  assert ( (val >= _m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID");

  _m_ID = val;

  _m_iNextValidID = _m_ID + 1;
}
