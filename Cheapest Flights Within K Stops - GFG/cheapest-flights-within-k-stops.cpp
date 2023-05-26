//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        vector<pair<int, int>> adj[n];
        for(auto x: flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        queue<vector<int>> q;
        q.push({0, src, 0});
        dist[src] = 0;
        
        while(!q.empty())
        {
            int stop = q.front()[0];
            int node = q.front()[1];
            int startCost = q.front()[2];
            q.pop();
            
            if(stop <= K)
            {
                for(auto x: adj[node])
                {
                    int neighbour = x.first;
                    int cost = x.second;
                    
                    if(dist[neighbour] > cost + startCost)
                    {
                        dist[neighbour] = cost + startCost;
                        q.push({stop + 1, neighbour, dist[neighbour]});
                    }
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1;
        else return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends