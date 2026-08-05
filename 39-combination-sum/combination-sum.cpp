class Solution {
public:
    vector<vector<int>> res;

    void cs(const vector<int>& c, int target, int start, vector<int>& cur)
    {
        if(target == 0)
        {
            res.push_back(cur);
            return;
        }

        for(int i = start; i < c.size(); i++)
        {
            if(target - c[i] >= 0)
            {
                cur.push_back(c[i]);
                cs(c, target - c[i], i, cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> cur;
        cs(candidates, target, 0, cur);
        return res;
    }
};