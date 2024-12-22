#include <iostream>

void ComparisonsSort(int* array, std::size_t size) {
    std::size_t counts[size];

    for (std::size_t i = 0; i < size; ++i) {
        counts[i] = 0;
        for (std::size_t j = 0; j < size; ++j) {
            if (array[i] > array[j]) {
                ++counts[i];
            }
        }
    }

    int temp[size];
    for (std::size_t i = 0; i < size; ++i) {
        temp[i] = array[i];
    }

    for (std::size_t i = 0; i < size; ++i) {
        array[counts[i]] = temp[i];
    }
}

int main(int, char**) {
    const int arraySize = 5;
    int array[arraySize] = {6, 2, 9, 1, 3};

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    ComparisonsSort(array, arraySize);

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
