#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if username already exists
bool usernameExists(string username)
{
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n===== User Registration =====\n";

    cout << "Enter Username: ";
    cin >> username;

    if (usernameExists(username))
    {
        cout << "Username already exists! Try another username.\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    if (username.empty() || password.empty())
    {
        cout << "Username and Password cannot be empty!\n";
        return;
    }

    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string user, pass;
    bool found = false;

    cout << "\n===== User Login =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass)
    {
        if (user == username && pass == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login Successful! Welcome " << username << ".\n";
    else
        cout << "Invalid Username or Password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}