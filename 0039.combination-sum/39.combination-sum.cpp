#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (62.73%)
 * Total Accepted:    881.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 * 
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: candidates = [1], target = 2
 * Output: [[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 * 
 * 
 */
class Solution {
public:
  void solve(vector<int> &a, int x, int cur, int pos,
      vector<int> &used, vector<vector<int>> &res) {
    if (cur == x) {
      vector<int> row;
      for (int i = 0; i < used.size(); i++) {
        for (int j = 0; j < used[i]; j++) {
          row.push_back(a[i]);
        }
      }
      res.push_back(row);
      return;
    }
    for (int i = pos; i < a.size(); i++) {
      if (cur + a[i] <= x) {
        used[i]++;
        solve(a, x, cur + a[i], i, used, res);
        used[i]--;
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& a, int x) { 
    vector<vector<int>> res;
    vector<int> used(a.size());
    solve(a, x, 0, 0, used, res);
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    Solution *sol = new Solution();
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> ans1 = sol->combinationSum(a, x);
    cout << ans1.size() << endl;
    for (vector<int> row : ans1) {
      for (int val : row) {
        cout << val << " ";
      }
      cout << endl;
    }
  }
}
