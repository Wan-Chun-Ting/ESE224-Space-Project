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
    // Open the user credentials file
    ifstream InputFile("users.txt");
    if (!InputFile) {
        cerr << "Unable to open file example.txt" << endl; // Error handling
        return 1;
    }
    // Open the Probes input file
    ifstream ProbesInput("Probes.txt");
    if (!ProbesInput) {
        cerr << "Unable to open file example.txt" << endl; // Error handling
        return 1;
    }
    string user, password, input_user, input_password; // Variables for storing user credentials
    bool credential = false; // Flag for tracking successful login
    int id; // Variable to store Probe ID
    array<int, 2> dim, pos; // Arrays to store dimensions and positions of Probes
    Galaxy galaxy; // Create a Galaxy object

    // Read user credentials from the file
    InputFile >> user >> password;
    // cout << user << password << endl;
    
    // user login
    cout << "Login with credential" << endl;
    while (!credential) {
        
        cout << "User name: ";
        cin >> input_user; // Get username from user
        cout << "Password: ";
        cin >> input_password; // Get password from user
        // Check if input credentials match stored credentials
        if((input_user != user) || (input_password != password)){
            cout << "User name or password does not match, input again" << endl;
        }
        else{
            credential = true;
        }
    }

    string Probe_name; // Variable to store Probe names

    // read from Probes.txt
    while(!ProbesInput.eof()){
        
        getline(ProbesInput, Probe_name); // Read the Probe name
        // Check if the Probe name is valid
        if(isalpha(Probe_name[0]) && !Probe_name.empty()){
            ProbesInput >> id >> dim[0] >> dim[1] >> pos[0] >> pos[1];
            Probe p; // Create a new Probe object
            p.setName(Probe_name); // Set the Probe name
            p.setID(id); // Set the Probe ID
            p.setDimension(0, dim[0]); // Set dimensions
            p.setDimension(1, dim[1]);
            p.setPosition(0, pos[0]); // Set positions
            p.setPosition(1, pos[1]);
            p.calculateArea(); // Calculate the area of the Probe
            galaxy.add_Probe(p); // Add the Probe to the Galaxy
        }
    }


    

    bool contin = true; // Flag to control the main menu loop
    int choice, index, source, destin, n, nn; // Variables for user choices and indices
    string temp_word; // Temporary variable for input
    double new_value; // Variable to hold new dimension/position values
    Probe result; // Variable to store search results

    // main menu
    while (contin) {
        // Display menu options to the user
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
        cout << "14. Return a list of name for each Probe that would collide" << endl;

        cout << "Enter your choice (1-13): ";
        cin >> choice;

        switch (choice) {
            case 1: // Sort Probes by name
                cout << "Probes sorted by name." << endl << endl;
                galaxy.sortByName();
                cout << "Current order of probes: " << endl;
                galaxy.printAllNames();
                
                break;
            case 2: // Sort Probes by ID
                cout << "Probes sorted by ID." << endl << endl;
                galaxy.sortByID();
                cout << "Current order of probes: " << endl;
                for (int i = 0; i < 10; i++ ) {
                    cout << i + 1 << ". " << galaxy.retrieve(i).getName() << "(ID: " << galaxy.retrieve(i).getID() << ")" << endl;
                }
                break;
            case 3: // Sort Probes by area
                cout << "Probes sorted by area." << endl << endl;
                galaxy.sortByarea();
                cout << "Current order of probes: " << endl;
                for (int i = 0; i < 10; ++i ) {
                    cout << i + 1 << ". " << galaxy.retrieve(i).getName() << "(Area: " << galaxy.retrieve(i).getArea() << ")" << endl;
                }
                break;
            case 4: // Randomize the order of Probes
                cout << "Probe order randomized." << endl << endl;
                galaxy.randomizeOrder();

                cout << "Current order of probes: " << endl;
                for (int i = 0; i < 10; i++ ) {
                    cout << i + 1 << ". " << galaxy.retrieve(i).getName() << endl;
                }
                break;
            case 5: // Print all Probe names
                cout << endl << "All Probe Names: " << endl;
                galaxy.printAllNames();
                break;
            case 6: // Search for a Probe by name
                cout << "Enter the name of the probe to search: ";
                cin >> temp_word;
                
                result = galaxy.searchProbeByName(temp_word);
                if(result.getID()){
                    cout << endl << "Probe found: " << endl;
                    result.displayProbe();
                } else {
                    break;
                }
                break;
            case 7: // Search for a Probe by ID
                cout << "Enter the ID of the probe to search: ";
                cin >> index;
                result = galaxy.searchProbeByID(index);
                if(result.getID() == index){
                    cout << endl << "Probe found: " << endl;
                    result.displayProbe();
                } else {
                    break;
                }
                break;
            case 8: // Write Galaxy data to a file
                galaxy.writeGalaxyToFile();
                break;
            case 9: // Swap data between two Probes
                cout << "Enter the index of the first probe: ";
                cin >> source;
                cout << "Enter the index of the second probe: ";
                cin >> destin;
                
                if (source < 0 || source > 9 || destin < 0 || destin > 9 ) {
                    cout << "Index Out of Range." << endl;
                    break;
                }

                galaxy.swapProbeData(source, destin);

                cout << "Probe at index " << source << ":" << endl;

                galaxy.retrieve(source).displayProbe();
                cout << endl << "Probe at index " << destin << ":" << endl;
                galaxy.retrieve(destin).displayProbe();
                break;
            case 10: // Insert data into a Probe
                cout << "Enter the index of the probe to modify: ";
                cin >> index;
                cout << "Enter 0 to modify dimension, 1 to modify position: ";
                cin >> n;
                cout << "Enter the index to modify ";
                if(n == 0){
                    cout << "(0 for length, 1 for width): ";
                    cin >> nn;
                }
                else{
                    cout << "(0 for x, 1 for y): ";
                    cin >> nn;
                }
                cout << "Enter the new value: ";
                cin >> new_value;
                galaxy.insertProbeData(index, n, nn, new_value);
                cout << "Data inserted succesfully." << endl << endl;
                cout << "Updated Probe: " << endl;
                galaxy.displayProbe(index);
                break;
            case 11: // Copy Probe
                cout << "Enter the index of the source probe: ";
                cin >> source;
                cout << "Enter the index of the destination probe: ";
                cin >> destin;
                galaxy.copyProbe(source, destin);
                cout << "Probe copied succesfully." << endl << endl;
                cout << "Destination Probe (index " << destin << "):" << endl;
                galaxy.displayProbe(destin);
                break;
            case 12: // Display Probe
                cout << "Enter the index of the probe to display: ";
                cin >> index;
                cout << endl << "Probe Details:" << endl;
                galaxy.displayProbe(index);
                break;
            case 13: // Quit 
                cout << "Thank you for using Galactic Explorer System. Goodbye!" << endl;
                contin = false;
                break;
            case 14: // collisions
                cout << "List of Probes that can collide with each other: " << endl;

                for(int i = 0 ; i < 10 ; i++){
                    cout << galaxy.retrieve(i).getName() << " can collide with ";

                    vector<int> a = galaxy.collision_detection(i);
                    for(int j = 0 ; j < a.size() ; j++){
                        cout << galaxy.retrieve(a[j]).getName()<< ", ";
                    }
                    cout << endl;
                }

                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 13." << endl;
                break;
        }
}
    
}
