

#include <array>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "Galaxy.h"

using namespace std;

int main(){
    ifstream InputFile("users.txt");
    ifstream ProbesInput("Probes.txt");
    string user, password;
    string input_user, input_password;
    bool credential = false;
    int id;
    array<int, 2> dim, pos;
    Galaxy galaxy;

    // read from Probes.txt
    for(int i = 0 ; i < 10 ; i++){
        // ProbesInput >> user >> id >> dim[0] >> dim[1] >> pos[0] >> pos[1];
        // cout << user << id << dim[0] << dim[1] << pos[0] << pos[1] << endl;
        ProbesInput >> user;
        ProbesInput >> id;
        cout << user << id;
        Probe p;

        // galaxy.add_Probe(a);
    }


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

    bool contin = true;
    int choice, index, source, destin;
    string temp_word;

    // main menu
    while(contin){
        
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

        if(choice == 1){
            cout << "Probes sorted by name." << endl;
            galaxy.sortByName();
        }
        else if(choice == 2){
            cout << "Probes sorted by ID." << endl;
            galaxy.sortByID();
        }
        else if(choice == 3){
            cout << "Probes sorted by area." << endl;
            galaxy.sortByarea();
        }
        else if (choice == 4) {
            
        }
        else if (choice == 5) {
            galaxy.printAllNames();
        }
        else if(choice == 6){
            cout << "Enter the name of the probe to search: " << endl;
            cin >> temp_word;
            galaxy.searchProbeByName(temp_word);
        }
        else if(choice == 7){
            cout << "Enter the ID of the probe to search: " << endl;
            cin >> index;
            galaxy.searchProbeByID(index);
        }
        else if (choice == 9) {
            cout << "Enter the index of the first probe: ";
            cin >> source;
            cout << "Enter the index of the second probe: ";
            cin >> destin;

            galaxy.swapProbeData(source, destin);
        }
        else if (choice == 10) {
            cout << "Enter the index of the probe to modify: ";
            cin >> index;
            
        }
        else if(choice == 11){
            cout << "Enter the index of the source probe: " << endl;
            cin >> source;
            cout << "Enter the index of the destination probe: " << endl;
            cin >> destin;


        }
        else if(choice == 12){
            cout << "Enter the index of the probe to display: " << endl;
            cin >> index;
            cout << endl << "Probe Details:" << endl;
            galaxy.displayProbe(index);
        }
        else if(choice == 13){
            cout << "Thank you for using Galactic Explorer System. Goodbye!" << endl;
            contin = false;
        }
    }



    
}