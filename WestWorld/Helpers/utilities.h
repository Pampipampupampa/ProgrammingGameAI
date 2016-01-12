#ifndef UTILITIES_H
#define UTILITIES_H

#include <limits>


//------------------------------------------------------------------------
//
//  Name:   utilities.h
//
//  Desc:   Some useful function
//
//------------------------------------------------------------------------


// Inline allows to write full function inside the header file.


//----------------------------------------------------------------------------
// A few useful constants
//----------------------------------------------------------------------------
const int     MaxInt    = (std::numeric_limits<int>::max)();
const double  MaxDouble = (std::numeric_limits<double>::max)();
const double  MinDouble = (std::numeric_limits<double>::min)();
const float   MaxFloat  = (std::numeric_limits<float>::max)();
const float   MinFloat  = (std::numeric_limits<float>::min)();

const double   Pi        = 3.14159;
const double   TwoPi     = Pi * 2;
const double   HalfPi    = Pi / 2;
const double   QuarterPi = Pi / 4;


//----------------------------------------------------------------------------
//  Some random number functions.
//----------------------------------------------------------------------------

//returns a random integer between x and y
inline int   RandInt(int x,int y)
{
  assert(y >= x && "<RandInt>: y is less than x");
  return rand() % (y - x + 1) + x;
}

//returns a random double between zero and 1
inline double RandFloat()
{
	return (rand() / (RAND_MAX + 1.0));
}

inline double RandInRange(double x, double y)
{
  return x + RandFloat() * (y - x);
}

//returns a random bool
inline bool   RandBool()
{
  if (RandFloat() > 0.5) return true;

  else return false;
}


#endif
