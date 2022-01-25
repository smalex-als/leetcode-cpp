#include <bits/stdc++.h>
#include "tree.hpp"

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
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (52.51%)
 * Total Accepted:    616K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the root of a binary tree, return the length of the diameter of the
 * tree.
 * 
 * The diameter of a binary tree is the length of the longest path between any
 * two nodes in a tree. This path may or may not pass through the root.
 * 
 * The length of a path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 * 
 * 
 */

class Solution {
public:
  int mx = 0;

  int solve(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    int l = solve(node->left);
    int r = solve(node->right);
    
    return XXX
  }

  int diameterOfBinaryTree(TreeNode* root) {
    mx = 0;
    solve(root);
    return mx;
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
    TreeNode *tree = makeTree(a);
    Solution *sol = new Solution();
    cout << sol->diameterOfBinaryTree(tree) << endl;
  }
}
