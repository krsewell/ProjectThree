/*
 *   kjs170430_Project3/file.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */


#ifndef FILE_H_INCL_GUARD
#define FILE_H_INCL_GUARD

#include "magicsquare.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>


using std::ofstream;
using std::stringstream;
using std::string;
using std::ios;
using std::cout;
using std::endl;
using std::setw;


class File {
private:

    MagicSquare * m_square;
    stringstream m_streamObj; 
    string * m_name;
    ofstream m_fileObj;
    
public:

    File::File(MagicSquare&,string&);
    File::~File();

    bool File::setSquare(MagicSquare&);
    bool File::setName(string&);

    MagicSquare* File::getSquare() const;
    string* File::getName() const;

    bool File::writeFile();
    bool File::appendFile();
    bool File::openFile();

    bool File::formatFile();

};


#endif