//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int find(int* nums, int i, vector<int> &dp)
    {
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + find(nums, i - 2, dp);
        int notpick = 0 + find(nums, i-1, dp);

        return dp[i] = max(pick, notpick);
    }
	
	int findMaxSum(int *arr, int n) {
	   
	   vector<int> dp(n+1, -1);
       return find(arr, n-1, dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends