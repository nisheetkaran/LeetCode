//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool lemonadeChange(int N, vector<int> &bills) {
        
        int fiveBill = 0;
        int tenBill = 0;
        
        bool ans = true;
        
        for(int i = 0; i < N; i++)
        {
            if(bills[i] == 5) fiveBill++;
            else if(bills[i] - 5 == 5)
            {
                if(fiveBill == 0)
                {
                    ans = false;
                    break;
                }
                else 
                {
                    fiveBill--;
                    tenBill++;
                }
            }
            else 
            {
                if(tenBill > 0 and fiveBill > 0)
                {
                    fiveBill--;
                    tenBill--;
                }
                else if(fiveBill >= 3)
                {   
                    fiveBill = fiveBill - 3;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends