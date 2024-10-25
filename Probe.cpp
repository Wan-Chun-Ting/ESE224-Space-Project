
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
    int num_temp;
    double area_temp;
    array<int, 2> d_temp;
    array<int, 2> p_temp;

    
    other.name = name_temp;
    other.ID = num_temp;
    other.dimensions = d_temp;
    other.area = area_temp;
    other.positions = p_temp;

    other.name = name;
    other.ID = ID;
    other.dimensions = dimensions;
    other.area = area;
    other.positions = positions;
    
    name = name_temp;
    ID = num_temp;
    dimensions = d_temp;
    area = area_temp;
    positions = p_temp;

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

