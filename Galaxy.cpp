
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
    cout << "Current order of probs: " << endl;
}

void Galaxy::displayProbe(int index){
    probs[index].displayProbe();
}

 

void Galaxy::sortByarea() {
    for (int i = 0; i < probs.size() - 1; ++i) {
        for (int j = 0; j < probs.size() - i - 1; ++j) {
            if (probs[j].getArea() > probs[j + 1].getArea()) {
                swapProbes(probs[j], probs[j + 1]);
            }
        }
    }
}



int binarySearchByName(const vector<Probe>& probs, const std::string& name)
{
    int left = 0;
    int right = probs.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (probs[mid].getName() == name)
            return mid;
        if (probs[mid].getName() < name)
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


int binarySearchByID(const vector<Probe>& probs, int id)
{
    int left = 0;
    int right = probs.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (probs[mid].getID() == id)
            return mid;
        if (probs[mid].getID() < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Probe not found
}

Probe Galaxy::searchProbeByID(int id)
{
    sortByID();  // Sort by ID before performing binary search
    int index = binarySearchByID(probs, id);

    if (index != -1)
    {
        return probs[index];
    }
    else
    {
        std::cerr << "Probe not found by ID: " << id << std::endl;
        return Probe();  // Return an empty Probe
    }
}
void Galaxy::swapProbeData(int idx1, int idx2)
{
    if (idx1 >= 0 && idx1 < probs.size() && idx2 >= 0 && idx2 < probs.size())
    {
        // Use the overloaded '-' operator to swap dimensions, positions, and areas
        probs[idx1] - probs[idx2];  
    }
    else
    {
        std::cerr << "Index out of range." << std::endl;
    }
}



void Galaxy::insertProbeData(int galaxyIdx, int probeIdx, int value) {
    // Check for valid galaxy index and probe index
    if (galaxyIdx < 0 || galaxyIdx >= probs.size() || 
        probeIdx < 0 || probeIdx > 1) {  // Only two dimensions
        std::cerr << "Error: Invalid index." << std::endl;
        return;
    }

    // Determine if we are inserting into dimensions or positions
    if (galaxyIdx < 2) {
        probs[galaxyIdx].setDimension(galaxyIdx, value);
    } else {
        probs[galaxyIdx].setPosition(probeIdx, value);
    }
}

