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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  map<int,string> mp = {{-1, "dennis"}, {-5, "alexander"}, {-36, "tanya"}, {-44, "alexey"}};

  function<void(int)> Dfs = [&](int v) {
    auto it = mp.lower_bound(-v);
    cout << "search " << v << " ";
    if (it == mp.end()) {
      cout << "not found\n";
    } else {
      cout << it->second;
    }
    cout << endl;
  };
  // function<void(int)> Dfs = [&](int v) {
  //   auto it = mp.upper_bound(v);
  //   cout << "search " << v << " ";
  //   if (it == mp.begin()) {
  //     cout << "not found\n";
  //   } else {
  //     cout << prev(it)->second << endl;
  //   }
  // };
  for (int i = 0; i < 50; i++) {
    Dfs(i);
  }
}
