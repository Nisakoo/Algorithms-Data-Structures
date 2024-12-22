#include <iostream>

int LeftBinarySearch(int* array, int size, int key) {
    int low = -1;
    int high = size;
    int mid{};

    while (low < high - 1) {
        mid = low + (high - low) / 2;

        if (array[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return high;
}

int RightBinarySearch(int* array, int size, int key) {
    int low = -1;
    int high = size;
    int mid{};

    while (low < high - 1) {
        mid = low + (high - low) / 2;

        if (array[mid] > key) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return low;
}

int main(int, char**) {
    const int arraySize = 7;
    int array[arraySize] = {1, 1, 1, 2, 2, 2, 2};

    int leftBound = LeftBinarySearch(array, arraySize, 2);
    int rightBound = RightBinarySearch(array, arraySize, 2);

    std::cout << leftBound << ' ' << rightBound << std::endl;

    return 0;
}
