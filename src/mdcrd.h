#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <vector>

struct Coordinates {
    double X;
    double Y;
    double Z;
};

bool read_mdcrd (string mdcrdfilename,int time_steps, int number_of_atoms,
         vector<Coordinates> & mdcrd, vector<Coordinates> & per_box_bound );

bool write_mdcrd (string mdcrdoutname, int time_steps, int number_of_atoms,
         vector<int> & strip, vector<Coordinates> & mdcrd, vector<Coordinates> & per_box_bound);
