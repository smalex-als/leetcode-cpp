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
#include "list.hpp"

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (46.70%)
 * Total Accepted:    314.3K
 * Total Submissions: 671K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct LinkedList {
  ListNode *head;
  ListNode *tail;

  ListNode *pop_front() {
    if (empty()) {
      return nullptr;
    }
    ListNode *next = head->next;
    ListNode *node = head;
    head = next;
    if (next == nullptr) {
      tail = nullptr;
    }
    node->next = nullptr;
    return node;
  }

  void join(LinkedList *b) {
     if (head == nullptr) {
       head = b->head;
       tail = b->tail;
    } else if (b->head != nullptr) {
       tail->next = b->head;
       tail = b->tail;
     }
  }

  void push_back(ListNode *node) {
    if (!head) {
      head = node;
    }
    if (tail) {
      tail->next = node;
    }
    tail = node;
  }

  bool empty() {
    return head == nullptr;
  }
};

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    LinkedList *src = new LinkedList();
    src->head = head;
    LinkedList *first = new LinkedList();
    LinkedList *second = new LinkedList();
    while (!src->empty()) {
      ListNode *node = src->pop_front();
      if (node->val < x) {
        first->push_back(node);
      } else {
        second->push_back(node);
      }
    }
    first->join(second);
    return first->head;
  }
};

int main() {
  Solution *sol = new Solution();
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << to_string(sol->partition(makeList(a), x)) << endl;
  }
}
