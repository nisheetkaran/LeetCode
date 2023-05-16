//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, int m, int n, vector<vector<char>> &grid)
    {
        if(i < 0 or j < 0 or i >= m or j >= n or grid[i][j] == '0' or grid[i][j] == '2') return;
        
        grid[i][j] = '2';
        for(int a = -1; a <= 1; a++)
        {
            for(int b = -1; b <= 1; b++)
            {
                dfs(i+a, j+b, m, n, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
       
       int m = grid.size();
       int n = grid[0].size();
       
       int ans = 0;
       for(int i = 0; i < m; i++)
       {
           for(int j = 0; j < n; j++)
           {
               if(grid[i][j] == '1' and grid[i][j] != '2')
               {
                   dfs(i, j, m, n, grid);
                   ans++;
               }
           }
       }
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends