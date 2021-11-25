#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (39.09%)
 * Total Accepted:    802.8K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 * 
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: coins = [1], amount = 1
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: coins = [1], amount = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * 
 */
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 1e6);
    dp[0] = 0;
    for (int c : coins) {
      for (int i = c; i <= amount; i++) {
        dp[i] = min(dp[i], dp[i-c]+1);
      }
    }
    return dp[amount] == 1e6 ? -1 : dp[amount];
  }
};

int main() {
  Solution *sol = new Solution();
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  int cnt = sol->coinChange(coins, amount);
  cout << cnt << endl;
}
