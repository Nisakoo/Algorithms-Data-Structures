#include <iostream>

void SelectionSort(int* array, std::size_t size) {
    for (std::size_t i = 0; i < size - 1; ++i) {
        std::size_t minElement = i;

        for (std::size_t j = i; j < size; ++j) {
            if (array[minElement] > array[j]) {
                minElement = j;
            }
        }

        if (array[minElement] != array[i]) {
            std::swap(array[minElement], array[i]);
        }
    }
}

int main(int, char**) {
    const int arraySize = 5;
    int array[arraySize] = {6, 2, 9, 1, 3};

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    SelectionSort(array, arraySize);

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
