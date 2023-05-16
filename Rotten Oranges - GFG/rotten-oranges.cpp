//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int vis[m][n];
        
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0;
            }
        }
        
        int ans = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1}; 
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second; 
            q.pop();
            ans = max(ans, t);
            
            for(int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++) 
            {
                if(vis[i][j] != 2 and grid[i][j] == 1) 
                return -1;
            }
        }
    
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends