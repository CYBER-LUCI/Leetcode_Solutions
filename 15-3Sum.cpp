class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i + 1; j < n - 1; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int target = -(nums[i] + nums[j]);

                int l = lower_bound(nums.begin() + j + 1, nums.end(), target) - nums.begin();

                if(l < n && nums[l] == target)
                    ans.push_back({nums[i], nums[j], nums[l]});
            }
        }

        return ans;
    }
};