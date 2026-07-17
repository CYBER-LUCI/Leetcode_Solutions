class Solution {
public:
    int countPalindromes(string s) {
        int n = s.length();
        if (n < 5) return 0;
        
        long long MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> pref(n, vector<vector<long long>>(10, vector<long long>(10, 0)));
        vector<vector<vector<long long>>> suff(n, vector<vector<long long>>(10, vector<long long>(10, 0)));
        
        vector<long long> count_left(10, 0);
        for (int i = 0; i < n; i++) {
            int curr = s[i] - '0';
            if (i > 0) {
                for (int a = 0; a < 10; a++) {
                    for (int b = 0; b < 10; b++) {
                        pref[i][a][b] = pref[i-1][a][b];
                    }
                }
                for (int a = 0; a < 10; a++) {
                    pref[i][a][curr] = (pref[i][a][curr] + count_left[a]) % MOD;
                }
            }
            count_left[curr]++;
        }
        
        vector<long long> count_right(10, 0);
        for (int i = n - 1; i >= 0; i--) {
            int curr = s[i] - '0';
            if (i < n - 1) {
                for (int a = 0; a < 10; a++) {
                    for (int b = 0; b < 10; b++) {
                        suff[i][a][b] = suff[i+1][a][b];
                    }
                }
             
                for (int a = 0; a < 10; a++) {
                    suff[i][a][curr] = (suff[i][a][curr] + count_right[a]) % MOD;
                }
            }
            count_right[curr]++;
        }
        
        long long total_palindromes = 0;
        
        for (int i = 2; i < n - 2; i++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    long long combinations = (pref[i-1][a][b] * suff[i+1][a][b]) % MOD;
                    total_palindromes = (total_palindromes + combinations) % MOD;
                }
            }
        }
        
        return total_palindromes;
    }
};