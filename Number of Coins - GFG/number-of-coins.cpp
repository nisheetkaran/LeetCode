//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	   int t[M+1][V+1];
	   for(int j = 0; j <= V; j++) t[0][j] = INT_MAX - 1;
	   for(int i = 0; i <= M; i++) t[i][0] = 0;
	   
	   for(int i = 1; i <= M; i++)
	   {
	       for(int j = 1; j <= V; j++)
	       {
	           if(coins[i-1] > j) t[i][j] = t[i-1][j];
	           else t[i][j] = min(1 + t[i][j - coins[i-1]], t[i-1][j]);
	       }
	   }
	   
	   if(t[M][V] == INT_MAX - 1) return -1;
	   else return t[M][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends