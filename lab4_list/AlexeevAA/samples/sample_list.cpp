#include<iostream>
#include"TList.h"
using std::cout;

int main(){
    TList<int> l;
    l.push_back(334);
    l.push_back(12);
    l.push_back(1);
    l.push_after(1,212);
    l.erase_after(1);
    l.pop_back();
    l.push_front(34);
    l.pop_front();
    cout << l.size() << "\n";
    for(TList<int>::iterator i = l.begin(); i != l.end();i++){
        cout << i.i->data << " ";
    }
}