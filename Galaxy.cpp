
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

void Galaxy::sortByID(){
    for (int i = 0; i < probs.size(); ++i) {
        for (int j = 0; j < probs.size() - 1 - i; ++j) {
            if (probs[j].getID() > probs[j + 1].getID()) {
                swap(probs[j], probs[j + 1]);
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
        cout << endl << "Probe found: " << endl;
        probs[index].displayProbe();
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
        cout << "Probe at index " << idx1 << ":" << endl;
        probs[idx1].displayProbe();
        cout << endl << "Probe at index " << idx2 << ":" << endl;
        probs[idx2].displayProbe();
    }
    else
    {
        std::cerr << "Index out of range." << std::endl;
    }
}



void Galaxy::insertProbeData(int probs_index, int dim_pos, int options, int value) {
    // Check for valid galaxy index and probe index
    if (probs_index < 0 || probs_index > 10 || dim_pos > 1 || dim_pos < 0 || options > 1 || options < 0) {  // Only two dimensions
        std::cerr << "Error: Invalid index." << std::endl;
        return;
    }

    // Determine if we are inserting into dimensions or positions
    if(dim_pos == 0){
        // dim
        probs[probs_index].setDimension(options, value);
    }
    else{
        probs[probs_index].setPosition(options, value);
    }
}

void Galaxy::printAllNames(){
    for(int i = 0 ; i < 10 ; i++){
        cout << i+1 << ". " << probs[i].getName() << endl;
    }
}

void Galaxy::copyProbe(int src, int dest){
    probs[dest].setName(probs[src].getName());
}