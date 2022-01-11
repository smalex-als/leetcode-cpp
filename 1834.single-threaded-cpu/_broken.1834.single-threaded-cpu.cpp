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
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 *
 * https://leetcode.com/problems/single-threaded-cpu/description/
 *
 * algorithms
 * Medium (38.33%)
 * Total Accepted:    21.2K
 * Total Submissions: 55.1K
 * Testcase Example:  '[[1,2],[2,4],[3,2],[4,1]]'
 *
 * You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D
 * integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means
 * that the i^​​​​​​th​​​​ task will be available to process at enqueueTimei
 * and will take processingTimei to finish processing.
 * 
 * You have a single-threaded CPU that can process at most one task at a time
 * and will act in the following way:
 * 
 * 
 * If the CPU is idle and there are no available tasks to process, the CPU
 * remains idle.
 * If the CPU is idle and there are available tasks, the CPU will choose the
 * one with the shortest processing time. If multiple tasks have the same
 * shortest processing time, it will choose the task with the smallest
 * index.
 * Once a task is started, the CPU will process the entire task without
 * stopping.
 * The CPU can finish a task then start a new one instantly.
 * 
 * 
 * Return the order in which the CPU will process the tasks.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
 * Output: [0,2,3,1]
 * Explanation: The events go as follows: 
 * - At time = 1, task 0 is available to process. Available tasks = {0}.
 * - Also at time = 1, the idle CPU starts processing task 0. Available tasks =
 * {}.
 * - At time = 2, task 1 is available to process. Available tasks = {1}.
 * - At time = 3, task 2 is available to process. Available tasks = {1, 2}.
 * - Also at time = 3, the CPU finishes task 0 and starts processing task 2 as
 * it is the shortest. Available tasks = {1}.
 * - At time = 4, task 3 is available to process. Available tasks = {1, 3}.
 * - At time = 5, the CPU finishes task 2 and starts processing task 3 as it is
 * the shortest. Available tasks = {1}.
 * - At time = 6, the CPU finishes task 3 and starts processing task 1.
 * Available tasks = {}.
 * - At time = 10, the CPU finishes task 1 and becomes idle.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
 * Output: [4,3,2,0,1]
 * Explanation: The events go as follows:
 * - At time = 7, all the tasks become available. Available tasks =
 * {0,1,2,3,4}.
 * - Also at time = 7, the idle CPU starts processing task 4. Available tasks =
 * {0,1,2,3}.
 * - At time = 9, the CPU finishes task 4 and starts processing task 3.
 * Available tasks = {0,1,2}.
 * - At time = 13, the CPU finishes task 3 and starts processing task 2.
 * Available tasks = {0,1}.
 * - At time = 18, the CPU finishes task 2 and starts processing task 0.
 * Available tasks = {1}.
 * - At time = 28, the CPU finishes task 0 and starts processing task 1.
 * Available tasks = {}.
 * - At time = 40, the CPU finishes task 1 and becomes idle.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * tasks.length == n
 * 1 <= n <= 10^5
 * 1 <= enqueueTimei, processingTimei <= 10^9
 * 
 * 
 */
class Solution {
  public:
  typedef pair<int, int> T; // processing time, index
  vector<int> getOrder(vector<vector<int>>& tasks) {
    priority_queue<T, vector<T>, greater<>> pq;
    vector<int> ans;
    int start = 0;
    long long time = 1;
    vector<array<int,3>> a(tasks.size());
    for (int i = 0; i < tasks.size(); i++) {
      a[i] = {tasks[i][0], tasks[i][1], i};
    }
    sort(a.begin(), a.end());
    while (start < a.size() || !pq.empty()) {
      if (pq.empty()) {
        time = max((long long)a[start][0], time);
      }
      while (start < a.size() && a[start][0] <= time) {
        pq.emplace(a[start][1], a[start][2]);
        start++;
      }
      auto cur = pq.top();
      pq.pop();
      time += cur.first;
      ans.push_back(cur.second);
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
    int n;
    cin >> n;
    vector<vector<int>> tasks(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
      cin >> tasks[i][0] >> tasks[i][1];
    }
    Solution *sol = new Solution();
    vector<int> ans = sol->getOrder(tasks);
    for (int i : ans) {
      cout << i << " ";
    }
    cout << endl;
  }
}
