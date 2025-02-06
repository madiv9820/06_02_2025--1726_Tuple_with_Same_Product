from typing import List

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        tupleCount = 0  # Initialize the variable to count valid tuples
        
        # Iterate over all possible pairs (a, b) and (c, d)
        for a in nums:
            for b in nums:
                for c in nums:
                    for d in nums:
                        # Check if a, b, c, d are distinct elements and the product of (a * b) equals the product of (c * d)
                        if((a != b and a != c and a != d) and  # Ensure 'a' is distinct from 'b', 'c', and 'd'
                           (b != c and b != d) and  # Ensure 'b' is distinct from 'c' and 'd'
                           (c != d) and  # Ensure 'c' is distinct from 'd'
                           (a * b == c * d)):  # Check if the product of (a * b) equals the product of (c * d)
                            tupleCount += 1  # If the conditions are met, increment the tupleCount
        
        # Return the total count of valid tuples
        return tupleCount