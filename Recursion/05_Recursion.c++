#include<bits/stdc++.h>
using namespace std;


int fibo(int n);
int main(){
    int n;
    cout<<"ENTER THE NUMBER : ";
    cin>>n;
   cout<<fibo(n);
}

int fibo(int n){
    if(n<=1){
        return n;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}