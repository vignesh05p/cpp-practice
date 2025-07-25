// // Problem Title: Longest Substring Without Repeating Characters
// // Description:

// // Given a string s, find the length of the longest substring without repeating characters.
// Constraints:
// 0 <= s.length <= 10^5

// s consists of English letters, digits, symbols and spaces.






#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLength = 0;
    int start = 0;  // Start index of current window

    for (int end = 0; end < s.length(); ++end) {
        char current = s[end];

        // If the character was seen and is inside the current window
        if (lastIndex.find(current) != lastIndex.end() && lastIndex[current] >= start) {
            // Move the start to one position after the last occurrence
            start = lastIndex[current] + 1;
        }

        // Update last seen index of the character
        lastIndex[current] = end;

        // Update maxLength
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    // Test cases
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // Output: 3 ("abc")
    cout << lengthOfLongestSubstring("bbbbb") << endl;    // Output: 1 ("b")
    cout << lengthOfLongestSubstring("pwwkew") << endl;   // Output: 3 ("wke")
    cout << lengthOfLongestSubstring("") << endl;         // Output: 0 (empty string)
    cout << lengthOfLongestSubstring(" ") << endl;        // Output: 1 (single space)
    cout << lengthOfLongestSubstring("au") << endl;       // Output: 2 ("au")
    cout << lengthOfLongestSubstring("dvdf") << endl;     // Output: 3 ("vdf")

    return 0;
}
