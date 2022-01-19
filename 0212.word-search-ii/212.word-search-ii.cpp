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
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (38.43%)
 * Total Accepted:    394.8K
 * Total Submissions: 1M
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given an m x n board of characters and a list of strings words, return all
 * words on the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once in a word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["a","b"],["c","d"]], words = ["abcb"]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] is a lowercase English letter.
 * 1 <= words.length <= 3 * 10^4
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * All the strings of words are unique.
 * 
 * 
 */
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int y, int x, int pos, vector<vector<bool>> &used) {
      if (!(y >= 0 && x >= 0 && y < board.size() && x < board[0].size() && board[y][x] == word[pos] && !used[y][x])) {
        return false;
      }
      if (pos + 1 == word.size()) {
        return true;
      }
      used[y][x] = true;
      if (dfs(board, word, y - 1, x, pos + 1, used) || dfs(board, word, y + 1, x, pos + 1, used) 
          || dfs(board, word, y, x - 1, pos + 1, used) || dfs(board, word, y, x + 1, pos + 1, used)) {
        return true;
      }
      used[y][x] = false;
      return false;
    }

    bool findWord(vector<vector<char>>& board, string word) {
      vector<vector<bool>> used(board.size(), vector<bool>(board[0].size()));
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
          if (word[0] == board[i][j]) {
            if (dfs(board, word, i, j, 0, used)) {
              return true;
            }
          }
        }
      }
      return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      vector<string> res;
      set<char> st;
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
          st.insert(board[i][j]);
        }
      }
      for (string word : words) {
        int matched = 0;
        for (char ch : word) {
          matched += st.count(ch);
        }
        if (matched == word.size() && findWord(board, word)) {
          res.push_back(word);
        }
      }
      sort(all(res));
      return res;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> words(k);
  vector<vector<char>> board(n, vector<char>(m));
  for (int i = 0; i < k; i++) {
    cin >> words[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  for (string word : (new Solution())->findWords(board, words)) {
    cout << word << "\n";
  }
}
