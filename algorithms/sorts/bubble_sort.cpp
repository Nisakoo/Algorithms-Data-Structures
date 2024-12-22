#include <iostream>

void BubbleSort(int* array, std::size_t size) {
    int swaps = 0;

    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                ++swaps;
                std::swap(array[j], array[j + 1]);
            }
        }

        if (!swaps) {
            return;
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

    BubbleSort(array, arraySize);

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
