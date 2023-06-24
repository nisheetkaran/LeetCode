//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		
		int nthStair(int n) {
		 
		 //for n = 1,  1 way
		 //for n = 2,  2 way
		 //for n = 3,  2 way;
		 //for n = 4,  3 way;
		 //for n = 5,  3 way;
		 //for n = 6,  4 way;
		 
		 return n/2 + 1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends