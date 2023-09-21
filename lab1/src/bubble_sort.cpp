#include <iostream>
#include <cstdlib>
#include <string>

class Array{
    int* arr;
    size_t size;
public:
    explicit Array(size_t size): arr(new int[size]{}), size(size){
        for(size_t i = 0; i < size; i++){
            arr[i] = rand();
//            std::cin >> arr[i];
        }
    }
    int &operator[](size_t i){
        return arr[i];
    }
    size_t get_size() const {
        return size;
    }
    ~Array(){
        delete[] arr;
    }
};

void swap(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort(Array& arr){
    for (int i = 0; i < arr.get_size(); i++) {
        for (int j = 0; j < arr.get_size(); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void print(Array& arr) {
    size_t size = arr.get_size();
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
}

int main(int argv, char** argc){
    if(argv == 2){
        size_t size = std::stoi(argc[1]);
        Array arr(size);
        bubble_sort(arr);
    }
//    print(arr);
    return 0;
}





//    Array(const Array& other) : arr(new int[other.size]), size(other.size) {
//        for (size_t i = 0; i < size; i++) {
//            arr[i] = other.arr[i];
//        }
//    }
//
//    Array& operator=(const Array& other) {
//        if (this != &other) {
//            delete[] arr;
//            size = other.size;
//            arr = new int[size];
//            for (size_t i = 0; i < size; i++) {
//                arr[i] = other.arr[i];
//            }
//        }
//        return *this;
//    }
//







//#include <iostream>
//#include <cstdlib>
//
//template <class t>
//class Array{
//    t* arr;
//    size_t size;
//public:
//    explicit Array(size_t size): arr(new int[size]{}), size(size){
//        for(size_t i = 0; i < size; i++){
//            arr[i] = rand();
////            std::cin >> arr[i];
//        }
//    }
//    Array(const Array& other): arr(new int[*other.arr]), size(size){}
//    Array &operator=(const Array& other){
//        *arr = *other.arr;
//    }
//    t &operator[](size_t i){
//        return arr[i];
//    }
//    size_t get_size() const {
//        return size;
//    }
//    ~Array(){
//        delete[] arr;
//    }
//};
//
//void swap(int* x, int* y){
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//
//template <class t>
//void bubble_sort(Array<t>& arr){
//    for (int i = 0; i < arr.get_size(); i++) {
//        for (int j = 0; j < arr.get_size(); j++) {
//            if (arr[j] > arr[j + 1]) {
//                swap(&arr[i], &arr[i + 1]);
//            }
//        }
//    }
//}
//
//template <class t>
//void print(Array<t>& arr) {
//    size_t size = arr.get_size();
//    for (size_t i = 0; i < size; i++) {
//        std::cout << arr[i] << ' ';
//    }
//}
//
//int main(){
//    size_t size = 0;
//    std::cin >> size;
//    Array<int> arr(size);
//    bubble_sort(arr);
//    print(arr);
//    return 0;
//}