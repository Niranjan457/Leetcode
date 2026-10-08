class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
                else
                {
                    visited[i][j]=0;
                }
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
      int dr[]={-1,0,1,0};
      int dc[]={0,-1,0,1};
      int tmax=0;
      int cnt=0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tmax=max(tmax,t);

            for(int j=0;j<4;j++)
            {
                int nr= r+dr[j];
                int nc = c+dc[j];
                if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]==0 && grid[nr][nc]==1)
                {
                    q.push({{nr,nc},t+1});
                    grid[nr][nc]=2;
                    visited[nr][nc]=1;
                    cnt++;
                }
            }
            

        }
        return count==cnt?tmax:-1;
    }
};