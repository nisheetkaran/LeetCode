//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void merge(int l, int mid, int r, vector<int> &arr, int &ans)
    {
        int i = l;
        int j = mid + 1;
        
        while(i <= mid and j <= r)
        {
            if(arr[i] > 2*1ll*arr[j])
            {
                ans += mid - i + 1;
                j++;
            }
            else i++;
        }
        
        i = l;
        j = mid + 1;
        int k = l;
        int *v = new int[r + 1];

        while(i <= mid and j <= r)
        {
            if(arr[i] < arr[j])
            {
                v[k] = arr[i];
                k++;
                i++;
            } 
            else 
            {
                v[k] = arr[j];
                k++;
                j++;
            }
        }

        if(i > mid)
        {
            while(j <= r)
            {
                v[k] = arr[j];
                j++;
                k++;
            }
        }
        else
        {
            while(i <= mid)
            {
                v[k] = arr[i];
                i++;
                k++;
            }
        }

        for(int k = l; k <= r; k++) arr[k] = v[k];  
        delete []v;
    }
    
    void mergeSort(int l, int r, vector<int> &arr, int &ans)
    {
        if(l < r)
        {
            int mid = l + (r - l)/2;
            mergeSort(l, mid, arr, ans);
            mergeSort(mid+1, r, arr, ans);
            merge(l, mid, r, arr, ans);
        }
    }
    
    int countRevPairs(int n, vector<int> arr) {
        int ans = 0;
        mergeSort(0, n-1, arr, ans);
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
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends