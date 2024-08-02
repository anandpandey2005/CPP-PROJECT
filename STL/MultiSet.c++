// it only  obey sorted not unique

#include<bits/stdc++.h>
using namespace std;

int main(){

multiset <int> mst;

mst.insert(1);       // {1}
mst.insert(1);       // {1,1}
mst.insert(1);       // {1,1,1}
mst.erase(1);        // all 1's erased

int count = mst.count(1);    // it  return count of the 1's

// only one single one  erased


mst.erase(mst.find(1));        // it  return iterator pointing to the erased element   

// rest all functions are same as previous one

}