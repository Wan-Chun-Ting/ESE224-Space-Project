

#include <string>

using namespace std;
class Probe{
    private:
        string name;
        int ID;
        int dimention[2];
        double area;
        int position[2];
    public:
        void calculateArea();
        void displayProbe();
};