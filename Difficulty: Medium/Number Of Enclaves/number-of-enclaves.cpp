//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j] == 1){
                        
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            for(int a=-1;a<=1;a++){
                for(int b=-1;b<=1;b++){
                    if(abs(a) == 1 && abs(b) == 1 ) continue;
                    
                    int nr =  r +a;
                    int nc = c + b;
                    if(nr>=0 && nr<n && nc>=0 && nc<m &&
                    !vis[nr][nc] && grid[nr][nc] ==1) {
                        vis[nr][nc] =1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] ==1) cnt++;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends