/*
 *   kjs170430_Project3/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */


#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include <iostream>
#include <string>
#include <locale>

#include "magicsquare.hpp"

short getUserShort();

using namespace std;

#endif



int main() {
  //Magic Squares up to 999 rows and columns. 999^2 is 6 digit number
  //file formatting and output.

  //get user short value which must be of odd order
  short ofOrder;
  do {
    ofOrder = getUserShort();
    MagicSquare square(ofOrder);
    cout << square.getMagicNum() << endl;
    ofOrder = 0;
  } 
  while (ofOrder != 0);
  
  return 0;

}




short getUserShort() {
  short uShort = 0;
  string userString;
  while (uShort % 2 == 0) {
    cout << "Please enter an odd value between 1 and 999: ";
    cin >> userString;
    cout << endl;

    bool isDigitFlag = true;
    for (char c : userString) {
      if (!isdigit(c)) {
        isDigitFlag = false;
      }
    }
    if (isDigitFlag) {
      uShort = stoi(userString);
    } else {
      uShort = 2;
    }
    
    if (uShort == 0) {
      return 0;
    }
    if (uShort % 2 == 0) {
      cout << "ERROR: that value is not odd." << endl;  
    }
  } 
  return uShort;
}