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
  string longestPalindrome(string s) {
    return "";
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int t;
  cin >> t;
  while (t--) {
    auto sol = new Solution();
    string s;
    cin >> s;
    cout << sol->longestPalindrome(s) << endl;
  }
}
