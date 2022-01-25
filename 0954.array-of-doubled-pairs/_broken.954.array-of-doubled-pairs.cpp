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
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 *
 * https://leetcode.com/problems/array-of-doubled-pairs/description/
 *
 * algorithms
 * Medium (37.23%)
 * Total Accepted:    58.3K
 * Total Submissions: 156.2K
 * Testcase Example:  '[3,1,3,6]'
 *
 * Given an integer array of even length arr, return true if it is possible to
 * reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i <
 * len(arr) / 2, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,1,3,6]
 * Output: false
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,1,2,6]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [4,-2,2,-4]
 * Output: true
 * Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4]
 * or [2,4,-2,-4].
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [1,2,4,16,8,4]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 3 * 10^4
 * arr.length is even.
 * -10^5 <= arr[i] <= 10^5
 * 
 * 
 */
class Solution {
public:
  bool canReorderDoubled(vector<int>& arr) {
    unordered_map<int,int> mp;
    for (int i = 0; i < arr.size(); i++) {
      mp[arr[i]]++;
    }
    sort(arr.begin(), arr.end(), [&](int i, int j) {
        return abs(i) < abs(j);
    });
    for (int i = 0; i < arr.size(); i++) {
      if (mp[arr[i]] > 0) {
        if (mp.find(2 * arr[i]) == mp.end()) {
          return false;
        } else {
          if (mp[2 * arr[i]] <= 0) {
            return false;
          }
          mp[arr[i]]--;
          mp[2 * arr[i]]--;
        }
      }
    }
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution *sol = new Solution();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << sol->canReorderDoubled(a) << endl;
  }
}
