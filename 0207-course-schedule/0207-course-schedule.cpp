class Solution {
public:
    int topological(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto it: pre) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            topo.push_back(x);

            for(auto it: adj[x]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo.size();
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return numCourses == topological(numCourses, prerequisites); 
    }
};