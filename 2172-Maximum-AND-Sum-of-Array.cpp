class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        // intiliase a dp of size 1<<2*numsslots
        vector<int> dp(1<<2*numSlots,0);

        for(int i=0; i<(1<<2*numSlots); i++){
            // ye loop apna elemnt batayega in the nums
            if(__builtin_popcount(i)>=nums.size()) continue;
            for(int j=0;j<2*numSlots;j++){
                int slt= j/2+1;
                int new_slot= i|(1<<j);
                if((i&(1<<j))==0){
                    dp[new_slot]=max(dp[new_slot],dp[i]+(nums[__builtin_popcount(i)]&slt));
                } 

            } }
            return *max_element(dp.begin(),dp.end());

            

        }

};