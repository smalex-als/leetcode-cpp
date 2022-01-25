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
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 *
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
 *
 * algorithms
 * Hard (43.90%)
 * Total Accepted:    62.5K
 * Total Submissions: 142.4K
 * Testcase Example:  '[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]\n1'
 *
 * You are given an m x n integer matrix grid where each cell is either 0
 * (empty) or 1 (obstacle). You can move up, down, left, or right from and to
 * an empty cell in one step.
 * 
 * Return the minimum number of steps to walk from the upper left corner (0, 0)
 * to the lower right corner (m - 1, n - 1) given that you can eliminate at
 * most k obstacles. If it is not possible to find such walk return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
 * Output: 6
 * Explanation: 
 * The shortest path without eliminating any obstacle is 10.
 * The shortest path with one obstacle elimination at position (3,2) is 6. Such
 * path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
 * Output: -1
 * Explanation: We need to eliminate at least two obstacles to find such a
 * walk.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 40
 * 1 <= k <= m * n
 * grid[i][j] is either 0 or 1.
 * grid[0][0] == grid[m - 1][n - 1] == 0
 * 
 */
class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    // At a particular cell we will store the number of obstacles 
    // that we can still remove after walking through that cell
    vector<vector<int>> vis(grid.size(), vector<int>(m, -1));
    queue<vector<int>> q;

    // queue stores (x,y,current path length,number of obstacles we can still remove)
    q.push({0, 0, 0, k});
    while (!q.empty()) {
      auto t = q.front();
      int x = t[0], y = t[1], cost = t[2], lk = t[3];
      q.pop();

      // Exit if current position is outside of the grid
      if (x < 0 || y < 0 || x >= n || y >= m) {
        continue;
      }

      // Destination found
      if (x == n - 1 && y == m - 1) {
        return cost;
      }

      if (grid[x][y] == 1){
        // If we encounter an obstacle and we can remove it
        if (lk > 0) {
          lk--;
        } else {
          continue;
        }
      }

      // The cell was previously visited by some path and 
      // we were able to remove more obstacles from the previous path.
      // Then we don't need to continue on our current path
      if (vis[x][y] != -1 && vis[x][y] >= lk) {
        continue;
      }
      vis[x][y] = lk;

      q.push({x+1, y, cost+1, lk});
      q.push({x, y+1, cost+1, lk});
      q.push({x-1, y, cost+1, lk});
      q.push({x, y-1, cost+1, lk});
    }
    return -1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    Solution *sol = new Solution();
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
      }
    }
    cout << sol->shortestPath(grid, k) << endl;
  }
}
