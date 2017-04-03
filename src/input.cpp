
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>


using namespace std;

#include "input.h"

bool Input::read_input( string inputfilename ) {

    ifstream file;
    cout << "Enter input file name: " ;  
    cin >> inputfilename;

    file.open( inputfilename.c_str() );
    if( !file.is_open() ) return false;
     
    for( int i = 0; i < 6; ++i ) {
	  file >> inputArray[i];
        }
    pdbfilename   = inputArray[0];
    pdboutname    = inputArray[1];
    parmfilename  = inputArray[2];
    mdcrdfilename = inputArray[3];
    stripcommand  = inputArray[4];
    rdfcommand    = inputArray[5];
   
    return true;
}
