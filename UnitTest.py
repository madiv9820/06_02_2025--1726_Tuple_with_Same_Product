from Solution import Solution
from timeout_decorator import timeout
import unittest

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__sol = Solution()
        self.__testcases = (([2,3,4,6], 8), ([1,2,4,8,16], 24), ([1,2,3,6,12], 16),
                            ([5,10,20,25,50], 16), ([2,5,7,11,13], 0), ([1,3,7,11,17], 0),
                            ([1,2,3,6,12,15], 16), ([1], 0), ([1,2,4,8,16,32], 56),
                            ([535,634,280,538,517,861,363,
                              670,817,885,89,595,813,633,674,
                              652,117,179,133,887,430,729,818,297,
                              47,18,889,202,329,374,328,427,694,660,
                              943,577,253,506,385,748,616,147,162,537,
                              304,158,168,467,453,426,645,292,822,203,
                              296,980,316,695,323,27,480,715,268,906,361,
                              955,966,768,441,49,588,231,988,539,376,921,
                              890,334,597,586,384,923,942,713,858,765,129,
                              600,145,154,798,797,902,722,693,940,331,138,727,223], 480),
                            ([1,2,4,5,10], 16))
        return super().setUp()
    
    @timeout(0.5)
    def test_case_basic_small_case_1(self):
        nums, output = self.__testcases[0]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)

    @timeout(0.5)
    def test_case_all_numbers_are_powers_of_2(self):
        nums, output = self.__testcases[1]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)

    @timeout(0.5)
    def test_case_multiple_combinations(self):
        nums, output = self.__testcases[2]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)
    
    @timeout(0.5)
    def test_case_larger_numbers(self):
        nums, output = self.__testcases[3]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)
    
    @timeout(0.5)
    def test_case_sparse_set_of_numbers(self):
        nums, output = self.__testcases[4]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)
    
    @timeout(0.5)
    def test_case_increasing_numbers_with_no_pair_multiplicative_relationships(self):
        nums, output = self.__testcases[5]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)
    
    @timeout(0.5)
    def test_case_mixed_large_and_small_numbers(self):
        nums, output = self.__testcases[6]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)
    
    @timeout(0.5)
    def test_case_single_number(self):
        nums, output = self.__testcases[7]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)
    
    @timeout(0.5)
    def test_case_all_pair_multiplicative_relationships(self):
        nums, output = self.__testcases[8]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)
    
    @timeout(0.5)
    def test_case_max_constraint(self):
        nums, output = self.__testcases[9]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)

    @timeout(0.5)
    def test_case_basic_small_case_2(self):
        nums, output = self.__testcases[10]
        self.assertEqual(self.__sol.tupleSameProduct(nums), output)


if __name__ == "__main__":
    unittest.main()