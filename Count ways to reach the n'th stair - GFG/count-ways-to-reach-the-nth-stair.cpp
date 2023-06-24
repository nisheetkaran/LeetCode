//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        int mod = 1e9 + 7;
        if(n <= 2) return n;

        //after realising its similar to fibonacci
        int prev2 = 1;  // for n == 1
        int prev1 = 2;  // for n == 2
        int ans = 0;

        for(int i = 3; i <= n; i++)
        {
            ans = (prev1 + prev2)%mod;
            prev2 = prev1;
            prev1 = ans;
        }

        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends