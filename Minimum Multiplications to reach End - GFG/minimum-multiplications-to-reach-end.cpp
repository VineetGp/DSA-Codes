//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// #define make_pair mp;
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int x = 1e5;
        int n = arr.size();
        queue<pair<int,int>> q;
        vector<int> vis(x,-1);
        q.push(make_pair(start,0));
        vis[start] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            int node = it.first;
            int level = it.second;
            q.pop();
            for(int i = 0; i<n; i++){
                int nn = (arr[i]*node)%x;
                if(vis[nn] == -1){
                    if(nn == end) return level+1;
                    q.push(make_pair(nn, level+1));
                    vis[nn] = level+1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends