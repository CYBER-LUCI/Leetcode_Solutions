class Solution {
public:
    int minimumTime(string s) {
        int left_cost=0;
        int max_cos=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                left_cost= min(left_cost+2,i+1);
            }
            else{
                left_cost=min(left_cost,i+1);
            }
            int max_coss;
            max_coss=left_cost+s.length()-i-1;
            max_cos=min(max_coss,max_cos);
        }
        return max_cos;
    }
};