/*
 *   kjs170430_Project3/magicsquare.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */


#ifndef MAGICSQUARE_H_INCL_GUARD
#define MAGICSQUARE_H_INCL_GUARD

#include <iostream>
#include <string>


class MagicSquare {
private:
    const short m_ofOrder;
    int ** m_squareArray;
    int m_magicNumber;

    void mallocArray(int**&,short);
    void delArray(int**&);
    void fillArray();
    int generateElementValue(short,short) const;
    void generateMagicNumber();

public:
    MagicSquare(short);
    ~MagicSquare();
    
    short getSize() const;
    int getElement(short, short) const;
    int getMagicNum() const;    
};
#endif






