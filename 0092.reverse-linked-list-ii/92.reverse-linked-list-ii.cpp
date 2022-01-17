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

//Given the head of a singly linked list and two integers left and right where 
//left <= right, reverse the nodes of the list from position left to position 
//right, and return the reversed list. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5], left = 2, right = 4
//Output: [1,4,3,2,5]
// 
//
// Example 2: 
//
// 
//Input: head = [5], left = 1, right = 1
//Output: [5]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is n. 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//Follow up: Could you do it in one pass? Related Topics Linked List 👍 4876 👎 
//239


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 */
struct LinkedList {
  ListNode *head = nullptr;
  ListNode *tail = nullptr;

  LinkedList() {}
  LinkedList(ListNode *head) : head(head) {}

  void Append(LinkedList *src) {
    if (tail) {
      tail->next = src->head;
    } else {
      head = src->head;
    }
    tail = src->tail;
    src->head = nullptr;
    src->tail = nullptr;
  }

  void PushFront(ListNode *node) {
    if (node == nullptr) {
      return;
    }
    if (head) {
      node->next = head;
    }
    head = node;
    if (tail == nullptr) {
      tail = node;
    }
  }

  void PushBack(ListNode *node) {
    if (head == nullptr) {
      head = node;
    }
    if (tail) {
      tail->next = node;
    }
    tail = node;
  }

  ListNode* PopFront() {
    ListNode *node = head;
    head = head->next;
    if (head == nullptr) {
      tail = nullptr;
    }
    node->next = nullptr;
    return node;
  }

  bool Empty() {
    return head == nullptr;
  }
};

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    LinkedList *src = new LinkedList();
    src->head = head;
    LinkedList *dst = new LinkedList();
    for (int i = 1; i < left && !src->Empty(); i++) {
      dst->PushBack(src->PopFront());
    }
    LinkedList *tmp = new LinkedList();
    for (int i = left; i <= right && !src->Empty(); i++) {
      tmp->PushFront(src->PopFront());
    }
    dst->Append(tmp);
    while (!src->Empty()) {
      dst->PushBack(src->PopFront());
    }
    return dst->head;
  }
};

int main() {
  Solution *sol = new Solution();
  int t;
  cin >> t;
  while (t--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << to_string(sol->reverseBetween(makeList(a), l, r)) << endl;
  }
}

