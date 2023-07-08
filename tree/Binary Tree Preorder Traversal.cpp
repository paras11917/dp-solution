void helper(vector<int> &v, TreeNode *root)
{
   if (root == NULL)
   {
      return;
   }
   v.push_back(root->val);
   if (root->left != NULL)
   {
      helper(v, root->left);
   }

   if (root->right != NULL)
   {
      helper(v, root->right);
   }
}

vector<int> preorderTraversal(TreeNode *root)
{
   vector<int> v;
   helper(v, root);

   return v;
}