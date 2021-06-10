# Chem_Strip
Removes atoms from pdb, topology and trajectory files. It includes radial distribution calculations and other options.

## Introduction

Molecular Dynamics in Biomolecular Modeling
Molecular dynamics is a computer simulation method used for various types of systems. In brief, molecular dynamics computes the positions of atoms and the changes in those positions over time. The focus in the Chem_Strip project development is to create a program that edits and evaluates files commonly used in molecular dynamics for biomolecular modeling. There are two types of files that this program can process so far: Protein Data Base (pdb) files and Molecular Dynamics Coordinate (mdcrd) files. The pdb files list the atoms and their properties of a system that is to be evaluated. The mdcrd files list the coordinates of each atom in the same order as the pdb file for every time step in sequential order.

![picture_1](https://camo.githubusercontent.com/434ca02e0b0d35dac483818dc96e96dd9a4825688cff6c192b1d06d66da91465/687474703a2f2f617263686976652e616d6265726d642e6f72672f3230313130382f6174742d303635362f322e676966)

Photo Credit: http://archive.ambermd.org/201108/att-0656/2.gif


## Stripping Residues

### Problems with Big Files
Molecular Dynamics Coordinate (MDCRD) files are very large when employing molecular dynamics for the purpose of biomolecular research. The size of these files can range up to several hundred gigabytes. This leads to the main purpose for creating the Chem_Strip program: removing unnecessary atoms from MDCRD files and their corresponding Protein Data Bank (PDB) Files.

### Stripping PDB and MDCRD files
This program allows those who employ molecular dynamics in their research to remove any unwanted residues from their PDB and MDCRD files. This inherently shrinks the size of these files, making them more portable and easier to analyze. The user can also specify any residues it wants to use for radial distribution calculations.(Currently, this part of the program is not functional and is not included in the Github repository.) Images of a visualized PDB file (example.pdb) and a stripped PDB file (out.pdb) are shown below.

![picture_2](https://github.com/chemMD/Chem_Strip/wiki/example.png)
![picture_3](https://github.com/chemMD/Chem_Strip/wiki/out.png)

The same is conducted for the MDCRD files but for multiple time steps.


## User Instructions
The code in this repository compiles to create an executable name MD_strip.

To run the program the file containing all of the input parameters must be present in the same directory as the MD_strip executable. MD_strip is executed on the command in the following way.

$ ./MD_strip example.inp
Below is an example of input parameters file that can be given to the program. This is the example.inp file in the Github repository.

```
example.pdb out.pdb
example.mdcrd out.mdcrd
WAT 2
N1U N1 Cl- Cl-
log.txt
```

As of now, the program only reads the input parameters in sequential order. Therefore, the file doesn't need this exact format. It only needs the parameters to be listed in order. However, all of the commands must be provided in order for the program to run.

The example.pdb is the name of the PDB file that the user wants to analyze and process. The PDB must be in the same directory as the executable.

The out.pdb is the name the user wants for the stripped PDB file. It can be anything.

The example.mdcrd is the name of the MDCRD file that the user wants to analyze and process. The MDCRD must be in the same directory as the executable.

The out.mdcrd is the name the user wants for the stripped MDCRD file. It can be anything.

For this program, both the PDB file and the MDCRD file must be in their standard formats.

The WAT in this example is the name of the residue that is to be stripped from the PDB and MDCRD files. If the specified residue isn't present within the PDB or MDCRD files, the program will produce unchanged outputs.

The 2 in this example is the number of time steps to be analyzed in the MDCRD file.

The N1U in this example is the name of the solute residue to be used in the radial distribution calculation.

The N1 in this example is the name of the atom within the solute residue to be used in the radial distribution calculation.

The Cl- in this example is the name of the solvent residue to be used in the radial distribution calculation.

The Cl- in this example is the name of the atom within the solvent residue to be used in the radial distribution calculation.

In the Cl- case, the residue name and the atom name are the same. This can be seen in example.pdb. Still both must be specified in order for the program to work.

The log.txt is the name the user wants for the log file.


