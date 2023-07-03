//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    vector<int> findTwoElement(vector<int> A, int n) {
    int store = 0;
    
    for(int i = 1; i <= n; i++) store ^= i;
    for(int i = 0; i < n; i++)
    {
        store ^= A[i];
    }
    
    //rightmost set bit mask
    int rsbm = store & (-store);
    
    int ans1 = 0;
    int ans2 = 0;
    
    for(int i = 1; i <= n; i++)
    {
        if(rsbm&i) ans1 ^= i;
        else ans2 ^= i;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(rsbm&A[i]) ans1 = ans1^A[i];
        else ans2 = ans2^A[i];
    }
    
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(ans1 == A[i])
        {
            flag = 1;
            break;
            //duplicate is in ans1 and missing in anns2
        }
    }
    
    vector<int> ans;
    if(flag)
    {
        ans.push_back(ans1);
        ans.push_back(ans2);
    } 
    else 
    {
        ans.push_back(ans2);
        ans.push_back(ans1);
    } 

    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends