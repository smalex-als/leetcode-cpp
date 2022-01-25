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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a = {1, 3, 5, 6, 8, 9, 10, 53};
  cout << *upper_bound(all(a), 1) << endl;
  cout << *prev(upper_bound(all(a), 1)) << endl;
  cout << *prev(upper_bound(all(a), 2)) << endl;
}
