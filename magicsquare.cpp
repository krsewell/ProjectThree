/*
 *   kjs170430_Project3/magicsquare.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */

#include "magicsquare.hpp"

MagicSquare::MagicSquare(short ofOrder) : m_ofOrder(ofOrder) {
  mallocArray(m_squareArray,m_ofOrder);
  fillArray();
  generateMagicNumber();
}

MagicSquare::~MagicSquare() {
    delArray(m_squareArray);
    //std::cout << "Square object of size: " << m_ofOrder << " has been deleted.\n"; 
}

short MagicSquare::getSize() const {
    return m_ofOrder;
}

int MagicSquare::getElement(short i, short j) const {
    return m_squareArray[i][j];
}

int MagicSquare::getMagicNum() const {
    return m_magicNumber;
}

void MagicSquare::mallocArray(int ** &ptr,short n) {
  try {  
    ptr = new int*[n];
    for (int i = 0; i < n; i++) {
        ptr[i] = new int[n];
    }
    //std::cout << "Address of Array: " << ptr << std::endl;
  } catch (...) {
    std::cout << "ERROR: Unable to allocate memory" << std::endl;
  }
}

void MagicSquare::delArray(int ** &ptr) {

    for (int i = 0; i < m_ofOrder; i++) {
        delete [] ptr[i];
    }
    delete [] ptr;
}

void MagicSquare::fillArray() {
  //std::cout << "Address of Array: " << m_squareArray << std::endl;
    
  for (int i = 0; i < m_ofOrder; i++) {
      for (int j = 0; j < m_ofOrder; j++) {
          m_squareArray[i][j] = generateElementValue(i,j);
         // std::cout << "i: " << i << " j: " << j << " value: " << m_squareArray[i][j] << std::endl;
      }
  }
}

int MagicSquare::generateElementValue(short i, short j) const {
    int value, value2;
    i++;
    j++;

    short halfn = m_ofOrder / 2; // n being odd the result will normally be x.5 however we want just x so no type casting
    value = i + j - 1 + halfn; 
    value %= m_ofOrder;
    value *= m_ofOrder;
  
    j *= 2;
    value2 = i + j - 2;
    value2 %= m_ofOrder;
    value2++;
  
    value += value2;
    //std::cout << value;
    return value;
}

void MagicSquare::generateMagicNumber() {
    int var;

    var = m_ofOrder * m_ofOrder;
    var++;
    var *= m_ofOrder;
    var /= 2;
    
    m_magicNumber = var;
    //std::cout << "Magic number: " << m_magicNumber << std::endl;
}

