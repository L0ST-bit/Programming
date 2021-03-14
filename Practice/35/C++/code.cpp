#include <iostream>

struct IntArray {
  int *data;
  int size;
};

void create(IntArray& arr, int size) {
    arr.data = new int[size];
    arr.size = size;
}

void create(IntArray* arr, int size) {
    create(*arr, size);
}

int get(IntArray& arr, int index) {
    if (index < 0 or index >= arr.size) {
        std::cerr << "The index is outside the array" << std::endl;
        exit(1);
    }
    return arr.data[index];
}

int get(IntArray* arr, int index) {
    return get(*arr, index);
}


void destroy(IntArray& arr) {
    if (!arr.data) {
        return;
    }

    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
}

void destroy(IntArray* arr) {
    destroy(*arr);
}

int main() {
    IntArray arr;
    create(arr, 30);

    for (int i = 0; i < 30; i++) {
        set(arr, i, i + 1);
    }


    destroy(arr);
}
