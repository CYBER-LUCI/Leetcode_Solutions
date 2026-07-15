class Solution {
public: 
    vector<int> countVisitedNodes(vector<int>& edges) {
    int n = edges.size();
    vector<int> ans(n, 0);
    vector<int> inDegree(n, 0);
    
    for (int i = 0; i < n; i++) {
        inDegree[edges[i]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<bool> inCycle(n, true); 
    vector<int> branchNodes;      
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        inCycle[u] = false; 
        branchNodes.push_back(u); 
        
        int v = edges[u];
        inDegree[v]--;
        if (inDegree[v] == 0) {
            q.push(v);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (inCycle[i] && ans[i] == 0) {
            int curr = i;
            int cycleLength = 0;
            
            do {
                cycleLength++;
                curr = edges[curr];
            } while (curr != i);
            
            curr = i;
            do {
                ans[curr] = cycleLength;
                curr = edges[curr];
            } while (curr != i);
        }
    }
    
    reverse(branchNodes.begin(), branchNodes.end());
    
    for (int u : branchNodes) {
        ans[u] = ans[edges[u]] + 1;
    }
    
    return ans;
}
};