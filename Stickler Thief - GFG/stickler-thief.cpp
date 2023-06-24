//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int find(int nums[], int i, vector<int> &dp)
    {
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + find(nums, i - 2, dp);
        int notpick = 0 + find(nums, i-1, dp);

        return dp[i] = max(pick, notpick);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1, -1);
        return find(arr, n-1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends