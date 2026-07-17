class Solution {
public:
// sabse phele dfs likh base case ke liye ek 
   int dfs(int u,int n,int p,vector<vector<pair<int,int>>> &adj){
    int total_cost=0;
    for(auto v: adj[u]){
        int cost=v.second;
        int node_v=v.first;
        if(node_v!=p){
        total_cost+=dfs(node_v,n,u,adj)+cost;}
    }
    return total_cost;
   }
   void dfs2(int u,int p, vector<vector<pair<int,int>>> &adj,vector<int>&dp){
    for(auto v: adj[u]){
        int cost= v.second;
        int node= v.first;
        if(node!=p){
        if(cost==0){
            dp[node]=dp[u]+1;
        }
        else{
            dp[node]=dp[u]-1;
        }
        
        dfs2(node,u,adj,dp);
        }

    }

   }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1],0});
            adj[edge[1]].push_back({edge[0],1});
        }
        vector<int> dp(n,0);
        int total_initial=dfs(0,n,-1,adj);
        dp[0]=total_initial;
        dfs2(0,-1,adj,dp);
        return dp;
            
        }
    
};