/*
=======>   it is based on lifo application (last in first out)


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<int> st2;
    stack<int> st;
    st.push(2024);        //   {2024}
    st.push(2025);        //   {2025,2024}
    st.push(2026);        //   {2026,2025,2024}
    st.push(2027);        //   {2027,2026,2025,2024}
    st.emplace(2028);     //   {2028,2027,2026,2025,2024}

    st.top();             // it return the top of the data structure
    st.size();            // it return the size of the data structure 
    st.empty();           // it return true if non element inn this data structure otherwise false  
    st.pop();             // it remove the top element from the data structure
    st.swap(st2);          // it retusrn swap of  the elelment
    

} 
