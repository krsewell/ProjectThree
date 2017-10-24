/*
 *   kjs170430_Project3/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */


#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include "magicsquare.hpp"
#include "file.hpp"

#include <iostream>
#include <string>
#include <locale>

short getUserShort();

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::stoi;
using std::stringstream;

#endif



int main() {
  //Magic Squares up to 999 rows and columns. 999^2 is 6 digit number
  //file formatting and output.
  
  //create the file object. and dependancies
  File file();

  short ofOrder;
  while (true) {
    //gets a user value that is either odd from 1-999, or 0
    ofOrder = getUserShort();
    
    //code that will exit the loop
    if (ofOrder == 0) {
      break;
    }
    //create the magic square object
    MagicSquare square(ofOrder);


    
  }
  
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
  cout  << "If you would like to exit without creating another Magic Square\n" 
        << "you may do so by entering 0 for your next value.\n\n";
  return uShort;
}