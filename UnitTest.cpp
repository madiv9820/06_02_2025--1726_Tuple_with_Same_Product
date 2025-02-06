#include <iostream>
#include "Solution.hpp"

class UnitTest {
private:
    Solution sol;
    vector<pair<vector<int>, int>> testcases;
    void test_case_basic_small_case_1() {
        vector<int> nums = testcases[0].first;
        int output = testcases[0].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case Basic Small Case 1: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_all_numbers_are_powers_of_2() {
        vector<int> nums = testcases[1].first;
        int output = testcases[1].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case All Numbers Are Powers of 2: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_multiple_combinations() {
        vector<int> nums = testcases[2].first;
        int output = testcases[2].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case Multiple Combinations: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_larger_numbers() {
        vector<int> nums = testcases[3].first;
        int output = testcases[3].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case Larger Numbers: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_sparse_set_of_numbers() {
        vector<int> nums = testcases[4].first;
        int output = testcases[4].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case Sparse Set of Numbers: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_increasing_numbers_with_no_pair_multiplicative_relationships() {
        vector<int> nums = testcases[5].first;
        int output = testcases[5].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case Increasing Numbers with No Pair Multiplicative Relationships: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_mixed_large_and_small_numbers() {
        vector<int> nums = testcases[6].first;
        int output = testcases[6].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case Mixed Large and Small Numbers: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_single_number() {
        vector<int> nums = testcases[7].first;
        int output = testcases[7].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case Single Number: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_all_pair_multiplicative_relationships() {
        vector<int> nums = testcases[8].first;
        int output = testcases[8].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case All Pair Multiplicative Relationships: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_max_constraint() {
        vector<int> nums = testcases[9].first;
        int output = testcases[9].second;
        int result = sol.tupleSameProduct(nums);
        cout << result << endl;
        cout << "Test Case Max Constraint: " << ((result == output) ? "passed": "failed") << endl;
    }
    void test_case_basic_small_case_2() {
        vector<int> nums = testcases[10].first;
        int output = testcases[10].second;
        int result = sol.tupleSameProduct(nums);
        cout << "Test Case Basic Small Case 2: " << ((result == output) ? "passed": "failed") << endl;
    }
public:
    UnitTest() {
        testcases = {{{2,3,4,6}, 8}, {{1,2,4,8,16}, 24}, {{1,2,3,6,12}, 16},
                        {{5,10,20,25,50}, 16}, {{2,5,7,11,13}, 0}, {{1,3,7,11,17}, 0},
                        {{1,2,3,6,12,15}, 16}, {{1}, 0}, {{1,2,4,8,16,32}, 56},
                        {{535,634,280,538,517,861,363,
                            670,817,885,89,595,813,633,674,
                            652,117,179,133,887,430,729,818,297,
                            47,18,889,202,329,374,328,427,694,660,
                            943,577,253,506,385,748,616,147,162,537,
                            304,158,168,467,453,426,645,292,822,203,
                            296,980,316,695,323,27,480,715,268,906,361,
                            955,966,768,441,49,588,231,988,539,376,921,
                            890,334,597,586,384,923,942,713,858,765,129,
                            600,145,154,798,797,902,722,693,940,331,138,727,223}, 480},
                        {{1,2,4,5,10}, 16}};
    }
    void test() {
        // test_case_basic_small_case_1();
        // test_case_basic_small_case_2();
        // test_case_all_numbers_are_powers_of_2();
        // test_case_multiple_combinations();
        // test_case_larger_numbers();
        // test_case_sparse_set_of_numbers();
        // test_case_increasing_numbers_with_no_pair_multiplicative_relationships();
        // test_case_mixed_large_and_small_numbers();
        // test_case_single_number();
        // test_case_all_pair_multiplicative_relationships();
        test_case_max_constraint();
    }
};

int main() {
    UnitTest ut;
    ut.test();
    return 0;
}