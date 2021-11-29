#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2034 lang=cpp
 *
 * [2034] Stock Price Fluctuation 
 *
 * https://leetcode.com/problems/stock-price-fluctuation/description/
 *
 * algorithms
 * Medium (37.15%)
 * Total Accepted:    8.3K
 * Total Submissions: 21.4K
 * Testcase Example:  '["StockPrice","update","update","current","maximum","update","maximum","update","minimum"]\n' +
  '[[],[1,10],[2,5],[],[],[1,3],[],[4,2],[]]'
 *
 * You are given a stream of records about a particular stock. Each record
 * contains a timestamp and the corresponding price of the stock at that
 * timestamp.
 * 
 * Unfortunately due to the volatile nature of the stock market, the records do
 * not come in order. Even worse, some records may be incorrect. Another record
 * with the same timestamp may appear later in the stream correcting the price
 * of the previous wrong record.
 * 
 * Design an algorithm that:
 * 
 * 
 * Updates the price of the stock at a particular timestamp, correcting the
 * price from any previous records at the timestamp.
 * Finds the latest price of the stock based on the current records. The latest
 * price is the price at the latest timestamp recorded.
 * Finds the maximum price the stock has been based on the current records.
 * Finds the minimum price the stock has been based on the current records.
 * 
 * 
 * Implement the StockPrice class:
 * 
 * 
 * StockPrice() Initializes the object with no price records.
 * void update(int timestamp, int price) Updates the price of the stock at the
 * given timestamp.
 * int current() Returns the latest price of the stock.
 * int maximum() Returns the maximum price of the stock.
 * int minimum() Returns the minimum price of the stock.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["StockPrice", "update", "update", "current", "maximum", "update",
 * "maximum", "update", "minimum"]
 * [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
 * Output
 * [null, null, null, 5, 10, null, 5, null, 2]
 * 
 * Explanation
 * StockPrice stockPrice = new StockPrice();
 * stockPrice.update(1, 10); // Timestamps are [1] with corresponding prices
 * [10].
 * stockPrice.update(2, 5);  // Timestamps are [1,2] with corresponding prices
 * [10,5].
 * stockPrice.current();     // return 5, the latest timestamp is 2 with the
 * price being 5.
 * stockPrice.maximum();     // return 10, the maximum price is 10 at timestamp
 * 1.
 * stockPrice.update(1, 3);  // The previous timestamp 1 had the wrong price,
 * so it is updated to 3.
 * ⁠                         // Timestamps are [1,2] with corresponding prices
 * [3,5].
 * stockPrice.maximum();     // return 5, the maximum price is 5 after the
 * correction.
 * stockPrice.update(4, 2);  // Timestamps are [1,2,4] with corresponding
 * prices [3,5,2].
 * stockPrice.minimum();     // return 2, the minimum price is 2 at timestamp
 * 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= timestamp, price <= 10^9
 * At most 10^5 calls will be made in total to update, current, maximum, and
 * minimum.
 * current, maximum, and minimum will be called only after update has been
 * called at least once.
 * 
 * 
 */
class StockPrice {
public:
  map<int,int> mx;
  map<int,int> st;
  
  StockPrice() {
  }

  void update(int timestamp, int price) {
    if (st.find(timestamp) != st.end()) {
      int prev = st[timestamp];
      if (mx[prev] == 1) {
        mx.erase(prev);
      } else {
        mx[prev]--;
      }
    }
    mx[price]++;
    st[timestamp] = price;
  }

  int current() {
    return prev(st.end())->second;
  }

  int maximum() {
    return prev(mx.end())->first;
  }

  int minimum() {
    return mx.begin()->first;
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
    StockPrice *st = new StockPrice();
    for (int i = 0; i < n; i++) {
      string cmd;
      cin >> cmd;
      if (cmd == "update") {
        int ts, price;
        cin >> ts >> price;
        st->update(ts, price);
      } else if (cmd == "current") {
        cout << st->current() << endl;
      } else if (cmd == "maximum") {
        cout << st->maximum() << endl;
      } else if (cmd == "minimum") {
        cout << st->minimum() << endl;
      }
    }
  }
}
