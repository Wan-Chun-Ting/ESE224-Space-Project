
#include "Galaxy.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <vector>



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
    cout << "Current order of probes: " << endl;
    for (int i = 0; i < probs.size(); ++i ) {
        cout << i + 1 << ". " << probs[i].getName() << "(Area: " << probs[i].getArea() << ")" << endl;
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
        cout << endl << "Probe found: " << endl;
        probs[index].displayProbe();
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


void Galaxy::randomizeOrder(){
   
    double a;
    int randomNumber;

    a = time(0) * 0.036; 

    for (int i = 0; i < 10; i++) {

        a = 0.29 * (a - 360) + 63.6;

        randomNumber = static_cast<int>(a) % 10 + 1;  

        swapProbeData(randomNumber, 10-randomNumber);
    }
    
}

void Galaxy::writeGalaxyToFile(){
    fstream OutputFile("Galaxy.txt");
    for(int i = 0 ; i < 10 ; i++){
        OutputFile << probs[i].getName() << endl
        << probs[i].getID() << endl
        << probs[i].getDimension(0) << endl << probs[i].getDimension(1) << endl
        << probs[i].getPosition(0) << endl << probs[i].getPosition(1) << endl
        << probs[i].getArea() << endl << endl;
    }
}

vector<int> Galaxy::collision_detection(int index){

    vector<int> result;

    double upper, lower, source_upper, source_lower, samller_area;

    source_upper = probs[index].getPosition(1) + (probs[index].getDimension(1) / 2);
    source_lower = probs[index].getPosition(1) - (probs[index].getDimension(1) / 2);

    for(int i = 0 ; i < 10 ; i++){
        if( i != index){
            upper = probs[i].getPosition(1) + (probs[i].getDimension(1) / 2);
            lower = probs[i].getPosition(1) - (probs[i].getDimension(1) / 2);

            if(probs[i].getArea() <= probs[index].getArea()){
                samller_area = probs[i].getArea();
            }
            else{
                samller_area = probs[index].getArea();
            }
            
            if(source_upper >= lower && (source_upper - lower) <= samller_area){
                result.push_back(i);
            }
            else if (source_lower <= upper && (upper - source_lower) <= samller_area) {
                result.push_back(i);
            }
        }
    }
    return result;
}

void Galaxy::copyProbe(int src, int dest){
    probs[dest] = probs[src];
}