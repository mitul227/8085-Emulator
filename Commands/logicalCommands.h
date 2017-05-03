#ifndef LOGICAL_H
#define LOGICAL_H
#include "../header.h"
#include "../validate.h"
#include "../setFlags.h"
using namespace std;
bool doLogical(string cmd,string op1,string op2,map<int, pair<int,int> > &memory,map<string,int> &registers,int flagRegisters[]){
    bool result = true;
    if(cmd == "CMA"){
        if(op1 == "" && op2 == ""){
            registers["A"] = 255-registers["A"];
        }
        else
        result = false;
    }

    else if(cmd == "CMP"){
        if(validRegister(op1) && op2 == ""){
            int d1 = registers["A"];
            int d2 = registers[op1];
            if(d1 == d2){
                flagRegisters[zero] = 1;
            }
            else if(d1 < d2){
                flagRegisters[carry] = 1;
            }
            else{
                flagRegisters[carry] = 0;
                flagRegisters[zero] = 0;
            }
        }
        else if(op1 == "M" && op2 == ""){
            int mem = getMemoryFromRegPair("H","L",registers);
            int d1 = registers["A"];
            int d2 = memory[mem].first;
            if(d1 == d2){
                flagRegisters[zero] = 1;
            }
            else if(d1 < d2){
                flagRegisters[carry] = 1;
            }
            else{
                flagRegisters[carry] = 0;
                flagRegisters[zero] = 0;
            }
        }
        else
        result = false;
    }

    else
    result = false;

    return result;
}
#endif
