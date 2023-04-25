#pragma
#include <iostream>


struct DynamicArray {
    int *value;
    int capasity;
    int size;
    int step;
};

DynamicArray create_array(int capasity);
void delete_array(DynamicArray arr);
void delete_ell(DynamicArray *arr, int index);
void print_array(DynamicArray arr);
DynamicArray resize_x_2(DynamicArray arr);
int get_value(DynamicArray arr, int index);
void push_back(DynamicArray* arr, int value, DynamicArray (*func)(DynamicArray arr) = resize_x_2);
void set_value (DynamicArray* arr, int index, int value, DynamicArray (*func)(DynamicArray arr) = resize_x_2);
DynamicArray fill_array(int size, int step);
DynamicArray resize_const(DynamicArray arr);
DynamicArray resize_plus_1(DynamicArray arr);