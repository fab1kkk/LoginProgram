#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int userChoice;
    cout << "|\tEnter 1. if you want to log in:              |"<<endl;
    cout << "|\tEnter 2. if you want to register:            |"<<endl;
    cout << "|\tEnter 3. if you want to remind the password: |"<<endl;
    cout << "|\tEnter 4. to exit:                            |"<<endl;
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "Thank you!";
        break;
    default:
        system("cls");
        cout << "Please choose from options given.\n\n";
        main();
    }
}

void login() 
{   
    int count;
    string userId, password, id, pass;
    cout << "Please enter username and password: \n";
    cout << "Username: ";
    cin >> userId;
    cout << "\nPassword: ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1) {
        cout << userId << "Your login is succesfull\n\n\n";
        main();
    }
    else {
        cout << "Login error!";
        main();
    }
}

void registration() 
{
    string rUserId, rPassword, rId, rPass;
    system("cls");

    cout << "Please enter your username: ";
    cin >>rUserId;
    cout << "Please enter your password: ";
    cin >> rPassword;

    ofstream f1("records.txt", ios::app);
    f1 << rUserId << " " << rPassword << endl;
    system("cls");
    cout << "Registration is successfull! \n";
    main();
}

void forgot() 
{
    int option;
    system("cls");
    cout << "You forgot the password? No worries\n";
    cout << "Press 1. to search your id by username "<<endl;
    cout << "Press 2. to go back to the main menu" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) 
    {
    case 1:
    {
        int count = 0;
        string sUserId, sId, sPass;
        cout << "Enter the username: ";
        cin >> sUserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> sPass)
        {
            if (sId == sUserId) {
                count = 1;
            }
        }
        f2.close();
        if (count == 1) {
            cout << "\n\n Your account is found!";
            cout << "\n\n Your password is :" << sPass<<endl;
            main();
        }
        else {
            cout << "\n\nSorry your account is not found\n\n";
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
        cout << "Something went wrong. Try again." << endl;
        forgot();
    }
}