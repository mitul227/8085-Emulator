#ifndef BRANCH_H
#define BRANCH_H
#include "../header.h"
using namespace std;

bool doBranch(string cmd,string op1,string op2, map<int, pair<int,int> > &memory, map<string,int> &registers,int flagRegisters[],map<int, pair<int,int> > ::iterator &it,map<string,int> labels){
    bool result = true;

    if(cmd == "JMP"){
        int mem = convertToDecimal(op1);
        if(validMemory(mem) && op2 == ""){
            it = memory.find(mem);
        }
        else if(labels.find(op1) != labels.end() && op2 == ""){
            int memLoc = labels[op1];
            it = memory.find(memLoc);
        }
        else
        result = false;
    }

    else if(cmd == "JC"){
        int mem = convertToDecimal(op1);
        if(validMemory(mem) && op2 == ""){
            if( flagRegisters[carry] == 1 )
            it = memory.find(mem);
            else
            it++;
        }
        else if(labels.find(op1) != labels.end() && op2 == ""){
            int memLoc = labels[op1];
            if( flagRegisters[carry] == 1 )
            it = memory.find(memLoc);
            else
            it++;
        }
        else
        result = false;
    }

    else if(cmd == "JNC"){
        int mem = convertToDecimal(op1);
        if(validMemory(mem) && op2 == ""){
            if( flagRegisters[carry] == 0 )
            it = memory.find(mem);
            else
            it++;
        }
        else if(labels.find(op1) != labels.end() && op2 == ""){
            int memLoc = labels[op1];
            if( flagRegisters[carry] == 0 )
            it = memory.find(memLoc);
            else
            it++;
        }
        else
        result = false;
    }

    else if(cmd == "JZ"){
        int mem = convertToDecimal(op1);
        if(validMemory(mem) && op2 == ""){
            if( flagRegisters[zero] == 1 )
            it = memory.find(mem);
            else
            it++;
        }
        else if(labels.find(op1) != labels.end() && op2 == ""){
            int memLoc = labels[op1];
            if( flagRegisters[zero] == 1 )
            it = memory.find(memLoc);
            else
            it++;
        }
        else
        result = false;
    }

    else if(cmd == "JNZ"){
        int mem = convertToDecimal(op1);
        if(validMemory(mem) && op2 == ""){
            if( flagRegisters[zero] == 0 )
            it = memory.find(mem);
            else
            it++;
        }
        else if(labels.find(op1) != labels.end() && op2 == ""){
            int memLoc = labels[op1];
            if( flagRegisters[zero] == 0 )
            it = memory.find(memLoc);
            else
            it++;
        }
        else
        result = false;
    }

    else
    result = false;

    return result;
}

#endif
