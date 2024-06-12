#include "sort.h"
using namespace std;

std::vector<int> sort::insertion_sort(std::vector<int> &input) {
    std::vector<int> ret =
        std::vector<int>(input.begin(), input.end()); // copy input
    for (int i = 2; (long unsigned int)i <= ret.size(); ++i) {
        int target = ret[i - 1];
        for (int j = i - 1; j > 0; --j) {
            if (ret[j - 1] > target) {
                ret[j] = ret[j - 1];
                ret[j - 1] = target;
            } else {
                break; // j is not incremented when breaking
            }
        }
    }
    return ret;
}
