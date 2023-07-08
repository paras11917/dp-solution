vector<int> helper(TreeNode *root, vector<int> &v)
{
   if (!root)
      return v;
   if (root->left != NULL)
   {
      helper(root->left, v);
   }
   if (root->right != NULL)
   {
      helper(root->right, v);
   }

   v.push_back(root->val);
   return v;
}

vector<int> postorderTraversal(TreeNode *root)
{
   vector<int> v;
   helper(root, v);
   return v;
}