// //  Problem: Count Number of Subarrays with Given XOR
// // Given:
// // An array arr[] of integers and an integer X.

// // Task:
// // Find the total number of subarrays whose XOR is equal to X.

// ✅ Constraints:
// 1 <= arr.length <= 10^5

// 0 <= arr[i] <= 10^5

// 0 <= X <= 10^5

// Must run in O(n) time and space

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarraysWithXOR(const vector<int>& arr, int X) {
    unordered_map<int, int> freq;
    int count = 0;
    int xorSum = 0;

    for (int num : arr) {
        xorSum ^= num;

        // Case 1: Subarray from start has XOR == X
        if (xorSum == X)
            count++;

        // Case 2: Check if there's a prefix with xor == xorSum ^ X
        int requiredXOR = xorSum ^ X;
        if (freq.find(requiredXOR) != freq.end()) {
            count += freq[requiredXOR];
        }

        // Store the frequency of current xorSum
        freq[xorSum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int X = 6;

    int result = countSubarraysWithXOR(arr, X);
    cout << "Number of subarrays with XOR = " << X << " is: " << result << endl;

    return 0;
}

