class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        queue<int> q;
        unordered_set<int> st;
        for(int num:nums){
            if(st.count(num))
            return true;

            q.push(num);
            st.insert(num);

            if(q.size()>k)
            {
                st.erase(q.front());
                q.pop();
            }
        }
        return false;

    }
};