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
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 *
 * https://leetcode.com/problems/snapshot-array/description/
 *
 * algorithms
 * Medium (37.07%)
 * Total Accepted:    76.7K
 * Total Submissions: 206.8K
 * Testcase Example:  '["SnapshotArray","set","snap","set","get"]\n[[3],[0,5],[],[0,6],[0,0]]'
 *
 * Implement a SnapshotArray that supports the following interface:
 * 
 * 
 * SnapshotArray(int length) initializes an array-like data structure with the
 * given length.  Initially, each element equals 0.
 * void set(index, val) sets the element at the given index to be equal to
 * val.
 * int snap() takes a snapshot of the array and returns the snap_id: the total
 * number of times we called snap() minus 1.
 * int get(index, snap_id) returns the value at the given index, at the time we
 * took the snapshot with the given snap_id
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["SnapshotArray","set","snap","set","get"]
 * [[3],[0,5],[],[0,6],[0,0]]
 * Output: [null,null,0,null,5]
 * Explanation: 
 * SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
 * snapshotArr.set(0,5);  // Set array[0] = 5
 * snapshotArr.snap();  // Take a snapshot, return snap_id = 0
 * snapshotArr.set(0,6);
 * snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return
 * 5
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= length <= 50000
 * At most 50000 calls will be made to set, snap, and get.
 * 0 <= index < length
 * 0 <= snap_id < (the total number of times we call snap())
 * 0 <= val <= 10^9
 * 
 * 
 */
class SnapshotArray {
public:
  vector<map<int,int>> storage;
  int snap_id;
  SnapshotArray(int length) {
    storage = vector<map<int,int>>(length);
    snap_id = 0;
  }

  void set(int index, int val) {
    storage[index][-snap_id] = val;
  }

  int snap() {
    snap_id++;
    return snap_id-1;
  }

  int get(int index, int snap_id) {
    auto it = storage[index].lower_bound(-snap_id);
    return it->second;
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    SnapshotArray* arr = new SnapshotArray(n);
    for (int i = 0; i < m; ++i) {
      string cmd;
      cin >> cmd;
      if (cmd == "snap") {
        cout << arr->snap() << endl;
      } else if (cmd == "set") {
        int index, val;
        cin >> index >> val;
        arr->set(index, val);
      } else if (cmd == "get") {
        int index, span_id;
        cin >> index >> span_id;
        cout << arr->get(index, span_id) << endl;
      }
    }
  }
}
