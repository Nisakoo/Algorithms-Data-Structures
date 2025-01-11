#include <iostream>
#include <random>
#include <cmath>

namespace {
const double kTemperatureCoeff = 0.01;

int GetRandomMoveIndex(int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(0, max);

    return dist(generator);
}

void PrintState(int* state, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << state[i * n + j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
}

double GetTemperature(double t) {
    return t - kTemperatureCoeff;
}

int GetEnergy(int* array, int n) {
    int energy = 0;

    for (int i = 0; i < n * n; ++i) {
        if (array[i]) {
            energy += std::abs(array[i] - i - 1) % n + std::abs(array[i] - i - 1) / n;
        } else {
            energy += std::abs(n * n - i - 1) % n + std::abs(n * n - i - 1) / n;
        }
    }

    return energy;
}

int Move(int* current, int n, int zeroPosition) {
    int x = zeroPosition % n;
    int y = zeroPosition / n;

    int* availableMoves = new int[4]{};
    int moves = -1;

    if (x == 0) {
        availableMoves[++moves] = 1;
    } else if (x == (n - 1)) {
        availableMoves[++moves] = -1;
    } else {
        availableMoves[++moves] = 1;
        availableMoves[++moves] = -1;
    }

    if (y == 0) {
        availableMoves[++moves] = n;
    } else if (y == (n - 1)) {
        availableMoves[++moves] = -n;
    } else {
        availableMoves[++moves] = n;
        availableMoves[++moves] = -n;
    }

    int randomMoveIndex = GetRandomMoveIndex(moves);
    std::swap(current[zeroPosition], current[zeroPosition + availableMoves[randomMoveIndex]]);

    return zeroPosition + availableMoves[randomMoveIndex];
}

double ShouldMakeMove(int de, double temperature) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    return std::exp(-(static_cast<double>(de)/temperature)) > dist(generator);
}

void SimulatedAnneading(int* state, int n, double temperature, double endTemperature) {
    int zeroPosition{};

    for (int i = 0; i < n * n; ++i) {
        if (!state[i]) {
            zeroPosition = i;
            break;
        }
    }

    int i = 0;
    int energy = GetEnergy(state, n);

    std::cout << "Start energy: " << energy << std::endl;
    while (temperature > endTemperature) {
        int newZeroPosition = Move(state, n, zeroPosition);
        int newEnergy = GetEnergy(state, n);

        if (energy > newEnergy) {
            energy = newEnergy;
            zeroPosition = newZeroPosition;
        } else {
            if (ShouldMakeMove(newEnergy - energy, temperature)) {
                energy = newEnergy;
                zeroPosition = newZeroPosition;
            } else {
                std::swap(state[zeroPosition], state[newZeroPosition]);
            }
        }

        temperature = GetTemperature(temperature);
        ++i;
    }

    std::cout << "End energy: " << energy << std::endl;
    std::cout << "Iterations: " << i << std::endl;
    std::cout << std::endl;
}

int main(int, char**) {
    const int n = 3;

    double temperature = 50000.0;
    double endTemperature = 0.01;

    // int* startPosition = new int[n * n]{1, 2, 3, 4, 5, 6, 7, 8, 0};
    int* startPosition = new int[n * n]{6, 7, 0, 2, 4, 3, 5, 8, 1};
    // int* startPosition = new int[n * n]{1, 0, 3, 2};

    PrintState(startPosition, n);
    SimulatedAnneading(startPosition, n, temperature, endTemperature);
    PrintState(startPosition, n);

    return 0;
}
