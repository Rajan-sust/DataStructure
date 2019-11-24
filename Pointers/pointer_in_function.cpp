#include <iostream>


void getseconds(unsigned long* ptr) {
    *ptr = time(NULL);
}



double get_avg(int* arr, int n) {
    double sum = 0;
    for(int i = 0; i<n ;i++) {
        sum += arr[i];
    }
    return (sum/n);
}



int main(int argc, char const *argv[]) {
    unsigned long sec = 0;
    getseconds(&sec);
    //std::cout<<sec<<std::endl;

    //As array name points the first elememt, just pass array name as a pointer
    int marks[] = {10,20,30,40,50};
    std::cout<<get_avg(marks,5)<<std::endl;
    return 0;
}


