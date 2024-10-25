
#include "Probe.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;

Probe::Probe(){}

string Probe::getName() const {
    return name;
}

int Probe::getID() const {
    return ID;
}

int Probe::getDimension(int index) const {
    if (index == 0 || index == 1) {
        return dimensions[index];
    }
    return -1;
}

double Probe::getArea() const {
    return area;
}

int Probe::getPosition(int index) const {
    if (index == 0 || index == 1) {
        return positions[index];
    }
    return -1;
}

void Probe::setName(const string& newName) {
    name = newName;
}

void Probe::setID(int newID) {
    ID = newID;
}

void Probe::setDimension(int index, int value) {
    if (index == 0 || index == 1) {
        dimensions[index] = value;
        calculateArea();
    } else {
        throw out_of_range("Invalid index for dimension");
    }
}

void Probe::setPosition(int index, int value) {
    if (index == 0 || index == 1) {
        positions[index] = value;
    } else {
        throw out_of_range("Invalid index for position");
    }
}




void Probe::operator<<(Probe& other){
    name = other.name;
    ID = other.ID;
    dimensions[0] = other.dimensions[0];
    dimensions[1] = other.dimensions[1];
    calculateArea();  //calculated area when dimention changes
    positions[0] = other.positions[0];
    positions[1] = other.positions[1];
}

void Probe::operator-(Probe& other){
    // swap
    string name_temp;
    int num_temp, d0, d1, p0, p1;

    name_temp = other.getName();
    d0 = other.getDimension(0);
    d1 = other.getDimension(1);
    p0 = other.getPosition(0);
    p1 = other.getPosition(1);

    other.setName(getName());
    other.setDimension(0, getDimension(0));
    other.setDimension(1, getDimension(1));
    other.setPosition(0, getPosition(0));
    other.setPosition(1, getPosition(1));
    other.calculateArea();

    setName(name_temp);
    setDimension(0, d0);
    setDimension(1, d1);
    setPosition(0, p0);
    setPosition(1, p1);
    calculateArea();

    cout << endl <<  "Probe data swapped sucessfully." << endl << endl;
}


void Probe::calculateArea(){
    area = 2 * (dimensions[0] * dimensions[1]);
}

void Probe::displayProbe() const{
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Dimensions: [" << dimensions[0] << ", " << dimensions[1] << "]" << endl;
    cout << "Area: " << area << endl;
    cout << "Positions: [" << positions[0] << ", " << positions[1] << "]" << endl;
}

void randomizeProbes(vector<Probe>& probs) {
   
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < probs.size(); ++i) {
        // Generate a random index between i and the end of the array
        size_t randomIndex = i + std::rand() % (probs.size() - i);
        // Swap the current element with the randomly chosen element
    swap(probs[i], probs[randomIndex]);
    }
    
    cout << "Probes have been randomized." << endl;
}