#include <iostream>

template <typename T>
class Vector {
private:
    T *container;
    int size;
public:
    Vector() {
        size = 0;
        container = new T[1];
    }
    void push_back(T num) {
        container[size] = num;
        size += 1;
        if((size & (size-1)) == 0) {
            T *temp;
            temp = new T[(size<<1)];
            for(int i=0; i<size; i++){
                temp[i] = container[i];
            }
            delete[] container;
            container = temp;
        }
    }
    T operator [](int idx) {
        return container[idx];
    }
    int length() {
        return size;
    }
};



int main(int argc, char const *argv[]) {
    Vector<int>v;
    for(int i=1; i<=100; i++) {
        v.push_back((i*i));
    }
    for(int i=0;i<v.length(); i++) {
        std::cout<<v[i]<<std::endl;
    }
    
}
