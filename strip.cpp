
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>

using namespace std;

struct distance {
    string atom_type;
    float x_coord;
    float y_coord;
    float z_coord;
};

int main () {

    string   inputfilename;
    ifstream inputfile;
    string   residueinputname;
    string   atom;
    string   atomlist;
    string   distance;
    
    // Prompt user for input file + residue
    cout << "Enter input filename: " ;
    cin  >> inputfilename;
    cout << "Enter name of residue to be removed:";
    cin  >> residueinputname;

    // Sanity check on the file stream
    inputfile.open(inputfilename.c_str());
    if ( !inputfile.is_open() ) {
        cout << "Cannot open input file: " 
             << inputfilename
             << endl;
        return 1;
    }
}



