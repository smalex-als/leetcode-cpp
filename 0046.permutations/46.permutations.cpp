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
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (70.07%)
 * Total Accepted:    989K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */
class Solution {
public:
  bool next_perm(vector<int>& nums, vector<vector<int>> &res) {
    int i = nums.size() - 1;
    while (i > 0 && nums[i] <= nums[i-1]) i--;
    if (i == 0) {
      return false;
    }
    int j = nums.size() - 1;
    while (nums[j] <= nums[i-1]) j--;
    swap(nums[j], nums[i-1]);
    reverse(nums.begin() + i, nums.end()); 
    res.push_back(nums);
    return true;
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    sort(all(nums));
    res.push_back(nums);
    while (next_perm(nums, res));
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution *sol = new Solution();
    for (vector<int> &row : sol->permute(a)) {
      for (int col : row) {
        cout << col << " ";
      }
      cout << endl;
    }
  }
}
