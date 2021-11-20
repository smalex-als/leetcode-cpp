#include <bits/stdc++.h>
using namespace std;

// You are given an array of integers nums, there is a sliding window of size k 
// which is moving from the very left of the array to the very right. You can only 
// see the k numbers in the window. Each time the sliding window moves right by one 
// position. 
// 
//  Return the max sliding window. 
// 
//  
//  Example 1: 
// 
//  
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//  
// 
//  Example 2: 
// 
//  
// Input: nums = [1], k = 1
// Output: [1]
//  
// 
//  Example 3: 
// 
//  
// Input: nums = [1,-1], k = 1
// Output: [1,-1]
//  
// 
//  Example 4: 
// 
//  
// Input: nums = [9,11], k = 2
// Output: [11]
//  
// 
//  Example 5: 
// 
//  
// Input: nums = [4,-2], k = 2
// Output: [4]
//  
// 
//  
//  Constraints: 
// 
//  
//  1 <= nums.length <= 10⁵ 
//  -10⁴ <= nums[i] <= 10⁴ 
//  1 <= k <= nums.length 
//  
//  Related Topics Array Queue Sliding Window Heap (Priority Queue) Monotonic 
// Queue 👍 7624 👎 276


class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& a, int k) {
    deque<int> d;
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
      while (!d.empty() && a[i] >= a[d.back()]) {
        d.pop_back();
      }
      d.push_back(i);
      while (!d.empty() && i - d.front() >= k) {
        d.pop_front();
      }
      if (i + 1 >= k) {
        res.push_back(a[d.front()]);
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
// Output: [3,3,5,5,6,7]
  auto sol = new Solution();
  auto res = sol->maxSlidingWindow(nums, 3);
  for (int i : res) {
    cout << i << " ";
  }
}
