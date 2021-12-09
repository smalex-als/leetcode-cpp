using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *makeTree(vector<int> &a, int &pos, int val) {
  if (val == INT_MAX) {
    return nullptr;
  }
  TreeNode *node = new TreeNode(val);
  if (pos < a.size()) {
    int leftVal = a[pos];
    int rightVal = INT_MAX;
    pos++;
    if (pos < a.size()) {
      rightVal = a[pos];
      pos++;
    }
    node->left = makeTree(a, pos, leftVal);
    node->right = makeTree(a, pos, rightVal);
  }
  return node;
}

TreeNode *makeTree(vector<int> &a) {
  int pos = 0;
  if (pos < a.size()) {
    int val = a[pos];
    pos++;
    return makeTree(a, pos, val);
  }
  return NULL;
}

