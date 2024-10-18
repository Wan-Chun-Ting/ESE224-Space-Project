

#include <array>
#include <string>

using namespace std;
class Probe{
    private:
        string name;
        int ID;
        array<int, 2> dimensions;
        double area;
        array<int, 2> positions;
    public:
        Probe(string n = "", int id = -1, array<int, 2> dim = {-1, -1}, double ar = -1, array<int, 2> pos = {-1, -1});

        void operator<<(Probe& p2);
        void operator-(Probe& p2);

        void calculateArea();
        void displayProbe();

        //need accessor and mutated methods
};