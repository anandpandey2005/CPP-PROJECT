// reverse an array and check palindrome using recursion

#include <iostream>
using namespace std;


void revArray(int arr[], int start, int end) {
    if (start >= end) return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    revArray(arr, start + 1, end - 1);
}


bool isPalindrome(int arr[], int start, int end) {
    if (start >= end) return true;
    if (arr[start] != arr[end]) return false;
    return isPalindrome(arr, start + 1, end - 1);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "ENTER THE SIZE : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "ENTER THE ELEMENT " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "Original Array: ";
    printArray(arr, n);

    revArray(arr, 0, n - 1);

    cout << "Reversed Array: ";
    printArray(arr, n);

    if (isPalindrome(arr, 0, n - 1)) {
        cout << "The array is a palindrome." << endl;
    } else {
        cout << "The array is not a palindrome." << endl;
    }

    return 0;
}