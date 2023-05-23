//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis( n , vector<int> (m, INT_MAX));
        dis[source.first][source.second] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int l = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            if(r == destination.first and c == destination.second) return l;
            for(int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];
                
                if(nr < n and nr >= 0 and nc >= 0 and nc < m and grid[nr][nc] == 1)
                {
                    if(dis[nr][nc] > l + 1)
                    {
                        dis[nr][nc] = l+1;
                        q.push({l+1, {nr, nc}});
                    }
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends