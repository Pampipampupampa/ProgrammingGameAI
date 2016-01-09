#include "EntityNames.h"
#include "Locations.h"
#include "Miner.h"

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
  Miner miner(ent_Miner_Bob);
  // cout << miner.ID() << endl;

  // Simply run the miner through a few Update calls
  for (int i=0; i<20; ++i)
  {
    miner.Update();
    // Let user enough time to see what’s happening.
    sleep(5);
  }

  return 0;
}
