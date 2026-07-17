class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int m = nums.size();

        vector<int> leftSum(m, 0);
        vector<int> rightSum(m, 0);
        vector<int> ans(m);

        for (int i = 1; i < m; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        for (int i = m - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < m; i++) {
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }

        return ans;
    }
};