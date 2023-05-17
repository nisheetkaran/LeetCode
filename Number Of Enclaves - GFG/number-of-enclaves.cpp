//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        if(i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 0 or vis[i][j] == 1) return;

        vis[i][j] = 1;
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            dfs(ni, nj, n, m, grid, vis);
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++)
        {
            if(grid[i][0] == 1 and vis[i][0] == 0)
            dfs(i, 0, n, m, grid, vis);
            if(grid[i][m-1] == 1 and vis[i][m-1] == 0)
            dfs(i, m-1, n, m, grid, vis);
        }
        
        for(int j = 0; j < m; j++)
        {
            if(grid[0][j] == 1 and vis[0][j] == 0)
            dfs(0, j, n, m, grid, vis);
            if(grid[n-1][j] == 1 and vis[n-1][j] == 0)
            dfs(n-1, j, n, m, grid, vis);
        }
        
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //     {
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(grid[i][j] == 1 and vis[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends