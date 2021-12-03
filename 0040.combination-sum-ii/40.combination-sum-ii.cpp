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
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (51.60%)
 * Total Accepted:    480.9K
 * Total Submissions: 930.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */
class Solution {
public:
  void dfs(vector<int> &a, vector<vector<int>> &res, vector<bool> &used, int x, int sum, int pos, vector<int> &cur) {
    if (x == sum) {
      res.push_back(cur);
      return;
    }
    for (int i = pos; i < a.size(); i++) {
      if (!used[i] && sum + a[i] <= x) {
        used[i] = true;
        cur.push_back(a[i]);
        dfs(a, res, used, x, sum + a[i], i, cur);
        cur.pop_back();
        used[i] = false;
        while (i + 1 < a.size() && a[i] == a[i+1]) i++;
      }
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& a, int x) {
    sort(all(a));
    vector<vector<int>> res;
    vector<bool> used(a.size());
    vector<int> cur;

    dfs(a, res, used, x, 0, 0, cur);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution *sol = new Solution();
    vector<vector<int>> res = sol->combinationSum2(a, x);
    for (vector<int> row : res) {
      for (int col : row) {
        cout << col << " ";
      }
      cout << endl;
    }
  }
}
