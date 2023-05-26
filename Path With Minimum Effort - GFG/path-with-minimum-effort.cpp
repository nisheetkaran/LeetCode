//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;
        
        priority_queue <pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}});
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int maxDiff = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            
            if(r == n - 1 and c == m - 1) return maxDiff;
            
            for(int k = 0; k < 4; k++)
            {
                int x = r + dr[k];
                int y = c + dc[k];
                
                if(x < n and x >= 0 and y < m and y >= 0)
                {
                    int d = max(abs(heights[x][y] - heights[r][c]), maxDiff);
                    if(d < dist[x][y])
                    {
                        dist[x][y] = d;
                        q.push({d, {x, y}});
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends