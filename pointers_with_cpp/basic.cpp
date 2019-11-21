#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    
    int x = 5;
    //Output the memory address of x
    cout<<&x<<endl;
    int* ptr = &x;
    //Output the memory address of x with pointer
    cout<<ptr<<endl;
    // Dereference: Output the value of x with the pointer
    cout<<*ptr<<endl;

    return 0;
}
