#include <bits/stdc++.h>

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

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.22%)
 * Total Accepted:    2.3M
 * Total Submissions: 6.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 */

struct LinkedList {
  ListNode* head;
  ListNode* tail;

  void append(int val) {
    ListNode *node = new ListNode(val);
    if (tail != nullptr) {
      tail->next = node;
    }
    if (head == nullptr) {
      head = node;
    }
    tail = node;
  }
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    LinkedList *res = new LinkedList();
    int carry = 0;
    while (     ) {
      int val = carry;
      if (l1) {
        val += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        val += l2->val;
        l2 = l2->next;
      }

    }
    return res->head;
  }
};

int main() {
  Solution *sol = new Solution();
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    cout << to_string(sol->addTwoNumbers(makeList(a), makeList(b))) << endl;
  }
}
