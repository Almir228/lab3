#include "../Libaries/Dynamic_array/Dynamic_array.h"
#include <chrono>
#include <fstream>



int main() {

    std::ofstream fout("py_graphics/task2.2.py");

    fout << "from matplotlib import pyplot as plt\nimport numpy as np\n";

    fout << "am_of_ells = [";

    int value[] = {100,228,400,1337,1600,3200,5000,7000,10000,15000,20000,
                   25000,35000,45000,60000,75000,95000};
    for ( int i : value ){
        fout << i << " ,";
    }
    fout << "]\n";
    int amount = sizeof(value)/sizeof(int);
    int Size[amount];
    fout << "time = [";
    for( int i:value) {
        DynamicArray arr = create_array(1);

        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j<i;++j) {
            set_value(&arr, j, j, resize_const);
        }
        //printArray(arr);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        fout << time_span.count() << " ,";

        std::cout<<i<<std::endl;
        delete_array(arr);
    }

    fout << "]\n";
    fout << "plt.grid()";
    fout << "\n";
    fout << "plt.plot(am_of_ells, time, '.')";
    fout << "\n";
    fout << "plt.savefig('graphics/task2.2.pdf')";
    fout << "\n";
    fout << "plt.show()";
    return 0;
}