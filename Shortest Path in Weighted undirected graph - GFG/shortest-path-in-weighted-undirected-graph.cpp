//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int, int>> adj[n+1];
        for(auto x: edges)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> dis(n+1, INT_MAX);
        dis[1] = 0;
        
        vector<int> parent(n+1, 0);
        for(int i = 0; i < n+1; i++)
        {
            parent[i] = i;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});
        
        while(!q.empty())
        {
            int l = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto x: adj[node])
            {
                int par = x.first;
                int d = x.second;
                
                if(l + d < dis[par])
                {
                    dis[par] = l + d;
                    q.push({dis[par], par});
                    parent[par] = node;
                }
            }
        }
        
        if(dis[n] == INT_MAX) return {-1};
        else
        {
            vector<int> ans;
            int node = n;
            
            while(parent[node] != node)
            {
                ans.push_back(node);
                node = parent[node];
            }
            
            ans.push_back(1);
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends