class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int v){
        if(v==parent[v]) return v;
        return parent[v]=find(parent[v]);

    }
    void unite(int u, int v){
        int rootu= find(u);
        int rootv= find(v);
        if(rootu==rootv) return;
        if(rank[rootv]>rank[rootu]) swap(rootu,rootv);
        parent[rootv]=rootu;
        if(rank[rootu]==rank[rootv]) rank[rootu]++;  
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,0);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(edgeList.begin(),edgeList.end(),[](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2];
        });
        sort(queries.begin(),queries.end(),[](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2];
        });
        int first=0,second=0;
        vector<bool> ans(queries.size(),false);
        while(second<queries.size()){
            if(first<edgeList.size()&&queries[second][2]>edgeList[first][2]){
                int u= edgeList[first][0];
                int v= edgeList[first][1];
                unite(u,v);
                first++;
            }
            else{
                int u1= queries[second][0];
                int u2= queries[second][1];
                int idx= queries[second][3];
                if(find(u1)==find(u2)) ans[idx]=true;
                else{
                    ans[idx]=false;
                }
                second++;
            }
            
        }
        return ans;


    }
};