//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
     int helper(int i, int j1, int j2, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>> &dp)
    {   
        if(j1 < 0 or j1 >= m or j2 < 0 or j2 >= m) return -1e9;
        if(i == n - 1) 
        {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = INT_MIN;
        for(int k1 = -1; k1 <= 1; k1++)
        {
            for(int k2 = -1; k2 <= 1; k2++)
            {
                if(j1 == j2) maxi = max(maxi, grid[i][j1] + helper(i+1, j1+k1, j2+k2, grid, m, n, dp));
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + helper(i+1, j1+k1, j2+k2, grid, m, n, dp));
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int >>> dp(n, vector<vector<int>> (m, vector < int> (m, -1)));
        
        return helper(0, 0, m-1, grid, m, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends