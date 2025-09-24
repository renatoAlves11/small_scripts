#include<iostream>
using namespace std;
main()
{
    int a, *p;
    a=30;
    p=&a;
    cout << a << "\n";
    cout << *p << "\n";
    cout << &a << "\n";
    cout << p;
}