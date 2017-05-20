#ifndef DISPLAY_H
#define DISPLAY_H
#include "header.h"

using namespace std;
void displayResults(map<int, pair<int,int> > memory , map<string,int> registers,int flagRegisters[]){

    map<string,int>::iterator itReg;
    cout<<"\n\n----- REGISTERS -----\n\n";
    for(itReg=registers.begin();itReg != registers.end(); itReg++){
        cout<<itReg->first<<" -> "<<hex<<itReg->second<<endl;
    }

    map<int, pair<int,int> >::iterator itMem;
    cout<<"\n\n----- MEMORY -----\n\n";
    for(itMem=memory.begin();itMem != memory.end(); itMem++){
        if(itMem->second.second == -1){
           cout<<itMem->first<<" -> "<<hex<<itMem->second.first<<endl;
        }
    }

    cout<<"\n\n----- FLAG REGISTERS -----\n\n";
    cout<<"Sign Flag \t->\t "<<flagRegisters[sign]<<endl;
    cout<<"Zero Flag \t->\t "<<flagRegisters[zero]<<endl;
    cout<<"Auxiliary Flag \t->\t "<<flagRegisters[aux]<<endl;
    cout<<"Parity Flag \t->\t "<<flagRegisters[parity]<<endl;
    cout<<"Carry Flag \t->\t "<<flagRegisters[carry]<<endl;
}
#endif
