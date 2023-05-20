//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(Item a, Item b)
    {
        return (a.value*1.0/a.weight > b.value*1.0/b.weight);
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, compare);
        int curWeight = 0;
        double finalValue = 0;
        
        for(int i =0; i < n; i++)
        {
            if(curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            else
            {
                finalValue += (W - curWeight)*arr[i].value*1.0/arr[i].weight;
                break;
            }
        }
        
        return finalValue;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends