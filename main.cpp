#include <iostream>
#include "List.h"
using namespace std;
int main (){
    
    List<int> list;
    auto node = new Node<int>(5,nullptr);
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    
    list.insert(node,3);

    cout << list;

}