vector<vector<int>> levelOrder(TreeNode *root)
{
   vector<vector<int>> ans;
   if (!root)
      return ans;
   TreeNode *curr = root;
   queue<TreeNode *> q;
   q.push(curr);
   vector<int> v;
   v.push_back(root->val);
   ans.push_back(v);
   while (!q.empty())
   {
      int n = q.size();
      vector<int> x;
      for (int i = 0; i < n; i++)
      {
         curr = q.front();
         q.pop();
         if (curr->left)
         {
            q.push(curr->left);
            x.push_back(curr->left->val);
         }
         if (curr->right)
         {
            q.push(curr->right);
            x.push_back(curr->right->val);
         }
      }
      if (!x.empty())
         ans.push_back(x);
   }
   return ans;
}