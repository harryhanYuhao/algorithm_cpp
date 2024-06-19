#include <iostream>

#include "sort/sort.h"
#include "test_util.h"

int main() {
    std::vector<int> input = test_util::shuffled_vec_int(100);
    test_util::print_vec(input);

    std::vector<int> output = sort::insertion_sort(input);
    test_util::print_vec(output);
    test_util::print_vec(input);

    return 0;
}
