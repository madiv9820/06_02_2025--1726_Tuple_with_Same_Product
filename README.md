# [1726. Tuple with Same Product](https://leetcode.com/problems/tuple-with-same-product)

**Type:** Medium <br>
**Topics:** Array, Hash Table, Counting
<hr>

Given an array `nums` of **distinct** positive integers, return the number of tuples `(a, b, c, d)` such that `a * b = c * d` where `a`, `b`, `c`, and `d` are elements of `nums`, and `a != b != c != d`.
<hr>

- ### Examples:
    - **Example 1:**
        ```
        Input: nums = [2,3,4,6]
        Output: 8
        Explanation: There are 8 valid tuples:
        (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
        (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
        ```
    - **Example 2:**
        ```
        Input: nums = [1,2,4,5,10]
        Output: 16
        Explanation: There are 16 valid tuples:
        (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
        (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
        (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
        (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
        ```
<hr>

- ### Constraints:
    - `1 <= nums.length <= 1000`
    - <code>1 <= nums[i] <= 10<sup>4</sup></code>
    - All elements in `nums` are **distinct**.
<hr>

- ### Hints:
    - Note that all of the integers are distinct. This means that each time a product is formed it must be formed by two unique integers.
    - Count the frequency of each product of 2 distinct numbers. Then calculate the permutations formed.
<hr>