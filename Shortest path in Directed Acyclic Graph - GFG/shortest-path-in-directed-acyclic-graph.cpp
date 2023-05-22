//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     
     void dfs(int i, int vis[], vector<pair<int, int>> adj[], stack<int> &s) {
        vis[i] = 1;
        
        for(auto x: adj[i])
        {
            int v = x.first;
            if(!vis[v]) dfs(v, vis, adj, s);
        }
        
        s.push(i);
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for(int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        int vis[N] = {0};
        stack<int> s;
        for(int i = 0; i < N; i++)
        {
            if(!vis[i])
            dfs(i, vis, adj, s);
        }
        
        vector<int> dis(N);
        for(int i = 0; i < N; i++)
        {
            dis[i] = 1e9;
        }
        
        dis[0] = 0;
        while(s.size())
        {
            int node = s.top();
            s.pop();
            
            for(auto x: adj[node])
            {
                int v = x.first;
                int wt = x.second;
                
                if(dis[v] > dis[node] + wt)
                {
                    dis[v] = dis[node] + wt;
                }
            }
        }
        
        for(int i = 0; i < N; i++)
        {
            if(dis[i] == 1e9) dis[i] = -1;
        }
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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