#include <bits/stdc++.h>
#include <fstream>
#include <iomanip> // Include the iomanip library
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    while (1)
    {
        cout << "++++++++++++++++++ ENTER YOUR CHOICE ++++++++++++++++++++" << endl;
        int choice;
        cout << "1. Login" << endl;
        cout << "2. Registration" << endl;
        cout << "3. Forgot Password" << endl;
        cout << "Enter your Choice : ";
        cin >> choice;
        cout << endl;

        switch (choice)
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

        default:
            cout << "INVALID CHOICE !!!!!!" << endl;
            cout << "" << endl;
            break;
        }
    }
}

void login()
{
    int count;
    string username, password;
    cout << "++++++++++++++++++ LOGIN ++++++++++++++++++++" << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream input("records.txt");
    string line;
    bool found = false;
    while (getline(input, line))
    {
        size_t pos = line.find(" ");
        string fileUsername = line.substr(0, pos);
        string filePassword = line.substr(pos + 1);

        if (fileUsername == username && filePassword == password)
        {
            found = true;
            cout << setw(20) << left << "Username" << setw(20) << left << "Password" << endl;
            cout << setw(20) << left << fileUsername << setw(20) << left << filePassword << endl;
            cout << "Login successful!" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Invalid username or password!" << endl;
    }

    input.close();
}

void registration()
{
    string username, password;
    cout << "++++++++++++++++++ REGISTRATION ++++++++++++++++++++" << endl;
    cout << "Enter your desired username: ";
    cin >> username;
    cout << "Enter your desired password: ";
    cin >> password;

    ofstream output("records.txt", ios::app);
    output << username << " " << password << endl;
    output.close();

    cout << setw(20) << left << "Username" << setw(20) << left << "Password" << endl;
    cout << setw(20) << left << username << setw(20) << left << password << endl;
    cout << "Registration successful!" << endl;
}

void forgot()
{
    string username, password, newPassword;
    cout << "++++++++++++++++++ FORGOT PASSWORD ++++++++++++++++++++" << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your old password: ";
    cin >> password;

    ifstream input("records.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;
    while (getline(input, line))
    {
        size_t pos = line.find(" ");
        string fileUsername = line.substr(0, pos);
        string filePassword = line.substr(pos + 1);

        if (fileUsername == username && filePassword == password)
        {
            found = true;
            cout << "Enter your new password: ";
            cin >> newPassword;
            temp << username << " " << newPassword << endl;
            cout << setw(20) << left << "Username" << setw(20) << left << "New Password" << endl;
            cout << setw(20) << left << username << setw(20) << left << newPassword << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    if (!found)
    {
        cout << "Invalid username or password!" << endl;
    }

    input.close();
    temp.close();
    remove("records.txt");
    rename("temp.txt", "records.txt");
}