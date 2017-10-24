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
    stringstream * m_stream;
    stringstream m_streamObj;
    
    string * m_name;
    
    ofstream * m_file;
    ofstream m_fileObj;
    
public:

    File::File(const MagicSquare&,string&);
    File::File(const MagicSquare&,stringstream&,string&,ofstream&);
    File::~File();

    bool File::setSquare(MagicSquare&);
    bool File::setStream(stringstream&);
    bool File::setName(string&);
    bool File::setFile(ofstream&);

    MagicSquare* File::getSquare() const;
    stringstream* File::getStream() const;
    string* File::getName() const;
    ofstream* File::getFile() const;

    bool File::writeFile() const;
    bool File::appendFile() const;
    bool File::openFile() const;

    bool File::formatFile();

};


#endif