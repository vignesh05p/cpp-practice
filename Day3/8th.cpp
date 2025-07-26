// // Problem: Palindrome Partitioning II
// // (Given a string, partition it into the fewest possible palindromic substrings.)

// // 🔧 Task:
// // // Given a string s, partition it into substrings such that every substring is a palindrome, and return the minimum number of cuts needed to do so.


// ✅ Constraints:
// 1 <= s.length <= 2000

// Must solve in O(n²) time.

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    vector<int> dp(n, 0);

    // Precompute all palindromic substrings
    for (int end = 0; end < n; ++end) {
        int minCut = end;
        for (int start = 0; start <= end; ++start) {
            if (s[start] == s[end] && (end - start <= 2 || isPalindrome[start + 1][end - 1])) {
                isPalindrome[start][end] = true;
                minCut = (start == 0) ? 0 : min(minCut, dp[start - 1] + 1);
            }
        }
        dp[end] = minCut;
    }

    return dp[n - 1];
}

int main() {
    string s = "aab";
    cout << "Minimum cuts needed for palindrome partitioning: " << minCut(s) << endl;
    return 0;
}
