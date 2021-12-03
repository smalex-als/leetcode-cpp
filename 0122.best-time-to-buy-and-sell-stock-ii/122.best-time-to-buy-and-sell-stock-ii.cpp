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
// You are given an integer array prices where prices[i] is the price of a given 
// stock on the iᵗʰ day. 
// 
//  On each day, you may decide to buy and/or sell the stock. You can only hold 
// at most one share of the stock at any time. However, you can buy it then 
// immediately sell it on the same day. 
// 
//  Find and return the maximum profit you can achieve. 
// 
//  
//  Example 1: 
// 
//  
// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 
// 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// 
// Total profit is 4 + 3 = 7.
//  
// 
//  Example 2: 
// 
//  
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 
// 5-1 = 4.
// Total profit is 4.
//  
// 
//  Example 3: 
// 
//  
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the 
// stock to achieve the maximum profit of 0.
// 
//
// 
// Constraints: 
//
// 
// 1 <= prices.length <= 3 * 10⁴ 
// 0 <= prices[i] <= 10⁴ 
// 
// Related Topics Array Dynamic Programming Greedy 👍 5669 👎 2210


class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans = 0;
      for (int i = 1; i < prices.size(); i++) {
        ans += max(0, prices[i] - prices[i-1]);
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
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
      cin >> prices[i];
    }
    auto sol = new Solution();
    cout << sol->maxProfit(prices) << endl;
  }
}
