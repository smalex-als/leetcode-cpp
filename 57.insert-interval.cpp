#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Medium (36.69%)
 * Total Accepted:    422.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * You are given an array of non-overlapping intervals intervals where
 * intervals[i] = [starti, endi] represent the start and the end of the i^th
 * interval and intervals is sorted in ascending order by starti. You are also
 * given an interval newInterval = [start, end] that represents the start and
 * end of another interval.
 * 
 * Insert newInterval into intervals such that intervals is still sorted in
 * ascending order by starti and intervals still does not have any overlapping
 * intervals (merge overlapping intervals if necessary).
 * 
 * Return intervals after the insertion.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * Example 3:
 * 
 * 
 * Input: intervals = [], newInterval = [5,7]
 * Output: [[5,7]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: intervals = [[1,5]], newInterval = [2,3]
 * Output: [[1,5]]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: intervals = [[1,5]], newInterval = [2,7]
 * Output: [[1,7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^5
 * intervals is sorted by starti in ascending order.
 * newInterval.length == 2
 * 0 <= start <= end <= 10^5
 * 
 * 
 */
class Solution {
public:
  vector<vector<int>> insert(const vector<vector<int>>& ab,
      const vector<int>& c) {
    if (ab.empty()) {
      vector<vector<int>> res;
      res.push_back(c);
      return res;
    }
    int l = -1;
    int r = ab.size();
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (ab[m][0] <= c[0]) {
        l = m;
      } else {
        r = m;
      }
    }
    if (l == ab.size()) {
      vector<vector<int>> res = ab;
      res.push_back(c);
      return res;
    }
    int start = l;
    l = -1;
    r = ab.size();
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (ab[m][0] <= c[1]) {
        l = m;
      } else {
        r = m;
      }
    }
    int end = l;
    vector<vector<int>> res;
    for (int i = 0; i < start; i++) {
      res.push_back(ab[i]);
    }
    vector<int> newPair = {min(ab[start][0], c[0]), max(ab[end][1], c[1])};
    res.push_back(newPair);
    for (int i = end + 1; i < ab.size(); i++) {
      res.push_back(ab[i]);
    }

    return res;
  }
};

int main() {
  auto sol = new Solution();
  {
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    vector<vector<int>> ab = (sol->insert(intervals, newInterval));
    for (vector<int> row : ab) {
      cout << "[" << row[0] << ", " << row[1] << "] ";
    }
    cout << endl;
  }
  {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> ab = (sol->insert(intervals, newInterval));
    for (vector<int> row : ab) {
      cout << "[" << row[0] << ", " << row[1] << "] ";
    }
    cout << endl;
  }
  {
    vector<vector<int>> intervals = {};
    vector<int> newInterval = {5,7};
    vector<vector<int>> ab = (sol->insert(intervals, newInterval));
    for (vector<int> row : ab) {
      cout << "[" << row[0] << ", " << row[1] << "] ";
    }
    cout << endl;
  }
  {
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {2,7};
    vector<vector<int>> ab = (sol->insert(intervals, newInterval));
    for (vector<int> row : ab) {
      cout << "[" << row[0] << ", " << row[1] << "] ";
    }
    cout << endl;
  }
}
