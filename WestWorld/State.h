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
template <class entity_type>
class State
{
public:
    virtual ~State(){}

// All pure virtual --> Must be implemented by children
    // This will execute when the state is entered
    virtual void Enter(entity_type*)=0;

    // This is the state's normal update function
    virtual void Execute(entity_type*)=0;

    // This will execute when the state is exited.
    virtual void Exit(entity_type*)=0;

};

#endif
