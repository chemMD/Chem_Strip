
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
        string mdcrdoutname;
        string stripcommand;
        int time_steps;
        string rdfcommand;

};

extern input inp;
bool read_input( string inputfilename );
