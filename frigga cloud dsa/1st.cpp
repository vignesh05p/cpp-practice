//  Question 1: Two Sum
// Problem Statement:

// Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;  // stores num -> index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // check if complement already exists
        if (map.find(complement) != map.end()) {
            return {map[complement], i};  // return indices
        }

        // store current number with its index
        map[nums[i]] = i;
    }

    return {}; // should never reach here if exactly one solution exists
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}
