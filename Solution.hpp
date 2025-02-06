#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Get the size of the input array
        int nums_length = nums.size();
        
        // Sort the array to simplify the search process and avoid duplicates
        sort(nums.begin(), nums.end());

        // Initialize the total number of valid tuples
        int total_number_of_tuples = 0;

        // Outer loop: Iterate through the elements of the array for the first pair (a, b)
        for(int a_index = 0; a_index < nums_length; ++a_index) {
            // Inner loop: Iterate backward to select the second pair (b) for the current 'a'
            for(int b_index = nums_length-1; b_index > a_index; --b_index) {
                // Get the values of 'a' and 'b' for the current combination
                long a = nums[a_index];
                long b = nums[b_index];
                // Calculate the product of 'a' and 'b'
                int product = a * b;

                // Set to store potential 'd' values for valid tuples
                unordered_set<long> possible_d_values;

                // Loop through the elements between 'a_index' and 'b_index' to find valid 'c' and 'd' values
                for(int c_index = a_index + 1; c_index < b_index; ++c_index) {
                    // Get the value of 'c' for the current position
                    int c = nums[c_index];

                    // Check if 'c' is a divisor of the product
                    if(product % c == 0) {
                        // Calculate the corresponding 'd' value
                        int d = product / c;

                        // If 'd' is found in the set of possible 'd' values, it's a valid tuple
                        if(possible_d_values.find(d) != possible_d_values.end()) {
                            // If we found a valid tuple (a, b, c, d), we add 8 to the count
                            // This accounts for all 8 permutations of the tuple (a, b, c, d)
                            total_number_of_tuples += 8;
                        }

                        // Insert 'c' into the set of possible 'd' values
                        possible_d_values.insert(c);
                    }
                }
            }
        }

        // Return the total number of valid tuples found
        return total_number_of_tuples;
    }
};