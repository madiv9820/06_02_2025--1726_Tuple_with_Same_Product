# 1726. Tuple with Same Product (All Approaches)
For **complete solution and test cases**, please **refer** here:- [Tuple with Same Product](https://github.com/madiv9820/06_02_2025--1726_Tuple_with_Same_Product)

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

- ## Approach 2:- Brute Force Optimization
    - ### Intuition:
        The problem asks us to find the number of valid tuples `(a, b, c, d)` such that `a * b = c * d`, where `a`, `b`, `c`, and `d` are distinct elements from the input array `nums`. 

        - We can iterate over all pairs `(a, b)` and for each pair, calculate the product `a * b`.
        - Then, for each such product, we try to find other pairs `(c, d)` such that `c * d = a * b` and all elements `a`, `b`, `c`, and `d` are distinct.
        - We ensure that all four elements are distinct and check if the product conditions hold. If so, we increase the tuple count.
        - To efficiently find valid pairs `(c, d)`, we use a set to store previously seen values of `c`, making it easier to check if `d` exists.

    - ### Approach:
        1. **Sorting the Array:**
            - First, sort the array `nums`. Sorting helps in efficiently managing the search for valid pairs and avoids considering the same element multiple times.        
        2. **Outer Loops (Iterating over all pairs `(a, b)`):**
            - We iterate over all possible pairs `(a, b)` where `a != b` using two nested loops. For each pair, we calculate the product `a * b`.
        3. **Inner Loop (Finding valid `(c, d)` pairs):**
            - For each product `a * b`, we look for pairs `(c, d)` such that `c * d = a * b`. We iterate through the elements between `a` and `b` to find valid `c`, and check if the corresponding `d` exists in the set of previously encountered `c` values.
        4. **Checking Distinctness and Validity:**
            - To ensure the tuple `(a, b, c, d)` is valid, we use the set `possible_d_values` to store valid `c` values, which helps efficiently check if the corresponding `d` exists.
        5. **Counting Valid Tuples:**
            - Every time we find a valid tuple `(a, b, c, d)`, we increment the result by `8`, as there are 8 possible permutations of four distinct numbers `(a, b, c, d)`.
        6. **Return the Result:**
            - After processing all possible pairs, we return the total number of valid tuples.
    
    - ### Code Implementation:
        - **Python Solution:**
            ```python3 []
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
            ```
        - **C++ Solution:**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - Sorting the array `nums` takes **$O(n \times log(n))$**, where $n$ is the length of the array.
        - The nested loops over pairs `(a, b)` will take **$O(n^2)$** time, as we check each pair.
        - The inner loop iterates over the range between `a` and `b` and performs constant-time operations such as checking divisibility and looking up values in the set. Since this is done at most `n` times, the total complexity for this part is also **$O(n)$**.
        
        Therefore, the overall **time complexity** of the algorithm is **$O(n^3)$**.

    - ### Space Complexity:
        - The primary extra space used is the set `possible_d_values`, which stores `c` values as we iterate through the list. In the worst case, this set can hold $n$ values, making the **space complexity** **$O(n)$**.
        - Other variables used for counting and indexing require constant space, which does not depend on the input size.

        Thus, the **space complexity** is **$O(n)$**.
<hr>

- ## Approach 3:- Finding Pairs for Each Product
    - ### Intuition:
        The goal of the problem is to find the number of distinct tuples `(a, b, c, d)` such that the product of the first two elements equals the product of the last two, i.e., `a * b = c * d`, with the constraint that all four elements are distinct.

        To solve this, we can break the problem down into the following steps:

        1. **Identify all pairs**: For each pair of numbers `(a, b)` in the input array, calculate the product `a * b`.
        2. **Store pairs with the same product**: We can store these pairs in a map (or dictionary) where the key is the product and the value is a list of pairs that yield that product.
        3. **Count valid tuples**: Once we have all pairs grouped by their product, we need to count how many ways we can select two distinct pairs (from those having the same product). For each valid pair combination, there are 8 possible permutations of `(a, b, c, d)`, so we multiply the count by 8.

    - ### Approach:
        1. **Iterate through all pairs**: Using two nested loops, iterate through all pairs `(a, b)` in the array. For each pair, compute the product and store the pair in a dictionary where the key is the product.
        2. **Group pairs by product**: In the dictionary, each product key maps to a list of pairs `(a, b)` that produce that product.   
        3. **Count valid tuple combinations**: Once we have the pairs grouped by product, calculate how many ways we can select two distinct pairs `(a, b)` and `(c, d)` from the same group. The number of ways to select 2 pairs from `n` pairs is given by the combination formula: ${^C{n}_2} = \frac{n \times (n - 1)}{2}$. For each valid selection, there are 8 permutations of the tuple `(a, b, c, d)`, so we multiply by 8.
        4. **Return the result**: After processing all product groups, return the total count of valid tuples.
    
    - ### Code ImplementationL
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution:**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - **Time Complexity**: The time complexity is **$O(n^2)$**, where $n$ is the number of elements in the array. This is because we are iterating over all possible pairs `(a, b)` using two nested loops, which results in $O(n^2)$ operations. In each operation, we perform constant-time operations such as inserting into the dictionary and calculating products.

        - **Explanation**: For each pair `(a, b)` in the array, we perform a constant number of operations, and there are $n^2$ pairs in total (since there are `n` choices for `a` and `n-1` choices for `b` for each `a`).

    - ### Space Complexity:
        - **Space Complexity**: The space complexity is **$O(n^2)$**. This is due to the space required to store all possible pairs `(a, b)` in the dictionary. In the worst case, every pair will have a unique product, and we will store each pair in the dictionary.
        - **Explanation**: We need space to store the dictionary of pairs. In the worst case, where all pairs have unique products, we would store $O(n^2)$ pairs in total, leading to a space complexity of $O(n^2)$.
<hr>

- ## Approach 4:- Count Product Frequency
    - ### Intuition:
        The problem asks to find the number of distinct tuples `(a, b, c, d)` such that the product of `a * b` is equal to the product of `c * d`, where `a`, `b`, `c`, and `d` are distinct elements from the input list `nums`. The brute force approach of checking every possible combination of four distinct elements would result in an inefficient solution. Instead, we can optimize the solution by recognizing that if we have pairs `(a, b)` and `(c, d)` that give the same product, we can count all possible distinct tuples that can be formed by selecting two pairs from those products.

    - ### Approach:
        1. **Hash Map for Pair Products:**
            - For each pair of elements `(a, b)` in the array, calculate the product `a * b`.
            - Store the product as the key in a hash map (or dictionary) and maintain a count of how many pairs resulted in that product.    
        2. **Counting Tuples:**
            - After processing all pairs, for each product that has more than one pair, calculate how many distinct tuples can be formed using those pairs.
            - If there are `n` pairs that produce the same product, the number of distinct ways to select two pairs is `n * (n - 1) / 2` (this is a combination formula).
            - Each valid combination of two pairs can be arranged in 8 distinct ways, since the order of `a, b, c, d` matters (i.e., there are 8 possible permutations of four distinct elements).
        3. **Final Calculation:**
            - Multiply the number of pair combinations by 8 to account for all permutations of the tuple and add it to the total count.

    - ### Code Implementation:
        - **Python Solution:**
            ```python3 []
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
            ```
        - **C++ Solution:**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - The time complexity of this approach is **$O(n^2)$**, where $n$ is the number of elements in the input array. This is due to the double loop that generates all pairs `(a, b)` and calculates the product. Each pair computation and insertion into the hash map takes constant time.

    - ### Space Complexity:
        - The space complexity is **$O(n^2)$** in the worst case. This is because, in the worst case, each product might be unique, resulting in storing up to $\frac{n\times(n - 1)}{2}$ pairs in the hash map. The space is mainly used for storing the pairs and the products in the hash map.
<hr>