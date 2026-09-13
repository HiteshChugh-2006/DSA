class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, 
                       vector<vector<int>>& img2) {
        
        int n = img1.size();

        vector<pair<int, int>> a, b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j])
                    a.push_back({i, j});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img2[i][j])
                    b.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;

        int ans = 0;

        for (auto p : a) {
            for (auto q : b) {

                int dx = p.first - q.first;
                int dy = p.second - q.second;

                mp[{dx, dy}]++;

                ans = max(ans, mp[{dx, dy}]);
            }
        }

        return ans;
    }
};