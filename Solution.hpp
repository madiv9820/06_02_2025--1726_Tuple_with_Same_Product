#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Get the length of the input array
        int nums_length = nums.size();

        // Create an unordered_map to store the count of pairs (a, b) that give the same product.
        // The key is the product (a * b), and the value is the number of pairs (a, b) that result in this product.
        unordered_map<long, int> pairs_for_each_product;

        // Initialize the total number of valid tuples to 0
        int total_number_of_tuples = 0;

        // Iterate over all possible pairs (a, b) where a != b
        for(int a_index = 0; a_index < nums_length; a_index++) {
            for(int b_index = a_index + 1; b_index < nums_length; b_index++) {
                // Calculate the product of the current pair (a, b)
                long product = long(nums[a_index]) * nums[b_index];

                // Increment the count for this product in the unordered_map
                // If this product has been encountered before, its count will be incremented
                ++pairs_for_each_product[product];
            }
        }

        // Iterate over each product and its corresponding count of pairs
        for(auto& [product, number_of_pairs] : pairs_for_each_product) {
            // If there are 'n' pairs with the same product, the number of ways to pick 2 distinct pairs is given by:
            // n * (n - 1) / 2 (this is the combination formula for selecting 2 pairs from 'n' pairs)
            // Since each valid tuple has 8 distinct permutations (since order matters), 
            // we multiply the result by 8 to count all the permutations.
            total_number_of_tuples += (number_of_pairs * (number_of_pairs - 1) / 2) * 8;
        }

        // Return the total number of valid tuples found
        return total_number_of_tuples;
    }
};