
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>

class Input {

    public:
        string inputfilename;
        string inputArray[5];
        string pdbfilename;
        string pdboutname;
        string mdcrdfilename;
        string stripcommand;
        string rdfcommand;
        bool read_input(string inputfilename);

};
