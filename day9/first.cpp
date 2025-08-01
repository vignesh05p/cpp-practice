//  DSA Question: Subarray Sum Equals K
// Problem Statement:
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

// ✨ Example:
// makefile
// Copy
// Edit
// Input: nums = [1, 1, 1], k = 2  
// Output: 2  
// Explanation: [1,1] (the first two), and [1,1] (the last two)
// 📂 Topics:
// Arrays

// Hash Map

// Prefix Sum

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;  // To handle cases where subarray starts from index 0

    int count = 0;
    int prefixSum = 0;

    for (int num : nums) {
        prefixSum += num;

        // If (prefixSum - k) exists, there is a subarray that sums to k
        if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - k];
        }

        // Store current prefixSum in the map
        prefixSumCount[prefixSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << "Number of subarrays: " << subarraySum(nums, k) << endl;
    return 0;
}
