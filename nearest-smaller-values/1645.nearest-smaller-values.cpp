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
#define mp make_pair

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

class TaskB {
public:
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    vi a(n);
    stack<ii> st;
    st.push({0, 0});
    for (int i = 0; i < n; ++i) {
      int x;
      in >> x;
      while (st.top().first >= x) {
        st.pop();
      }
      out << st.top().second << " ";
      st.push({x, i + 1});
    }
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  TaskB solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solveOne(in, out);
}

