// roblem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: Strings, Hashing, Sliding Window

// 🔶 Problem Statement:
// Given a string s, find the length of the longest substring without repeating characters.

// 🧪 Example:
// vbnet
// Copy
// Edit
// Input: s = "abcabcbb"  
// Output: 3  
// Explanation: The answer is "abc", with the length of 3.

// Input: s = "bbbbb"  
// Output: 1  
// Explanation: The answer is "b", with the length of 1.

// Input: s = "pwwkew"  
// Output: 3  
// Explanation: The answer is "wke", with the length of 3.
// 🧾 Constraints:
// 0 <= s.length <= 10^5

// s consists of English letters, digits, symbols and spaces.

#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int maxLength = 0;
    int start = 0; // Left pointer of the sliding window

    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // If character is already in the window, move the start
        if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
            start = charIndex[currentChar] + 1;
        }

        // Update the last index of the current character
        charIndex[currentChar] = end;

        // Update maxLength if current window is longer
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
