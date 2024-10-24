

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

    string getName() const;
    int getID() const;
    int getDimension(int index) const;
    double getArea() const;
    int getPosition(int index) const;

    // Mutator methods
    void setName(const std::string& newName);
    void setID(int newID);
    void setDimension(int index, int value);
    void setPosition(int index, int value);

    // Other methods
    void calculateArea();  // Recalculate area when dimensions change
    void displayProbe() const;

        //need accessor and mutated methods
};