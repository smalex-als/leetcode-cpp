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
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (63.08%)
 * Total Accepted:    123.5K
 * Total Submissions: 192.9K
 * Testcase Example:  '"00110011"'
 *
 * Give a binary string s, return the number of non-empty substrings that have
 * the same number of 0's and 1's, and all the 0's and all the 1's in these
 * substrings are grouped consecutively.
 * 
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 * 
 * 
 */
class Solution {
public:
    int countBinarySubstrings(string s) {
      vector<int> cnt(2);
      int prev = -1;
      int ans = 0;
      int l = 0;
      for (int i = 0; i < s.size(); i++) {
        int cur = s[i] - '0';
        if (prev >= 0 && prev != cur) {
          ans += min(cnt[0], cnt[1]);
          while (l < s.size() && s[l] == cur + '0') {
            cnt[s[l] - '0']--;
            l++;
          }
        }
        cnt[cur]++;
        prev = cur;
      }
      ans += min(cnt[0], cnt[1]);
      return ans;
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
    cout << (new Solution())->countBinarySubstrings(s) << endl;
  }
}
