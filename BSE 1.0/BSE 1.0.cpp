#include <iostream>
#include <iomanip>


using namespace std;

















void initializeArray(float** array, int size) {

    for (int i = 0; i < size; i++)
    {
        array[i] = new float[size];
    }
}

void createMatrix(float** array, int size) {

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = -12 + rand() % (12 + 12 - 1);
        }
    }
}

void display(float **array, int width, int size){

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout << setw(width) << array[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
