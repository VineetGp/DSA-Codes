//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    bool check(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(check(it, adj, vis, pathVis)) return true;
            }
            else if(pathVis[it] == 1) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis (V,0);
        vector<int> pathVis (V,0);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(check(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends