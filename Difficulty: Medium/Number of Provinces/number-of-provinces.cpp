//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void dfs(vector<int> adj[] , int vis[] , int node){
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(adj , vis , it);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjls[V];
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        int vis[V] ={0} ;
        int cnt =0 ;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(adjls , vis , i);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends