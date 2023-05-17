//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void dfs(int i, int j, int m, int n, vector<vector<char>> &mat, vector<vector<int>> &vis)
    {
        if(i >= n or i < 0 or j >= m or j < 0 or vis[i][j] == 1 or mat[i][j] == 'X') return;
        
        vis[i][j] = 1;
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        for(int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            dfs(ni, nj, m, n, mat, vis);
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++)
        {
            if(mat[i][0] == 'O' and vis[i][0] == 0)
            dfs(i, 0, m, n, mat, vis);
            if(mat[i][m - 1] == 'O' and vis[i][m - 1] == 0)
            dfs(i, m-1, m, n, mat, vis);
        }
     
        for(int j = 0; j < m; j++)
        {
            if(mat[0][j] == 'O' and vis[0][j] == 0)
            dfs(0, j, m, n, mat, vis);
            if(mat[n - 1][j] == 'O' and vis[n - 1][j] == 0)
            dfs(n-1, j, m, n, mat, vis);
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(mat[i][j] == 'O' and vis[i][j] == 0) 
                mat[i][j] = 'X';
            }
        }
        
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //     {
        //         cout<<vis[i][j]<<" ";
        //     }
            
        //     cout<<endl;
        // }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends