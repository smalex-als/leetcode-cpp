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
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (53.52%)
 * Total Accepted:    617K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = 
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = 
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit 1-9 or '.'.
 * 
 * 
 */
class Solution {
public:
  bool isValidHLine(vector<vector<char>>& board, int y) {
    vector<int> a(9);
    for (int i = 0; i < 9; i++) {
      if (board[y][i] == '.') {
        continue;
      }
      int val = board[y][i] - '1';
      if (a[val] > 0) {
        return false;
      }
      a[val]++;
    }
    return true;
  }

  bool isValidVLine(vector<vector<char>>& board, int x) {
    



    return true;
  }

  bool isValidSquare(vector<vector<char>>& board, int y, int x) {
    vector<int> a(9);
    int sy = y - y%3;
    int sx = x - x%3;
    for (int i = 0; i < 9; i++) {
      int cy = i / 3;
      int cx = i % 3;
      if (board[sy + cy][sx + cx] == '.') {
        continue;
      }
      int val = board[sy + cy][sx + cx] - '1';
      if (a[val] > 0) {
        return false;
      }
      a[val]++;
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      if (!isValidVLine(board, i)) {
        return false;
      }
      if (!isValidHLine(board, i)) {
        return false;
      }
    }
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        if (!isValidSquare(board, i, j)) {
          return false;
        } 
      }
    }
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cin >> board[i][j];
      }
    }
    Solution *sol = new Solution();
    cout << sol->isValidSudoku(board) << endl;
  }
}
