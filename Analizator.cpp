//
// Created by JK on 09/03/2022.
//

#include "Analizator.h"

char Analizator::retChar(int number) {
    /**
     * @return char
     * This method is responsible for returning a char corresponding to a given number
     * -returns a char based on a given number by searching a charTab
     */
     std::cout<<"Your character is: ";
    return charTab[number];
}

int Analizator::retInt(char character) {
    /**
     * @return int
     * This method is responsible for returning a int
     * -returns a number based on given character by going through a charTab
     */
     std::cout<<"Your number is: ";
    for (int i = 0; i < std::size(charTab); ++i) {
        if(charTab[i]==character)
            return i;
    }
}

Analizator::Analizator() {

}
