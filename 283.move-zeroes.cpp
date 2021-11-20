#include <bits/stdc++.h>
using namespace std;
//Given an integer array nums, move all 0's to the end of it while maintaining 
//the relative order of the non-zero elements. 
//
// Note that you must do this in-place without making a copy of the array. 
//
// 
// Example 1: 
// Input: nums = [0,1,0,3,12]
//Output: [1,3,12,0,0]
// Example 2: 
// Input: nums = [0]
//Output: [0]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 
//
// 
//Follow up: Could you minimize the total number of operations done? Related 
//Topics Array Two Pointers 👍 6935 👎 193


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int dst = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[dst]);
        dst++;
      }
    }
  }
};

int main() {
  vector<int> nums = {0,1,0,3,12};
  auto sol = new Solution();
  sol->moveZeroes(nums);
  for (int i : nums) {
    cout << i << " ";
  }
  cout << endl;
}
