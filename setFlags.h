#ifndef FLAG_H
#define FLAG_H
#include "header.h"
#include "validate.h"
#include "convert.h"
using namespace std;


void checkAuxiliary(int d1,int d2,int flagResgisters[]){
    int res = getLowerNibble(d1) + getLowerNibble(d2);
    if(res >= 16){
        flagResgisters[aux] = 1;
    }
    else{
        flagResgisters[aux] = 0;
    }
}
void checkZero(int n,int flagRegisters[]){
    if(n == 0)
    flagRegisters[zero] = 1;
    else
    flagRegisters[zero] = 0;
}
void checkParity(map<string,int> registers,int flagRegisters[]){
    int n = registers["A"],count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    if(count%2 == 0){
        flagRegisters[parity] = 1;
    }
    else{
        flagRegisters[parity] = 0;
    }
}
int checkCarry(int res,int flagRegisters[]){
    if(res > 255){
        flagRegisters[carry] = 1;
        res = res-256;
    }
    else if(res < 0){
        flagRegisters[carry] = 1;
        res = 256+res;
    }
    return res;
}

#endif
