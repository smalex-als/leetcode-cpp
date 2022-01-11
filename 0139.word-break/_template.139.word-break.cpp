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

// Given a string s and a dictionary of strings wordDict, return true if s can 
// be segmented into a space-separated sequence of one or more dictionary words. 
// 
//  Note that the same word in the dictionary may be reused multiple times in 
// the segmentation. 
// 
//  
//  Example 1: 
// 
//  
// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
//  
// 
//  Example 2: 
// 
//  
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple 
// pen apple".
// Note that you are allowed to reuse a dictionary word.
//  
// 
//  Example 3: 
// 
//  
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
//  
// 
//  
//  Constraints: 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s and wordDict[i] consist of only lowercase English letters. 
// All the strings of wordDict are unique. 
// 
// Related Topics Hash Table String Dynamic Programming Trie Memoization 👍 8382
// 👎 388


class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return false;
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
    auto sol = new Solution();
    cout << sol->wordBreak(s, dict) << endl;
  }
}
