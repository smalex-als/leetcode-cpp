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
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.72%)
 * Total Accepted:    658.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * continuous subarrays whose sum equals to k.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int sum = 0;
      map<int,int> mp;
      int ans = 0;
      mp[0] = 1;
      for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        ans += mp[sum - k];
        mp[sum]++;
      }
      return ans;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << (new Solution())->subarraySum(a, k) << endl;
  }
}
