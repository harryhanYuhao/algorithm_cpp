#include <algorithm>
#include <iostream>
#include <random>

#include "util.h"

// initialisation
static std::mt19937 mersenne_engine{std::random_device{}()};
static std::uniform_int_distribution<int> dist{-100000, 100000};

int util::random_int() {
    int a = dist(mersenne_engine);
    return a;
}

// return a shuffleld vector containing values from 0 ... length - 1
std::vector<int> util::shuffled_vec_int(long unsigned int length) {
    std::vector<int> values(length);
    std::iota(
        values.begin(), values.end(),
        0); // use iota to generate vector holding values from 0 to length - 1
    std::shuffle(values.begin(), values.end(), mersenne_engine);
    return values;
}

bool util::validate_ascend(std::vector<int> &input) {
    for (int i = 1; (long unsigned int)i < input.size(); i++) {
        if (input[i] < input[i - 1]) {
            return false;
        }
    }
    return true;
}

void util::print_vec(std::vector<int> &input) {
    for (auto i : input) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
