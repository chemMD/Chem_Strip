/**
 * @mainpage Chemistry_Strip Program
 *
 * Welcome to the Chemistry_Strip documentation. Here you will find all the relevant info
 * related to this program which was designed to remove residues from AMBER suite 
 * trajectory and topology files.
 */

#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <cmath>

/**
 * @short   Chemistry_Strip
 * @file    strip.cpp
 * @author  Caleb Gallops & Dennis Kennetz
 * @param   none
 * @return  0 on success
 *
 * This program removes any specified residue from AMBER suite trajectory and topology files 
 * It also simultaneously produces radial distribution functions for the removed residue.
 * This is intended to reduce the size of these files so quicker analyses can be performed.  
 * The purpose of producing an radial distribution is to extract any valuable information 
 * before the strip. 
 */

using namespace std;

#include "strip.h"

int main () {

    string   inputfilename;
    ifstream inputfile;
    string   residueinputname;

    cout << "Executing main..." << endl;

    // input file + residue
    cout << "Enter input filename: " ;
    cin  >> inputfilename;
    cout << "Enter name of residue to be removed:";
    cin  >> residueinputname;

    // check file stream
    inputfile.open(inputfilename.c_str());

    if ( !inputfile.is_open() )
        cout << "Cannot open input file: " 
             << inputfilename << endl;
    else 
        cout << "Reading:" 
             << inputfilename << endl;  
           
    strip x;
    x.set_residue("WAT");
    cout << "Residue :" 
         << x.get_residue() 
         << endl;
    
    return 0;
}



