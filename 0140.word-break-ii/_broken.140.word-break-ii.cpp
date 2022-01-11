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
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (39.53%)
 * Total Accepted:    394.6K
 * Total Submissions: 988.4K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a string s and a dictionary of strings wordDict, add spaces in s to
 * construct a sentence where each word is a valid dictionary word. Return all
 * such possible sentences in any order.
 * 
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * Output: ["cats and dog","cat sand dog"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * 
 * 
 */
class Solution {
public:
  void wordBreakInner(string &s, int pos, vector<string>& wordDict, vector<string> &cur, vector<string> &res) {
    if (pos == s.size()) {
      string line;
      for (string i : cur) {
        if (line.size() > 0) {
          line += " ";
        }
        line += i;
      }
      res.push_back(line);
      return;
    }
    for (string word : wordDict) {
      if (        ) {
        cur.push_back(word);
        wordBreakInner(s, pos + word.size(), wordDict, cur, res);
        cur.pop_back();
      }
    }
  }

  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> res;
    vector<string> cur;
    wordBreakInner(s, 0, wordDict, cur, res);
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
    vector<string> dict(n);
    for (int i = 0; i < n; i++) {
      cin >> dict[i];
    }
    Solution *sol = new Solution();
    for (string x : sol->wordBreak(s, dict)) {
      cout << x << " " << endl;
    }
  }
}
