//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        
        int prev2 = cost[0];
        int prev1 = cost[1];

        int ans = 0;
        
        for(int i = 2; i < N; i++)
        {
            int left = INT_MAX;
            int right = INT_MAX;

            left = prev1 + cost[i];
            if(i > 1) right = prev2 + cost[i];

            ans = min(left, right);
            prev2 = prev1;
            prev1 = ans;
        }

        return min(prev1, prev2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends