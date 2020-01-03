/*
Author: Rajan Saha Raju
02-01-2020
*/

#include <iostream>

template <typename T>
class vector {
private:
    int idx;
    T *container;
public:
    vector() : idx(0) , container(new T[1]) {}
    /*
    Destructor: https://docs.microsoft.com/en-us/cpp/cpp/destructors-cpp?view=vs-2019
    If anyone use new operator for object creating, then it requires explicit delete
    for calling destructor.
    Example:
    vector<int> *v = new vector<int>();
    delete v;
    */
    ~vector() {
        delete[] container;
    }
    void push_bacK(T num) {
        container[idx] = num;
        idx += 1;
        if((idx & (idx-1)) == 0) {
            T *temp = new T[(idx<<1)];
            for(int i = 0; i < idx; i++) {
                temp[i] = container[i];
            }
            delete[] container;
            /*
            Dangling pointers do not point to a valid object. Here, container is a dangling pointer. 
            Best pratice:
            delete[] container;
            container = nullptr;
            */
            container = temp;
        }
    }
    T operator[](int k) {
        return container[k];
    }
    int size() {
        return idx;
    }
};


int main(int argc, char const *argv[])
{
     
    vector<int> v;
    for(int i = 0; i < 10; i++) {
        v.push_bacK(i*i);
    }
    for(int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<std::endl;
    }


    return 0;
}
