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
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 *
 * https://leetcode.com/problems/bus-routes/description/
 *
 * algorithms
 * Hard (44.67%)
 * Total Accepted:    66.9K
 * Total Submissions: 149.4K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * You are given an array routes representing bus routes where routes[i] is a
 * bus route that the i^th bus repeats forever.
 * 
 * 
 * For example, if routes[0] = [1, 5, 7], this means that the 0^th bus travels
 * in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
 * 
 * 
 * You will start at the bus stop source (You are not on any bus initially),
 * and you want to go to the bus stop target. You can travel between bus stops
 * by buses only.
 * 
 * Return the least number of buses you must take to travel from source to
 * target. Return -1 if it is not possible.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
 * Output: 2
 * Explanation: The best strategy is take the first bus to the bus stop 7, then
 * take the second bus to the bus stop 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target
 * = 12
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 10^5
 * All the values of routes[i] are unique.
 * sum(routes[i].length) <= 10^5
 * 0 <= routes[i][j] < 10^6
 * 0 <= source, target < 10^6
 * 
 * 
 */
class Solution {
  public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
      unordered_map<int, vector<int>> to_routes;
      for (int i = 0; i < routes.size(); ++i)
        for (int j : routes[i])
          to_routes[j].push_back(i);
      queue<pair<int, int>> bfs;
      bfs.push({S, 0});
      unordered_set<int> seen = {S};
      while (!bfs.empty()) {
        int stop = bfs.front().first, bus = bfs.front().second;
        bfs.pop();
        if (stop == T)
          return bus;
        for (int i : to_routes[stop]) {
          for (int j : routes[i]) {
            if (seen.find(j) == seen.end()) {
              seen.insert(j);
              bfs.push({j, bus + 1});
            }
          }
          routes[i].clear();
        }
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
    int n, source, target;
    cin >> n >> source >> target;
    vector<vector<int>> routes(n);
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      routes[i] = vector<int>(m);
      for (int j = 0; j < m; j++) {
        cin >> routes[i][j];
      }
    }
    Solution *sol = new Solution();
    cout << sol->numBusesToDestination(routes, source, target) << endl;
  }
}
