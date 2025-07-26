// Problem: Kth Smallest Element in a Sorted Matrix
// Given:
// An n x n matrix where each row and each column is sorted in ascending order,
// and an integer k.

// Task:
// Return the k-th smallest element in the matrix.

#include <iostream>
#include <vector>

using namespace std;

int countLessEqual(const vector<vector<int>>& matrix, int mid, int n) {
    int count = 0;
    int row = n - 1, col = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            count += (row + 1);
            col++;
        } else {
            row--;
        }
    }

    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int cnt = countLessEqual(matrix, mid, n);

        if (cnt < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    cout << "The " << k << "-th smallest element is: " << kthSmallest(matrix, k) << endl;
    return 0;
}



