class Solution {
public:
    bool isvalid(vector<int> &nums, int k, int mid){
        int count=1;
        int st=0;
        int running_sum=0;
        while(st<nums.size()){
            if(running_sum+nums[st] <=mid){
                running_sum+= nums[st];
                st++;
            }
            else{
                count++;
                running_sum=0;
            }

        }
        if(count<=k) return true;
        return false;


        }

    int splitArray(vector<int>& nums, int k) {
        int low=0;
        int sum=0;
        int maxi=0;
        for(auto x: nums){
            maxi=max(maxi,x);
            sum+=x;
        }
        low=maxi;
        int high= sum;
        int ans=0;
        while(low<=high){
           int mid=low+(high-low)/2;
            if(isvalid(nums, k, mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};