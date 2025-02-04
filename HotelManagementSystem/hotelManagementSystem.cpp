#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Room {
    string name;
    int price;
    int roomNumber;
    int floor;
    string bookedBy; 
};

struct Snack {
    string name;
    int price;
    int stock;
    int sold;
};

void showAdminPanel(vector<Room>& rooms, vector<Snack>& snacks);
void showUserPanel(vector<Room>& rooms, vector<Snack>& snacks);
void showDashboard(vector<Room>& rooms, vector<Snack>& snacks);
void generateReceipt(string itemName, int quantity, int totalPrice, int roomNumber = 0, int floor = 0, string username = "");
void checkoutRoom(vector<Room>& rooms);

int main() {
    int choice;

    vector<Room> rooms = { 
        {"Single Room", 1200, 101, 1, ""}, {"Single Room", 1200, 102, 1, ""}, {"Single Room", 1200, 103, 1, ""}, 
        {"Single Room", 1200, 104, 1, ""}, {"Single Room", 1200, 105, 1, ""}, {"Single Room", 1200, 106, 1, ""}, 
        {"Single Room", 1200, 107, 1, ""}, {"Single Room", 1200, 108, 1, ""}, {"Single Room", 1200, 109, 1, ""}, 
        {"Single Room", 1200, 110, 1, ""}, 
        {"Double Room", 2000, 201, 2, ""}, {"Double Room", 2000, 202, 2, ""}, {"Double Room", 2000, 203, 2, ""}, 
        {"Double Room", 2000, 204, 2, ""}, {"Double Room", 2000, 205, 2, ""}, 
        {"Suite", 5000, 301, 3, ""}, {"Suite", 5000, 302, 3, ""} 
    };

    vector<Snack> snacks = { {"Pasta", 250, 10, 0}, {"Burger", 200, 10, 0}, {"Pizza", 500, 5, 0}, {"Sandwich", 150, 15, 0},
                             {"Noodles", 180, 10, 0}, {"French Fries", 100, 20, 0}, {"Momos", 120, 10, 0}, {"Hotdog", 220, 8, 0},
                             {"Milkshake", 180, 10, 0}, {"Ice Cream", 90, 10, 0} };

    while (true) {
        cout << "\n+------------ AP Hotel System ------------+" << endl;
        cout << "| 1. Admin Panel                        |" << endl;
        cout << "| 2. User Panel                         |" << endl;
        cout << "| 0. Exit                               |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showAdminPanel(rooms, snacks);
                break;
            case 2:
                showUserPanel(rooms, snacks);
                break;
            case 0:
                cout << "Exiting the system. Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}

void showAdminPanel(vector<Room>& rooms, vector<Snack>& snacks) {
    int choice;
    while (true) {
        cout << "\n+------------ Admin Panel ------------+" << endl;
        cout << "| 1. View Available Rooms             |" << endl;
        cout << "| 2. View Available Snacks            |" << endl;
        cout << "| 3. View Sales Dashboard             |" << endl;
        cout << "| 4. Checkout Room                    |" << endl;
        cout << "| 0. Back to Main Menu                |" << endl;
        cout << "+------------------------------------+" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) {
            cout << "\nAvailable Rooms:" << endl;
            for (int i = 0; i < rooms.size(); i++) {
                if (rooms[i].bookedBy.empty()) {
                    cout << "Room Number: " << rooms[i].roomNumber << " - " << rooms[i].name 
                         << " - Price: " << rooms[i].price << " - Floor: " << rooms[i].floor << endl;
                }
            }
        } else if (choice == 2) {
            cout << "\nAvailable Snacks:" << endl;
            for (int i = 0; i < snacks.size(); i++) {
                cout << i + 1 << ". " << snacks[i].name << " - Price: " << snacks[i].price 
                     << " - Available: " << snacks[i].stock - snacks[i].sold << endl;
            }
        } else if (choice == 3) {
            showDashboard(rooms, snacks);
        } else if (choice == 4) {
            checkoutRoom(rooms);
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
}

void showUserPanel(vector<Room>& rooms, vector<Snack>& snacks) {
    int choice;
    string username;
    while (true) {
        cout << "\n+------------ User Panel ------------+" << endl;
        cout << "| 1. Book a Room                     |" << endl;
        cout << "| 2. Order Snacks                    |" << endl;
        cout << "| 0. Back to Main Menu               |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) {
            cout << "\nAvailable Rooms:" << endl;
            for (int i = 0; i < rooms.size(); i++) {
                if (rooms[i].bookedBy.empty()) {
                    cout << i + 1 << ". " << rooms[i].name << " - Price: " << rooms[i].price 
                         << " - Floor: " << rooms[i].floor << endl;
                }
            }
            cout << "Enter room number to book: ";
            cin >> choice;
            if (choice >= 1 && choice <= rooms.size()) {
                if (rooms[choice - 1].bookedBy.empty()) {
                    cout << "Enter your username: ";
                    cin >> username;
                    rooms[choice - 1].bookedBy = username;
                    generateReceipt(rooms[choice - 1].name, 1, rooms[choice - 1].price,
                                    rooms[choice - 1].roomNumber, rooms[choice - 1].floor, username);
                } else {
                    cout << "Room is already booked by " << rooms[choice - 1].bookedBy << "." << endl;
                }
            }
        } else if (choice == 2) {
            for (int i = 0; i < snacks.size(); i++) {
                cout << i + 1 << ". " << snacks[i].name << " - Price: " << snacks[i].price 
                     << " - Available: " << snacks[i].stock - snacks[i].sold << endl;
            }
            cout << "Enter snack number to order: ";
            cin >> choice;
            if (choice >= 1 && choice <= snacks.size()) {
                int quant;
                cout << "Enter quantity: ";
                cin >> quant;
                if (snacks[choice - 1].stock - snacks[choice - 1].sold >= quant) {
                    snacks[choice - 1].sold += quant;
                    generateReceipt(snacks[choice - 1].name, quant, snacks[choice - 1].price * quant);
                } else {
                    cout << "Not enough stock available." << endl;
                }
            }
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
}

void showDashboard(vector<Room>& rooms, vector<Snack>& snacks) {
    cout << "\nSales Dashboard:" << endl;
    cout << "Rooms:" << endl;
    for (int i = 0; i < rooms.size(); i++) {
        cout << "Room Number: " << rooms[i].roomNumber << " - " << rooms[i].name 
             << " - Booked By: " << (rooms[i].bookedBy.empty() ? "Available" : rooms[i].bookedBy) << endl;
    }
    cout << "Snacks:" << endl;
    for (int i = 0; i < snacks.size(); i++) {
        cout << snacks[i].name << " - Sold: " << snacks[i].sold << endl;
    }
}

void generateReceipt(string itemName, int quantity, int totalPrice, int roomNumber, int floor, string username) {
    cout << "\n--- AP Hotel Receipt ---" << endl;
    cout << "Item: " << itemName << "\nQuantity: " << quantity << "\nTotal Price: " << totalPrice << endl;
    if (roomNumber != 0) {
        cout << "Room Number: " << roomNumber << " | Floor: " << floor << endl;
        cout << "Booked By: " << username << endl;
        cout << "Welcome to AP Hotel! Enjoy your stay!" << endl;
    }
    cout << "-------------------------" << endl;
}

void checkoutRoom(vector<Room>& rooms) {
    int roomNumber;
    cout << "Enter room number to checkout: ";
    cin >> roomNumber;

    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].roomNumber == roomNumber && !rooms[i].bookedBy.empty()) {
            cout << "Room " << roomNumber << " checked out by " << rooms[i].bookedBy << "." << endl;
            rooms[i].bookedBy = "";
            return;
        }
    }
    cout << "Room not found or already available." << endl;
}
