// sum of first natural number 

#include<bits/stdc++.h>
using namespace std;

long long sumNthNumber(int n, long long sum = 0);
long long factorial(int n, long long fact = 1);

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if(n <= 0) {
        cout << "Invalid input. Please enter a positive integer.";
        return 1;
    }
    //sumNthNumber(n);
    factorial(n);
    return 0;
}

long long sumNthNumber(int n, long long sum){
    if(n < 1){
        cout << "The Sum Of The Number Is : " << sum;
        return sum;
    }
    else{
        return sumNthNumber(n-1, sum+n);
    }
}

long long factorial(int n, long long fact){
    
    if(n < 1){
        cout << "Factorial is: " << fact;
        return fact;
    }
    else{
        return factorial(n-1, fact*n);
    }
}