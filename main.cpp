#include "Obliczator.h"
#include "Analizator.h"


void randGenerator(int(*tab)[COLS]);
void showArr(int(*tab)[COLS]);
void zeroGenerate(int(*tab)[COLS]);

int main() {
    srand(time(NULL));
    int twoja_stara[8][8];
    int test[8][8];
    randGenerator(twoja_stara);
//    showArr(twoja_stara);
    randGenerator(test);
    zeroGenerate(test);
    showArr(test);
    space;

    {
        std::unique_ptr<Obliczator> oblicz = std::make_unique<Obliczator>();
        oblicz->tabInputParser(twoja_stara);
        oblicz->tabInputShow();
//        std::unique_ptr<Analizator> analizuj = std::make_unique<Analizator>();
//        space;
//        std::cout<<analizuj->retChar(oblicz->retCharacteristicNumber());
//        space;

//        std::cout<<analizuj->retChar(18);
//        space;
//        std::cout<<analizuj->retInt('t');
        space;
//        oblicz->targetToBinary(15);
        int a = 12;
        std::cout<<"target characteristic number is: "<<a<<"\n";
        oblicz->intInputParser(a);
        space;
//        oblicz->intShow();

    }
    return 0;
}
void randGenerator(int(*tab)[ROWS]){
    for (int i=0; i<COLS; i++) {
        for (int j=0; j<ROWS; j++) {
            tab[i][j]=rand()%2;
            std::this_thread::sleep_for(std::chrono::nanoseconds(rand()%4));
        }
        std::this_thread::sleep_for(std::chrono::nanoseconds(rand()%4));
    }
}
void showArr(int(*tab)[COLS]){
    for (int i=0; i<COLS; i++) {
        for (int j=0; j<ROWS; j++) {
            std::cout<<tab[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}
void zeroGenerate(int(*tab)[COLS]){
    for (int i=0; i<COLS; i++) {
        for (int j=0; j<ROWS; j++) {
            tab[i][j]=0;
        }
    }
}