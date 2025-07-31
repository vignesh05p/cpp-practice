// 💡 2. Group Anagrams
// 📄 Problem Statement:

// Given an array of strings, group the anagrams together.
// You can return the answer in any order.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> grouped;

    for (const string& s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());  // Anagrams will match when sorted
        grouped[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& entry : grouped) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> output = groupAnagrams(input);

    for (const auto& group : output) {
        for (const auto& word : group)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}
