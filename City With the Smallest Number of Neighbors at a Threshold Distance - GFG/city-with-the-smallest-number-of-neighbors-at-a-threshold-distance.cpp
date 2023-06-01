//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
                     
        vector<vector<int>> dis(n, vector<int> (n, 1e6));
        for(auto x: edges)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            dis[u][v] = wt;
            dis[v][u] = wt;
        }
        
        for(int i = 0; i < n; i++) dis[i][i] = 0;
        
        for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
//             if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX)
// 			continue;
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
        
        int city = -1;
        int minCity = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(dis[i][j] <= distanceThreshold) count++;
            }
            
            if(count <= minCity)
            {
                minCity = count;
                city = i;
            }
        }
        
        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends