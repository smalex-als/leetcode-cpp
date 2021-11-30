#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int type;
  int size;
  string value;
  TreeNode* left;
  TreeNode* right;

  char findChar(TreeNode *node, int i) {
    if (node == NULL || i >= node->size) {
      return 0;
    }
    if (node->type == 2) {
      return i < node->size ? node->value[i] : 0;
    }
    if (i < node->left->size) {
      return findChar(node->left, i);
    }
    return findChar(node->right, i - node->left->size);
  }

  void deleteRange(TreeNode *node, int i, int len) {
    if (node == NULL) {
      return;
    }
    if (node->type == 2) {
      node->value = node->value.substr(0, i) + node->value.substr(i + len);
      node->size = node->value.size();
      return;
    }
    if (i < node->left->size && i + len < node->left->size) {
      deleteRange(node->left, i, len);
    } else if (i >= node->left->size) {
      deleteRange(node->right, i - node->left->size, len);
    } else {
      deleteRange(node->left, i, node->left->size - i);
      deleteRange(node->right, 0, len - node->left->size + i - 1);
    }
    node->size = node->left->size + node->right->size;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  TreeNode *root = new TreeNode();
  root->type = 1;
  root->size = 26;
  root->left = new TreeNode();
  root->left->type = 2;
  root->left->value = "ABCDEF";
  root->left->size = 6;
  root->right = new TreeNode();
  root->right->type = 2;
  root->right->value = "GHIJKLMNOPQRSTUVWXYZ";
  root->right->size = 20;
  cout << "res=" << root->findChar(root, 2) << endl;
  cout << "res=" << root->findChar(root, 5) << endl;
  cout << "res=" << root->findChar(root, 6) << endl;
  cout << "res=" << root->findChar(root, 25) << endl;
  root->deleteRange(root, 2, 1);
  cout << "res=" << root->findChar(root, 1) << endl;
  cout << "res=" << root->findChar(root, 2) << endl;
  root->deleteRange(root, 6, 1);
  root->deleteRange(root, 5, 2);
  cout << "res=" << root->findChar(root, 4) << endl;
  cout << "res=" << root->findChar(root, 5) << endl;
  root->deleteRange(root, 20, 2);
  for (int i = 0; i < root->size; i++) {
    cout << root->findChar(root, i);
  }
  cout << endl;
  root->deleteRange(root, 3, 10);
  // ABCDE HIJKLMNOPQRSTUVYZ
  for (int i = 0; i < root->size; i++) {
    cout << root->findChar(root, i);
  }
  cout << endl;
}
