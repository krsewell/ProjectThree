/*
 *   kjs170430_Project3/file.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */


#include "file.hpp"

/*
    The file will need a name and a square to function. If a stringstream or ofstream
    is not provided the class will create one within the constructor. Once the object
    goes out of scope all dependacies will be destructed. Therefore an explicit decontructor
    is not needed. 
*/



File::File(MagicSquare& square, string& name) : m_streamObj(stringstream()), m_fileObj(ofstream()) {
    setSquare(square);
    setName(name);
    setStream(m_streamObj);
    setFile(m_fileObj);
}

File::File(MagicSquare& square, string& name, stringstream& stream,  ofstream& file) {
    setSquare(square);
    setName(name);
    setStream(stream);
    setFile(file);
}

File::~File() {}


/*
    Accessor and Mutator functions 
    each set function will return a valueof true if successful, while the get function will 
    only return what is read within the class
*/

bool File::setSquare(MagicSquare& square) {
    m_square = &square;
    bool vR = m_square != nullptr ? true : false;
    return vR;
}

bool File::setStream(stringstream& stream) {
    m_stream = &stream;
    bool vR = m_stream != nullptr ? true : false;
    return vR;
}

bool File::setName(string& name) {
    m_name = &name;
    bool vR = m_name != nullptr ? true : false;
    return vR;
}

bool File::setFile(ofstream& file) {
    m_file = &file;
    bool vR = m_file != nullptr ? true : false;
    return vR;
}


MagicSquare* File::getSquare() const {
    return m_square;
}
stringstream* File::getStream() const {
    return m_stream;
}
string* File::getName() const {
    return m_name;
}
ofstream* File::getFile() const {
    return m_file;
}

/*
    File operations which include opening, closing, and writing to a file.
*/

bool File::appendFile() {
    *m_file.open(*m_name,ios::app);
    if (file) {
        return true;
    } else {
        std::cout << "FILE: error appending file." << std::endl;
        return false;
    }

}

bool File::openFile() {
    *m_file.open(*m_name,ios::in);
    if (*m_file) {
        return true;
    } else {
        cout << "FILE: error opening file." << endl;
        return false;
    }
}

bool File::writeFile() {
    
    cout << 
    File::openFile();   
    if (!file.is_open()) {
        appendFile();
    }

}

bool File::formatFile() {
    const short SIZE = *m_square.getSize();
    //header
    *m_stream << "---------------------------------------------------------------" << endl;
    *m_stream << "\n Magic Square of size " << SIZE << endl;
    *m_stream << "Magic Constant is equal to " << *m_square.getMagicNum() << endl;
    *m_stream << endl << endl;

    //output square

    
    for (short i = 0; i < SIZE; i++) {
        for (short j = 0; j < SIZE; j++) {
            *m_stream << setw(8) << *m_square.getElement(i,j);
        }
        *m_stream << endl;
    }
    
}




