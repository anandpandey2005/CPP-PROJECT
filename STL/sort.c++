#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

bool comparePerson(const Person& a, const Person& b) {
    return a.age < b.age;
}

int main() {
    int arr[] = {4, 2, 9, 6, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    vector<int> vec1 = {4, 2, 9, 6, 5, 1};

    sort(vec1.begin(), vec1.end());

    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }

    list<int> lst = {4, 2, 9, 6, 5, 1};

    lst.sort();

    for (int i : lst) {
        cout << i << " ";
    }

    map<int, string> m1 = {{4, "four"}, {2, "two"}, {9, "nine"}, {6, "six"}, {5, "five"}, {1, "one"}};

    // Sort by key
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    map<int, string> m2 = {{4, "four"}, {2, "two"}, {9, "nine"}, {6, "six"}, {5, "five"}, {1, "one"}};

    // Sort by value
    vector<pair<int, string>> vec2(m2.begin(), m2.end());
    sort(vec2.begin(), vec2.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second < b.second;
    });

    for (const auto& p : vec2) {
        cout << p.first << ": " << p.second << endl;
    }

    vector<Person> people = {{"John", 25}, {"Alice", 30}, {"Bob", 20}};

    sort(people.begin(), people.end(), comparePerson);

    for (const auto& p : people) {
        cout << p.name << ": " << p.age << endl;
    }

    return 0;
}