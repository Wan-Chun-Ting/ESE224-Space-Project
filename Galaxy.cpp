
#include "Galaxy.h"
#include <iostream>

using namespace std;

Galaxy::Galaxy(){

}

void Galaxy::add_Probe(Probe pro){
    probs.push_back(pro);
}

Probe Galaxy::retrieve(int index){
    return probs[index];
}


void Galaxy::sortByName(){
    cout << "Current order of probes" << endl;
}