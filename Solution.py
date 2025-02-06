from typing import List
from collections import defaultdict

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        # Get the length of the input array
        nums_length = len(nums)
        
        # Create a defaultdict to store the count of pairs (a, b) that produce the same product
        # The key is the product, and the value is the number of pairs that result in that product
        pairs_for_each_product = defaultdict(int)

        # Initialize the total number of valid tuples to 0
        total_number_of_tuples = 0

        # Iterate over all possible pairs (a, b) where a != b
        for a_index in range(nums_length):
            for b_index in range(a_index + 1, nums_length):
                # Calculate the product of the current pair (a, b)
                product = nums[a_index] * nums[b_index]
                
                # Increment the count for this product in the dictionary
                pairs_for_each_product[product] += 1

        # Iterate over each product and the corresponding count of pairs (a, b)
        for product, number_of_pairs in pairs_for_each_product.items():
            # For each product, calculate the number of valid tuple combinations
            # The number of ways to select 2 distinct pairs from 'number_of_pairs' is 'number_of_pairs * (number_of_pairs - 1) // 2'
            # Each valid pair combination corresponds to 8 permutations of (a, b, c, d), so multiply by 8
            total_number_of_tuples += (number_of_pairs * (number_of_pairs - 1) // 2) * 8

        # Return the total number of valid tuples
        return total_number_of_tuples