
#include "Galaxy.h"
#include <iostream>

using namespace std;

void swapProbes(Probe& a, Probe& b)
{
    Probe temp = a;
    a = b;
    b = temp;
}

Galaxy::Galaxy(){

}

void Galaxy::add_Probe(Probe pro){
    probs.push_back(pro);
}

Probe Galaxy::retrieve(int index){
    return probs[index];
}


void Galaxy::sortByName(){
    for (int i = 0; i < probs.size(); ++i) {
        for (int j = 0; j < probs.size() - 1 - i; ++j) {
            if (probs[j].getName() > probs[j + 1].getName()) {
                swap(probs[j], probs[j + 1]);
            }
        }
    }
    cout << "Current order of probes" << endl;

    for (int i = 0; i < probs.size(); ++i ) {
        cout << i + 1 << ". " << probs[i].getName() << endl;
    }
}


void Galaxy::sortByID(){
    for (int i = 0; i < probs.size(); ++i) {
        for (int j = 0; j < probs.size() - 1 - i; ++j) {
            if (probs[j].getID() > probs[j + 1].getID()) {
                swap(probs[j], probs[j + 1]);
            }
        }
    }
        cout << "Current order of probes" << endl;

    for (int i = 0; i < probs.size(); ++i ) {
        cout << i + 1 << ". " << probs[i].getName() << "(ID: " << probs[i].getID() << ")" << endl;
    }
}


void Galaxy::displayProbe(int index){
    probs[index].displayProbe();
}

 
 void Galaxy::sortByarea()
{
    // This matches your provided sortByArea function
    for (int i = 0; i < probs.size() - 1; ++i)
    {
        for (int j = 0; j < probs.size() - i - 1; ++j)
        {
            if (probs[j].getArea() > probs[j + 1].getArea())
            {
                swapProbes(probs[j], probs[j + 1]);
            }
        }
    }
}



int binarySearchByName(const std::vector<Probe>& probes, const std::string& name)
{
    int left = 0;
    int right = probes.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (probes[mid].getName() == name)
            return mid;
        if (probes[mid].getName() < name)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Probe not found
}
Probe Galaxy::searchProbeByName(const std::string& name)
{
    sortByName();  // Sort by name before performing binary search
    int index = binarySearchByName(probs, name);

    if (index != -1)
    {
        return probs[index];
    }
    else
    {
        std::cerr << "Probe not found by name: " << name << std::endl;
        return Probe();  // Return an empty Probe
    }
}

int binarySearchByID(const vector<Probe>& probes, int id)
{
    int left = 0;
    int right = probes.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (probes[mid].getID() == id)
            return mid;
        if (probes[mid].getID() < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Probe not found
}

int binarySearchByID(const std::vector<Probe>& probes, int id)
{
    int left = 0;
    int right = probes.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (probes[mid].getID() == id)
            return mid;
        if (probes[mid].getID() < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Probe not found
}

void Galaxy::swapProbeData(int idx1, int idx2){

}
void Galaxy::insertProbeData(int galaxyIdx, int probeIdx, int value){
    
}

void Galaxy::randomizeOrder(){

}

void Galaxy::printAllNames(){
    cout << "All Probe Names: " << endl;
    
    for(int i = 0 ; i < 10 ; i++){
        cout << i << ". " << probs[i].getName() << endl;
    }
}

void Galaxy::writeGalaxyToFile(){

}