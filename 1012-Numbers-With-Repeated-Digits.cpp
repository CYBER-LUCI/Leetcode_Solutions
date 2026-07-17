class Solution {
public:
    string s;
    int dp[12][1024];
    int count_ways(int idx, bool tight, bool leading_zero, int mask){
        if(idx==s.length()) return leading_zero?0:1;
        if(!tight&&!leading_zero&&dp[idx][mask]!=-1) return dp[idx][mask];
        int limit= (tight)?(s[idx]-'0'):9;
        int total_unique=0;
        for(int i=0;i<=limit;i++){
            if(i==0&&leading_zero){
                total_unique+=count_ways(idx+1,tight&&(i==limit),true,mask);
            }
            else{
                if((mask&(1<<i))==0) total_unique+=count_ways(idx+1,tight&&(i==limit),false,(mask|(1<<i)));
            }


        }
        if(!tight&&!leading_zero) dp[idx][mask]=total_unique;
        return total_unique;

    }
    int numDupDigitsAtMostN(int n) {
        s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int unique_no= count_ways(0,true,true,0);
        return n-unique_no;
    
    }
};