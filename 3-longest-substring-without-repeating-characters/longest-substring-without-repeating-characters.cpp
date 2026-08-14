class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>freq;
        int res=0;
        for(int l=0,r=0;r<s.size();r++)
        {
            freq[s[r]]++;
            while(freq[s[r]]>1)
            {
                freq[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};