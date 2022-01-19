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
// 253. Meeting Rooms II
// 
// Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], 
// return the minimum number of conference rooms required.
// 
// Example 1:
// 
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: 2
// Example 2:
// 
// Input: intervals = [[7,10],[2,4]]
// Output: 1
// 
// Constraints:
// 
// 1 <= intervals.length <= 10^4
// 0 <= starti < endi <= 10^6
//

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& a) {
      map<int,int> mp;
      for (int i = 0; i < a.size(); i++) {
        mp[a[i][0]]++;
        mp[a[i][1]]--;
      }
      int mx = 0;
      int rooms = 0;
      for (auto [time, action] : mp) {
        rooms += action;
        mx = max(mx, rooms);
      }
      return mx;
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
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1];
    }
    cout << (new Solution())->minMeetingRooms(a) << endl;
  }
}
