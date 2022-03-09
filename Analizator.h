//
// Created by JK on 09/03/2022.
//

#ifndef PHOTOCRIPTIC_ANALIZATOR_H
#define PHOTOCRIPTIC_ANALIZATOR_H

#include <cstdint>
#include <iostream>

#define COLS 8
#define ROWS 8

class Analizator {
    ////////////////////////////////////////private variables
    constexpr static const char charTab[64]={
            'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','w','x','y','q','z',
            'A','B','C','D','E','F','G','H','I','L','K','L','M','N','O','P','R','S','T','U','W','Y','X','Q','Z',
            '1','2','3','4','5','6','7','8','9','0','!','@','_','='
    };
    ////////////////////////////////////////private methods
    void wykonywator();
public:
    ////////////////////////////////////////public methods
    Analizator();
    char retChar(int);
    int retInt(char);
};


#endif //PHOTOCRIPTIC_ANALIZATOR_H
