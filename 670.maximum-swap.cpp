#include <bits/stdc++.h>
using namespace std;
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
      if (s[i] < s[best]) {
        l = i;
        r = best;
      }
      if (s[i] > s[best]) {
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
  auto sol = new Solution();
  cout << (7236 == sol->maximumSwap(2736)) << endl;
  cout << (9973 == sol->maximumSwap(9973)) << endl;
}
