void helper(vector<int> &v, TreeNode *root)
{
   if (root == NULL)
   {
      return;
   }

   if (root->left != NULL)
   {
      helper(v, root->left);
   }
   v.push_back(root->val);
   if (root->right != NULL)
   {
      helper(v, root->right);
   }
}

vector<int> inorderTraversal(TreeNode *root)
{
   vector<int> v;
   helper(v, root);

   return v;
}