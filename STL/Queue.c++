/*

=======> it is based on fifo application, (first in first  out)

*/
#include<bits/stdc++.h>
using namespace std;
int main(){

    queue<int> que;

    que.push(2024);
    que.push(2025);
    que.push(2026);
    que.push(2027);

    que.back() += 2027;    // it add 2027 that come latest

    cout << que.front() << endl;  // it print 2024 that come first
    cout<< que.back()  << endl;   // it prints that come latest 
    que.pop();
    cout<< que.front()  << endl;   // it prints that come second coz you poped 


}

