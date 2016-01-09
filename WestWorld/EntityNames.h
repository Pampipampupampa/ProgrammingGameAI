#ifndef NAMES_H
#define NAMES_H

#include <string>


// Create an enumerator for each entity type
enum
{
  ent_Miner_Bob,
  ent_Elsa
};

// Inline allows declaring function in a .h file
// Make the identifier in file scope (much like declaring as static)
inline std::string GetNameOfEntity(int n)
{
    switch(n)
    {
        case ent_Miner_Bob: return "Miner Bob";

        case ent_Elsa: return "Elsa";

        default: return "UNKNOWN!";
    }
}


#endif
