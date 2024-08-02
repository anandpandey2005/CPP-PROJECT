#include<bits/stdc++.h>
using namespace std;

int main(){

// Maximum Heap
priority_queue<int> pq;

pq.push(2024);
pq.push(2025);
pq.push(2026);
pq.push(2027);
pq.emplace(2028);

pq.top();   //   it return the top of the element
pq.pop();   //   it remove the top of the element

// size & swap function ssame as others

// Minimum Heap

priority_queue<int, vector<int>, greater<int>> pq2;
pq2.push(2024);
pq2.push(2025);
pq2.push(2026);
pq2.push(2027);
pq2.emplace(2028);

cout<<pq.top()<<" "<<pq2.top()<<endl;      // it prints  2027 2024







}