 Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
          
          
 TreeNode * flatten(TreeNode* root, TreeNode * pre = nullptr) {
        if (root == nullptr) return pre;
        pre = flatten(root->right, pre);
        pre = flatten(root->left, pre);
        root->right = pre;
        root->left = nullptr;
        pre = root;
        return pre;
    }
