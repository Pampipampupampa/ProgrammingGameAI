#ifndef STATEMACHINE_H
#define STATEMACHINE_H

//------------------------------------------------------------------------
//
//  Name:   StateMAchine.h
//
//  Desc:   A class defining a state machine.
//
//  Private: All value or method which begin by `_` are private.
//
//  Origin: `Programming game AI by example` book with syntax changes.
//
//------------------------------------------------------------------------

#include <cassert>
#include <typeinfo>

#include "State.h"


template <class entity_type>
class StateMachine
{
// PUBLIC ELEMENTS
public:
	// Constructor.
	StateMachine(entity_type* p_owner): _m_pOwner(p_owner),
		 								_m_pCurrentState(NULL),
		 								_m_pPreviousState(NULL),
		 								_m_pGlobalState(NULL)
	{}
	// Destructor.
	virtual ~StateMachine(){}

	// Setters.
	void SetCurrentState(State<entity_type>* p_state){_m_pCurrentState = p_state;}
	void SetPreviousState(State<entity_type>* p_state){_m_pPreviousState = p_state;}
	void SetGlobalState(State<entity_type>* p_state){_m_pGlobalState = p_state;}

	// Accessors.
	State<entity_type>* CurrentState() const{return _m_pCurrentState;}
	State<entity_type>* GlobalState() const{return _m_pGlobalState;}
	State<entity_type>* PreviousState() const{return _m_pPreviousState;}

	// Update method.
	void Update () const
	{
		// If current state exist.
		if (_m_pCurrentState) _m_pCurrentState->Execute(_m_pOwner);
		// If global state exist.
		if (_m_pGlobalState) _m_pGlobalState->Execute(_m_pOwner);
	}

	// Change state to another
	void ChangeState (State<entity_type>* p_newState)
	{
		// Check if p_newState exist
		assert(p_newState && "<StateMachine::ChangeState>: trying to change to a null state");
		// Update state pointer and call in the right order `Exit` and `Enter` method.
		_m_pCurrentState->Exit(_m_pOwner);
		_m_pPreviousState = _m_pCurrentState;
		_m_pCurrentState = p_newState;
		_m_pCurrentState->Enter(_m_pOwner);
	}

	// Return to previous state.
	void RevertToPreviousState ()
	{
		ChangeState(_m_pPreviousState);
	}

	// Returns true if the current state's type is equal to the type of the
	// class passed as a parameter.
	bool  isInState(const State<entity_type>& ref_state)const
	{
	  return typeid(*_m_pCurrentState) == typeid(ref_state);
	}

// PRIVATE ELEMENTS
private:
	// A pointer to owner of this state machine.
	entity_type* _m_pOwner;

	// Pointer to states.
	State<entity_type>* _m_pCurrentState;
	State<entity_type>* _m_pPreviousState;
	State<entity_type>* _m_pGlobalState;
};


#endif
