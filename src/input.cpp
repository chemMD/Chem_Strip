
/**
 * @short   input parameters
 * @file    input.cpp
 * @author  Caleb Gallops and Dennis Kennetz
 *
 * This file contains the read_input prototype. The read_input
 * function is a boolean that uses a pointer to read the parameters
 * into a struct.
 */


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

bool read_input( string inputfilename, Input *inp) {

    ifstream file;

    file.open( inputfilename.c_str() );

    if( !file.is_open() ) {

        return false;

    } else if ( !( file >> inp->pdbfilename
              >> inp->pdboutname
              >> inp->mdcrdfilename
              >> inp->mdcrdoutname
              >> inp->stripcommand
              >> inp->time_steps
              >> inp->rdf_solute
              >> inp->rdf_solute_atom
              >> inp->rdf_solvent
              >> inp->rdf_solvent_atom ) ){

        cout << "Input file has improper format" << endl;
        return false;
    }

    return true;
}
