#include <iostream>
using namespace std;

main()
{
    int a, *p;

    a = 30;
    p = &a;
    

    cout << "a -> " << a << endl;
    cout << "*p -> " << *p << endl;    
    cout << "&a -> " << &a << endl;
    cout << "p -> " << p << endl;
    cout << "&p -> " << &p << endl;
    cout << "&(*p) -> " << &(*p) << endl;
}