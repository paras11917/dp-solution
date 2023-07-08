class Solution
{
   int cnt = 0;
   void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, bool &flag, int &s)
   {

      int n = grid.size();
      int m = grid[0].size();
      int r[] = {-1, 0, 1, 0};
      int c[] = {0, -1, 0, 1};
      vis[row][col] = 1;
      for (int x = 0; x < 4; x++)
      {
         int nr = row + r[x];
         int nc = col + c[x];
         if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc])
         {
            if (nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1)
            {
               flag = false;
            }
            dfs(nr, nc, vis, grid, flag, s);
         }
      }
      s++;
   }

public:
   int numEnclaves(vector<vector<int>> &grid)
   {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m, 0));
      for (int i = 1; i < grid.size() - 1; i++)
      {
         for (int j = 1; j < grid[0].size() - 1; j++)
         {
            if (grid[i][j] == 1 && !vis[i][j])
            {
               bool flag = true;
               int s = 0;
               dfs(i, j, vis, grid, flag, s);
               if (flag)
                  cnt += s;
               ;
            }
         }
      }
      return cnt;
   }
};