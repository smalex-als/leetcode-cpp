#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.45%)
 * Total Accepted:    1.6M
 * Total Submissions: 4.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a"
 * Output: "a"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "ac"
 * Output: "a"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 * 
 * 
 */
class Solution {
public:
  int expand(string &s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l--;
      r++;
    }
    return r - l - 1;
  }

  string longestPalindrome(string s) {
    int mx = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
      int ln1 = expand(s, i, i+1);
      int ln2 = expand(s, i, i);
      int cur = max(ln1, ln2);
      if (mx < cur) {
        ans = s.substr(i - (cur-1)/2, cur);
        mx = cur;
      }
    }
    return ans;
  }
};

int main() {
  auto sol = new Solution();
  string ans = sol->longestPalindrome("babad");
  cout << ans << endl;
}
