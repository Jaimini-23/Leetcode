class Solution {
public:
    bool bfs(int src, int dest, vector<vector<int>> &adj, int n) {
        vector<int>vis(n + 1,0);
        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == dest) return true;

            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(auto it: edges) {
            int x = it[0];
            int y = it[1];
            if(bfs(x,y,adj,n)) return {x,y};

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        return {};
    }
};