#include <iostream>
#include "Libaries/Dynamic_array/Dynamic_array.h"

int main(){
    DynamicArray arr = create_array(10);
    for (int i = 0; i < 10; ++i) {
        push_back(&arr, i);
    }
    push_back(&arr, 10);
    push_back(&arr, 11);
    print_array(arr);
    set_value(&arr, 12, 1000);
    print_array(arr);
}
