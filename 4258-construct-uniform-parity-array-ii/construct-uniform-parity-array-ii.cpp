class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = INT_MAX;
       
        for (int x : nums1) {
            if (x % 2 == 1) {
                odd = min(odd, x);
            }
        }
        for (int x : nums1) {
            if (x % 2 == 0 && odd != INT_MAX && x < odd) {
                return false;
            }
        }

        return true;
    }
};