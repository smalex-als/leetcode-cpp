#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 *
 * https://leetcode.com/problems/find-and-replace-in-string/description/
 *
 * algorithms
 * Medium (53.07%)
 * Total Accepted:    82.3K
 * Total Submissions: 155.1K
 * Testcase Example:  '"abcd"\n[0, 2]\n["a", "cd"]\n["eee", "ffff"]'
 *
 * You are given a 0-indexed string s that you must perform k replacement
 * operations on. The replacement operations are given as three 0-indexed
 * parallel arrays, indices, sources, and targets, all of length k.
 * 
 * To complete the i^th replacement operation:
 * 
 * 
 * Check if the substring sources[i] occurs at index indices[i] in the original
 * string s.
 * If it does not occur, do nothing.
 * Otherwise if it does occur, replace that substring with targets[i].
 * 
 * 
 * For example, if s = "abcd", indices[i] = 0, sources[i] = "ab", and
 * targets[i] = "eee", then the result of this replacement will be "eeecd".
 * 
 * All replacement operations must occur simultaneously, meaning the
 * replacement operations should not affect the indexing of each other. The
 * testcases will be generated such that the replacements will not
 * overlap.
 * 
 * 
 * For example, a testcase with s = "abc", indices = [0, 1], and sources =
 * ["ab","bc"] will not be generated because the "ab" and "bc" replacements
 * overlap.
 * 
 * 
 * Return the resulting string after performing all replacement operations on
 * s.
 * 
 * A substring is a contiguous sequence of characters in a string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcd", indices = [0, 2], sources = ["a", "cd"], targets =
 * ["eee", "ffff"]
 * Output: "eeebffff"
 * Explanation:
 * "a" occurs at index 0 in s, so we replace it with "eee".
 * "cd" occurs at index 2 in s, so we replace it with "ffff".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abcd", indices = [0, 2], sources = ["ab","ec"], targets =
 * ["eee","ffff"]
 * Output: "eeecd"
 * Explanation:
 * "ab" occurs at index 0 in s, so we replace it with "eee".
 * "ec" does not occur at index 2 in s, so we do nothing.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * k == indices.length == sources.length == targets.length
 * 1 <= k <= 100
 * 0 <= indexes[i] < s.length
 * 1 <= sources[i].length, targets[i].length <= 50
 * s consists of only lowercase English letters.
 * sources[i] and targets[i] consist of only lowercase English letters.
 * 
 * 
 */
 class Solution {
   public:
     string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
       vector<string> a;
       int n = indices.size();
       vector<int> indexes(n);
       for (int i = 0; i < n; i++) {
         indexes[i] = i;
       }
       sort(indexes.begin(), indexes.end(), [&](int i, int j) {
           return indices[i] < indices[j];
       });
       int prev = 0;
       string res;
       for (int i = 0; i < n; i++) {
         int offset = indices[indexes[i]];
         if (i == 0 && offset > 0) {
           res += s.substr(0, offset);
         }
         int next = i + 1 == n ? s.size() : indices[indexes[i+1]];
         a.push_back(s.substr(offset, next - offset));
       }

       for (int i = 0; i < sources.size(); i++) {
         string w = sources[indexes[i]];
         if (a[i].compare(0, w.size(), w) == 0) {
           a[i] = targets[indexes[i]] + a[i].substr(w.size());
         }
       }
       for (string i : a) {
         res += i;
       }
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
    int n;
    cin >> n;
    vector<int> indices(n);
    vector<string> sources(n);
    vector<string> targets(n);
    for (int i = 0; i < n; ++i) {
      cin >> indices[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> sources[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> targets[i];
    }
    auto sol = new Solution();
    auto res = sol->findReplaceString(s, indices, sources, targets);
    cout << res << endl;
  }
}
