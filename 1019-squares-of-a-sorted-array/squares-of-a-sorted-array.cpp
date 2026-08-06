class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;

        int i = 0;
        int j = nums.size() - 1;

   
        while (i <= j) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans.push_back(nums[i] * nums[i]);
                i++;
            } else {
                ans.push_back(nums[j] * nums[j]);
                j--;
            }
        }

        int l = 0;
        int r = ans.size() - 1;

        while (l < r) {
            swap(ans[l], ans[r]);
            l++;
            r--;
        }

        return ans;
    }
};