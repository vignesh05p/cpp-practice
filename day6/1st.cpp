//  Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: Strings, Sliding Window, Hashing

// Problem Statement:
// Given a string s, find the length of the longest substring without repeating characters.

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, right = 0, maxLen = 0;

    while (right < s.length()) {
        if (seen.find(s[right]) == seen.end()) {
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            seen.erase(s[left]);
            left++;
        }
    }

    return maxLen;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
