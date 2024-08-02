// it is  a part of utility library
#include<bits/stdc++.h>
using namespace std;

int main(){

pair<int,int> pair1 = {10,2} ;
//cout<< pair1.first;

pair<int, pair<int,pair<int,int>>> pair2 = {1,{5,{10,20}}};
//cout<< pair2.second.second.first <<endl;

 pair<int,pair<float,pair<int,pair<int,pair<int,int>>>>> pair3 = {1,{1.5,{1,{110,{50,56}}}}};
 cout<< pair3.second.second.second.second.first;

pair<int,int>pair4[]= {{0,2020},{1,2021},{2,2022},{3,2023},{4,2024}};

cout<< pair4[3].second<<endl;

}
