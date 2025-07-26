// // gven:
// // An array nums[] of size n and an integer k.

// // Task:
// // Find the maximum element in every sliding window of size k.
// Constraints:
// 1 <= nums.length <= 10^5

// -10^4 <= nums[i] <= 10^4

// 1 <= k <= nums.length

// Must run in O(n) time

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Will store indices of useful elements
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        // 1. Remove indices that are out of this window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Remove elements smaller than current element from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // 3. Add current element's index
        dq.push_back(i);

        // 4. If window is at least k elements, add max to result
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> res = maxSlidingWindow(nums, k);

    cout << "Sliding window maximums are: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
