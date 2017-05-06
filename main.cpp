#include "header.h"
#include "initialize.h"
#include "process.h"
#include "display.h"
using namespace std;
int main(){
    map<int, pair<int,int> > memory;
    vector< pair< pair<string,string> , pair<string,string> > > instruction;
    map<string,int> registers;
    map<string,int> labels;
    bool set=true;
    int flagRegisters[5]={0};
    init(memory,instruction,registers,labels,set);             //initialize.h
    if(set && process(memory,instruction,registers,flagRegisters,labels)){      //process.h
        displayResults(memory,registers,flagRegisters);
    }
    else{
        cout<<"\n\n ----- Sorry There is An Error In Your Program ----- \n";
    }
    cout<<"\n\n";
    map<int, pair<int,int> >::iterator it;
    for(it=memory.begin();it!=memory.end();it++){
        int index = it->second.second;
        char c=' ';
        if(index != -1){
            if(instruction[index].first.first != "")
            c = ':';
            cout<<hex<<it->first<<" "<<instruction[index].first.first<<c<<instruction[index].first.second<<" "<<instruction[index].second.first<<" "<<instruction[index].second.second<<endl;
        }
    }
    return 0;
}
