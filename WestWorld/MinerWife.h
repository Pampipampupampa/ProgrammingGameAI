#ifndef MinerWife_H
#define MinerWife_H

//------------------------------------------------------------------------
//
//  Name:   MinerWife.h
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
#include "StateMachine.h"


class MinerWife: public BaseGameEntity
{
public:
	// Constructor
	MinerWife(int id);
	// Clean allocated memory in the destructor
	~MinerWife(){delete _m_pStateMachine;};
   // This must be implemented.
	void Update ();

	// Accessors.
	StateMachine<MinerWife>* GetSM() const {return _m_pStateMachine;};
	location_type            Location() const {return _m_Location;};

	// Setters.
	void                     ChangeLocation (const location_type loc){_m_Location=loc;}

private:
	// Current location
	location_type _m_Location;
	// Associated state machine
	StateMachine<MinerWife>* _m_pStateMachine;
};

#endif
