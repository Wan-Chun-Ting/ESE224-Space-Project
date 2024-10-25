
#include "Probe.h"
#include <vector>

class Galaxy{
    private:
        vector<Probe> probs;
    public:
        Galaxy();
        void add_Probe(Probe pro);
        Probe retrieve(int index);

        void sortByName();
        void sortByID();
        void sortByarea();
        Probe searchProbeByName(const string& name);
        Probe searchProbeByID(int id);
        void swapProbeData(int idx1, int idx2);
        void insertProbeData(int galaxyIdx, int probeIdx, int value);
        void copyProbe(int idx1, int idx2);
        void displayProbe(int idx1);

        void insertProbeData(int galaxyIdx, int probeIdx, int value);
        void randomizeOrder();
        void printAllNames();
        void writeGalaxyToFile();
};