// // Given:
// // An array of integers arr[] and an integer K.

// // Task:
// // Find the length of the longest subarray whose sum is equal to K.

// Constraints:
// 1 <= arr.length <= 10^5

// -10^5 <= arr[i] <= 10^5

// Time Complexity: O(n)


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        // Case 1: entire subarray from 0 to i has sum == k
        if (sum == k) {
            maxLen = i + 1;
        }

        // Case 2: check if (sum - k) was seen before
        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
            int len = i - prefixSumIndex[sum - k];
            maxLen = max(maxLen, len);
        }

        // Only store the first occurrence of each sum
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
    int k = 3;

    int result = longestSubarrayWithSumK(arr, k);
    cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;

    return 0;
}
