#include "EntityNames.h"
#include "Locations.h"
#include "Miner.h"
#include "MinerWife.h"

// To enable sleep function in UNIX system.
#include <unistd.h>

#include <iostream>
// Using only need to avoid namespace pollution
using std::cout;
using std::endl;


//------------------------------------------------------------------------
//
//  Name:   main.cpp
//
//  Desc:   Main entry for WestWorld project
//
//------------------------------------------------------------------------



int main()
{
  // Create a miner
  Miner Bob(ent_Miner_Bob);
  // Create the miner wife
  MinerWife Elsa(ent_Elsa);

  // Simply run the Bob through a few Update calls
  for (int i=0; i<20; ++i)
  {
    Bob.Update();
    Elsa.Update();
    // Let user enough time to see what’s happening.
    sleep(3);
  }

  return 0;
}
