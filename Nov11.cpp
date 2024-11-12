/*
Date: November 11, 2024
Problem: Prime Subtraction Operation
Difficulty: Medium
Time Complexity: O(m * log(log(m)) + n)
Space Complexity: O(m)
Using a prime sieve and sequential value checks, the code tries to transform each element in nums to an increasing sequence by subtracting only prime or zero values. If this is possible for all elements, it returns true; otherwise, false.
Solution Intuition
-Prime Sieve for Primality Check
-Iterate and Transform
*/
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());/**/

        vector<int> sieve(maxElement + 1, 1);
        sieve[1] = 0;
        for (int i = 2; i <= sqrt(maxElement + 1); i++) {
            if (sieve[i] == 1) {
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = 0;
                }
            }
        }

        int currValue = 1;
        int i = 0;
        while (i < nums.size()) {
            int difference = nums[i] - currValue;
            if (difference < 0) {
                return 0;
            }
            if (sieve[difference] == 1 or difference == 0) {
                i++;
                currValue++;
            } else {
                currValue++;
            }
        }
        return 1;
    }
};
