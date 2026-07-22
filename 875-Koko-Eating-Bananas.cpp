class Solution {
public:
   bool isvalid(int mid, vector<int> &piles, int h){
    long long hours_spent=0;
    for(int i=0;i<piles.size();i++){
       if(piles[i]%mid==0){
        hours_spent+= piles[i]/mid;
       }
       else{
        hours_spent+= piles[i]/mid+1;
       }
    }
    if(hours_spent<=h) return true;
    return false;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        //maximum soeed is eat all banana and min speed is eating one banana of max
        int high=0;
        int low=1;
        for(auto x: piles){
            high=max(high,x);
        }
        int ans=0;
        while(high>=low){
            int mid= low+(high-low)/2;
            if(isvalid(mid,piles,h)){
                high= mid-1;
                ans=mid;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};