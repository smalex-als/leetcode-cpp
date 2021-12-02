#include <bits/stdc++.h>
using namespace std;
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


/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* newHead = nullptr;
    ListNode* cur = head;
    while (cur) {
      ListNode *next = cur->next;
      if (newHead != nullptr) {
        cur->next = newHead;
      } else {
        cur->next = nullptr;
      }
      newHead = cur;
      cur = next;
    }
    return newHead;
  }
};

ListNode *makeList(vector<int> a) {
  ListNode *head = nullptr;
  ListNode *tail = nullptr;
  for (int i : a) {
    ListNode *node = new ListNode(i);
    if (tail != nullptr) {
      tail->next = node;
    }
    if (head == nullptr) {
      head = node;
    }
    tail = node;
  }
  return head;
}

void Dump(ListNode *head) {
  ListNode *cur = head;
  while (cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

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
    Dump(sol->reverseList(makeList(a)));
  }
}

