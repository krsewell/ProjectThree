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

bool File::setName(string& name) {
    m_name = &name;
    bool vR = m_name != nullptr ? true : false;
    return vR;
}



MagicSquare* File::getSquare() const {
    return m_square;
}

string* File::getName() const {
    return m_name;
}


/*
    File operations which include opening, closing, and writing to a file.
*/

bool File::appendFile() {
    //flush and changes to file first and clear stream flags
    if (m_fileObj.is_open()) {
        m_fileObj.close();
        m_fileObj.clear();
    }
    
    
    m_fileObj.open(*m_name,ios::app);
    if (m_fileObj) {
        return true;
    } else {
        std::cout << "FILE: error appending file." << std::endl;
        return false;
    }

}

bool File::openFile() {
    //flush and changes to file first and clear stream flags
    if (m_fileObj.is_open()) {
        m_fileObj.close();
        m_fileObj.clear();
    }

    m_fileObj.open(*m_name,ios::in);
    if (m_fileObj) {
        return true;
    } else {
        cout << "FILE: error opening file." << endl;
        return false;
    }
}

bool File::writeFile() {
    
    cout << 
    File::openFile();   
    if (!m_fileObj.is_open()) {
        appendFile();
    }

}

bool File::formatFile() {
    const short SIZE = *m_square.getSize();
    //header
    m_streamObj << "---------------------------------------------------------------" << endl;
    m_streamObj << "\n Magic Square of size " << SIZE << endl;
    m_streamObj << "Magic Constant is equal to " << *m_square.getMagicNum() << endl;
    m_streamObj << endl << endl;

    //output square

    
    for (short i = 0; i < SIZE; i++) {
        for (short j = 0; j < SIZE; j++) {
            m_streamObj << setw(8) << *m_square.getElement(i,j);
        }
        m_streamObj << endl;
    }
    
}




