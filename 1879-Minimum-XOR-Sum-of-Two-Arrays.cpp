class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        // can i write all states and solve ??
        //current state and ,mask likh lu fir 
        //dp have 2 state i and mask the max xor upto i with the given mask ?
        //intitally mask=0;
        // dp[0][mask]= xor wirh each elemnt and find the mask
        // dp[1][mask]= again same xor with other elemnts and such that the bit of mask is not fixed 
        // dp[i][mask]= xor with all i-1 masks and find??
        vector<int> dp(1<<nums1.size(),INT_MAX);
        dp[0]=0;
        for(int mask=0;mask<(1<<nums1.size());mask++){
            if(dp[mask]==INT_MAX) continue;
            int i= __builtin_popcount(mask);
            if(i==nums1.size()) continue;
            for(int j=0;j<nums2.size();j++){
                if((mask&(1<<j))==0){
                    int new_mask= mask|(1<<j);
                    dp[new_mask]=min(dp[new_mask],dp[mask]+(nums1[i]^nums2[j]));
                }
            }
        }
        return dp[(1<<nums1.size())-1];
    }
};