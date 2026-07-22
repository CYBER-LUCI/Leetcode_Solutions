class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> ps(nums.size(),0);
        map<int,int> mp;
        ps[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            ps[i]=ps[i-1]+nums[i];
        }
        
        mp[0]=1;
        mp[ps[0]]++;
        int ans=0;
        if(ps[0]==k) ans++;
        for(int i=1;i<nums.size();i++){
            int a= ps[i]-k;
            if(mp[a]>0) ans+=mp[a];
            mp[ps[i]]++;
        }
        return ans;

    }
};