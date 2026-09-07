class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(26, 0);
        long long total = 0;

        for (char c : s) {
            int i = c - 'a';

            long long add = (total - dp[i] + 1 + MOD) % MOD;

            total = (total + add) % MOD;

            dp[i] = (dp[i] + add) % MOD;
        }

        return total;
    }
};