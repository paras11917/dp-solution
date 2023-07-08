class Solution
{
   void dfs(int node, vector<int> adj[], vector<int> &vis)
   {
      vis[node] = 1;
      for (auto adnod : adj[node])
      {
         if (!vis[adnod])
         {
            dfs(adnod, adj, vis);
         }
      }
   }

public:
   int findCircleNum(vector<vector<int>> &isConnected)
   {
      int n = isConnected.size();
      vector<int> adj[n];
      vector<int> vis(n, 0);
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (isConnected[i][j] && i != j)
            {
               adj[i].push_back(j);
               adj[j].push_back(i);
            }
         }
      }
      int c = 0;
      for (int i = 0; i < n; i++)
      {
         if (!vis[i])
         {
            c++;
            dfs(i, adj, vis);
         }
      }
      return c;
   }
};