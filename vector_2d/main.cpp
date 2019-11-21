#include <iostream>

template <typename T>
class Vector {
    private:
    T *arr;
    int size;
    public:
    Vector() {
        size = 0;
        arr = (T *) malloc(1 * sizeof(T));
    }
    void push_back(T num) {
        arr[size] = num;
        size += 1;
        if(size & (size-1) == 0) {
            arr = (int *) realloc(arr,(size<<1));
        }
    }
    T at(int idx) {
        return arr[idx];
    }
    int length() {
        return size;
    }
};



int main(int argc, char const *argv[]) {
    Vector<int>v[10];
    v[0].push_back(5);
    v[1].push_back(15);
    std::cout<<v[1].at(0)<<std::endl;
}
