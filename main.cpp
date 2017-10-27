/*
 *   kjs170430_Project3/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 */


#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD

#include "magicsquare.hpp"

#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::stoi;
using std::ostringstream;
using std::setw;


const char * getUserFilename();
void printHeader();
short getUserShort();
bool formatFile(const MagicSquare&, ostringstream&);

#endif



int main() {
  printHeader();
  
  short ofOrder;
  const string filename = getUserFilename();
  std::ofstream file;

  //open file for first time to see if it can be opened. 
  file.open(filename,std::ios::app);
  if (!file.is_open()) {
    cout << "Error opening file. Please re-run the program to try again." << endl;
    return -1;
  }

  while (true) {
    //gets a user value that is either odd from 1-999, or 0
    ofOrder = getUserShort();
    
    //code that will exit the loop
    if (ofOrder == 0) {
      break;
    }

    //check if file is open. if not open it.
    if (!file.is_open()) {
      file.open(filename,std::ios::app);
    }

    //create the magic square
    MagicSquare square(ofOrder);    //goes out of scope each loop.
    ostringstream format;
    formatFile(square,format);
    file << format.str();
    file.close();
    file.clear();                   //should ready the object if it needs to be reopened.
  }
  
  return 0;
}

const char * getUserFilename() {
  string userFilename;
  string extention = ".txt";
  while (userFilename.empty()) {
    cout << "Please enter a filename: ";
    cin >> userFilename;
    cout << endl;

    if (!userFilename.empty()) {
      auto const pos = userFilename.find_last_of('.');
      const auto currentExtention = userFilename.substr(pos + 1);
      
      if (currentExtention != "txt") {
        userFilename += extention; 
      }
      return userFilename.c_str();
    }
  }
}

void printHeader() {
  cout << "Odd Magic Squares\n\t by Kristopher Sewell\n\t Oct. 2017\n\n";
  
  cout << "This program is designed to create a magic square where all values in either a row, column, or\n";
  cout << "major diagonal add to an identical value. This value is called the \"Magic Sum\" or \"Magic Constant.\"\n";
  cout << "After entering a filename you will be asked for your desired square size. You may continue entering as\n";
  cout << "many values as you like after the first one and they will all be printed to your file. When you are finished\n";
  cout << "just enter a value of \'0\' to end the program." << endl << endl;
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

    uShort = isDigitFlag ? stoi(userString) : 2;

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

bool formatFile(const MagicSquare& square, ostringstream& streamObj) {
  const short SIZE = square.getSize();
  //header
  streamObj << "---------------------------------------------------------------" << endl;
  streamObj << "\n Magic Square of size " << SIZE << endl;
  streamObj << "Magic Constant is equal to " << square.getMagicNum() << endl;
  streamObj << endl << endl;

  //output square

  
  for (short i = 0; i < SIZE; i++) {
    for (short j = 0; j < SIZE; j++) {
      streamObj << setw(8) << square.getElement(i,j) << ' ';
    }
    streamObj << endl;
  }
  
  return streamObj.good();
}
