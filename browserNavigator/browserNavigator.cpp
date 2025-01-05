#include <bits/stdc++.h>
using namespace std;

class Browser
{
public:
    string url;
    Browser *next;
    Browser *prev;

    Browser() : url(""), next(nullptr), prev(nullptr) {}
    Browser(string url) : url(url), next(nullptr), prev(nullptr) {}

    Browser *current = nullptr;
    Browser *head = nullptr;

    Browser* forward(string url) {
        Browser* newNode = new Browser(url);
        if (head == nullptr) {
            head = newNode;
            current = newNode;
            return newNode;
        }
        if (current->next == nullptr) {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        return current;
    }

    Browser* forward() {
        if (current->next != nullptr) {
            current = current->next;
            return current;
        }
        else {
            return nullptr;
        }
    }

    Browser* previous() {
        if (current->prev != nullptr) {
            current = current->prev;
        } else {
            cout << "No previous history available." << endl;
        }
        return current;
    }

    void printHistory() {
        Browser *temp = head;
        cout << "Browsing History:" << endl;
        while (temp != nullptr) {
            cout << temp->url << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Browser browser;
    string input;
    while (true) {
        cout << "Enter a command (forward <url>, forward, previous, printHistory, exit): ";
        getline(cin, input);

        if (input.find("forward") == 0) {
            if (input.length() > 7) {
                string url = input.substr(8);
                browser.forward(url);
                cout << "Current URL: " << browser.current->url << endl;
            } else {
                if (browser.forward() != nullptr) {
                    cout << "Current URL: " << browser.current->url << endl;
                } else {
                    cout << "No forward webPage open ." << endl;
                }
            }
        } else if (input == "previous") {
            if (browser.previous() != nullptr) {
                cout << "Current URL: " << browser.current->url << endl;
            }
        } else if (input == "printHistory") {
            browser.printHistory();
        } else if (input == "exit") {
            break;
        } else {
            cout << "Invalid command. Try again." << endl;
        }
    }
    return 0;
}