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
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (55.28%)
 * Total Accepted:    241.7K
 * Total Submissions: 436.5K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 * 
 * Return the number of combinations that make up that amount. If that amount
 * of money cannot be made up by any combination of the coins, return 0.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * The answer is guaranteed to fit into a signed 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: amount = 5, coins = [1,2,5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: amount = 10, coins = [10]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 300
 * 1 <= coins[i] <= 5000
 * All the values of coins are unique.
 * 0 <= amount <= 5000
 * 
 * 
 */
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int coin : coins) {
      for (int i = coin; i <= amount; i++) {
        // Problem
        dp[i]
      }
    }
    return dp[amount];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
      cin >> coins[i];
    }
    Solution *sol = new Solution();
    cout << sol->change(x, coins) << endl;
  }
}
