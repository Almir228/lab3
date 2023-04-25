#include <iostream>


struct DynamicArray{
    int* value;
    int capasity;
    int size;
    int step;
};


DynamicArray create_array(int capasity) {
    DynamicArray arr{};
    arr.value = new int[capasity];
    arr.capasity = capasity;
    return arr;
}


DynamicArray fill_array(int size, int step) {
    DynamicArray arr{};
    arr.value = new int[size];
    arr.capasity = size;

    arr.step = step;
    return arr;
}

void delete_array(DynamicArray arr) {
    delete[] arr.value;
}



void delete_ell(DynamicArray *arr, int index){
    for (int i = index; i < arr->capasity-1; i++) {
        arr->value[i] = arr->value[i + 1];
    }
    --arr->capasity;
}

void print_array(DynamicArray arr){
    for (int i = 0; i < arr.size; ++i){
        std::cout<< arr.value[i]<< ' ';
    }
    std::cout<<'\n';
}


DynamicArray resize_x_2(DynamicArray arr) {
    DynamicArray newArr{};
    int newCap = arr.capasity * 2;
    newArr.size = arr.size;
    newArr.value = new int[newCap];
    newArr.capasity = newCap;
    for (int i = 0; i < arr.capasity; i++) {
        newArr.value[i] = arr.value[i];
    }
    delete[] arr.value;
    return newArr;
}

DynamicArray resize_plus_1(DynamicArray arr) {
    DynamicArray newArr{};
    int newSize = arr.capasity + 1;
    newArr.size = arr.size;
    newArr.value = new int[newSize];
    newArr.capasity = newSize;
    for (int i = 0; i < arr.capasity; i++) {
        newArr.value[i] = arr.value[i];
    }
    delete[] arr.value;
    return newArr;
}

DynamicArray resize_const(DynamicArray arr) {
    DynamicArray newArr{};
    int newSize = arr.capasity+arr.step;
    newArr.value = new int[newSize];
    newArr.size = arr.size;
    newArr.capasity = newSize;
    newArr.step = arr.step;
    for (int i = 0; i < arr.capasity; i++) {
        newArr.value[i] = arr.value[i];
    }
    delete[] arr.value;
    return newArr;
}

int get_value(DynamicArray arr, int index) {
    if (index >= 0 && index < arr.capasity) {
        return arr.value[index];
    }
    return -1;
}

void push_back(DynamicArray* arr, int value, DynamicArray (*func)(DynamicArray arr) = resize_x_2){
    int size = arr->size;
    if(arr->size == arr->capasity)
        *arr = func(*arr);
    arr->value[size] = value;
    arr->size++;
}

void set_value (DynamicArray* arr, int index, int value,
                DynamicArray (*func)(DynamicArray arr) = resize_x_2){
    if (index >= 0 && index < arr->size) {
        arr->value[index] = value;
    }
    else if (index == arr->size) {
        push_back(arr, value, func);
    }
    else{
        std::cout<<"Error: Index out of range."<<std::endl;
    }
}