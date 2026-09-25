class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>st(score.size());
        vector<pair<int,int>>pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push_back({score[i],i});
        }
        sort(pq.begin(),pq.end(),greater<pair<int, int>>());
        int rank=1;
       for (int rank = 1; rank <= pq.size(); rank++){
            int index=pq[rank-1].second;
            if(rank==1)
              st[index]="Gold Medal";
            else if(rank==2)
              st[index]="Silver Medal";
            else if(rank==3)
              st[index]="Bronze Medal";
            else
              st[index]=to_string(rank);     
            }
            return st;
    }
};