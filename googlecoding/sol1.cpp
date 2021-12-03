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
  vector<int> start;
  vector<int> end;

  GenID(int n) {
    start.assign(n + 2, 0);
    end.assign(n + 2, 0);
  }

  int nextId = 1;

  int reserveAny() {
    if (start[nextId] != 0) {
      nextId = end[nextId]+1;
    }
    int val = nextId;
    nextId++;
    return val;
  }

  bool reserveID(int i) {
    if (start[i]) {
      return false;
    }
    if (start[i-1] == 0 && start[i+1] == 0) {
      start[i] = i;
      end[i] = i;
    } else if (start[i-1] == 0 && start[i+1] != 0) {
      start[i] = i;
      end[i] = end[i+1];
    } else if (start[i-1] != 0 && start[i+1] == 0) {
      start[i] = start[i-1];
      end[start[i-1]] = i;
      end[i-1] = i;
      end[i] = i;
    } else if (start[i-1] != 0 && start[i+1] != 0) {
      start[i] = start[i-1];
      start[i+1] = start[i-1];
      end[i-1] = end[i+1];
      end[i] = end[i+1];
      end[start[i-1]] = end[i+1];
    }

    return true;
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
