
#include "Probe.h"
#include <iostream>

using namespace std;

Probe::Probe(std::string n, int id, std::array<int, 2> dim, double ar, array<int, 2> pos)
    : name(n), ID(id), dimensions(dim), area(ar), positions(pos){

}

void Probe::calculateArea(){
    area = 2 * (dimensions[0] * dimensions[1]);
}