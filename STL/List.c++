/*
=> doubly linked list is maintainer for it
=>  push_front  is very cheap in complecity
=>  all functions are same as vector
->  begin   -> end   -> rend()  -> clear  -> rbegin   ->  rend   -> empty   -> clear  -> size   ->  swap  -> insert
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main() {

    list<int> li;

    li.push_front(1);    // 1
    li.emplace_back(4);  // 1,4
    li.push_front(5);    // 5,1,4
    li.emplace_front();  // 2,4

}
