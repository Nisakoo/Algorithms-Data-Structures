#include <iostream>
#include <algorithm>
#include <stdexcept>

namespace {
const std::size_t kDefaultCapacity = 8;
const std::size_t kGrouthFactor = 2;
}

struct Vector {
    std::size_t size{};
    std::size_t capacity{};
    int* vector{};

    void Resize() {
        this->capacity = kGrouthFactor * this->capacity;

        int* buffer = new int[this->capacity];
        std::copy(this->vector, this->vector + this->size, buffer);

        delete[] this->vector;
        this->vector = buffer;
    }

    void Create() {
        this->size = 0;
        this->capacity = kDefaultCapacity;

        this->vector = new int[this->capacity];
    }

    void Delete() {
        if (!this->vector) {
            throw std::runtime_error("Invalid vector");
        }

        this->size = 0;
        this->capacity = 0;

        delete[] this->vector;

        this->vector = nullptr;
    }

    void PushBack(int value) {
        if (!this->vector) {
            throw std::runtime_error("Invalid vector");
        }

        if (this->size >= this->capacity) {
            Resize();
        }

        this->vector[this->size++] = value;
    }

    int Get(std::size_t index) {
        if (!this->vector) {
            throw std::runtime_error("Invalid vector");
        }

        if (index >= this->size) {
            throw std::runtime_error("Invalid index");
        }

        return this->vector[index];
    }
};

void PrintVector(Vector& vec) {
    if (!vec.size) {
        return;
    }

    for (std::size_t i = 0; i < vec.size; ++i) {
        std::cout << vec.Get(i) << ' ';
    }
    std::cout << std::endl;
}

int main(int, char**) {
    Vector v{};
    v.Create();

    for (int i = 0; i < 10; ++i) {
        v.PushBack(i);
    }

    PrintVector(v);

    v.Delete();

    return 0;
}
