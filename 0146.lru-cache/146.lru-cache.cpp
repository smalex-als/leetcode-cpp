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
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (38.49%)
 * Total Accepted:    964K
 * Total Submissions: 2.5M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 * 
 * Implement the LRUCache class:
 * 
 * 
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 * 
 * 
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 * 
 */
class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> l;
    int capacity;

    LRUCache(int cap) {
      capacity = cap;
    }
    
    int get(int key) {
      if (mp.find(key) != mp.end()) {
        l.splice(l.begin(), l, mp[key]);
        return mp[key]->second;
      }
      return -1;
    }
    
    void put(int key, int value) {
      if (mp.find(key) != mp.end()) {
        l.splice(l.begin(), l, mp[key]);
        mp[key]->second = value;
        return;
      }
      if (capacity == l.size()) {
        auto oldKey = l.back().first;
        l.pop_back();
        mp.erase(oldKey);
      }
      l.push_front({key, value});
      mp[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cap, n;
  cin >> cap >> n;
  LRUCache *cache = new LRUCache(cap);
  for (int i = 0; i < n; i++) {
    int key;
    string cmd;
    cin >> cmd >> key;
    if (cmd == "put") {
      int val;
      cin >> val;
      cache->put(key, val);
    } else {
      cout << cache->get(key) << endl;
    }
  }
}
