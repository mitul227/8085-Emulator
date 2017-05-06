#ifndef SIZES_H
#define SIZES_H
using namespace std;
int getSize(string cmd){
    if(cmd == "MOV" || cmd == "ADD" || cmd == "SUB" || cmd == "XCHG" || cmd == "STAX" || cmd == "INR")
    return 1;
    else if(cmd == "INX" || cmd == "DCR" || cmd == "DCX" || cmd == "CMA" || cmd == "DAD" || cmd == "SET")
    return 1;
    else if(cmd == "CMP")
    return 1;
    else if(cmd == "MVI" || cmd == "ADI" || cmd == "SUI")
    return 2;
    else if(cmd == "LXI" || cmd == "LDA" || cmd == "LHLD" || cmd == "SHLD" || cmd == "STA")
    return 3;
    else if(cmd == "JMP" || cmd == "JC" || cmd == "JNC" || cmd == "JNZ" || cmd == "JZ")
    return 3;
    else
    return 0;
}
#endif
