// its store very element in the sorted order and unique

// =====> time complexity log(n)

#include <bits/stdc++.h>
using namespace std;
int main()
{

    set<int> st;

    st.insert(2024);
    st.insert(2023);
    st.insert(2025);
    st.insert(2026);
    st.insert(2024);

    //   begin()  ,   end()  ,   rbegin() ,     rend() ,   size() ,   empty()  ,  swap()  are same as preivious
    //   can be used also , that only increase efficiency

    auto it = st.find(2025);          // return the iterator tha point ton the 2025

    auto it2 = st.find(2032);        // if element is not in set tha t it point to the right of the last element (end())

    st.erase(2024);                // it delete the element and maintained the sorted order
     
    int count = st.count(2025);   // gives the element that count inn a set   

    st.erase(it,it2);             // it eraae the element that come under passed value

// lowdr bound and upper bound works  same as the vector


    auto it = st.lower_bound(2024);
    auto it = st.upper_bound(2025);



}