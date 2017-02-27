// simple multi file strip.h, main.cpp, and strip.cpp
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>

using namespace std;

#include "strip.h"

// using the scope operator to ensure set_residue is recognized as
// the member function of strip
void strip::set_residue (string newresidue) {
  if ( newresidue == "WAT")
    residue = newresidue;
  else
    cout << "Illegal residue: " << newresidue << endl;
}
