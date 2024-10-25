

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
        Probe();

        void operator<<(Probe& p2);
        void operator-(Probe& p2);
// Accessor methods
    string getName() const;
    int getID() const;
    int getDimension(int index) const;
    double getArea() const;
    int getPosition(int index) const;

        void setName(const std::string& newName);
        void setID(int newID);
        void setDimension(int index, int value);
        void setPosition(int index, int value);
        void randomizeProbes(vector<Probe>& probs);
        void calculateArea();
        void displayProbe() const;
};