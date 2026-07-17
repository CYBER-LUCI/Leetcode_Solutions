
class Solution {
    string upper_bound_str;
    string suffix_str;
    int max_limit;
    long long memo[20][2]; // Only need idx and tight

    long long dp(int idx, bool tight) {
        // Base case: successfully built a valid number
        if (idx == upper_bound_str.length()) return 1;
        
        if (!tight && memo[idx][tight] != -1) return memo[idx][tight];

        // The max digit allowed by the upper bound prefix
        int current_bound = tight ? (upper_bound_str[idx] - '0') : 9;
        
        // The max digit allowed by the problem's 'limit' variable
        int allowed_limit = min(current_bound, max_limit);
        
        long long ways = 0;
        int L = upper_bound_str.length();
        int len = suffix_str.length();

        if (idx < L - len) {
            for (int d = 0; d <= allowed_limit; d++) {
                ways += dp(idx + 1, tight && (d == current_bound));
            }
        } 
        else {
            int locked_digit = suffix_str[idx - (L - len)] - '0';
            
            if (locked_digit <= allowed_limit) {
                ways += dp(idx + 1, tight && (locked_digit == current_bound));
            }
        }

        if (!tight) memo[idx][tight] = ways;
        return ways;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        max_limit = limit;
        suffix_str = s;
        
        for (char c : s) {
            if (c - '0' > limit) return 0;
        }

        auto solve = [&](long long n) {
            upper_bound_str = to_string(n);
            if (upper_bound_str.length() < suffix_str.length()) return 0LL;
            
            memset(memo, -1, sizeof(memo));
            return dp(0, true);
        };

        return solve(finish) - solve(start - 1);
    }
};