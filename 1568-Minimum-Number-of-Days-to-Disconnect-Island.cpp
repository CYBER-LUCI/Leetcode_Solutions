class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[r][c] = true;
        for (auto dir : dirs) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && 
                grid[nr][nc] == 1 && !vis[nr][nc]) {
                dfs(nr, nc, grid, vis);
            }
        }
    }
    
    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int islands = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    islands++;
                    dfs(i, j, grid, vis); 
                }
            }
        }
        return islands;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        if (countIslands(grid) != 1) {
            return 0;
        }
        
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    
                    if (countIslands(grid) != 1) {
                        return 1;  
                    }
                    
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};