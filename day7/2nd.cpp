// 1. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.
// 📂 Topics: String, HashMap, Sliding Windo

#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.size(); ++end) {
        char currentChar = s[end];

        // If character is seen and its index is within the current window
        if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
            start = charIndex[currentChar] + 1;
        }

        charIndex[currentChar] = end;
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
