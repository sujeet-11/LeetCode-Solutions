class Solution {
private:
  int n, m;
  vector<vector<bool>> vis;
  bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid) {
    vis[r][c] = true;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    auto is_valid = [&](int nr, int nc) -> bool {
      return nr >= 0 && nr < n && nc >= 0 && nc < m;
    };
    for (int d = 0; d < 4; d++) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (!is_valid(nr,nc)) {
        continue;
      }
      if (grid[nr][nc] != grid[r][c]) {
        continue;
      }
      if (!vis[nr][nc]) {
        if (dfs(nr, nc, r, c, grid)) {
          return true;
        }
      } else if (nr != pr || nc != pc) {
        return true;
      }
    }
    return false;
  }
public:
  bool containsCycle(vector<vector<char>>& grid) {
    n = (int) grid.size();
    m = (int) grid[0].size();
    vis.assign(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j]) {
          if (dfs(i, j, -1, -1, grid)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
