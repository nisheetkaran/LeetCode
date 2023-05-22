//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    
        set<string> s;
        for(auto x: wordList) s.insert(x);
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        s.erase(startWord);
        
        int ans = 0;
        while(!q.empty())
        {
            string cur = q.front().first;
            int l = q.front().second;
            q.pop();
            
            if(cur == targetWord)
            {
                ans = l;
                break;
            }
            
            for(int i = 0; i < cur.size(); i++)
            {
                char original = cur[i];
                for(char j = 'a'; j <= 'z'; j++)
                { 
                    cur[i] = j;
                    if(s.find(cur) != s.end())
                    {
                        q.push({cur, l+1});
                        s.erase(cur);
                    }
                }
                
                cur[i] = original;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends