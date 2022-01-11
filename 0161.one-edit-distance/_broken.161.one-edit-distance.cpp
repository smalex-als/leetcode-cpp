#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <iomanip>
#include <zconf.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
/*
 * @lc app=leetcode id=161 lang=cpp
 *
 * [161] One Edit Distance
 *
 * https://leetcode.com/problems/one-edit-distance/description/
 *
 * algorithms
 * Medium (33.66%)
 * Total Accepted:    157.1K
 * Total Submissions: 466.7K
 * Testcase Example:  '"ab"\n"acb"'
 *
 * Given two strings s and t, return true if they are both one edit distance
 * apart, otherwise return false.
 * 
 * A string s is said to be one distance apart from a string t if you
 * can:
 * 
 * 
 * Insert exactly one character into s to get t.
 * Delete exactly one character from s to get t.
 * Replace exactly one character of s with a different character to get t.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ab", t = "acb"
 * Output: true
 * Explanation: We can insert 'c' into s to get t.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "", t = ""
 * Output: false
 * Explanation: We cannot get t from s by only one step.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a", t = ""
 * Output: true
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "", t = "A"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 10^4
 * 0 <= t.length <= 10^4
 * s and t consist of lower-case letters, upper-case letters and/or digits.
 * 
 * 
 */

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    for (int i = 0; i < min(s.size(), t.size()); i++) {
      if (s[i] != t[i]) {
        if (s.compare(i + 1, s.size() - i - 1, t, i + 1) == 0 ||
            s.compare(i + 1, s.size() - i - 1, t, i) == 0 ||
            s.compare(i, s.size() - i, t, i + 1) == 0) {
          return true;
        } else {
          return false;
        }
      }
    }
    return abs((int)s.size() - (int)t.size()) == 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    auto sol = new Solution();
    cout << sol->isOneEditDistance(a, b) << endl;
  }
}
