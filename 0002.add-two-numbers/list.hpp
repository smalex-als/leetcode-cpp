using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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

string to_string(ListNode *head) {
  string res;
  ListNode *cur = head;
  bool first = true;
  while (cur) {
    if (!first) {
      res += " ";
    }
    first = false;
    res += to_string(cur->val);
    cur = cur->next;
  }
  return res;
}

