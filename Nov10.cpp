/*
Date: November 12, 2024
Problem: Shortest Subarray With OR at Least K II
Difficulty: Medium
Time Complexity: O(n)
Space Complexity: O(1)
Using a sliding window and bit-counting, the code efficiently finds the smallest subarray whose bitwise OR is at least k by tracking bit states across the window and dynamically adjusting its size.
 steps:
 1)Sliding Window
 2)Bit Counting for Efficiency
 3)Bitwise OR Calculation
 4)Updating the Window*/
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLength = INT_MAX;
        int windowStart = 0;
        int windowEnd = 0;
        vector<int> bitCounts(32,0); 

        while (windowEnd < nums.size()) {

            updateBitCounts(bitCounts, nums[windowEnd], 1);

            while (windowStart <= windowEnd &&
                   convertBitCountsToNumber(bitCounts) >= k) {

                minLength = min(minLength, windowEnd - windowStart + 1);

                updateBitCounts(bitCounts, nums[windowStart], -1);
                windowStart++;
            }

            windowEnd++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    void updateBitCounts(vector<int>& bitCounts, int number, int delta) {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) 
            if ((number >> bitPosition) & 1) {
                bitCounts[bitPosition] += delta;
            }
        }
    }
    int convertBitCountsToNumber(const vector<int>& bitCounts) {
        int result = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if (bitCounts[bitPosition] != 0) {
                result |= 1 << bitPosition;
            }
        }
        return result;
    }
};
