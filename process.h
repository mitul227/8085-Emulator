#ifndef PROCESS_H
#define PROCESS_H
#include "header.h"
#include "Commands/classifyCmd.h"
#include "Commands/moveCommands.h"
#include "Commands/arithmeticCommands.h"
#include "Commands/logicalCommands.h"
#include "Commands/branchingCommands.h"
#include "setFlags.h"

using namespace std;
bool process(map<int, pair<int,int> > &memory , vector< inst > &instruction, map<string,int> &registers,int flagRegisters[],map<string,int> labels){
    map<int, pair<int,int> >::iterator it;
    bool result=true;
    int lineNo = 1;
    for(it=memory.begin(); it != memory.end(); ){
        if( !validMemory(it->first) && it->second.second != -1){
            cout<<"\nSorry your Program doesn't fit in Memory\n";
            return false;
        }
        int index = it->second.second;
        string label,cmd,op1,op2;
        if(index != -1){
            label = instruction[index].first.first;
            cmd = instruction[index].first.second;
            op1 = instruction[index].second.first;
            op2 = instruction[index].second.second;
            char cmdType = classify(cmd);
            if(cmdType == move){          //classsifyCmd.h
                result = result && doMove(cmd,op1,op2,memory,registers,flagRegisters,instruction);   //moveCommands.h
                it++;
            }
            else if(cmdType == arithmetic){
                result = result && doArt(cmd,op1,op2,memory,registers,flagRegisters);
                it++;
            }
            else if(cmdType == logical){
                result = result && doLogical(cmd,op1,op2,memory,registers,flagRegisters);
                it++;
            }
            else if(cmdType == branch){
                result = result && doBranch(cmd,op1,op2,memory,registers,flagRegisters,it,labels);
            }
            else{
                cout<<"Error at Line No : "<<lineNo<<" -> "<<label<<" "<<cmd<<" "<<op1<<" "<<op2<<endl;
                return false;
            }


            if(result == false){
                cout<<"Error at Line No : "<<lineNo<<" -> "<<label<<" "<<cmd<<" "<<op1<<" "<<op2<<endl;
                return false;
            }
            lineNo++;
        }
        else{
            it++;
        }
    }
    return result;
}
#endif
