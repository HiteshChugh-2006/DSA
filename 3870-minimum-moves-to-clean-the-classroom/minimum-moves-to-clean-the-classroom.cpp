class Solution {
public:
    int minMoves(vector<string>& a, int E) {
        int m=a.size(),n=a[0].size(),sr,sc,L=0;
        vector<vector<int>> id(m,vector<int>(n,-1));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) {
                if(a[i][j]=='S') sr=i,sc=j;
                if(a[i][j]=='L') id[i][j]=L++;
            }

        if(!L) return 0;

        int M=1<<L, full=M-1;
        vector<char> vis(m*n*(E+1)*M);

        auto get=[&](int r,int c,int e,int mask) {
            return (((r*n+c)*(E+1)+e)*M+mask);
        };

        queue<array<int,4>> q;
        q.push({sr,sc,E,0});
        vis[get(sr,sc,E,0)]=1;

        int dr[]={1,-1,0,0},dc[]={0,0,1,-1},d=0;

        while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                auto [r,c,e,mask]=q.front();q.pop();
                if(mask==full) return d;
                if(!e) continue;

                for(int k=0;k<4;k++) {
                    int x=r+dr[k],y=c+dc[k];
                    if(x<0||x>=m||y<0||y>=n||a[x][y]=='X') continue;

                    int ne=e-1,nm=mask;
                    if(a[x][y]=='L') nm|=1<<id[x][y];
                    if(a[x][y]=='R') ne=E;

                    int z=get(x,y,ne,nm);
                    if(!vis[z]) {
                        vis[z]=1;
                        q.push({x,y,ne,nm});
                    }
                }
            }
            d++;
        }
        return -1;
    }
};