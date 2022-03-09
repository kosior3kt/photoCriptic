//
// Created by JK on 09/03/2022.
//

#include "Obliczator.h"

//////////////////////////////////////////private functions
void Obliczator::initVariables() {
    /**
     * @return void
     * This method is responsible for initializing all the variables
     * -initializes variables
     */
}
///section for getting number out of matrix
bool Obliczator::checkBit(int nrBitu, int(*tab)[COLS]) {
    /**
     * @return void
     * This method is responsible for calculating weather the given bit is 1 or 0 in given 2d array based on oddity of given parts
     * This method:
     * -takes bit number
     * -takes 2d array
     * -splits array into groups, based on given bit
     * -returns value of group %2
     * -updates sum, used to represent the 2d array (which is dec representation of base 2 number)
     */
    int SUMATOR3000=0; //is a temporary variable used to sum value of group

    //first 3 bits sum over groups in horizontal orientation, other 3 in vertical orientation these, "if's" are responsible for that
    if(nrBitu<=2 && nrBitu>=0){
        for(int i=0; i<COLS; i++){
            for(int j=0; j<ROWS; j++){
                //sets configuration of columns based on given bit to check
                if(j==this->hashTab[nrBitu][0] || j==this->hashTab[nrBitu][1] || j==this->hashTab[nrBitu][2] || j==this->hashTab[nrBitu][3]){
                    SUMATOR3000+=tab[i][j];
                }
            }
        }}
    else if(nrBitu<=5){
        for(int i=0; i<COLS; i++){
            for(int j=0; j<ROWS; j++){
                //sets configuration of rows based on given bit to check
                if(i==this->hashTab[nrBitu][0] || i==this->hashTab[nrBitu][1] || i==this->hashTab[nrBitu][2] || i==this->hashTab[nrBitu][3]){
                    SUMATOR3000+=tab[i][j];
                }
            }
        }
    }
    else{
        //error handling
        std::cout<<"podaj nr bitu w zakresie 0-5\n";
        return 0;
    }
    //binarizes answear
    if(SUMATOR3000%2==0)
        return 1; //returns 1 when odd
    else
        return 0; //returns 0 when odd
}

int Obliczator::wykonywator(int(*tab)[COLS], int* inputBin) {
    /**
     * @return int
     * This method is responsible for handling backend tasks and returns characteristic number for a 2d array
     * -initializes characteristic number variable
     * -calls checkBit method
     * -fills inputBin array, which then is returned to user as reference
     */
    int suma=0;

    for(int i =0; i<std::size(this->bitValue); i++){
        *(inputBin+i) = this->checkBit(i, tab);  //creates the associated to input 2d array inputBin array
        if(*(inputBin+i)) {
            suma = suma + *(inputBin+i) * this->bitValue[i];
//            std::cout<<"\nsuma has been updated: "<<this->suma<<"\ninput bit: "<<this->inputBin[i]<<"\nbin value: "<<this->bitValue[i]<<std::endl;
        }
    }
    return suma;
}

///section for modifying previous matrix for a given matrix
bool Obliczator::porownywator(int nrBitu, int* targetBin, int* inputBin) {
    if(targetBin[nrBitu] == inputBin[nrBitu]) {
        return false;
    }
    return true;
}

void Obliczator::targetToBinary(int target, int* targetBin) {
    /**
     * @return void
     * This method is responsible for updating targetBit array, and representing target value in binary array
     * -represents target in for of binary array
     * -updates targetBin array
     */
    for(int i = std::size(bitValue)-1; i>=0; i--) {
        if(this->bitValue[i]<=target){
            *(targetBin+i)=1;
            target=target-this->bitValue[i];
        }
    }
}

int Obliczator::targetToDec(int* calculationTab) {
    /**
     * @return int
     * This method is responsible for changing a given binary array to a int
     * -returns int decoded from binary array
     */
     int inputSuma1=0;
    for(int i =0; i<std::size(bitValue);i++){
        if(*(calculationTab+i))
            inputSuma1 = inputSuma1 | this->bitValue[i];
    }
    return inputSuma1;
}

void Obliczator::przemieniator(int nrBitu, int(*tab)[COLS]) {
    int licznik = 0;
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if(nrBitu==licznik) {
                if(tab[i][j])
                    tab[i][j]=0;
                else
                    tab[i][j]=1;
                std::cout<<"robie cos\n";
                return;
            }
            licznik++;
        }
    }
}

////////////////////////////////////////public functions
void Obliczator::decode(int(*tab)[COLS]) {
    /**
     * @return void
     * This method is responsible for showing test data to a user
     * -returns 2d array to a console
     * -returns number corresponding to a 2d array
     */
    this->initVariables();
    int inputBin[6]={0,0,0,0,0,0};
    std::cout<<"Your characteristic number is: "<<this->wykonywator(tab, inputBin);
    space;
    for(int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            std::cout<<tab[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    space;
    space;
}

Obliczator::Obliczator() {
    this->initVariables();
}

Obliczator::~Obliczator() {
    this->initVariables();
}

void Obliczator::encode(int target, int (*tab)[ROWS]) {
    /**
     * @return void
     * This method is responsible for parsing data from user in order to count a return 2d array corresponding to a given int
     */
     if(target>63 || target<0){
         std::cout<<"\n"<<"zle wprowadzone bity"<<"\n";
         return;
     }
    this->initVariables();
    int inputBin[6]={0,0,0,0,0,0};
    int targetBin[6]={0,0,0,0,0,0};
    int calculationTab[6]={0,0,0,0,0,0};
    this->wykonywator(tab, inputBin);
    this->targetToBinary(target, targetBin);
    for (int i = 0; i < std::size(targetBin); i++) {
        calculationTab[i] = this->porownywator(i, targetBin, inputBin);
    }
    this->targetToDec(calculationTab);
    this->przemieniator(this->targetToDec(calculationTab), tab);
    this->wyswietlator(tab);
    std::cout<<"Your characteristic number is: "<<this->wykonywator(tab, inputBin);
}

void Obliczator::wyswietlator(int (*tab)[COLS]) {
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            std::cout<<tab[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}


