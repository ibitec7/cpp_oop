#include <iostream>
#include <stdexcept>
#include <algorithm>

class SafeArray {
protected:
    int sz;
    int* arr;

public:
    SafeArray(int sz) : sz(sz), arr(new int[sz]) {
        std::fill(arr, arr + sz, 0); 
    }

    SafeArray(const SafeArray& other) : sz(other.sz), arr(new int[sz]) {
        std::copy(other.arr, other.arr + sz, arr); 
    }

    ~SafeArray() {
        delete[] arr; 
    }

    int& operator[](int i) {
        if (i < 0 || i >= sz) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[i];
    }

    int size() const {
        return sz;
    }

    void print() const {
        for (int i = 0; i < sz; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SafeArray a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a.print(); 
    std::cout << "Size: " << a.size() << std::endl; 
    SafeArray b = a;
    b.print();
    std::cout << "Size: " << b.size() << std::endl; 
    b[0] = 10;
    b.print(); 
    std::cout << "Size: " << b.size() << std::endl; 

    try {
        b[5] = 10;
    } catch (std::out_of_range& e) {
        std::cout << "Caught an exception of type: " << e.what() << std::endl;
    }
}
