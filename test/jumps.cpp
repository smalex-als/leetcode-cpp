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
//
// This problem was asked by Flipkart.
// Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.
// On the ith jump, you may move exactly i places to the left or right.
// Find a path with the fewest number of jumps required to get from 0 to N.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  // int n = 11;
  // for (int i = 1; i <= n; i++) {
  //   int pos = n * (1 + n) / 2 + 1;
  //   int pos2 = (n+1) * (1 + (n+1)) / 2 + 1;
  //   cout << "i=" << i << " pos=" << pos - 2*i;
  //   cout << " pos2=" << pos2 - 2*i;
  //   cout << endl;
  // }

  map<int, int> mp;
  for (int i = 0; i <= 20; i++) {
    int pos = 1;
    cout << i << ": ";
    for (int j = 1; j <= 20; j++) {
      if (i == j) {
        pos -= j;
      } else {
        pos += j;
      }
      cout << pos << " ";
      if (mp[pos] > 0) {
        mp[pos] = min(mp[pos], j);
      } else {
        mp[pos] = j;
      }
    }
    cout << endl;
  }
  debug(mp);
}
