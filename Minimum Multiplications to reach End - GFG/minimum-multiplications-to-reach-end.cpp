//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        int mod = 1e5;
        queue<pair<int, int>> q;
        q.push({0, start});
        vector<int> dist(1e5, INT_MAX);
        
        while(!q.empty())
        {
            int d = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node == end) return d;
            for(auto x: arr)
            {
                int newNode = node*x%mod;
                if(d+1 < dist[newNode])
                {
                    dist[newNode] = d+1;
                    q.push({d+1, newNode});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends