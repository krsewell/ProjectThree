/*
 *   kjs170430_Project3/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */


#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include <iostream>
#include <string>
#include <locale>

//Dec
short getUserShort();
int getElementValue(int,int,short);

using namespace std;
//

#endif



int main() {
  //Magic Squares up to 999 rows and columns. 999^2 is 6 digit number
  //file formatting and output.

  //get user short value which must be of odd order
  short ofOrder = getUserShort();
  cout << getElementValue(1,1,ofOrder);
  

  //algorithm n * ((i + j - 1 + [n/2]) % n) + ((i + 2j - 2) % n) + 1 = element value

  //

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
    uShort = userString.stoi();
    if (uShort % 2 == 0) {
      cout << "ERROR: that value is not odd." << endl;  
    }
  } 
  return uShort;
}

int getElementValue(int i, int j, short n) {
  int value,
      value2;

  short halfn = n / 2; // n being odd the result will normally be x.5 however we want just x 
  value = i + j - 1 + halfn; 
  value %= n;
  value *= n;

  j *= 2;
  value2 = i + j - 2;
  value2 %= n;
  value2++;

  value += value2;
  return value;
}