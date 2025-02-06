# 1726. Tuple with Same Product (All Approaches)
- ## Approach 1:- Brute Force
    - ### Intuition:
        The problem is asking us to find the number of valid tuples `(a, b, c, d)` such that the product of `a * b` is equal to the product of `c * d`. The key observation is that, once we ensure all numbers in the tuple are distinct, the problem boils down to counting how many times the product of two pairs is equal.

        Since all elements are distinct, we need to explore every possible pair of elements from the input array. The naive approach is to check all combinations of four distinct numbers `(a, b, c, d)` from the list, compute the products, and compare them. The challenge is to handle large input sizes efficiently.

    - ### Approach:
        1. **Brute Force Approach:**
            - Iterate over all possible combinations of four elements from the array. Specifically, four nested loops will be used to check each possible combination of `(a, b, c, d)`.
            - For each combination, ensure that the elements are distinct.
            - Calculate the products of `(a * b)` and `(c * d)`. If the products are equal, increment the tuple count.
        
        2. **Avoid Counting Same Tuples Multiple Times:**
            - To ensure that we don't count the same tuple multiple times (e.g., `(a, b, c, d)` and `(c, d, a, b)`), the solution uses the condition of distinct elements `a != b != c != d` in the nested loops.

        3. **Output the Result:**
            - Return the total number of valid tuples found.
    
    - ### Code Implementation:
        - **Python Solution:**
            ```python3 []
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
            ```
        - **C++ Solution:**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - The approach uses **four nested loops**, each iterating over the entire list `nums`. If the size of the list is `n`, each loop runs `n` times.
        
        Therefore, the time complexity is **$O(n^4)$**, where $n$ is the length of the input array.

    - ### Space Complexity:
        - The space complexity is **$O(1)$** because we are only using a few extra variables (e.g., `prod1`, `prod2`, and `tupleCount`) and not storing any additional data structures that grow with input size.
<hr>