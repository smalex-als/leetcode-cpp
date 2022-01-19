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
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.69%)
 * Total Accepted:    768.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 * 
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * 
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 * 
 * 
 */
class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &status, int u) {
      status[u] = 1;
      for (int v : adj[u]) {
        if (status[v] == 0) {
          if (dfs(adj, status, v)) {
            return true;
          }
        } else if (status[v] == 1) {
          return true;
        }
      }
      status[u] = 2;
      return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
      vector<vector<int>> adj(n);
      for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
      }
      vector<int> status(n);
      for (int i = 0; i < n; i++) {
        if (status[i] == 0) {
          if (dfs(adj, status, i)) {
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
      cin >> edges[i][0] >> edges[i][1];
    }
    cout << (new Solution())->canFinish(n, edges) << endl;
  }
}
