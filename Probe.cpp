
#include "Probe.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;

// Default constructor
Probe::Probe(){}

// Get the name of the Probe
string Probe::getName() const {
    return name;
}

// Get the ID of the Probe
int Probe::getID() const {
    return ID;
}

// Get a specific dimension of the Probe
int Probe::getDimension(int index) const {
    if (index == 0 || index == 1) {
        return dimensions[index];
    }
    return -1;
}

// Get the area of the Probe
double Probe::getArea() const {
    return area;
}

// Get a specific position of the Probe
int Probe::getPosition(int index) const {
    if (index == 0 || index == 1) {
        return positions[index];
    }
    return -1;
}

// Set the name of the Probe
void Probe::setName(const string& newName) {
    name = newName;
}

// Set the ID of the Probe
void Probe::setID(int newID) {
    ID = newID;
}

// Set a specific dimension of the Probe
void Probe::setDimension(int index, int value) {
    if (index == 0 || index == 1) {
        dimensions[index] = value;
        calculateArea();
    } else {
        throw out_of_range("Invalid index for dimension");
    }
}

// Set a specific position of the Probe
void Probe::setPosition(int index, int value) {
    if (index == 0 || index == 1) {
        positions[index] = value;
    } else {
        throw out_of_range("Invalid index for position");
    }
}



// Overload the << operator for copying Probe data
void Probe::operator<<(Probe& other){
    name = other.name;
    ID = other.ID;
    dimensions[0] = other.dimensions[0];
    dimensions[1] = other.dimensions[1];
    calculateArea();  //calculated area when dimention changes
    positions[0] = other.positions[0];
    positions[1] = other.positions[1];
}

// Overload the - operator for swapping Probe data
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
    //cout << endl <<  "Probe data swapped sucessfully." << endl << endl;
}

// Calculate the area of the Probe based on its dimensions
void Probe::calculateArea(){
    area = 2 * (dimensions[0] + dimensions[1]);
}

// Display the details of the Probe
void Probe::displayProbe() const{
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Dimensions: [" << dimensions[0] << ", " << dimensions[1] << "]" << endl;
    cout << "Area: " << area << endl;
    cout << "Positions: [" << positions[0] << ", " << positions[1] << "]" << endl;
}


