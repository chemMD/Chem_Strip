/**
 * @short   input Headers
 * @file    input.h
 * @author  Caleb Gallops and Dennis Kennetz
 *
 * This header file contains the Input struct and the read_input function
 * declaration.
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

//all of the user-specified parameters
struct Input {
    string pdbfilename;
    string pdboutname;
    string mdcrdfilename;
    string mdcrdoutname;
    string stripcommand;
    int time_steps;
    string rdf_solute;
    string rdf_solute_atom;
    string rdf_solvent;
    string rdf_solvent_atom;
    string logfilename;
};

bool read_input( string inputfilename, Input & inp, ofstream& log_file );
