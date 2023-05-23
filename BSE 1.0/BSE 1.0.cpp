#include <iostream>
#include <iomanip>


using namespace std;

















void initializeArray(float** array, int size) {

    for (int i = 0; i < size; i++)
    {
        array[i] = new float[size];
    }
}