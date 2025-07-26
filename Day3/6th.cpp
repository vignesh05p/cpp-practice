// // Problem: Maximum Sum of Rectangle No Larger Than K
// // Given:
// // A 2D matrix of integers and an integer k,
// // find the rectangle (submatrix) with the max sum such that it is ≤ k.

// Constraints:
// 1 <= rows, cols <= 100

// -10^4 <= matrix[i][j] <= 10^4

// 1 <= k <= 10^5

#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

// Helper function to find the max subarray sum no larger than k
int maxSubarrayNoLargerThanK(const vector<int>& nums, int k) {
    set<int> prefixSums;
    prefixSums.insert(0);  // handle exact match at beginning
    int currSum = 0, maxSum = INT_MIN;

    for (int num : nums) {
        currSum += num;

        // We need smallest prefix >= currSum - k
        auto it = prefixSums.lower_bound(currSum - k);
        if (it != prefixSums.end()) {
            maxSum = max(maxSum, currSum - *it);
        }

        prefixSums.insert(currSum);
    }

    return maxSum;
}

// Main function to solve the 2D version
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxResult = INT_MIN;

    // Compress rows between pairs of top & bottom
    for (int top = 0; top < rows; ++top) {
        vector<int> colSums(cols, 0);

        for (int bottom = top; bottom < rows; ++bottom) {
            // Add current row to column sums
            for (int c = 0; c < cols; ++c) {
                colSums[c] += matrix[bottom][c];
            }

            // Find the best subarray sum ≤ k in this compressed array
            int currMax = maxSubarrayNoLargerThanK(colSums, k);
            maxResult = max(maxResult, currMax);

            if (maxResult == k) return k; // Best possible answer
        }
    }

    return maxResult;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, -2, 3}
    };
    int k = 2;

    int result = maxSumSubmatrix(matrix, k);
    cout << "Max sum of rectangle no larger than " << k << " is: " << result << endl;

    return 0;
}
