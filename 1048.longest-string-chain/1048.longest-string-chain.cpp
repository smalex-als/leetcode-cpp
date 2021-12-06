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
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 *
 * https://leetcode.com/problems/longest-string-chain/description/
 *
 * algorithms
 * Medium (57.08%)
 * Total Accepted:    162.8K
 * Total Submissions: 284.8K
 * Testcase Example:  '["a","b","ba","bca","bda","bdca"]'
 *
 * You are given an array of words where each word consists of lowercase
 * English letters.
 * 
 * wordA is a predecessor of wordB if and only if we can insert exactly one
 * letter anywhere in wordA without changing the order of the other characters
 * to make it equal to wordB.
 * 
 * 
 * For example, "abc" is a predecessor of "abac", while "cba" is not a
 * predecessor of "bcad".
 * 
 * 
 * A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1,
 * where word1 is a predecessor of word2, word2 is a predecessor of word3, and
 * so on. A single word is trivially a word chain with k == 1.
 * 
 * Return the length of the longest possible word chain with words chosen from
 * the given list of words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["a","b","ba","bca","bda","bdca"]
 * Output: 4
 * Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * Output: 5
 * Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc",
 * "pcxbc", "pcxbcf"].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["abcd","dbqca"]
 * Output: 1
 * Explanation: The trivial word chain ["abcd"] is one of the longest word
 * chains.
 * ["abcd","dbqca"] is not a valid word chain because the ordering of the
 * letters is changed.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of lowercase English letters.
 * 
 * 
 */
class Solution {
public:
  int dfs(string &u, unordered_set<string> &dict, unordered_map<string, int> &vis) {
    if (vis.find(u) != vis.end()) {
      return vis[u];
    }
    int mx = 0;
    for (int i = 0; i < u.size(); i++) {
      string next = u.substr(0, i) + u.substr(i + 1, u.size() - i - 1);
      if (next.size() > 0 && dict.find(next) != dict.end()) {
        mx = max(mx, dfs(next, dict, vis));
      }
    }
    vis[u] = mx + 1;
    return vis[u];
  }

  int longestStrChain(vector<string>& words) {
    unordered_set<string> dict;
    unordered_map<string, int> vis;
    for (string &word : words) {
      dict.insert(word);
    }
    int mx = 0;
    for (string word : words) {
      mx = max(mx, dfs(word, dict, vis));
    }
    return mx;
  }
};

int main() {
  Solution *sol = new Solution();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
      cin >> words[i];
    }
    cout << sol->longestStrChain(words) << endl;
  }
}
