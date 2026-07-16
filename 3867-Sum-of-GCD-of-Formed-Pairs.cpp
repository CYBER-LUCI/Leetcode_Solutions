class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixgcd(nums.size(),0);
        vector<int> mx(nums.size(),0);
        mx[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            mx[i]=max(mx[i-1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            prefixgcd[i]=gcd(nums[i],mx[i]);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long sum=0;
        for(int i=0;i<nums.size()/2;i++){
            sum+=gcd(prefixgcd[i],prefixgcd[nums.size()-1-i]);
        }
        return sum;

    }
};