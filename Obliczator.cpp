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
    suma=0;
    for (auto & i :inputBin) //empties inputBin array;
        i=0;
    for(auto& i: targetBin)
        i=0;
    for(auto& i: calculationTab)
        i=0;
    for(auto & i : this->dummyTab) //empties dummyTab;
        for (int &j: i)
            j=0;
}
///section for getting number out of matrix
bool Obliczator::checkBit(int nrBitu) {
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
                if(j==hashTab[nrBitu][0] || j==hashTab[nrBitu][1] || j==hashTab[nrBitu][2] || j==hashTab[nrBitu][3]){
                    SUMATOR3000+=this->dummyTab[i][j];
                }
            }
        }}
    else if(nrBitu<=5){
        for(int i=0; i<COLS; i++){
            for(int j=0; j<ROWS; j++){
                //sets configuration of rows based on given bit to check
                if(i==hashTab[nrBitu][0] || i==hashTab[nrBitu][1] || i==hashTab[nrBitu][2] || i==hashTab[nrBitu][3]){
                    SUMATOR3000+=this->dummyTab[i][j];
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

void Obliczator::wykonywator() {
    /**
     * @return void
     * This method is responsible for handling backend tasks
     * -calls method initVariables
     * -calls checkBit method
     * -fills inputBin array, which then is returned to user
     */
    for(int i =0; i<6; i++)
        this->inputBin[i] = this->checkBit(i);  //creates the associated to input 2d array inputBin array

    for(int i =0; i<6;i++){
        if(inputBin[i]) {
            this->suma = this->suma + this->inputBin[i] * this->bitValue[i];
//            std::cout<<"\nsuma has been updated: "<<this->suma<<"\ninput bit: "<<this->inputBin[i]<<"\nbin value: "<<this->bitValue[i]<<std::endl;
        }
    }
}

///section for modifying previous matrix for a given matrix
bool Obliczator::porownywator(int nrBitu) {
    if(targetBin[nrBitu] == inputBin[nrBitu]) {
        return false;
    }
    return true;
}

void Obliczator::targetToBinary(int target) {
    /**
     * @return void
     * This method is responsible for updating targetBit array, and representing target value in binary array
     * -represents target in for of binary array
     * -updates targetBin array
     */
    for(int i = std::size(bitValue)-1; i>=0; i--) {
        if(this->bitValue[i]<=target){
            this->targetBin[i]=1;
            target=target-this->bitValue[i];
        }
//        std::cout<<i<<" "; //used to debug
//        std::cout<<targetBin[i]<<" "; //used to debug
    }
}

int Obliczator::targetToDec() {
    /**
     * @return int
     * This method is responsible for changing a given binary array to a int
     * -returns int decoded from binary array
     */
    for(int i =0; i<std::size(calculationTab);i++){
        if(calculationTab[i])
            this->inputSuma = inputSuma | bitValue[i];
    }
    return inputSuma;
}

void Obliczator::przemieniator(int nrBitu, int(*tab)[COLS]) {
    int licznik = 0;
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
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
void Obliczator::tabInputShow() {
    /**
     * @return void
     * This method is responsible for showing test data to a user
     * -returns 2d array to a console
     * -returns number corresponding to a 2d array
     */
     this->suma=0;
     wykonywator();
    for(int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            std::cout<<this->dummyTab[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    space;
    std::cout<<"Your characteristic number is: "<<suma;
}

Obliczator::Obliczator() {

}

void Obliczator::updateTab(int (*tab)[ROWS]) {
    for(int i= 0; i<COLS; i++)
        for (int j = 0; j < ROWS; ++j)
            this->dummyTab[i][j]=tab[i][j];
}

int Obliczator::retCharacteristicNumber() {
    /**
     * @return int
     * This method is responsible for returning a characteristic number of a previously loaded dummyTab
     * -returns characteristic number of a dummyTab
     */
     return this->suma;
}

void Obliczator::tabInputParser(int (*tab)[COLS]) {
    /**
     * @return void
     * This method is responsible for interaction between user and class
     * -takes 2d array
     * -calls initVariables function
     * -calls copying tab to dummyTab method
     * -calls method responsible for showing results to a user
     */
    this->initVariables();
    this->updateTab(tab);
    //used to test results
//    this->test();
}

void Obliczator::test() {
    /**
     * @return void
     * This method is used mainly to debug
     * -takes actions on dumyTab
     */
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            dummyTab[i][j]=0;
        }
    }
}

Obliczator::~Obliczator() {
    this->initVariables();
}

void Obliczator::intInputParser(int target) {
    /**
     * @return void
     * This method is responsible for parsing data from user in order to count a return 2d array corresponding to a given int
     */
    this->targetToBinary(target);
    for (int i = 0; i < std::size(targetBin); ++i) {
        this->calculationTab[i] = this->porownywator(i);
//        std::cout<<this->porownywator(i)<<" ";
    }
    this->suma=0;
    this->targetToDec();
    this->przemieniator(this->targetToDec(), this->dummyTab);
    this->tabInputShow();
}

void Obliczator::intShow() {
    /**
     * @return void
     * This method prints to console a matrix position which is going to be changed
     */
    std::cout<<targetToDec();
}

