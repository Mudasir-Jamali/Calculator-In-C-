#include <iostream>
#include <string>
#include <map>

using namespace std;

// Define a struct to represent user data
struct UserData
{
    string username;
    string password;
};

int main()
{
    map<string, UserData> users;

    // Add default user
    users["mudasir"] = {"mudasir", "jamali"};

    string username, password;
    char choice;

    do
    {
        // Prompt the user to enter username
        cout << "Enter username: ";
        cin >> username;

        // Prompt the user to enter password
        cout << "Enter password: ";
        cin >> password;

        // Check if the entered username and password are correct
        if (users.count(username) > 0 && users[username].password == password)
        {
            cout << "Login successful! Welcome, " << username << "." << endl;
        }
        else
        {
            cout << "Incorrect username or password. Access denied." << endl;
            cout << "Do you want to register? (y/n): ";
            cin >> choice;

            if (choice == 'y')
            {
                // Register a new user
                cout << "Enter new username: ";
                cin >> username;
                cout << "Enter new password: ";
                cin >> password;

                // Add the new user to the map
                users[username] = {username, password};
                cout << "Registration successful! You can now login with your new account." << endl;
            }
        }

        cout << "Do you want to login again? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
