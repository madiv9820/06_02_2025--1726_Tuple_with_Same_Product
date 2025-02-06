from Solution import Solution
from timeout_decorator import timeout
import unittest

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__sol = Solution()
        self.__testcases = (([2,3,4,6], 8), ([1,2,4,5,10], 16),
                            ([2,3,4,6,8,12], 288), ([2,3,5,7], 0), 
                            ([2,3,4,6,8,12,16], 1080), ([2,3,4,6,8,12,16,24], 4320), 
                            ([2,3,4,6,8,12,16,24,32], 14400), ([2,3,4,6,8,12,16,24,32,48], 43200), 
                            ([2,3,4,6,8,12,16,24,32,48,64], 115200), ([2,3,4,6,8,12,16,24,32,48,64,96], 345600), 
                            ([2,3,4,6,8,12,16,24,32,48,64,96,128], 1036800), 
                            ([2,3,4,6,8,12,16,24,32,48,64,96,128,192], 3110400), 
                            ([2,3,4,6,8,12,16,24,32,48,64,96,128,192,256], 9331200), 
                            ([2,3,4,6,8,12,16,24,32,48,64,96,128,192,256,384], 27993600), 
                            ([2,3,4,6,8,12,16,24,32,48,64,96,128,192,256,384,512], 83980800), 
                            ([2,3,4,6,8,12,16,24,32,48,64,96,128,192,256,384,512,768], 251942400))
        return super().setUp()
    
    @timeout(1)
    def test_solution(self):
        for i, (nums, expected) in enumerate(self.__testcases):
            with self.subTest(test = i):
                self.assertEqual(self.__sol.tupleSameProduct(nums), expected)

if __name__ == "__main__":
    unittest.main()