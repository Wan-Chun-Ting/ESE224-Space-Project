
#include "Probe.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;

Probe::Probe(std::string n, int id, std::array<int, 2> dim, double ar, array<int, 2> pos) : name(n), ID(id), dimensions(dim), area(ar), positions(pos){
    calculateArea();
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

void Probe::displayProbe(){
    cout << name << " with id: " << ID << endl;
    cout << "with width: " << dimensions[0] << " and length: " << dimensions[1] << endl;
    cout << "Located at x: " << positions[0] << "and y: " << positions[1] << endl;
}