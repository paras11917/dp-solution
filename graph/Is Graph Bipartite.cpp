class Solution
{
public:
   bool isBipartite(vector<vector<int>> &graph)
   {
      vector<int> adj[graph.size()];
      for (int i = 0; i < graph.size(); i++)
      {
         adj[i] = graph[i];
      }
      vector<int> col(graph.size(), -1);
      for (int i = 0; i < graph.size(); i++)
      {
         if (col[i] == -1)
         {
            if (!dfs(i, col, adj))
               return false;
         }
      }
      return true;
   }
   bool dfs(int i, vector<int> &col, vector<int> adj[])
   {
      for (auto x : adj[i])
      {
         if (col[x] == -1)
         {
            col[x] = !col[i];
            if (!dfs(x, col, adj))
               return false;
         }
         else if (col[x] == col[i])
         {
            return false;
         }
      }
      return true;
   }
};