#include <bits/stdc++.h>
#include "list.hpp"

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

//Given the head of a singly linked list, reverse the list, and return the 
//reversed list. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5]
//Output: [5,4,3,2,1]
// 
//
// Example 2: 
//
// 
//Input: head = [1,2]
//Output: [2,1]
// 
//
// Example 3: 
//
// 
//Input: head = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is the range [0, 5000]. 
// -5000 <= Node.val <= 5000 
// 
//
// 
// Follow up: A linked list can be reversed either iteratively or recursively. 
//Could you implement both? 
// Related Topics Linked List Recursion 👍 8935 👎 158

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* newHead = nullptr;
    ListNode* cur = head;
    while (cur) {
      ListNode *next = cur->next;
      cur->next = newHead;
      newHead = cur;
      cur = next;
    }
    return newHead;
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution *sol = new Solution();
    cout << to_string(sol->reverseList(makeList(a))) << endl;
  }
}

