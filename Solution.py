from typing import List

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        # Get the length of the input array
        nums_length = len(nums)

        # Sort the array to simplify the search and avoid duplicate calculations
        nums.sort()

        # Initialize a variable to store the total number of valid tuples
        total_number_of_tuples = 0

        # Iterate over all possible values for 'a' (outer loop)
        for a_index in range(nums_length):
            # Iterate over all possible values for 'b', starting from the end of the list
            # to check for pairs (a, b) where b > a
            for b_index in range(nums_length - 1, a_index, -1):
                # Calculate the product of the current pair (a, b)
                product = nums[a_index] * nums[b_index]

                # Use a set to store possible 'c' values that may form valid tuples
                possible_d_values = set()

                # Iterate over all possible values for 'c' that are between 'a' and 'b'
                # These are the elements that lie between a_index and b_index
                for c_index in range(a_index + 1, b_index):
                    # Check if the product of 'a' and 'b' is divisible by nums[c_index]
                    if product % nums[c_index] == 0:
                        # Calculate the corresponding 'd' value
                        d_value = product // nums[c_index]

                        # If 'd_value' is already in the set, then we found a valid tuple (a, b, c, d)
                        if d_value in possible_d_values:
                            # Increment the tuple count by 8, as there are 8 permutations of any valid tuple (a, b, c, d)
                            total_number_of_tuples += 8

                        # Add nums[c_index] to the set of possible 'd' values
                        # for future comparisons with other 'c' values
                        possible_d_values.add(nums[c_index])

        # Return the total number of valid tuples found
        return total_number_of_tuples