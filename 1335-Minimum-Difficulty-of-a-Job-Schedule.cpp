#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        
        const int INF = 1e9;
       
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INF));
        
        dp[0][0] = 0;
        
        for (int j = 1; j <= d; ++j) {
            
            for (int i = j; i <= n; ++i) {
                
                int max_diff = 0;
               
                for (int k = i - 1; k >= j - 1; --k) {
                    
                    
                    max_diff = max(max_diff, jobDifficulty[k]);
                    
                    if (dp[k][j - 1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[k][j - 1] + max_diff);
                    }
                }
            }
        }
        
        return dp[n][d];
    }
};