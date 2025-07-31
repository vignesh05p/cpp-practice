//  1. Longest Subarray with Sum K
// 📄 Problem Statement:

// Given an array of integers nums and an integer k, return the length of the longest subarray whose sum is equal to k.

// ✍️ Example:
// cpp
// Copy
// Edit
// Input: nums = [1, 2, 3, -1, 4], k = 5  
// Output: 4  
// Explanation: Subarray [2, 3, -1, 1] has sum 5 and length 4
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(const vector<int>& nums, int k) {
    unordered_map<int, int> prefixIndex;  // Stores sum -> first index
    int sum = 0, maxLen = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];

        // Case 1: Subarray from index 0 to i has sum == k
        if (sum == k)
            maxLen = i + 1;

        // Case 2: Check if there is a prefix sum that makes current sum - k
        if (prefixIndex.find(sum - k) != prefixIndex.end())
            maxLen = max(maxLen, i - prefixIndex[sum - k]);

        // Store the first occurrence of the sum
        if (prefixIndex.find(sum) == prefixIndex.end())
            prefixIndex[sum] = i;
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, 2, 3, -1, 4};
    int k = 5;
    cout << "Length of longest subarray: " << longestSubarrayWithSumK(nums, k) << endl;
    return 0;
}
