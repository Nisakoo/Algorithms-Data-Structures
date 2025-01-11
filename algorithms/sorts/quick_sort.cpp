#include <iostream>

void PrintArray(int* array, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int Partition(int* array, int l, int r) {
    int m = array[l + (r - l) / 2];

    while (l <= r) {
        while (array[l] < m) {
            ++l;
        }

        while (array[r] > m) {
            --r;
        }

        if (l >= r) {
            break;
        }

        std::swap(array[l++], array[r--]);
    }

    return r;
}

void QuickSort(int* array, int l, int r) {
    if (l < r) {
        int q = Partition(array, l, r);

        // std::cout << q << std::endl;
        // PrintArray(array, r - l + 1);
        QuickSort(array, l, q);
        // return;
        QuickSort(array, q + 1, r);
    }
}

int main(int, char**) {
    const int arraySize = 13;
    int array[arraySize] = {6, 2, 9, 1, 5, 8, 1, 3, 0, 4, -1, 4, 1};

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    QuickSort(array, 0, arraySize - 1);

    for (std::size_t i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
