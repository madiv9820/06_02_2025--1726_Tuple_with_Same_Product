#include <vector>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int tupleCount = 0;  // Initialize a counter for the valid tuples

        // Iterate over all possible combinations of elements (a, b, c, d)
        for(int a: nums) {  // Outer loop for 'a'
            for(int b: nums) {  // Second loop for 'b'
                for(int c: nums) {  // Third loop for 'c'
                    for(int d: nums) {  // Fourth loop for 'd'
                        
                        // Check if all four numbers are distinct
                        if((a != b && a != c && a != d) &&  // 'a' must not be equal to 'b', 'c', or 'd'
                           (b != c && b != d) &&  // 'b' must not be equal to 'c' or 'd'
                           (c != d)) {  // 'c' must not be equal to 'd'
                           
                            // Calculate the product of pairs (a, b) and (c, d)
                            long long prod1 = (long long) a * b;
                            long long prod2 = (long long) c * d;
            
                            // Check if the products of the two pairs are equal
                            if(prod1 == prod2) {
                                ++tupleCount;  // If the products match, increment the tuple count
                            }
                        }
                    }
                }
            }
        }

        return tupleCount;  // Return the total number of valid tuples found
    }
};