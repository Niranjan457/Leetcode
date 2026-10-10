class Solution {
public:
     int solve(int idx,int buy, vector<int>&prices,int n)
     {
        if(idx==n)
        {
            return 0;
        }


        int profit=0;
        if(buy)
        {
            profit=max(-prices[idx]+solve(idx+1,0,prices,n),0+solve(idx+1,1,prices,n));

        }
        else
        {
            profit=max(prices[idx]+solve(idx+1,1,prices,n),0+solve(idx+1,0,prices,n));

        }
        return profit;
     }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        dp[n][0]=0;
        dp[n][1]=0;
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
        if(buy)
        {
            profit=max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);

        }
        else
        {
            profit=max(prices[idx]+dp[idx+1][1],dp[idx+1][0]);

        }
        dp[idx][buy]=profit;
            }
        }
        

         return dp[0][1];
        
    }
};