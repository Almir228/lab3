#include "../Libaries/Dynamic_array/Dynamic_array.h"
#include <chrono>
#include <fstream>



int main() {

    std::ofstream fout("py_graphics/task2.3.py");

    fout << "from matplotlib import pyplot as plt\nimport numpy as np\n";

    fout << "am_of_ells = [";

    int value[] = {100,228,400,1337,1600,3200,5000,7000,10000,15000,20000,
                   25000,35000,45000,60000,75000,95000,115000,140000,165000,
                   195000,225000,250000,295000,335000,375000,420000,465000,499999, 510000

    };
    for ( int i : value ){
        fout << i << " ,";
    }
    fout << "]\n";
    int amount = sizeof(value)/sizeof(int);
    int Size[amount];
    fout << "time = [";
    for( int i:value) {
        DynamicArray arr = fill_array(1, 1000);

        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j<i;++j) {
            set_value(&arr, j, j, resize_x_2);
        }
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
    fout << "plt.savefig('graphics/task2.3.pdf')";
    fout << "\n";
    fout << "plt.show()";
    return 0;
}