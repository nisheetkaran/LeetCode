//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> s;
        for(auto x: wordList) s.insert(x);
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<string> used;
        used.push_back(beginWord);
        int l = 0;
        
        vector<vector<string>> ans;
        while(!q.empty())
        {
            vector<string> curr = q.front();
            q.pop();
            
            if(curr.size() > l)
            {
                l++;
                for(auto x: used) s.erase(x);
            }
            
            string word = curr.back();
            
            if(word == endWord)
            {
                if(ans.size() == 0) ans.push_back(curr);
                else if(ans[0].size() == curr.size())
                {
                    ans.push_back(curr);
                }
            }
            
            for (int i = 0; i < word.size(); i++)
            {  
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if(s.find(word) != s.end())
                    {
                        curr.push_back(word);
                        q.push(curr);
                        used.push_back(word);
                        curr.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends