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
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
 *
 * algorithms
 * Hard (50.40%)
 * Total Accepted:    95.9K
 * Total Submissions: 189.2K
 * Testcase Example:  '[1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]'
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i] to
 * endTime[i], obtaining a profit of profit[i].
 * 
 * You're given the startTime, endTime and profit arrays, return the maximum
 * profit you can take such that there are no two jobs in the subset with
 * overlapping time range.
 * 
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 * 
 * Example 1:
 * 
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job. 
 * Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
 * 
 * Example 2:
 * 
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
 * [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job. 
 * Profit obtained 150 = 20 + 70 + 60.
 * 
 * Example 3:
 * 
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 * 
 * Constraints:
 * 
 * 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
 * 1 <= startTime[i] < endTime[i] <= 10^9
 * 1 <= profit[i] <= 10^4
 */
class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<array<int,4>> tasks(n);
    map<int,int> dp;
    for (int i = 0; i < n; i++) {
      tasks[i] = {endTime[i], startTime[i], profit[i], i};
    }
    sort(all(tasks));
    dp[0] = 0;
    for (auto &[end, start, p, i]: tasks) {
      int last = prev(dp.upper_bound(start))->second;
      int lastV2 = dp.rbegin()->second;
      dp[end] = max({dp[end], p + last, lastV2});
    }
    return dp.rbegin()->second;
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
    vector<int> startTime(n);
    vector<int> endTime(n);
    vector<int> profit(n);
    for (int i = 0; i < n; i++) {
      cin >> startTime[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> endTime[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> profit[i];
    }
    cout << (new Solution())->jobScheduling(startTime, endTime, profit) << endl;
  }
}
