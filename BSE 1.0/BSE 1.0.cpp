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



void findMinValue(float **array, int size){

    float minEl;
    for (int i = 0; i < size; i++)
    { 
        minEl = minOfSting(array[i], size);
        for (int j = 0; j < size; j++)
        {
            array[i][j] /= minEl;
            array[i][j] = int(array[i][j]*100)/100.0;
        }
    }
}

void inverseMainDiagonal(float** array, int size) {

    float temp;
    for (int i = 0; i < (int)size / 2; i++)
    {
        temp = array[i][i];
        array[i][i] = array[size - 1 - i][size - 1 - i];
        array[size - i - 1][size - i - 1] = temp;
    }
}

float minOfSting(float *array, int size){

    float min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}
