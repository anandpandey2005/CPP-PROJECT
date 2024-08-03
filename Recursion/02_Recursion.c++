/*
============>     BASIC RECURSION PROBLEM    <=================

=>  PRINT NAME 5 TIMES
=>  PRINT LINEARLY FROM 1 TO N
=>  PRINT FROM N TO 1
=> PRINT LINEARLY FROM 1 TO N (BACKTRACKING)
=> PRINT FROM N TO 1 (BACKTRACKING)

*/

#include <bits/stdc++.h>
using namespace std;

void problem1(int num, string name);
void problem2(int num, int num2);
void problem3(int num, int num2);
void problem4(int num);
void problem5(int num);

int main()
{

    int num, num2;
    string name;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter a number: ";
    cin >> num2;
    // cout << "Enter a name: ";
    //  cin >> name;

    problem3(num, num2);
}

void problem1(int num, string name)
{
    if (num > 0)
    {
        cout << name << endl;
    }
    problem1(num - 1, name);
}

void problem2(int num, int num2)
{

    if (num <= num2)
    {
        cout << num << endl;
        problem2(num + 1, num2);
    }
}

void problem3(int num, int num2)
{

    if (num2 >= num)
    {
        cout << num2 << endl;
        problem3(num, num2 - 1);
    }
}

void problem4(int num)
{
    if (num > 0)
    {
        problem5(num - 1);
        cout << num << endl;
    }
}

void problem5(int num)
{
    if (num > 0)
    {
        problem5(num - 1);
        cout << num << endl;
    }
}