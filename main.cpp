/*
 *   kjs170430_Project3/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */


#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include <iostream>

//Dec
short getUserShort();
int getElementValue(int,int);

using namespace std;
//

#endif



int main() {
  //Magic Squares up to 999 rows and columns. 999^2 is 6 digit number
  //file formatting and output.

  //get user short value which must be of odd order
  short ofOrder = getUserShort();

  

  //algorithm n((i + j - 1 [n/2]) % n) + ((i + 2j - 2) % n) + 1 = element value

  //

}

short getUserShort() {
  short uShort = 0;
  while (uShort % 2 == 0) {
    cout << "Please enter an odd value between 1 and 999: ";
    cin >> uShort;
    cout << endl;
    if (uShort % 2 == 0) {
      cout << "ERROR: that value is not odd.";  
    }
  } return uShort;
}

int getElementValue(int i, int j) {
  int value;
  

}