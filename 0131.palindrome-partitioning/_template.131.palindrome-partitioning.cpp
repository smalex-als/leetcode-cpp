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
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (55.97%)
 * Total Accepted:    372.9K
 * Total Submissions: 663.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 * 
 * A palindrome string is a string that reads the same backward as forward.
 * 
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 * 
 * 
 */
class Solution {
public:
  bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++, r--;
    }
    return true;
  }

  void partitionSolve(string &s, int pos, vector<vector<string>> &res, vector<string> &cur) {
    if (pos == s.size()) {
      res.push_back(cur);
      return;
    }
    for (int i = pos; i < s.size(); i++) {
      if (isPalindrome(s, pos, i)) {



      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> cur;
    partitionSolve(s, 0, res, cur);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    Solution *sol = new Solution();
    vector<vector<string>> res = sol->partition(s);
    for (vector<string> line : res) {
      for (string col : line) {
        cout << col << " ";
      }
      cout << endl;
    }
  }
}
