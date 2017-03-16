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
#include "strip.h"

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


int main () {
    
    string   inputfilename;
    ifstream inputfile;
    string   inplist;

    cout << "Executing main..." << endl;

    // input file + residue
    cout << "Enter input filename: " ;
    cin  >> inputfilename;
     
    strip parameters;
    
    // check file stream
    inputfile.open(inputfilename.c_str());

    if ( inputfile.is_open() ) {
        cout << "Reading: " 
             << inputfilename << endl;
	while ( getline (inputfile,inplist) ) {
	  cout << inplist << '\n';
        }
        cout << inplist;
    }
    else 
        cout << "Cannot open input file: " 
             << inputfilename << endl;
        
    parameters.set_residue(inplist);
    cout << "Residue: "
         << parameters.get_residue() 
         << endl;
    
    return 0;
}



