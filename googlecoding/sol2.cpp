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

  GenID(int n) {
    p.assign(n + 2, 0);
    for (int i = 0; i < p.size(); i++) {
      p[i] = i;
    }
  }

  int reserveAny() {
    return reserveID(1);
  }

  int get(int i) {
    return p[i] == i ? i : p[i] = get(p[i]);
  }

  int reserveID(int i) {
    int id = get(i);
    p[id] = get(id + 1);
    return id;
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
    // cout << "start ";
    // for (int i : genID.start) {
    //   cout << i << " ";
    // }
    // cout << endl;
    // cout << "end ";
    // for (int i : genID.end) {
    //   cout << i << " ";
    // }
    // cout << endl;
  }
}
