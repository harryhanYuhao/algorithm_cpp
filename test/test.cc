#include <catch2/catch_test_macros.hpp>

#include "../sort/sort.h"
#include "../test_util.h"

TEST_CASE("insertion_sort", "[sort]") {
    std::vector<int> input = test_util::shuffled_vec_int(100);
    std::vector<int> output = sort::insertion_sort(input);
	REQUIRE( test_util::validate_ascend(output) == true );
}
