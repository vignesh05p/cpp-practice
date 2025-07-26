#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Optimized O(n) function to find max in each sliding window of size k
vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k == 0) return {};

    deque<int> dq;  // Stores indices of elements in decreasing order
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove indices whose values are less than nums[i]
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);  // Add current index

        // Append the max value to result once the first window is completed
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> res = maxSlidingWindow(nums, k);

    cout << "Sliding window maximums: ";
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    cout << endl;

    return 0;
}
