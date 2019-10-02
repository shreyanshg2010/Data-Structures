// C++ Program to count islands in boolean 2D matrix 
#include <bits/stdc++.h> 
using namespace std; 
 void dfs(vector<vector<int>>& grid, int r, int c, int& m, int& n) {
        if (r < 0 || c < 0 || r == m || c == n || grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0;
        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c - 1, m, n);
        dfs(grid, r, c + 1, m, n);
    }
  int numIslands(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++res;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return res;
    }
    
   
int main() 
{ 
	vector<vector<int>>M{ { 1, 1, 0, 0, 0 }, 
					              { 0, 1, 0, 0, 1 }, 
					              { 0, 0, 0, 1, 1 }, 
					              { 0, 0, 0, 0, 0 }, 
					              { 1, 0, 1, 0, 1 } }; 
              
	cout << "Number of islands is: " << numIslands(M); 

	return 0; 
} 

