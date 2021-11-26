#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.50%)
 * Total Accepted:    1.8M
 * Total Submissions: 4.4M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "{[]}"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */
class Solution {
  public:
    bool isValid(string s) {
      map<char, char> mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
      stack<char> st;
      for (char ch : s) {
        if (mp.find(ch) != mp.end()) {
          st.push(mp[ch]);
        } else {
          if (st.empty() || st.top() != ch) {
            return false;
          }
          st.pop();
        }
      }
      return st.empty();
    }
};

int main() {
  Solution *sol = new Solution();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << sol->isValid(s) << endl;
  }
}
