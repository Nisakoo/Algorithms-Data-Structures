#include <iostream>

int* Merge(int* first, std::size_t firstSize, int* second, std::size_t secondSize) {
    std::size_t size = firstSize + secondSize;

    int* temp = new int[size]{};

    int firstPtr = 0;
    int secondPtr = 0;

    while ((firstPtr + secondPtr) < size) {
        int index = firstPtr + secondPtr;
        if ((firstPtr < firstSize) && (secondPtr < secondSize)) {
            if (first[firstPtr] <= second[secondPtr]) {
                temp[index] = first[firstPtr++];
            } else {
                temp[index] = second[secondPtr++];
            }
        } else {
            if (firstPtr == firstSize) {
                temp[index] = second[secondPtr++];
            } else {
                temp[index] = first[firstPtr++];
            }
        }
    }

    return temp;
}

void MergeSort(int* array, std::size_t size) {
    if (size <= 1) {
        return;
    }

    int* first = array;
    int* second = array + (size / 2);

    std::size_t firstSize = size / 2;
    std::size_t secondSize = size - firstSize;

    MergeSort(first, firstSize);
    MergeSort(second, secondSize);

    int* temp = Merge(first, firstSize, second, secondSize);

    for (std::size_t i = 0; i < size; ++i) {
        array[i] = temp[i];
    }

    delete[] temp;
}

int main(int, char**) {
    const int arraySize = 13;
    int array[arraySize] = {6, 2, 9, 1, 5, 8, 1, 3, 0, 4, -1, 4, 1};

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    MergeSort(array, arraySize);

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
