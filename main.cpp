

#include <_stdio.h>
#include <array>
#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "Galaxy.h"

using namespace std;

int main(){
    ifstream InputFile("users.txt");
    ifstream ProbesInput("Probes.txt");
    string user, password, input_user, input_password;
    bool credential = false;
    int id;
    array<int, 2> dim, pos;
    Galaxy galaxy;


    InputFile >>  user >> password;
    cout << user << password;

    // user login
    cout << "Login with credential" << endl;
    while (!credential) {
        
        cout << "User name: ";
        cin >> input_user;
        cout << "Password: ";
        cin >> input_password;

        if((input_user != user) || (password != input_password)){
            cout << "User name or password does not match, input again" << endl;
        }
        else{
            credential = true;
        }
    }

    string Probe_name;

    // read from Probes.txt
    while(!ProbesInput.eof()){
        
        getline(ProbesInput, Probe_name);

        if(isalpha(Probe_name[0]) && !Probe_name.empty()){
            ProbesInput >> id >> dim[0] >> dim[1] >> pos[0] >> pos[1];
            Probe p;
            p.setName(Probe_name);
            p.setID(id);
            p.setDimension(0, dim[0]);
            p.setDimension(1, dim[1]);
            p.setPosition(0, pos[0]);
            p.setPosition(1, pos[1]);

            galaxy.add_Probe(p);
        }
    }


    

    bool contin = true;
    int choice, index, source, destin, n, nn;
    string temp_word;
    double new_value;

    // main menu
    while (contin) {
    cout << endl << "1. Sort Probes by Name" << endl;
    cout << "2. Sort Probes by ID" << endl;
    cout << "3. Sort Probes by Area" << endl;
    cout << "4. Randomize Probe Order" << endl;
    cout << "5. Print All Probe Names" << endl;
    cout << "6. Search Probe by Name" << endl;
    cout << "7. Search Probe by ID" << endl;
    cout << "8. Write Galaxy to File" << endl;
    cout << "9. Swap Probe Data" << endl;
    cout << "10. Insert Probe Data" << endl;
    cout << "11. Copy Probe" << endl;
    cout << "12. Display Probe" << endl;
    cout << "13. Quit" << endl;

    cout << "Enter your choice (1-13): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Probes sorted by name." << endl << endl;
            galaxy.sortByName();
            cout << "Current order of probes" << endl;
            galaxy.printAllNames();
            
            break;
        case 2:
            cout << "Probes sorted by ID." << endl << endl;
            galaxy.sortByID();
            break;
        case 3:
            cout << "Probes sorted by area." << endl;
            galaxy.sortByarea();
            break;
        case 4:
            cout << "Probes randomized" << endl;
            galaxy.randomizeOrder();
            break;
        case 5:
            galaxy.printAllNames();
            break;
        case 6:
            cout << "Enter the name of the probe to search: ";
            cin >> temp_word;
            galaxy.searchProbeByName(temp_word);
            break;
        case 7:
            cout << "Enter the ID of the probe to search: ";
            cin >> index;
            galaxy.searchProbeByID(index);
            break;
        case 9:
            cout << "Enter the index of the first probe: ";
            cin >> source;
            cout << "Enter the index of the second probe: ";
            cin >> destin;
            galaxy.swapProbeData(source, destin);
            break;
        case 10:
            cout << "Enter the index of the probe to modify: ";
            cin >> index;
            cout << "Enter 0 to modify dimension, 1 to modify position: ";
            cin >> n;
            cout << "Enter the index to modify: ";
            cin >> nn;
            cout << "Enter the new value: ";
            cin >> new_value;
            galaxy.insertProbeData(n, nn, new_value);
            break;
        case 11:
            cout << "Enter the index of the source probe: ";
            cin >> source;
            cout << "Enter the index of the destination probe: ";
            cin >> destin;
            // Add code to copy probe from source to destination
            break;
        case 12:
            cout << "Enter the index of the probe to display: ";
            cin >> index;
            cout << endl << "Probe Details:" << endl;
            galaxy.displayProbe(index);
            break;
        case 13:
            cout << "Thank you for using Galactic Explorer System. Goodbye!" << endl;
            contin = false;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 13." << endl;
            break;
    }
}

    
}