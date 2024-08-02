// map store unique key in sorted order 

#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){

    map<int,int>mp;
    
    map<int,pair<int,int>>mpp;
    
    map<pair<int,int>,int>mppp;

    mp[1] = 2;
    mpp.emplace(3,make_pair(4,5));
    mppp.insert(make_pair(make_pair(2, 4), 6));
    return 0;
}