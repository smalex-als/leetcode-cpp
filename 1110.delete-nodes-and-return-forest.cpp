/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 *
 * https://leetcode.com/problems/delete-nodes-and-return-forest/description/
 *
 * algorithms
 * Medium (68.78%)
 * Total Accepted:    134K
 * Total Submissions: 194.9K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n[3,5]'
 *
 * Given the root of a binary tree, each node in the tree has a distinct
 * value.
 * 
 * After deleting all nodes with a value in to_delete, we are left with a
 * forest (a disjoint union of trees).
 * 
 * Return the roots of the trees in the remaining forest. You may return the
 * result in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
 * Output: [[1,2,null,4],[6],[7]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,4,null,3], to_delete = [3]
 * Output: [[1,2,4]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is at most 1000.
 * Each node has a distinct value between 1 and 1000.
 * to_delete.length <= 1000
 * to_delete contains distinct values between 1 and 1000.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<TreeNode*> res;

  TreeNode* solve(TreeNode *node, unordered_set<int> &setDelete) {
    if (node == NULL) {
      return NULL;
    }
    TreeNode *left = solve(node->left, setDelete);
    TreeNode *right = solve(node->right, setDelete);
    if (setDelete.count(node->val) > 0) {
      setDelete.erase(node->val);
      if (left != NULL) {
        res.push_back(left);
      }
      if (right != NULL) {
        res.push_back(right);
      }
      return NULL;
    }
    node->left = left;
    node->right = right;
    return node;
  }

  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    res.clear();
    unordered_set<int> setDelete;
    for (int i : to_delete) {
      setDelete.insert(i);
    }

    root = solve(root, setDelete);
    if (root != NULL) {
      res.push_back(root);
    }
    return res;
  }
};
