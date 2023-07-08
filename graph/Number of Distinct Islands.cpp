void dfs(int ri, int rj, int i, int j, vector<pair<int, int>> &v, vector<vector<int>> &vis, vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vis[i][j] = 1;
   v.push_back({ri - i, rj - j});
   int dr[] = {-1, 0, 1, 0};
   int dc[] = {0, 1, 0, -1};

   for (int k = 0; k < 4; k++)
   {
      int nr = i + dr[k];
      int nc = j + dc[k];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc])
      {
         dfs(ri, rj, nr, nc, v, vis, grid);
      }
   }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
   // code here
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   set<vector<pair<int, int>>> st;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (!vis[i][j] && grid[i][j])
         {
            vector<pair<int, int>> v;
            dfs(i, j, i, j, v, vis, grid);
            st.insert(v);
         }
      }
   }
   return st.size();
}