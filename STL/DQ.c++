// it is already same as the previous one 
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){

deque<int>dq;

dq.push_back(1);            //  {1}
dq.emplace_back(2);        //   (1,2)
dq.push_front(4);         //    {4,1,2}        
dq.emplace_front(3);     //     {3,4,1,2}         

dq.pop_back();         //      {3,,4,1}           
 
dq.back();            //        {4,1}               

dq.front();                            


}