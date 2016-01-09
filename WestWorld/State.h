#ifndef STATE_H
#define STATE_H

//------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Private: All value or method which begin by `_` are private.
//
//  Origin: `Programming game AI by example` book with syntax changes.
//
//------------------------------------------------------------------------

// Template allows to make this class reusable
// template <class entity_type>

class Miner;

class State
{
public:
    virtual ~State(){}

// All pure virtual --> Must be implemented by children
    // This will execute when the state is entered
    virtual void Enter(Miner*)=0;

    // This is the state's normal update function
    virtual void Execute(Miner*)=0;

    // This will execute when the state is exited.
    virtual void Exit(Miner*)=0;

};

#endif
