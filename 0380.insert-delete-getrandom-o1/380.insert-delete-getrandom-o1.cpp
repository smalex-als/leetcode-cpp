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
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 *
 * algorithms
 * Medium (50.71%)
 * Total Accepted:    433.9K
 * Total Submissions: 852.1K
 * Testcase Example:  '["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]\n' +
  '[[],[1],[2],[2],[],[1],[2],[]]'
 *
 * Implement the RandomizedSet class:
 * 
 * 
 * RandomizedSet() Initializes the RandomizedSet object.
 * bool insert(int val) Inserts an item val into the set if not present.
 * Returns true if the item was not present, false otherwise.
 * bool remove(int val) Removes an item val from the set if present. Returns
 * true if the item was present, false otherwise.
 * int getRandom() Returns a random element from the current set of elements
 * (it's guaranteed that at least one element exists when this method is
 * called). Each element must have the same probability of being returned.
 * 
 * 
 * You must implement the functions of the class such that each function works
 * in average O(1) time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove",
 * "insert", "getRandom"]
 * [[], [1], [2], [2], [], [1], [2], []]
 * Output
 * [null, true, false, true, 2, true, false, 2]
 * 
 * Explanation
 * RandomizedSet randomizedSet = new RandomizedSet();
 * randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was
 * inserted successfully.
 * randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
 * randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now
 * contains [1,2].
 * randomizedSet.getRandom(); // getRandom() should return either 1 or 2
 * randomly.
 * randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now
 * contains [2].
 * randomizedSet.insert(2); // 2 was already in the set, so return false.
 * randomizedSet.getRandom(); // Since 2 is the only number in the set,
 * getRandom() will always return 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= val <= 2^31 - 1
 * At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
 * There will be at least one element in the data structure when getRandom is
 * called.
 * 
 * 
 */
class RandomizedSet {
  public:
    unordered_map<int, int> vals;
    vector<int> order;

    RandomizedSet() {
    }

    bool insert(int val) {
      int res = vals.count(val);
      if (res == 0) {
        vals[val] = order.size();
        order.push_back(val);
      }
      return res == 0;
    }

    bool remove(int val) {
      int res = vals.count(val);
      if (res > 0) {
        int index = vals[val];
        if (order.size() > 1 && index != order.size() - 1) {
          int yval = order[order.size() - 1];
          vals[yval] = index;
          order[index] = yval;
        }
        order.pop_back();
        vals.erase(val);
      }
      return res == 1;
    }

    int getRandom() {
      return order[rand() % order.size()];
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  RandomizedSet *rs = new RandomizedSet();
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "insert") {
      int val;
      cin >> val;
      cout << rs->insert(val) << endl;
    } else if (cmd == "remove") {
      int val;
      cin >> val;
      cout << rs->remove(val) << endl;
    } else {
      cout << rs->getRandom() << endl;
    }
  }
}
