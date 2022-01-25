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
#include "tree.hpp"

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
/*
 * @lc app=leetcode id=366 lang=cpp
 *
 * [366] Find Leaves of Binary Tree
 *
 * https://leetcode.com/problems/find-leaves-of-binary-tree/description/
 *
 * algorithms
 * Medium (75.38%)
 * Total Accepted:    119.4K
 * Total Submissions: 157.9K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the root of a binary tree, collect a tree's nodes as if you were doing
 * this:
 * 
 * 
 * Collect all the leaf nodes.
 * Remove all the leaf nodes.
 * Repeat until the tree is empty.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5]
 * Output: [[4,5,3],[2],[1]]
 * Explanation:
 * [[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers
 * since per each level it does not matter the order on which elements are
 * returned.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  int solve(TreeNode* node, vector<vector<int>> &res) {
    if (node == NULL) {
      return 0;
    }
    if (node->left == NULL && node->right == NULL) {
      if (0 == res.size()) {
        res.push_back(vector<int>());
      }
      res[0].push_back(node->val);
      return 0;
    }
    int mx = max(solve(node->left, res), solve(node->right, res)) + 1;
    while (mx >= res.size()) {
      res.push_back(vector<int>());
    }
    res[mx].push_back(node->val);
    return mx;
  }

  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    solve(root, res);
    return res;
  }
};

TreeNode *makeTree(vector<int> &a, int &pos, int val) {
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
    if (rightVal != INT_MAX) {
      node->right = makeTree(a, pos, rightVal);
    }
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
    int pos = 0;
    TreeNode* root = makeTree(a);
    Solution *sol = new Solution();
    vector<vector<int>> res = sol->findLeaves(root);
    cout << res.size() << endl;
    for (vector<int> row : res) {
      for (int col : row) {
        cout << col << " ";
      }
      cout << endl;
    }
  }
}
