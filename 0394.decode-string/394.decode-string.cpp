#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (54.76%)
 * Total Accepted:    397.7K
 * Total Submissions: 726.3K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 * 
 * 
 */
class Solution {
  public:
    string solve(string &s, int &pos) {
      string res;
      int number = 0;
      while (pos < s.size()) {
        if (s[pos] >= '0' && s[pos] <= '9') {
          number *= 10;
          number += s[pos] - '0';
          pos++;
        } else if (s[pos] == '[') {
          pos++;
          string col = solve(s, pos);
          for (int i = 0; i < number; i++) {
            res += col;   
          }
          number = 0;
        } else if (s[pos] == ']') {
          pos++;
          return res;
        } else {
          res += s[pos];
          pos++;
        }
      }
      return res;
    }

    string decodeString(string s) {
      int pos = 0;
      return solve(s, pos);
    } 
};

int main() {
  Solution *sol = new Solution();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << sol->decodeString(s) << endl;
  }
}
