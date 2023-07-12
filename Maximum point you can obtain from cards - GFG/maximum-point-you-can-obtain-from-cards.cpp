//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    long long maxScore(vector<int> &cardPoints, int n, int k) {

        int i = k - 1;
        int j = n - 1;
        
        int prev = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);   
        int ans = prev;

        while(k--)
        {
            int next = prev - cardPoints[i] + cardPoints[j];
            prev = next;
            ans = max(ans, next);
            i--;
            j--;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends