#ifndef ENTITY_H
#define ENTITY_H

//------------------------------------------------------------------------
//
//  Name:   BaseGameEntity.h
//
//  Desc:   Base class for a game object.
//          All game entities must have this class as Parent.
//          Assign a unique ID to each new instance (superclass or subclass)
//          Destructor not implemented
//          Update method as pure virtual --> Must be implemented by children
//
//  Private: All value or method which begin by `_` are private.
//
//  Origin: `Programming game AI by example` book with syntax changes.
//
//------------------------------------------------------------------------


class BaseGameEntity
{
public:
    // Constructor
    BaseGameEntity(int id)
    {
        _SetID(id);
    }

    // Destructor
    virtual ~BaseGameEntity(){}

    // All entities must implement an update function
    virtual void  Update()=0;

    int ID()const
    {
        return _m_ID;
    }

private:
    // Every entity must have a unique identifying number
    int _m_ID;

    // This is the next valid ID. Each time a BaseGameEntity is instantiated
    // This value is updated
    static int _m_iNextValidID;

    // This must be called within the constructor to make sure the ID is set
    // correctly. It verifies that the value passed to the method is greater
    // or equal to the next valid ID, before setting the ID and incrementing
    // the next valid ID
    void _SetID(int val);

};

#endif


