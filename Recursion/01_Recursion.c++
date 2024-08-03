// whrn function call itself until  a specified conndition is met

#include <bits/stdc++.h>
using namespace std;
void print(int num);
int main()
{

    int a = 1;
    print(a);
}

void print(int num)
{

    cout << num++<<endl;
    if(num!=10){

    print(num);
    }
}






