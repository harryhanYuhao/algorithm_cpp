#include "sort.h"
#include <iostream>

std::vector<int> sort::merge_sort(std::vector<int>& input) {

    std::vector<int> ret; // the returned vector
    if (input.size() == 1) {
        return input;
    }
    if (input.size() == 2) {
        if (input[0] > input[1]) {
            ret.push_back(input[1]);
            ret.push_back(input[0]);
        } else {
            ret.push_back(input[0]);
            ret.push_back(input[1]);
        }

        return ret;
    }

    std::vector<int> v1 =
        std::vector<int>(input.begin(), input.begin() + input.size() / 2);
    std::vector<int> v2 =
        std::vector<int>(input.begin() + input.size() / 2, input.end());
    // divide and conquer
    auto res1 = sort::merge_sort(v1);
    auto res2 = sort::merge_sort(v2);
    // merge them
    auto i = res1.begin();
    auto j = res2.begin();
    while (i != res1.end() || j != res2.end()) {
        if (i == res1.end()) {
            ret.push_back(*j);
            j++;
            continue;
        }
        if (j == res2.end()) {
            ret.push_back(*i);
            i++;
            continue;
        }
        if (*j > *i) {
            ret.push_back(*i);
            i++;
            continue;
        }
        ret.push_back(*j);
        j++;
    }
    return ret;
}
