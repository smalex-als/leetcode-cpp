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
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (44.15%)
 * Total Accepted:    162.4K
 * Total Submissions: 366.9K
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a
 * row.
 * 
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 * 
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: asteroids = [-2,-1,1,2]
 * Output: [-2,-1,1,2]
 * Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving
 * right. Asteroids moving the same direction never meet, so no asteroids will
 * meet each other.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 * 
 * 
 */
class Solution {
public:
  vector<int> asteroidCollision(vector<int>& a) {
    int n = a.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (    ) {
        if (st.top() == -a[i]) {
          st.pop();
        } else if (st.top() < -a[i]) {
          st.pop();
          i--;
        }
      } else {
        st.push(a[i]);
      }
    }
    vector<int> res;
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    reverse(all(res));
    return res;
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
    vector<int> a(n);
    for (int i = 0 ; i < n; i++) {
      cin >> a[i];
    }
    Solution *sol = new Solution();
    vector<int> res = sol->asteroidCollision(a);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
