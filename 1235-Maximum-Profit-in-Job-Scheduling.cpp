class Solution {
    int search(vector<int>& sortedEnds, int target, int index) {
        return upper_bound(sortedEnds.begin(), sortedEnds.begin() + index, target) - sortedEnds.begin() - 1;
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> sortedEnds(n);
        for (int i = 0; i < n; i++) {
            sortedEnds[i] = jobs[i][1];
        }
        
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        
        for (int i = 1; i < n; i++) {
            int inc = jobs[i][2];
            int last = search(sortedEnds, jobs[i][0], i);
            
            if (last != -1) {
                inc += dp[last];
            }
            
            dp[i] = max(dp[i - 1], inc);
        }
        
        return dp[n - 1];
    }
};