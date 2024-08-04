// find the second largest element in an array
// find the nth largest element in an array
// check array is sorted or not
// remove duplicate element

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isSorted(int arr[], int n);
int secondLargest(int arr[], int n);
int kThLargestNumber(int arr[], int n, int k);
void removeDuplicates(int arr[], int n);

int main()
{
    int n;
    cout << "ENTER THE SIZE :  ";
    cin >> n;
    int arr[n];
    int k;
    cout << "ENTER THE NTH NUMBER : ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cout << "ENTER THE ELEMENT " << i + 1 << " : ";
        cin >> arr[i];
    }
    int result = secondLargest(arr, n);
    cout << "Second largest element is: " << result << endl;
    int kth = kThLargestNumber(arr, n, k);
    cout << "Nth largest number is : " << kth << endl;
    cout << "Is array sorted? " << (isSorted(arr, n) ? "Yes" : "No") << endl;
    return 0;
}

int secondLargest(int arr[], int n)
{
    int max = arr[0];
    int secondMax = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] > secondMax && arr[i] != max)
        {
            secondMax = arr[i];
        }
    }
    if (secondMax == INT_MIN)
    {
        cout << "No second largest element found." << endl;
        return -1;
    }
    return secondMax;
}

int kThLargestNumber(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[n - k];
}

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void removeDuplicates(int arr[], int n)
{
    sort(arr, arr + n);

    int uniqueArr[n];
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || arr[i] != arr[i - 1])
        {
            uniqueArr[j++] = arr[i];
        }

        cout << "Array after removing duplicates: ";
        for (int i = 0; i < j; i++)
        {
            cout << uniqueArr[i] << " ";
        }
        cout << endl;
    }