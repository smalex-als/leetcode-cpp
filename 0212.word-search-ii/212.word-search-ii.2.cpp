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
class TrieNode {
public:
  bool wordEnd;
  vector<TrieNode *> children;

  TrieNode() {
    wordEnd = false;
    children = vector<TrieNode *>(26, NULL);
  }

  bool hasChildren(char ch) {
    return children[ch - 'a'] != NULL;
  }

  TrieNode* nextChildren(char ch) {
    return children[ch - 'a'];
  }
};

class Trie {
public:
  TrieNode *getRoot() {
    return root;
  }

  Trie(vector <string> &words) {
    root = new TrieNode();
    for (int i = 0; i < words.size(); ++i)
      addWord(words[i]);
  }

  void addWord(const string &word) {
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); ++i) {
      int index = word[i] - 'a';
      if (!cur->hasChildren(word[i])) {
        cur->children[index] = new TrieNode();
      }
      cur = cur->children[index];
    }
    cur->wordEnd = true;
  }

private:
  TrieNode *root;
};

class Solution {
public:
  vector <string> findWords(vector <vector<char>> &board, vector <string> &words) {
    Trie *trie = new Trie(words);
    TrieNode *root = trie->getRoot();
    set<string> res;
    for (int x = 0; x < board.size(); ++x) {
      for (int y = 0; y < board[0].size(); ++y) {
        findWords(board, x, y, root, "", res);
      }
    }
    vector<string> result;
    for (auto str : res) {
      result.push_back(str);
    }
    return result;
  }

private:
  void findWords(vector <vector<char>> &board, int x, int y, TrieNode *parent, string word, set<string> &result) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') {
      return;
    }

    if (parent->hasChildren(board[x][y])) {
      word += board[x][y];
      auto node = parent->nextChildren(board[x][y]);
      if (node->wordEnd) {
        result.insert(word);
      }
      char c = board[x][y];
      board[x][y] = ' ';
      findWords(board, x + 1, y, node, word, result);
      findWords(board, x - 1, y, node, word, result);
      findWords(board, x, y + 1, node, word, result);
      findWords(board, x, y - 1, node, word, result);
      board[x][y] = c;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <string> words(k);
  vector <vector<char>> board(n, vector<char>(m));
  for (int i = 0; i < k; i++) {
    cin >> words[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  for (string word: (new Solution())->findWords(board, words)) {
    cout << word << "\n";
  }
}
