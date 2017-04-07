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

input i;

bool read_input( string inputfilename ) {

    ifstream file;

    file.open( inputfilename.c_str() );

    if( !file.is_open() ) {

        return false;

    } else if ( !( file >> i.pdbfilename
              >> i.pdboutname
              >> i.mdcrdfilename
              >> i.stripcommand
              >> i.rdfcommand ) ){

        cout << "Input file has improper format" << endl;
        return false;
    }
    return true;

}
