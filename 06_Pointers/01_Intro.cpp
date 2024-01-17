#include <iostream>
using namespace std;

int main()
{
    /* What is a pointer?------>variable which holds the address of
    other variables*/

    int a = 3;
    int *ptr1 = &a; // pointer to int is created,and pointing to address of 'a'
    //  & ----> (Address of) operator

    cout << "The address of a is :" << &a << endl;
    cout << "The address of a is :" << ptr1 << endl;

    // *-----> (value at) Dereference operator
    cout << "The value at address ptr1 is " << *ptr1 << endl;

    // we can also initialize pointer this way

    int *ptr2 = 0; // Null Pointer
    ptr2 = &a;
    cout << "The address of a is :" << &a << endl;
    cout << "The address of a is :" << ptr2 << endl;

    // *-----> (value at) Dereference operator
    cout << "The value at address ptr2 is " << *ptr2 << endl;

    double d = 4.3;
    double *ptr3 = &d;

    cout << "The address of a is :" << &d << endl;
    cout << "The address of a is :" << ptr3 << endl;

    cout << "The value at address ptr3 is " << *ptr3 << endl;

    cout << "size of integer is " << sizeof(a) << endl;
    cout << "size of pointer is " << sizeof(ptr1) << endl;

    /*
    int num = 6;
    cout <<"Before " << num << endl;
    int *ptr4 = &num;
    cout << ptr4 << endl;  // address
    (*ptr4)++;
    cout << "after " << num << endl;

    //Copying a pointer
    int *ptr5 = ptr4;
    cout << ptr4 << " - "<< ptr5 << endl; // address
    cout << *ptr4 << " - "<< *ptr5 << endl; //value
    */

    // important concept
    int i = 3;
    int *t = &i;
    //cout << (*t)++ << endl;
    //cout << (*t)++ << endl;
    *t = *t + 1;
    cout << *t << endl;
    cout << "before t " << t << endl;
    t = t + 1;  // address change hora
    cout << "after " << t << endl; // 4 byte aage badh jaayega,basically agle int location pe jayega

    // Pointer to pointer
    // int** c = &b;
    // cout<<"The address of b is " <<&b<<endl;
    // cout<<"The address of b is " <<c<<endl;
    // cout<< "The value at address c is "<<*c<<endl;
    // cout<<"The value at address value_at(value_at(c)) is "<<**c<<endl;

    return 0;
}