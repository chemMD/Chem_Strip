
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>

struct input {
        string pdbfilename;
        string pdboutname;
        string mdcrdfilename;
        string stripcommand;
        string rdfcommand;

};
extern input i;
bool read_input( string inputfilename );
