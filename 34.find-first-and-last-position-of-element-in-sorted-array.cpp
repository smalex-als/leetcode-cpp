#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (39.02%)
 * Total Accepted:    888K
 * Total Submissions: 2.3M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto l = lower_bound(nums.begin(), nums.end(), target);
    if (l == nums.end() || *l != target) {
      return {-1,-1};
    }
    auto r = upper_bound(nums.begin(), nums.end(), target);
    int start = l - nums.begin();
    int end = r - nums.begin() - 1;
    return {start, end};
  }
};

int main() {
  auto sol = new Solution();
  vector<int> nums = {5,7,7,8,8,10};
  auto res = sol->searchRange(nums, 8);
  cout << res[0] << " " << res[1] << endl;
  auto res2 = sol->searchRange(nums, 6);
  cout << res2[0] << " " << res2[1] << endl;
  vector<int> nums2 = {1};
  auto res3 = sol->searchRange(nums2, 1);
  cout << res3[0] << " " << res3[1] << endl;
  vector<int> nums3 = {1,2,3};
  auto res4 = sol->searchRange(nums3, 1);
  cout << res3[0] << " " << res3[1] << endl;
}
