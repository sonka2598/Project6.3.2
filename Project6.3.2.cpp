#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int* data;
    int capacity;
    int size;

public:

    smart_array(int capacity) : capacity(capacity), size(0) {
        data = new int[capacity];
    }

    smart_array(smart_array& s)
        : capacity(s.capacity), size(s.size) {
        data = new int[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = s.data[i];
        }
    }

    smart_array& operator=(smart_array& s) {
        if (this != &s) {
            delete[] data;
            capacity = s.capacity;
            size = s.size;

            data = new int[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = s.data[i];
            }
        }
        return *this;
    }

    void add_element(int value) {
        if (size >= capacity) {
            throw std::out_of_range("Array is full");
        }
        data[size++] = value;
    }

    int get_element(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    ~smart_array() {
        delete[] data;
    }
};


int main()
{
    smart_array a(5);
    a.add_element(1);
    a.add_element(4);
    a.add_element(155);
    smart_array b(2);
    b.add_element(44);
    b.add_element(34);
    a = b; 
    std::cout << "a[0] = " << a.get_element(0) << std::endl; 
    std::cout << "a[1] = " << a.get_element(1) << std::endl; 
    return 0;
}
