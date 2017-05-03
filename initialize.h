#ifndef INITIALIZE_H
#define INITIALIZE_H
#include "header.h"
#include "Commands/sizes.h"
#include "validate.h"
using namespace std;
void setRegisters(map<string,int> &registers){
    registers["A"] = 0;
    registers["B"] = 0;
    registers["C"] = 0;
    registers["D"] = 0;
    registers["E"] = 0;
    registers["H"] = 0;
    registers["L"] = 0;
}
void init(map<int, pair<int,int> > &memory ,vector< pair<string, pair<string,string> > > &instruction, map<string,int> &registers){
    ifstream ip;
    string line,command,operands,op1,op2;
    int memLoc,pos,index=0;
    setRegisters(registers);
    ip.open("ip.txt");
    while(1){
        cout<<"Enter Memory Location to start with : "<<endl;
        cin>>hex>>memLoc;
        //cout<<memLoc<<endl;
        if( !validMemory(memLoc) ){
            cout<<"\n -- Please Enter a Valid Memory Location -- \n\n";
        }
        else
        break;
    }
    //memLoc = 2000;
    //cout<<hex<<memLoc<<endl;
    while( !ip.eof() ){
        getline(ip,line);
        if(line != ""){
            pos = line.find(' ');
            if(pos == -1){
                command = line;
                op1 = "";
                op2 = "";
            }
            else{
                command = line.substr(0,pos);
                operands = line.substr(pos+1);
                pos = operands.find(',');
                if(pos == -1){
                    op1 = operands;
                    op2 = "";
                }
                else{
                    op1 = operands.substr(0,pos);
                    op2 = operands.substr(pos+1);
                }
            }
            instruction.push_back(make_pair(command,make_pair(op1,op2)));
            memory[memLoc] = make_pair(0,index);
            index++;
            memLoc += getSize(command);
        }
        //cout<<line<<" h"<<endl;
    }
}
#endif

