/*
Date: November 12, 2024
Problem: Count the Number of Fair Pairs
Difficulty: Medium
Time Complexity: O(n log n)
Space Complexity: O(1)
The code efficiently counts pairs in a sorted array where the sum of each pair lies within a specified range, using a modified two-pointer approach to compute pairs within the bounds.
Steps:
1) Sorting
2) Two-Pointer Lower Bound Search
3) Counting Fair Pairs
*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
    }

private:
    long long lower_bound(vector<int>& nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long result = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < value) {
                result += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
