//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int i, vector<int> adj[], int vis[], int parent)
    {
        vis[i] = 1;
        for(auto x: adj[i])
        {
            if(vis[x] == 0)
            {
                if(check(x, adj, vis, i)) return true;
            }
            else if(x != parent) return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        for(int i = 0; i < V; i++)
        {
            if(!vis[i]) if(check(i, adj, vis, -1)) return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends