#include <bits/stdc++.h>
using namespace std;

void palindrome(string name) {
    int start = 0;
    int end = name.size() - 1;

    bool isPalindrome = true;

    while (start < end) {
        if (name[start] != name[end]) {
            isPalindrome = false;
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome) {
        cout << "PALINDROME";
    } else {
        cout << "NOT A PALINDROME";
    }
}

int main() {
    palindrome("jahaj");
    return 0;
}