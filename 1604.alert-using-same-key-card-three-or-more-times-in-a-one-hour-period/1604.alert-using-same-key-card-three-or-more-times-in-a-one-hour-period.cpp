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
 * @lc app=leetcode id=1604 lang=cpp
 *
 * [1604] Alert Using Same Key-Card Three or More Times in a One Hour Period
 *
 * https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/
 *
 * algorithms
 * Medium (45.91%)
 * Total Accepted:    15.1K
 * Total Submissions: 32.2K
 * Testcase Example:  '["daniel","daniel","daniel","luis","luis","luis","luis"]\n' +
  '["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]'
 *
 * LeetCode company workers use key-cards to unlock office doors. Each time a
 * worker uses their key-card, the security system saves the worker's name and
 * the time when it was used. The system emits an alert if any worker uses the
 * key-card three or more times in a one-hour period.
 * 
 * You are given a list of strings keyName and keyTime where [keyName[i],
 * keyTime[i]] corresponds to a person's name and the time when their key-card
 * was used in a single day.
 * 
 * Access times are given in the 24-hour time format "HH:MM", such as "23:51"
 * and "09:49".
 * 
 * Return a list of unique worker names who received an alert for frequent
 * keycard use. Sort the names in ascending order alphabetically.
 * 
 * Notice that "10:00" - "11:00" is considered to be within a one-hour period,
 * while "22:51" - "23:52" is not considered to be within a one-hour period.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"],
 * keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
 * Output: ["daniel"]
 * Explanation: "daniel" used the keycard 3 times in a one-hour period
 * ("10:00","10:40", "11:00").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime
 * = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
 * Output: ["bob"]
 * Explanation: "bob" used the keycard 3 times in a one-hour period
 * ("21:00","21:20", "21:30").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= keyName.length, keyTime.length <= 10^5
 * keyName.length == keyTime.length
 * keyTime[i] is in the format "HH:MM".
 * [keyName[i], keyTime[i]] is unique.
 * 1 <= keyName[i].length <= 10
 * keyName[i] contains only lowercase English letters.
 * 
 * 
 */
class Solution {
  public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
      int n = keyName.size();
      unordered_map<string, vector<int>> mp;
      for (int i = 0; i < n; i++) {
        string curTime = keyTime[i];
        mp[keyName[i]].push_back(stoi(curTime.substr(0, 2)) * 60 + stoi(curTime.substr(3, 2)));
      }
      vector<string> ans;
      for (auto &[k, values]: mp) {
        sort(all(values));
        for (int i = 0; i < values.size(); i++) {
          if (i + 2 < values.size() && values[i+2] - values[i] <= 60) {
            ans.push_back(k);
            break;
          }
        }
      }
      sort(all(ans));
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
    vector<string> keyName(n);
    vector<string> keyTime(n);
    for (int i = 0; i < n; i++) {
      cin >> keyName[i] >> keyTime[i];
    }
    vector<string> ans = (new Solution())->alertNames(keyName, keyTime);
    for (string name : ans) {
      cout << name << endl;
    }
  }
}
