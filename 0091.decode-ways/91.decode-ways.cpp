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
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (28.96%)
 * Total Accepted:    714.5K
 * Total Submissions: 2.4M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z can be encoded into numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 * 
 * 
 * To decode an encoded message, all the digits must be grouped then mapped
 * back into letters using the reverse of the mapping above (there may be
 * multiple ways). For example, "11106" can be mapped into:
 * 
 * 
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 * 
 * 
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
 * into 'F' since "6" is different from "06".
 * 
 * Given a string s containing only digits, return the number of ways to decode
 * it.
 * 
 * The test cases are generated so that the answer fits in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2
 * 2 6).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "06"
 * Output: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6"
 * is different from "06").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 * 
 * 
 */
class Solution {
public:
  bool checkOne(char ch) {
    return ch >= '1' && ch <= '9';
  }

  bool checkTwo(char ch0, char ch1) {
    if (ch0 == '1' && ch1 >= '0' && ch1 <= '9') {
      return true;
    } else {
      return ch0 == '2' && ch1 >= '0' && ch1 <= '6';
    }
  }

  int numDecodings(string s) {
    int n = (int) s.size();
    vector<int> dp(s.size() + 1);
    dp[0] = 1;
    for (int i = 0; i < s.size(); i++) {
      int cur = 0;
      if (checkOne(s[i])) {
        cur += dp[i];
      }
      if (i > 0 && checkTwo(s[i - 1], s[i])) {
        cur += dp[i - 1];
      }
      if (cur == 0) {
        return 0;
      }
      dp[i + 1] = cur;
    }
    return dp[n];
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
    cout << (new Solution())->numDecodings(s) << endl;
  }
}
