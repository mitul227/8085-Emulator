#ifndef CONVERT_H
#define CONVERT_H
#include "header.h"
using namespace std;
int convertToDecimal(string op){
    int i,d,num=0,b=1;
    if(op == "")
    return -1;

    for(i=op.size()-1;i>=0;i--){
        if(op[i] == 'F' || op[i] == 'f')
        d=15;
        else if(op[i] == 'E' || op[i] == 'e')
        d=14;
        else if(op[i] == 'D' || op[i] == 'd')
        d=13;
        else if(op[i] == 'C' || op[i] == 'c')
        d=12;
        else if(op[i] == 'B' || op[i] == 'b')
        d=11;
        else if(op[i] == 'A' || op[i] == 'a')
        d=10;
        else if(op[i] >= '0' && op[i] <= '9')
        d=op[i]-'0';
        else
        return -1;

        num += d*b;
        b=b*16;
    }
    return num;
}

int getMemoryFromRegPair(string op1,string op2,map<string,int> registers){
    stringstream memHex;
    int d2 = registers[op2];
    memHex<<hex<<registers[op1];
    if(d2 < 16)
    memHex<<hex<<0<<d2;
    else
    memHex<<hex<<d2;
    int mem = convertToDecimal(memHex.str());
    return mem;
}

int getLowerNibble(int n){
    stringstream dataHex;
    dataHex<<hex<<n;
    string low = "";
    string data = dataHex.str();
    low += data[data.size()-1];
    int l = convertToDecimal(low);
    return l;
}

#endif
