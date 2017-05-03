#ifndef MOVE_H
#define MOVE_H
#include "../header.h"
#include "../validate.h"
#include "../convert.h"
#include "../setFlags.h"
using namespace std;
bool doMove(string cmd,string op1,string op2, map<int, pair<int,int> > &memory, map<string,int> &registers,int flagRegisters[]){
    bool result=true;

    if(cmd == "SET"){
        int mem = convertToDecimal(op1);
        int data = convertToDecimal(op2);
        //cout<<mem<<" "<<data<<endl;
        if(validMemory(mem) && validData(data)){
            memory[mem] = make_pair(data,-1);
        }
        else
        result = false;
    }

    else if(cmd == "MOV"){
        if(validRegister(op1) && validRegister(op2)){     //validate.h
            registers[op1] = registers[op2];
        }
        else if(op1 == "M" && validRegister(op2)){
            int mem = getMemoryFromRegPair("H","L",registers);
            memory[mem] = make_pair(registers[op2],-1);
        }
        else if(validRegister(op1) && op2 == "M"){
            int mem = getMemoryFromRegPair("H","L",registers);
            if(memory.find(mem) != memory.end())
            registers[op1] = memory[mem].first;
            else
            registers[op1] = 0;
        }
        else
        result = false;
    }

    else if(cmd == "MVI"){
        int data = convertToDecimal(op2);               //convert.h
        if(validRegister(op1) && validData(data)){           //validate.h
            registers[op1] = data;
        }
        else if(op1 == "M" && validData(data)){
            int mem = getMemoryFromRegPair("H","L",registers);
            //cout<<mem<<endl;
            memory[mem] = make_pair(data,-1);
        }
        else
        result = false;
    }

    else if(cmd == "LXI"){
        int mem1 = convertToDecimal(op2.substr(0,2));       //convert.h
        int mem2 = convertToDecimal(op2.substr(2));
        string rp2;
        if(validRegisterPair(op1) && validMemory(mem1) && validMemory(mem2)){         //validate.h
            if(op1 == "B")
            rp2 = "C";
            else if(op1 == "D")
            rp2 = "E";
            else
            rp2 = "L";
            registers[op1] = mem1;
            registers[rp2] = mem2;
        }
        else
        result = false;
    }

    else if(cmd == "LDA"){
        int mem = convertToDecimal(op1);
        //cout<<mem<<endl;
        if(validMemory(mem) && op2 == ""){
            registers["A"] = memory[mem].first;
        }
        else
        result = false;
    }

    else if(cmd == "LHLD"){
        int mem = convertToDecimal(op1);
        if(validMemory(mem) && op2 == ""){
            registers["L"] = memory[mem].first;
            registers["H"] = memory[mem+1].first;
        }
        else
        result = false;
    }

    else if(cmd == "SHLD"){
        int mem = convertToDecimal(op1);
        if(validMemory(mem) && op2 == ""){
            memory[mem] = make_pair(registers["L"],-1);
            memory[mem+1] = make_pair(registers["H"],-1);
        }
        else
        result = false;
    }

    else if(cmd == "STA"){
        int mem = convertToDecimal(op1);
        if(validMemory(mem) && op2 == ""){
            memory[mem] = make_pair(registers["A"],-1);
        }
        else
        result = false;
    }

    else if(cmd == "XCHG"){
        if(op1 == "" && op2 == ""){
            int temp = registers["D"];
            registers["D"] = registers["H"];
            registers["H"] = temp;
            temp = registers["L"];
            registers["L"] = registers["E"];
            registers["E"] = temp;
        }
    }

    else if(cmd == "STAX"){
        if( (op1 == "B" || op1 == "D") && op2 == ""){
            if(op1 == "B")
            op2 = "C";
            else
            op2 = "E";
            int mem = getMemoryFromRegPair(op1,op2,registers);
            memory[mem] = make_pair(registers["A"],-1);
        }
        else
        result = false;
    }

    else
    result = false;

    return result;
}
#endif
