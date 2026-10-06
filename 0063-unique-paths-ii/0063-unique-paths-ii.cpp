class Solution {
public:
    int mod=(int) (2*1e9);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
           int m = obstacleGrid.size();
           int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                     dp[i][j]=0;
                     continue;

                }
                else if (i==0 && j==0)
                {
                    dp[i][j]=1;
                
                }
                else
                {     int left = 0;
                      int up =0;
                   
                    if(i>=1)
                    {
                        up = dp[i-1][j];


                    }
                    if(j>=1)
                    {
                        left = dp[i][j-1];
                    }
                    dp[i][j]=(left+up)%mod;
                }
                
            }
        }
        return dp[m-1][n-1];
        
    }
};