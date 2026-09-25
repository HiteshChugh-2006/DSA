class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>st(score.size());
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
        int rank=1;
        while(!pq.empty()){
            int index=pq.top().second;
            pq.pop();
            if(rank==1)
              st[index]="Gold Medal";
            else if(rank==2)
              st[index]="Silver Medal";
            else if(rank==3)
              st[index]="Bronze Medal";
            else
              st[index]=to_string(rank);     

              rank++;
            }
            return st;
    }
};
