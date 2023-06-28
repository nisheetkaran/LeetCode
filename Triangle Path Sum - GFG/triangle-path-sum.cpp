//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int help(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp)
    {
        if(i == triangle.size() - 1)
        {
            return triangle[i][j];
        } 

        if(dp[i][j] != -1) return dp[i][j];

        int direct = triangle[i][j] + help(i+1, j, triangle, dp);
        int oneRight = triangle[i][j] + help(i+1, j+1, triangle, dp);

        return dp[i][j] = min(direct, oneRight);
    }
    
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        
        int m = triangle[n-1].size();
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        if(triangle.size() == 1) return triangle[0][0];
        return help(0, 0, triangle, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends