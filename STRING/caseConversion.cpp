#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name = "Anand Pandey";
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] >= 97 && name[i] <= 122)
        {
            name[i] -= 32;
        }
        else if (name[i] >= 65 && name[i] <= 90)
        {
            name[i] += 32;
        }
    }

    cout << name;

    return 0;
}