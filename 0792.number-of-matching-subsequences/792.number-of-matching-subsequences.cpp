#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 *
 * https://leetcode.com/problems/number-of-matching-subsequences/description/
 *
 * algorithms
 * Medium (49.90%)
 * Total Accepted:    107.7K
 * Total Submissions: 215.5K
 * Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
 *
 * Given a string s and an array of strings words, return the number of
 * words[i] that is a subsequence of s.
 * 
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 * 
 * 
 * For example, "ace" is a subsequence of "abcde".
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s:
 * "a", "acd", "ace".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 50
 * s and words[i] consist of only lowercase English letters.
 * 
 * 
 */
class Solution {
public:
  int numMatchingSubseq(string S, vector<string>& words) {
    vector<pair<int, int>> waiting[128];
    for (int i = 0; i < words.size(); i++)
      waiting[words[i][0]].emplace_back(i, 1);
    for (char c: S) {
      auto advance = waiting[c];
      waiting[c].clear();
      for (auto it: advance)
        waiting[words[it.first][it.second++]].push_back(it);
    }
    return waiting[0].size();
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution *sol = new Solution();
    cout << sol->numMatchingSubseq(s, a) << endl;
  }
}
