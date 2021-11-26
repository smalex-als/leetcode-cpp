#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.97%)
 * Total Accepted:    1.8M
 * Total Submissions: 3.7M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int mx = 0;
    int cur = 0;
    for (int num : nums) {
      cur = max(num, cur + num);
      mx = max(mx, cur);
    }
    return mx;
  }
};

int main() {
  Solution *sol = new Solution();
  {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol->maxSubArray(nums) << endl;
  }
  {
    vector<int> nums = {5,4,-1,7,8};
    cout << sol->maxSubArray(nums) << endl;
  }
  {
    vector<int> nums = {1};
    cout << sol->maxSubArray(nums) << endl;
  }
}
