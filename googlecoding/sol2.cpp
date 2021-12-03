#include <bits/stdc++.h>
using namespace std;

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
