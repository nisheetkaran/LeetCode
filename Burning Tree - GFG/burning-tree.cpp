//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent;
        queue<Node*> q;
    
        Node* store;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
    
            if(temp->data == target) store = temp;
            if(temp->left)
            {
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right) 
            {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    
        unordered_map<Node*, int> vis;
        vis[store] = 1;
        q.push(store);
        int dis = 0;
    
        while(!q.empty())
        {
            int size = q.size();
            int flag = 0;
    
            for(int i = 0; i < size; i++)
            {
                Node* temp = q.front();
                q.pop();
    
                if(temp->left and !vis[temp->left])
                {
                    flag = 1;
                    q.push(temp->left);
                    vis[temp->left] = 1;
                }
                if(temp->right and !vis[temp->right])
                {
                    flag = 1;
                    q.push(temp->right);
                    vis[temp->right] = 1;
                }
                if(parent[temp] and !vis[parent[temp]])
                {
                    flag = 1;
                    q.push(parent[temp]);
                    vis[parent[temp]] = 1;
                }
            }
    
            if(flag == 1) dis++;
        }
    
        return dis;

    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends