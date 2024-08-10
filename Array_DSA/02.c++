// left rotate the array

#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int> &arr);
vector<int> nthRotateArray(vector<int> &arr, int k);
vector<int> moveZeroToEnd(vector<int> &arr);
vector<int> moveZeroToEnd2(vector<int> &arr);
vector<int> linearSearch(vector<int> &arr, int n);
vector<int> unionOfArray(vector<int> arr1, vector<int> arr2);

int main()
{
    vector<int> arr = {1, 0, 0, 1, 5};

    // moveZeroToEnd2(arr);
}

vector<int> rotateArray(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
    return arr;
}

vector<int> nthRotateArray(vector<int> &arr, int k)
{

    k = k % arr.size();

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    return arr;
}

vector<int> moveZeroToEnd(vector<int> &arr)
{

    vector<int> nonZero;
    vector<int> zero;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            zero.push_back(i);
        }
        else
        {
            nonZero.push_back(i);
        }
    }

    vector<int> result = nonZero;
    result.insert(result.end(), zero.begin(), zero.end());
    return result;
}

vector<int> moveZeroToEnd2(vector<int> &arr)
{
    int size = arr.size();
    int j = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        return arr;
    }
    for (int i = j + 1; i < size; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }

    return arr;
}

vector<int> linearSearch(vector<int> &arr, int n)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            return {i};
        }
    }
    return {false};
}

vector<int> unionOfArray(vector<int> arr1, vector<int> arr2)
{
    int size1 = arr1.size();
    int size2 = arr2.size();
    set<int> st;
    for (int i = 0; i < size1; i++)
    {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        st.insert(arr2[i]);
    }

    vector<int> temp;
    for (auto it : st)
    {
        temp.push_back(it);
    }

    return temp;
}