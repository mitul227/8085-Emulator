#ifndef CLASSIFY_H
#define CLASSIFY_H
#include "../header.h"
using namespace std;

char classify(string cmd){
    if(cmd == "MOV" || cmd == "MVI" || cmd == "LXI" || cmd == "LDA" || cmd == "LHLD" || cmd == "SHLD")
    return move;
    else if(cmd == "STAX" || cmd == "STA" || cmd == "XCHG" || cmd == "SET")
    return move;
    else if(cmd == "ADD" || cmd == "SUB" || cmd == "INR" || cmd == "INX" || cmd == "DCR" || cmd == "SUI")
    return arithmetic;
    else if(cmd == "DCX" || cmd == "ADI" || cmd == "DAD")
    return arithmetic;
    else if(cmd == "CMA" || cmd == "CMP")
    return logical;
    else if(cmd == "JMP" || cmd == "JC" || cmd == "JNC" || cmd == "JNZ" || cmd == "JZ")
    return branch;
}

#endif
