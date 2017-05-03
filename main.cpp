#include "header.h"
#include "initialize.h"
#include "process.h"
#include "display.h"
using namespace std;
int main(){
    map<int, pair<int,int> > memory;
    vector< pair<string, pair<string,string> > > instruction;
    map<string,int> registers;
    int flagRegisters[5]={0};
    init(memory,instruction,registers);             //initialize.h
    if(process(memory,instruction,registers,flagRegisters)){      //process.h
        displayResults(memory,registers,flagRegisters);
    }
    else{
        cout<<"\n\n ----- Sorry There is An Error In Your Program ----- \n";
    }
    cout<<"\n\n";
    map<int, pair<int,int> >::iterator it;
    for(it=memory.begin();it!=memory.end();it++){
        int index = it->second.second;
        if(index != -1){
            cout<<hex<<it->first<<" "<<instruction[index].first<<" "<<instruction[index].second.first<<" "<<instruction[index].second.second<<endl;
        }
    }
    return 0;
}
