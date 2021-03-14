#include <iostream>

using namespace std;

int *print(int *arr, int size){
    cout << "[";
    for(int i = 0;i < size; i++)
        cout << arr[i] << ",";
    cout << "]";
    return arr;
}

int *sort(int *arr, int size) {
    int j, temp;
    for (int i = 1; i < size; i++) {
        j = i;
        temp = arr[i];
        while (arr[j-1] > temp and j > 0) {
            arr[j] = arr[j -1];
            j--;
        }
        arr[j] = temp;
    }
    return arr;
}

int *create(int size, int first = 0, int step = 0){
    int *arr = new int[size];
    arr[0] = first;

    for(int i = 1; i < size; i++){
        arr[i] = arr[i-1] + step;
    }

    return arr;
}

int main(){
    int size, first, step;
    cin >> size >> first >> step;
    int *arr = create(size, first, step);
    sort(arr, size);
    print(arr, size);
    delete [] arr;
}
