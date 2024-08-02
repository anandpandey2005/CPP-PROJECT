// singly linked list is maintained for this

#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    vector<int> vector1; // it creates an empty container

    vector1.push_back(10);   // it adds an element at the end of the vector
    vector1.emplace_back(2); // it is faster than push_back

    vector<pair<int, int>> vector2;

    vector2.push_back({1, 2});
    vector2.emplace_back(3, 4);

    vector<int> vector3(5, 100); // it contains 5 instances of 100

    vector<int> vector4(5); // it creates 5 instances with 0 or any garbage value by the compiler

    vector<int> vector5(vector1);

    vector<int> vac(5, 100);

    //===========================> ACCESSING ELEMENT OF THE VECTOR

    //==========> METHOD 1
    vector<int>::iterator it = vac.begin();
    it++; // it points to the second element of the vector
    it = it + 2;
    // cout << *(it) << endl;

    vector<int>::iterator it2 = vac.end(); // it indicate the right after the last value
    // ❌ not important    vector<int>::iterator it3 = vac.rend();          // it indicate the left before the first elelment
    // ❌ not important    vector<int>::iterator it4 = vac.rbegin();       //  it indicate the last element if i it ++ then it move in reverese direction

    //==========> METHOD 2

    for (vector<int>::iterator it = vac.begin(); it != vac.end(); it++)
    {
        //cout << *(it) << endl;
    }

    //==========> METHOD 3

    for (auto it = vac.begin(); it != vac.end(); it++)
    {

        //cout << *(it) << endl;
    }
    //==========> METHOD 4

    for (auto it :vac)
    {
       // cout << it;
    }
    
//=====================> DELETION OF VECTOR
for(auto it :vac){
    cout<< it<<endl;
}
cout<<"before delete"<<endl;
vac.erase(vac.begin()+1);

cout<<"after delete"<<endl;
for(auto it :vac){
    cout<< it<<endl;
}

// if you want to be erase the elelment by gaving its starting element and  the end elelmet then you use belowed method

vac.erase(vac.begin(),vac.begin()+3);

//=====================> INSERTION OF VECTOR

vector<int> vac2;

vac2.insert(vac2.begin(),2024);
for(auto it: vac2){
    cout<<it<<endl;
}


vector<int> vac3(2,100);
vector<int> vac4(2,50);

vac3.insert(vac.begin(),vac4.begin(),vac4.end());  // copy vac 4 in vac 3 

vac4.pop_back();

vac4.swap(vac3);

vac4.clear();  // erase the entire the vector 

cout<< vac2.empty();    // if is ety then it return true otherwise false
    return 0;
}