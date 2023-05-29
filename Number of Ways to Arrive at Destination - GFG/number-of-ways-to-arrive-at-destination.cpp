//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        using ll = long long;
        vector<pair<ll, ll>> adj[n];
        for(auto x: roads)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        
        priority_queue<pair<ll, ll>, 
        vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        
        int mod = 1e9 + 7;
        vector<ll> ways(n, 0);
        vector<ll> dist(n, 1e15);
        
        dist[0] = 0;
        ways[0] = 1;
        
        q.push({0, 0});
        while(!q.empty())
        {
            ll l = q.top().first;
            ll node = q.top().second;
            q.pop();
            
            for(auto x: adj[node])
            {
                ll adjNode = x.first;
                ll d = x.second;
                
                //FIRST TIME COMING
                if(l + d < dist[adjNode])
                {
                    dist[adjNode] = l + d;
                    q.push({l+d, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(l + d == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends