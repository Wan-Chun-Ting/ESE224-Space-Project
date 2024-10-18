

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(){
    ifstream InputFile("users.txt");
    string user, password;
    string input_user, input_password;
    bool credential = false;

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
    int choice;

    // main menu
    while(contin){
        cout << "Enter your choice (1-13): ";
        cin >> choice;
        if(choice == 1){

        }
        else if(choice == 2){

        }
        else if(choice == 13){
            cout << "Thank you for using Galactic Explorer System. Goodbye!" << endl;
            contin = false;
        }
    }



    
}