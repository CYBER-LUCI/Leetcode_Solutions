class Solution {
public:
    bool isvalid(int mid, vector<int>& weights, int days){
        int rs=0;
        int total_days=1;
        for(int i=0;i<weights.size();i++){
            if(rs+weights[i]<=mid){
                rs+=weights[i];
            }
            else{
                rs= weights[i];
                total_days++;
            }
        }
        if(total_days<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //we need to find the min capacity of ship so easily can't we assume using binary search beasue linearly taking must give tle 
        // so binary search on the container weight
        int low=0;
        int high=0;
        int cap=0;
        for(auto x: weights){
            low= max(low,x);
            high+=x;
        }
        while(low<=high){
            int mid= low+(high-low)/2;
            if(isvalid(mid,weights,days)){
                high=mid-1;
                cap=mid;
            }
            else{
                low= mid+1;
            }
        }
        return cap;
    }
};