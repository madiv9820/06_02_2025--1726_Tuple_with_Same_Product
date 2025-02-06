from typing import List
from collections import defaultdict

from collections import defaultdict

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        # Get the length of the input array
        nums_length = len(nums)
        
        # Create a defaultdict to store lists of pairs (a, b) that produce the same product
        pairs_for_each_product = defaultdict(list)

        # Initialize the total number of valid tuples to 0
        total_number_of_tuples = 0

        # Iterate over all possible pairs (a, b) where a != b
        for a_index in range(nums_length):
            for b_index in range(a_index + 1, nums_length):
                # Calculate the product of the current pair (a, b)
                product = nums[a_index] * nums[b_index]
                
                # Append the pair (a, b) to the list of pairs corresponding to this product
                pairs_for_each_product[product].append((nums[a_index], nums[b_index]))

        # Iterate over each product and the corresponding list of pairs (a, b)
        for product, pairs in pairs_for_each_product.items():
            # Get the number of pairs that produced the same product
            number_of_pairs = len(pairs)
            
            # Calculate the number of valid tuple combinations:
            # - There are `number_of_pairs * (number_of_pairs - 1) // 2` ways to select 2 pairs from 'number_of_pairs'.
            # - Since for each valid tuple (a, b, c, d), there are 8 permutations, multiply by 8.
            total_number_of_tuples += (number_of_pairs * (number_of_pairs - 1) // 2) * 8

        # Return the total number of valid tuples
        return total_number_of_tuples