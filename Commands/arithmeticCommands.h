#ifndef ART_H
#define ART_H
#include "../header.h"
#include "../validate.h"
#include "../setFlags.h"
#include "../convert.h"
using namespace std;
bool doArt(string cmd,string op1,string op2,map<int, pair<int,int> > &memory,map<string,int> &registers,int flagRegisters[]){
    bool result=true;
    if(cmd == "ADD"){
        if(validRegister(op1) && op2 == ""){     //validate.h
            int res = registers["A"] + registers[op1];
            int temp = registers["A"];
            res = checkCarry(res,flagRegisters);
            registers["A"] = res;
            checkParity(registers,flagRegisters);
            checkZero(registers["A"],flagRegisters);
            checkAuxiliary(temp,registers[op1],flagRegisters);
        }
        else if(op1 == "M" && op2 == ""){
            int mem = getMemoryFromRegPair("H","L",registers);
            int temp = registers["A"];
            int res = registers["A"] + memory[mem].first;
            res = checkCarry(res,flagRegisters);
            registers["A"] = res;
            checkParity(registers,flagRegisters);
            checkZero(registers["A"],flagRegisters);
            checkAuxiliary(temp,memory[mem].first,flagRegisters);
        }
        else
        result = false;
    }

    else if(cmd == "SUB"){
        if(validRegister(op1) && op2 == ""){           //validate.h
            int res = registers["A"] - registers[op1];
            if(res < 0){
                flagRegisters[sign] = 1;
            }
            res = checkCarry(res,flagRegisters);
            registers["A"] = res;
            checkParity(registers,flagRegisters);
            checkZero(registers["A"],flagRegisters);
        }
        else if(op1 == "M" && op2 == ""){
            int mem = getMemoryFromRegPair("H","L",registers);
            int res = registers["A"] - memory[mem].first;
            if(res < 0){
                flagRegisters[sign] = 1;
            }
            res = checkCarry(res,flagRegisters);
            registers["A"] = res;
            checkParity(registers,flagRegisters);
            checkZero(registers["A"],flagRegisters);
        }
        else
        result = false;
    }

    else if(cmd == "INR"){
        if(validRegister(op1) && op2 == ""){
            int res = registers[op1]+1;
            if(res >=0 && op1 == "A")
            flagRegisters[sign] = 0;
            if(res > 255){
                res = 0;
            }
            registers[op1] = res;
            checkParity(registers,flagRegisters);
            checkZero(registers[op1],flagRegisters);
        }
        else if(op1 == "M" && op2 == ""){
            int mem = getMemoryFromRegPair("H","L",registers);
            int res = memory[mem].first + 1;
            if(res > 255){
                res = 0;
            }
            memory[mem].first = res;
            memory[mem].second = -1;
        }
        else
        result = false;
    }

    else if(cmd == "DCR"){
        if(validRegister(op1) && op2 == ""){
            int res = registers[op1]-1;
            if(res < 0){
                res = 255;
                if(op1 == "A"){
                    flagRegisters[sign] = 1;
                }
            }
            registers[op1] = res;
            checkParity(registers,flagRegisters);
            checkZero(registers[op1],flagRegisters);
        }
        else if(op1 == "M" && op2 == ""){
            int mem = getMemoryFromRegPair("H","L",registers);
            int res = memory[mem].first - 1;
            if(res < 0){
                res = 255;
            }
            memory[mem].first = res;
            memory[mem].second = -1;
        }
        else
        result = false;
    }

    else if(cmd == "INX"){
        if(validRegisterPair(op1) && op2 == ""){
            stringstream memHexStream;
            if(op1 == "H")
            op2 = "L";
            else if(op1 == "B")
            op2 = "C";
            else
            op2 = "E";
            int mem = getMemoryFromRegPair(op1,op2,registers);          //convert.h
            mem += 1;
            if( mem > 65535 ){
                mem = 0;
            }
            memHexStream<<hex<<mem;
            string memHex = memHexStream.str();
            int r1,r2;
            //cout<<memHex<<endl;
            if(memHex.size() <= 2){
                r1 = 0;
                r2 = convertToDecimal(memHex);
            }
            else if(memHex.size() > 2){
                r1 = convertToDecimal(memHex.substr(0,memHex.size()-2));
                r2 = convertToDecimal(memHex.substr(memHex.size()-2));
            }
            registers[op1] = r1;
            registers[op2] = r2;
        }
        else
        result = false;
    }

    else if(cmd == "DCX"){
        if(validRegisterPair(op1) && op2 == ""){
            stringstream memHexStream;
            if(op1 == "H")
            op2 = "L";
            else if(op1 == "B")
            op2 = "C";
            else
            op2 = "E";
            int mem = getMemoryFromRegPair(op1,op2,registers);
            mem -= 1;
            if( mem < 0 ){
                mem = 65535;
            }
            memHexStream<<hex<<mem;
            string memHex = memHexStream.str();
            int r1,r2;
            //cout<<memHex<<endl;
            if(memHex.size() <= 2){
                r1 = 0;
                r2 = convertToDecimal(memHex);
            }
            else if(memHex.size() > 2){
                r1 = convertToDecimal(memHex.substr(0,memHex.size()-2));
                r2 = convertToDecimal(memHex.substr(memHex.size()-2));
            }
            registers[op1] = r1;
            registers[op2] = r2;
        }
        else
        result = false;
    }

    else if(cmd == "ADI"){
        int d = convertToDecimal(op1);
        if(validData(d) && op2 == ""){
            int res = registers["A"] + d;
            if(res >= 0)
            flagRegisters[sign] = 0;
            int temp = registers["A"];
            res = checkCarry(res,flagRegisters);
            registers["A"] = res;
            checkParity(registers,flagRegisters);
            checkZero(registers["A"],flagRegisters);
            checkAuxiliary(temp,d,flagRegisters);
        }
        else
        result = false;
    }

    else if(cmd == "SUI"){
        int d = convertToDecimal(op1);
        if(validData(d) && op2 == ""){
            int res = registers["A"] - d;
            if(res < 0)
            flagRegisters[sign] = 1;
            int temp = registers["A"];
            res = checkCarry(res,flagRegisters);
            registers["A"] = res;
            checkParity(registers,flagRegisters);
            checkZero(registers["A"],flagRegisters);
            checkAuxiliary(temp,d,flagRegisters);
        }
        else
        result = false;
    }

    else if(cmd == "DAD"){
        if(validRegisterPair(op1) && op2 == ""){
            int sum = registers["E"] + registers["L"],c=0;
            if(sum > 255){
                sum = sum-256;
                c=1;
            }
            registers["L"] = sum;
            sum = registers["H"] + registers["D"] + c;
            sum = checkCarry(sum,flagRegisters);
            registers["H"] = sum;
        }
        else
        result = false;
    }

    else
    result = false;

    return result;
}

#endif
