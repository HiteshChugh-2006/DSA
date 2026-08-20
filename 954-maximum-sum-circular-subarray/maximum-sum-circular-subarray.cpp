class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax=nums[0];
        int curMin=nums[0];
        int MaxSum=nums[0];
        int MinSum=nums[0];
        int total=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            curMax=max(nums[i],nums[i]+curMax);
            MaxSum=max(MaxSum,curMax);
            curMin=min(nums[i],nums[i]+curMin);
            MinSum=min(MinSum,curMin);
            total+=nums[i];
        }
        if(MaxSum<0)
         return MaxSum;  
        return max(MaxSum,total-MinSum);
    }
};