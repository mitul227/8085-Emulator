#ifndef VALIDATE_H
#define VALIDATE_H
#include "header.h"
using namespace std;

bool validRegister(string r){
    if(r == "A" || r == "B" || r == "C" || r == "D" || r == "E" || r == "H" || r == "L")
    return true;
    else
    return false;
}
bool validData(int d){
    if(d >= 0 && d <= 255)
    return true;
    else
    return false;
}
bool validRegisterPair(string rp){
    if(rp == "B" || rp == "D" || rp == "H")
    return true;
    else
    return false;
}
bool validMemory(int m){
    if(m >= 0 && m <= 65535)
    return true;
    else
    return false;
}
#endif
