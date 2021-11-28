#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 *
 * https://leetcode.com/problems/find-original-array-from-doubled-array/description/
 *
 * algorithms
 * Medium (33.75%)
 * Total Accepted:    16.4K
 * Total Submissions: 47.7K
 * Testcase Example:  '[1,3,4,2,6,8]'
 *
 * An integer array original is transformed into a doubled array changed by
 * appending twice the value of every element in original, and then randomly
 * shuffling the resulting array.
 * 
 * Given an array changed, return original if changed is a doubled array. If
 * changed is not a doubled array, return an empty array. The elements in
 * original may be returned in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: changed = [1,3,4,2,6,8]
 * Output: [1,3,4]
 * Explanation: One possible original array could be [1,3,4]:
 * - Twice the value of 1 is 1 * 2 = 2.
 * - Twice the value of 3 is 3 * 2 = 6.
 * - Twice the value of 4 is 4 * 2 = 8.
 * Other original arrays could be [4,3,1] or [3,1,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: changed = [6,3,0,1]
 * Output: []
 * Explanation: changed is not a doubled array.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: changed = [1]
 * Output: []
 * Explanation: changed is not a doubled array.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= changed.length <= 10^5
 * 0 <= changed[i] <= 10^5
 * 
 * 
 */
class Solution {
public:
  vector<int> findOriginalArray(vector<int>& a) {
    if (a.size() & 1) {
      return vector<int>();
    }
    map<int,int> mp;
    for (int i : a) {
      mp[i]++;
    }
    vector<int> res;
    while (!mp.empty()) {
      int x = mp.begin()->first;
      if (mp[x] == 1) {
        mp.erase(x);
      } else {
        mp[x]--;
      }
      res.push_back(x);
      int doubleX = x * 2;
      if (mp.find(doubleX) == mp.end()) {
        return vector<int>();
      } else {
        if (mp[doubleX] == 1) {
          mp.erase(doubleX);
        } else {
          mp[doubleX]--;
        }
      }
    }
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> res = sol->findOriginalArray(a);
    for (int i : res) {
      cout << i << " ";
    }
    cout << endl;
  }
}
