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
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (51.65%)
 * Total Accepted:    304.4K
 * Total Submissions: 586.7K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 * 
 * 
 */
class Solution {
public:
  bool row[9][9];
  bool col[9][9];
  bool cell[3][3][9];

  bool dfs(vector<vector<char>>& board, int y, int x) {
    if (y == 9) {
      return true;
    }
    int nx = (x + 1) % 9;
    int ny = y + (x + 1) / 9;

    if (board[y][x] != '.') {
      return dfs(board, ny, nx);
    }
    for (int i = 0; i < 9; i++) {
      if (col[x][i] || row[y][i] || cell[y/3][x/3][i]) {
        continue;
      }
      col[x][i] = true;
      row[y][i] = true;
      cell[y/3][x/3][i] = true;
      board[y][x] = i + '1';
      if (dfs(board, ny, nx)) {
        return true;
      }
      col[x][i] = false;
      row[y][i] = false;
      cell[y/3][x/3][i] = false;
    }
    board[y][x] = '.';
    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int val = board[i][j] - '1';
          row[i][val] = col[j][val] = cell[i/3][j/3][val] = true;
        } 
      }
    }
    dfs(board, 0, 0);
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
    sol->solveSudoku(board);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }
}
