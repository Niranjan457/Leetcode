class Solution {
public:

     int solve(int idx, int buy,int cap, vector<int>&prices,int n, vector<vector<vector<int>>>&dp)
     {
        if(cap==0)
          return 0;
        if(idx==n)
           return 0;
       int profit =0;
          if(buy)
       {
          profit = max(-prices[idx]+solve(idx+1,0,cap,prices,n,dp),0+solve(idx+1,1,cap,prices,n,dp));
       }
       else
       {
            profit = max(prices[idx]+solve(idx+1,1,cap-1,prices,n,dp),solve(idx+1,0,cap,prices,n,dp));
       }
           return profit;
     }
    int maxProfit(vector<int>& prices) {
        int n = prices .size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

             for(int idx=n-1;idx>=0;idx--)
             {
                for(int buy=0;buy<=1;buy++)
                {
                    for(int cap=1;cap<=2;cap++)
                    {
                           int profit =0;
                       if(buy)
                 {
                    profit = max(-prices[idx]+dp[idx+1][0][cap],0+dp[idx+1][1][cap]);
                 }
                 else
               {
               profit = max(prices[idx]+dp[idx+1][1][cap-1],dp[idx+1][0][cap]);
                }
                dp[idx][buy][cap]=profit;
                 }
                    }
                }
             



        return dp[0][1][2];
        
    }
};