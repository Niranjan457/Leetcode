class Solution {

public:
      int solve(int idx, int x,vector<int>&nums,vector<vector<int>>&dp)
      {
        //base case
        int n = nums.size();
        if(idx==n)
        {
            if(x==0)
            {
                return 0;
            }
            else
            {
                return -1e8;
            }
        }
        if(dp[idx][x]!=-1)
           return dp[idx][x];

        //recurrenec
        return dp[idx][x]= max(solve(idx+1,(x+nums[idx])%3,nums,dp)+nums[idx],solve(idx+1,x,nums,dp));
      }

    int maxSumDivThree(vector<int>& nums) {
       
       int n = nums.size();

        vector<vector<int>>dp(n+1,vector<int>(4,-1));

        



        return solve(0,0,nums,dp);
        
    }
};