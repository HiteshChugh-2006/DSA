class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {

                if (nums1[i] == nums2[j]) {

                    bool found = false;

                    for (int k = 0; k < res.size(); k++) {
                        if (res[k] == nums1[i]) {
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        res.push_back(nums1[i]);

                    break;   // No need to check remaining elements of nums2
                }
            }
        }

        return res;
    }
};