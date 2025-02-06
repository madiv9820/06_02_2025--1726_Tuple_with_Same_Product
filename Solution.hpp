#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Get the length of the input array
        int nums_length = nums.size();

        // Create an unordered_map to store pairs of numbers that give the same product
        // The key is the product, and the value is a vector of pairs (a, b)
        unordered_map<long, vector<vector<int>>> pairs_for_each_product;

        // Initialize the total number of valid tuples to 0
        int total_number_of_tuples = 0;

        // Iterate over all possible pairs (a, b) where a != b
        for(int a_index = 0; a_index < nums_length; a_index++) {
            for(int b_index = a_index + 1; b_index < nums_length; b_index++) {
                // Calculate the product of the current pair (a, b)
                long product = long(nums[a_index]) * nums[b_index];

                // Store the pair (a, b) in the map, using the product as the key
                // If there are multiple pairs with the same product, they will be stored in the vector
                pairs_for_each_product[product].push_back({nums[a_index], nums[b_index]});
            }
        }

        // Iterate over each product in the map and calculate how many valid tuples can be formed
        for(auto& [product, pairs] : pairs_for_each_product) {
            // Get the number of pairs that produced the same product
            int number_of_pairs = pairs.size();

            // If there are 'n' pairs with the same product, the number of valid tuples is given by
            // n * (n - 1) / 2 (which is the number of ways to select 2 pairs from n pairs)
            // Since each valid tuple can be arranged in 8 different ways (permutations of 4 distinct elements),
            // we multiply by 8 to count all the permutations.
            total_number_of_tuples += (number_of_pairs * (number_of_pairs - 1) / 2) * 8;
        }

        // Return the total number of valid tuples found
        return total_number_of_tuples;
    }
};