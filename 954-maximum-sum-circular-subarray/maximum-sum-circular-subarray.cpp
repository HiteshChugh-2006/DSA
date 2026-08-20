class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int best = nums[0];
        int worst = nums[0];
        int ans = nums[0];
        int minSum = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            best = max(nums[i], best + nums[i]);
            ans = max(ans, best);

            worst = min(nums[i], worst + nums[i]);
            minSum = min(minSum, worst);

            sum += nums[i];
        }

        if (ans < 0)
            return ans;

        return max(ans, sum - minSum);
    }
};