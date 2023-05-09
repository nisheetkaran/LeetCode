//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    
    int t[1001][1001];
    bool flag = true;
    
    int lcs(int x, int y, string s1, string s2)
    {
        if(flag) {memset(t, -1, sizeof(t)); flag = false;}
        
        //base condition
        if(x == 0 || y == 0) return 0;
        else
        {
            if(t[x][y] != -1) return t[x][y];
            else
            {
                if(s1[x-1] == s2[y-1]) return t[x][y] = 1 + lcs(x-1, y-1, s1, s2);
                else
                {
                    return t[x][y] = max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1, s2));
                }
            }
            
        }
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends