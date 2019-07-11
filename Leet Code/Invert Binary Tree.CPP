Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr) {
        return nullptr;
    }
    TreeNode* right = invertTree(root->right);
    TreeNode* left = invertTree(root->left);
    root->left = right;
    root->right = left;
    return root;
}
};
