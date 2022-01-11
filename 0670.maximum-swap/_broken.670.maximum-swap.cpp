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
//You are given an integer num. You can swap two digits at most once to get the 
//maximum valued number. 
//
// Return the maximum valued number you can get. 
//
// 
// Example 1: 
//
// 
//Input: num = 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
// 
//
// Example 2: 
//
// 
//Input: num = 9973
//Output: 9973
//Explanation: No swap.
// 
//
// 
// Constraints: 
//
// 
// 0 <= num <= 10⁸ 
// 
// Related Topics Math Greedy 👍 1988 👎 117


class Solution {
public:
  int maximumSwap(int num) {
    string s = to_string(num);
    int best = s.size() - 1;
    int l = -1;
    int r = -1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (    ) {
        l = i;
        r = best;
      }
      if (    ) {
        best = i;
    }
    }
    if (l != -1) {
      swap(s[l], s[r]);
    }
    return stoi(s);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int t;
  cin >> t;
  while (t--) {
    auto sol = new Solution();
    int n;
    cin >> n;
    cout << sol->maximumSwap(n) << endl;
  }
}
