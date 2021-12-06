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

struct GenID {
  vector<int> p;
  vector<int> size;

  GenID(int n) {
    p.assign(n + 2, 0);
    for (int i = 0; i < p.size(); i++) {
      p[i] = i;
    }
    size.assign(n + 2, 1);
  }

  int reserveAny() {
    return reserveID(1);
  }

  int reserveID(int i) {
    int id = i + size[i];
    size[i]++;
    return i + size[i] - 1;
  }
};
// 0 1 2 3 4 5 6 7
// 0 0 0 0 0 0 0 0

// 0 1 2 3 4 5 6 7
// 0 1 0 0 1 0 0 0

// 0 1 1 3 4 5 6 7
// 0 2 0 0 1 0 0 0

// 0 1 1 3 4 5 6 7
// 0 1 0 0 1 0 0 0

// 0 1 1 1 4 4 6 7
// 0 1 0 0 2 0 0 0
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    GenID genID(n);
    for (int i = 0; i < m; i++) {
      string cmd;
      cin >> cmd;
      if (cmd == "reserveAny") {
        cout << genID.reserveAny() << " ";
      } else if (cmd == "reserveID") {
        int i;
        cin >> i;
        genID.reserveID(i);
      }
    }
    cout << endl;
  }
}
