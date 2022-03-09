//
// Created by JK on 09/03/2022.
//
/**
 * This class is responsible for all the math behind encryptic and decryptic the photo
 */


#ifndef PHOTOCRIPTIC_OBLICZATOR_H
#define PHOTOCRIPTIC_OBLICZATOR_H

#include <cstdio>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#define COLS 8
#define ROWS 8
#define space std::cout<<"\n"<<"----------------"<<"\n"

class Obliczator {
    /////////////////////////////////////////private variables
    const int hashTab[6][4]={
            {1,3,5,7},
            {2,3,6,7},
            {4,5,6,7},
            {1,3,5,7},
            {2,3,6,7},
            {4,5,6,7}
    };  //It's used to determine structure part and corresponding bit
    const int bitValue[6]={1, 2, 4, 8, 16, 32}; //It's used to both encode and decode number to binary and do operations on it
    int inputBin[6];    //Variable representing binary number associated with input 2d array
    int calculationTab[6];  //Variable used to represent a number in which bits have to be swaped in order to get a desired number
    int suma;   //Variable used as decimal representation of inputBin
    int inputSuma;  //variable used to recalculate stuff
    int dummyTab[COLS][ROWS]; //This array is used to store incoming 2d array
    int targetBin[6];   //This variable represents target number in binary
    ////////////////////////////////////////private functions
    void initVariables();   //This method initialized variables used in class
    ///section for getting number out of a matrix
    bool checkBit(int nrBitu); //It's used to check if the bit is 1 or 0, based on oddity of corresponding parts of array
    void wykonywator();  //This method is used to do all the practical work
    void test();  //this method is used to test action taken on 2d array
    ///section for getting matrix for a given number
    bool porownywator(int);
    void targetToBinary(int); //This method is used to change number from base10 to binary arr
    int targetToDec(); //This method is used to change number from binary arr to base10
    void przemieniator(int,int(*tab)[COLS]);
public:
    ////////////////////////////////////////public functions
    ///section for getting number out of a matrix
    void tabInputParser(int (*tab)[COLS]);     //This method is used to interact with user
    void updateTab(int (*tab)[ROWS]);   //This method is used to actualize a 2d array
    ///section for getting matrix for a given number
    void intInputParser(int);   //This method is used to parse information
    ///Konstruktor i dekonstruktor
    Obliczator();
    ~Obliczator();

    /////////////////////////////////////////Accesors
    ///section for getting number out of a matrix
    int retCharacteristicNumber();  //This method returns characteristic number for a previously loaded 2d array
    void tabInputShow();  //This method is used for showing results to a user (mainly debug tool)
    ///section for getting matrix for a given number
    void intShow();  //this method returns a number of 2d array position which should be changed in order for a characteristic number be equal to a target value
};


#endif //PHOTOCRIPTIC_OBLICZATOR_H
