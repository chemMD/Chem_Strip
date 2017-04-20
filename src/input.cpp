
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
#include <stdio.h>

using namespace std;

#include "input.h"

bool read_input( string inputfilename, Input & inp, ofstream& log_file ) {

    ifstream file;

    file.open( inputfilename.c_str() );

    if( !file.is_open() ) {

        return false;

    } else if ( !( file >> inp.pdbfilename
              >> inp.pdboutname
              >> inp.mdcrdfilename
              >> inp.mdcrdoutname
              >> inp.stripcommand
              >> inp.time_steps
              >> inp.rdf_solute
              >> inp.rdf_solute_atom
              >> inp.rdf_solvent
              >> inp.rdf_solvent_atom
              >> inp.logfilename) ){

        cout << "Input file has improper format" << endl;
        return false;
    }

    log_file.open(inp.logfilename);

    log_file << "*************************************************************" << endl
         << "Reading input file..." << endl
         << "Parameters:" << endl
         << "PDB file name: "<< inp.pdbfilename << endl
         << "Stripped PDB output file name: "<< inp.pdboutname << endl
         << "MDCRD file name: " << inp.mdcrdfilename << endl
         << "Stripped MDCRD output name: "<< inp.mdcrdoutname << endl
         << "Residue to be stripped: " << inp.stripcommand << endl
         << "Number of time_steps to be evaluated: " << inp.time_steps << endl
         << "Solute residue used for rdf calculation: " << inp.rdf_solute << endl
         << "Solute atom within residue used for rdf calculation: " << inp.rdf_solute_atom << endl
         << "Solvent residue used for rdf calculation: " << inp.rdf_solvent << endl
         << "Solvent atom within residue used for rdf calculation: " << inp.rdf_solvent_atom << endl
         << "*************************************************************" << endl;
    return true;
}
