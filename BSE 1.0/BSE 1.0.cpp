#include <iostream>
#include <iomanip>


using namespace std;

int main() {

    int size;
    cout << "Enter matrix size: ";
    cin >> size;

    float** array = new float* [size];

    initializeArray(array, size);

    createMatrix(array, size);

    display(array, 3, size);

    findMinValue(array, size);

    display(array, 6, size);

    inverseMainDiagonal(array, size);

    display(array, 6, size);

    findMinInSelectedArea(array, size);

    clearArray(array, size);
}















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

void findMinInSelectedArea(float** array, int size) {


    float minimum = INT_MAX;
    int bound = 0;
    for (int i = size - 1; i > size / 2 - 1; i--)
    {
        for (int j = bound; j < size - bound; j++)
        {

            if (array[i][j] < minimum && array[i][j] > 0)
            {
                minimum = array[i][j];
            }

        }
        bound++;
    }
    cout << "\nMinimum: " << minimum;

}

void clearArray(float **array, int size){

    for (int i = 0; i < size; i++)
    {
        delete [] array[i];
    }
    delete [] array;
}
