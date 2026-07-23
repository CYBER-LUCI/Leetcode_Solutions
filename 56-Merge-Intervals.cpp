class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            else{
                return a[0]<b[0];
            }
        });
        vector<vector<int>> ans;
        int start= intervals[0][0];
        int end= intervals[0][1];
        for(auto v: intervals){
            if(v[0]>end){
                ans.push_back({start,end});
                start=v[0];
                end=v[1];
            }
            else if(v[0]<=end&&v[1]>end){
                end= v[1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};